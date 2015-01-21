#include "TeleopDrive.h"

TeleopDrive::TeleopDrive()
{
	Requires(swerveDrive);
}

// Called just before this Command runs the first time
void TeleopDrive::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void TeleopDrive::Execute()
{

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
