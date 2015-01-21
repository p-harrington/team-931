#include <Subsystems/SwerveDrive.h>
#include "CommandBase.h"
# include <cfenv> // for FE_DIVBYZERO

SwerveDrive::SwerveDrive() :
		Subsystem("SwerveDrive")
{fedisableexcept (FE_DIVBYZERO);}

void SwerveDrive::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
 }

// These should each be {y, -x}
// where (x, y) is the vector of
// this wheel from the center of rotation.
static const float rot_scale = 1;
static const complex rot_vecs[4] =
  { {rot_scale,-rot_scale},{-rot_scale,-rot_scale},
	{-rot_scale,rot_scale},{rot_scale,rot_scale}};

void SwerveDrive::Drive(float x, float y, float rot)
 {complex straight(x,y), vecs[4];

 for (int n=0; n<4; ++n)
   vecs[n] = straight + rot * rot_vecs[n];

 float max = 0;
  for (int n=0; n<4; ++n)
   max = std::max(max, abs(vecs[n]));
  if (max < 1) max = 1;
  for (int n=0; n<4; ++n)
	wheels[n].Drive(vecs[n] / max);
 }

uint32_t SwerveDrive::Wheel::ix = 0;
/*//Still too clever.
size_t SwerveDrive::Wheel::GetIx()
 {return this-CommandBase::swerveDrive->wheels;}
*/

void SwerveDrive::Wheel::Drive(complex vec)
 {speedGoal = vec;
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

