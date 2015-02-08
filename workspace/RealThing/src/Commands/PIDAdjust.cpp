#include "PIDAdjust.h"

PIDAdjust::PIDAdjust()
{Requires(swerveDrive);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void PIDAdjust::Initialize()
{
	SmartDashboard::PutNumber("Drive P", swerveDrive->GetP()),
	SmartDashboard::PutNumber("Drive I", swerveDrive->GetI()),
	SmartDashboard::PutNumber("Drive D", swerveDrive->GetD());
}

// Called repeatedly when this Command is scheduled to run
void PIDAdjust::Execute()
{
  swerveDrive->SetPID(
	SmartDashboard::GetNumber("Drive P"),
	SmartDashboard::GetNumber("Drive I"),
	SmartDashboard::GetNumber("Drive D"));
}

// Make this return true when this Command no longer needs to run execute()
bool PIDAdjust::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void PIDAdjust::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PIDAdjust::Interrupted()
{

}
