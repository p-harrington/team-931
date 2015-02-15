#include <Subsystems/SwerveDrive.h>
#include "CommandBase.h"
# include "Commands/TeleopDrive.h"
# include <cfenv> // for FE_DIVBYZERO

SwerveDrive::SwerveDrive() :
		Subsystem("SwerveDrive"),
		speedface(false)
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
static const complex i = {0,1};
static const complex rot_vecs[numWheels] =
  { {-rot_width,  rot_length},{ rot_width,  rot_length},
	{ rot_width, -rot_length},{-rot_width, -rot_length}};

static const char* wheelnames[] = {"Wheel 0", "Wheel 1", "Wheel 2", "Wheel 3"};

static float sloper(float rotx){
  if(abs(rotx) *3 < 1) return 2*rotx;
  return (rotx +(rotx >0 ? 1: -1))/2;
}

void SwerveDrive::Drive(float x, float y, float rot, bool align)
 {/*SmartDashboard::PutNumber("SwerveDrive.Drive x:", x);
  SmartDashboard::PutNumber("SwerveDrive.Drive y:", y);
  SmartDashboard::PutNumber("SwerveDrive.Drive rot:", rot);
  SmartDashboard::PutNumber("SwerveDrive.Drive align:", align);
  SmartDashboard::PutBoolean("SwerveDrive.Toggle stat", speedface);*/
  complex straight(-x,y), vecs[numWheels];
   //straight *= norm(straight); // makes small motions smaller
   if(speedface) straight *= .75, rot *= .3;
   rot = sloper(rot); //same reason above
//   if(abs(rot) >=.85) oi->DriveStick();

 for (unsigned n=0; n<numWheels; ++n)
   {vecs[n] = straight + i* rot * rot_vecs[n];
    //if(n&2) vecs[n] *= .90; // ad hoc try to even up
    //SmartDashboard::PutNumber(wheelnames[n]/*"Talon x" + std::basic_string(n) + " setting"*/, real(vecs[n]));
    //SmartDashboard::PutNumber("Talon y" /*+ std::basic_string(n) + " setting"*/, imag(vecs[n]));
       }
 float max = 0;
  for (unsigned n=0; n<numWheels; ++n)
   max = std::max(max, abs(vecs[n]));
  if (max < 1) max = 1;
  for (unsigned n=0; n<numWheels; ++n)
	wheels[n].Drive(float(n==2?1:-1)*vecs[n] / max, align);
 }

uint32_t SwerveDrive::Wheel::ix = 0;
/*//Still too clever.
size_t SwerveDrive::Wheel::GetIx()
 {return this-CommandBase::swerveDrive->wheels;}
*/

void SwerveDrive::Wheel::Drive(complex vec, bool align)
 {speedGoal = align?0: vec;
  SetSetpoint((.5 + atan(imag(vec)/real(vec)) / pi) * maxRot);}

// I'm using this to do other responses to
// encoder.PIDGet() before handing it to Calculate.
double SwerveDrive::Wheel::PIDGet()
 {double val = encoder.PIDGet();
 SmartDashboard::PutNumber(wheelnames[this_ix], GetAngle());
 // This could be used more effectively
  complex rot_vec = speedGoal *
	exp(complex(0,-GetAngle()));
  // XXX: maybe have a ramp-up and/or conditional on this
  drvSpeed.Set(imag(rot_vec));
  while (val > maxRot) val -= maxRot;
  while (val < 0) val += maxRot;
    return val;
 }

bool SwerveDrive::OnTarget()
 {for(unsigned n = 0; n < numWheels; ++n)
   if(!wheels[n].OnTarget()) return false;
  return true;
 }

void SwerveDrive::SetPID(float P, float I, float D)
 {for(unsigned n = 0; n < numWheels; ++n)
   wheels[n].SetPID(P, I, D);
 }
// Put methods for controlling this subsystem
// here. Call these from Commands.

