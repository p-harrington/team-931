#include "Elevator.h"
#include "../RobotMap.h"

Elevator::Elevator() :
		Subsystem("ExampleSubsystem")
{

}

void Elevator::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
 }

void Elevator::Runwinch(float wspd)
 {winchSpeed.SetSpeed(wspd);
 }
// Put methods for controlling this subsystem
// here. Call these from Commands.
