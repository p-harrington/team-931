#include <Subsystems/SwerveDrive.h>
#include "CommandBase.h"
# include "Commands/TeleopDrive.h"
# include <cfenv> // for FE_DIVBYZERO

SwerveDrive::SwerveDrive() :
		Subsystem("SwerveDrive")
{fedisableexcept (FE_DIVBYZERO);}

void SwerveDrive::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new TeleopDrive);
 }

// These should each be {y, -x}
// where (x, y) is the vector of
// this wheel from the center of rotation.
static const float length = 24.203125; // check measure
static const float width  = 21.25; //   "       "
static const float rot_scale = 1/sqrt(length*length + width*width);
static const float rot_length = length * rot_scale;
static const float rot_width  = width  * rot_scale;
static const complex rot_vecs[numWheels] =
  { {rot_length,-rot_width},{-rot_length,-rot_width},
	{-rot_length,rot_width},{ rot_length, rot_width}};

void SwerveDrive::Drive(float x, float y, float rot, bool align)
 {complex straight(x,y), vecs[numWheels];

 for (unsigned n=0; n<numWheels; ++n)
   {vecs[n] = straight + rot * rot_vecs[n];
   //SmartDashboard::PutNumber("victor " /*+ std::basic_string(n) + " setting"*/, real(vecs[n]));
   }
 float max = 0;
  for (unsigned n=0; n<numWheels; ++n)
   max = std::max(max, abs(vecs[n]));
  if (max < 1) max = 1;
  for (unsigned n=0; n<numWheels; ++n)
	wheels[n].Drive(vecs[n] / max, align);
 }

uint32_t SwerveDrive::Wheel::ix = 0;
/*//Still too clever.
size_t SwerveDrive::Wheel::GetIx()
 {return this-CommandBase::swerveDrive->wheels;}
*/

void SwerveDrive::Wheel::Drive(complex vec, bool align)
 {speedGoal = align?0: vec;
  SetSetpoint((.5 - atan(real(vec)/imag(vec)) / pi) * maxVolts);}

// I'm using this to do other responses to
// encoder.PIDGet() before handing it to Calculate.
double SwerveDrive::Wheel::PIDGet()
 {double val = encoder.PIDGet();
 // This could be used more effectively
  complex rot_vec = speedGoal *
	exp(complex(0,-GetAngle()));
  // XXX: maybe have a ramp-up and/or conditional on this
  drvSpeed.Set(real(rot_vec));
  if (val > maxVolts) val -= maxVolts;
  return val;}

// Put methods for controlling this subsystem
// here. Call these from Commands.

