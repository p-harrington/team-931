#include "WinchReset.h"

WinchReset::WinchReset()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
  Requires(elevator);
}

// Called just before this Command runs the first time
void WinchReset::Initialize()
{elevator->ZeroSensor();

}

// Called repeatedly when this Command is scheduled to run
void WinchReset::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool WinchReset::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void WinchReset::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WinchReset::Interrupted()
{

}
