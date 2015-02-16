#include "TeleopDrive.h"

TeleopDrive::TeleopDrive()
{
	Requires(swerveDrive);
}

// Called just before this Command runs the first time
void TeleopDrive::Initialize()
{

}
const float minThrottle = .4;
// Called repeatedly when this Command is scheduled to run
void TeleopDrive::Execute()
{
  Joystick & joy = oi->DriveStick();
  swerveDrive->Drive(joy.GetX(Joystick::kLeftHand),
	joy.GetY(Joystick::kLeftHand),
# if newdrivestick
	joy.GetTwist(),
	(minThrottle + 1 + (minThrottle - 1) * joy.GetThrottle())/2
# else
	/*joy.GetX(Joystick::kRightHand)*/joy.GetRawAxis(4),
	.5
# endif
	/*,
	joy.GetRawButton(5)*/);//in case of realignment;5 is top left button
}

// Make this return true when this Command no longer needs to run execute()
bool TeleopDrive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void TeleopDrive::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TeleopDrive::Interrupted()
{
  End();
}
