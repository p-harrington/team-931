#include "autoner.h"

autoner::autoner(float dist):dist(dist)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
  Requires(swerveDrive);
  Requires(elevator);
}

// Called just before this Command runs the first time
void autoner::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void autoner::Execute()
{
  elevator->SetTarget(2);
  Wait(1);
  swerveDrive->Drive(.1,-1,0,.5);
  Wait(dist);
  swerveDrive->Drive(0,0,0,0);
  Wait(12);
}

// Make this return true when this Command no longer needs to run execute()
bool autoner::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void autoner::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void autoner::Interrupted()
{

}
