#include "Elevator.h"
#include "../RobotMap.h"

Elevator::Elevator() :
		Subsystem("Elevator"),
		winchSpeed(8), // PWM output 8;
					  // drive uses 0-7.
		sensor(0),//XXX insert actual dio port for 0
		ctrlr(1,0,0,&sensor, &winchSpeed),
		baselmt(2)//XXX insert dio port for 2
{
  ctrlr.SetInputRange(0,7);//XXX measure winch travel better
}

void Elevator::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
 }

void Elevator::ZeroSensor()
 {
  sensor.Init();
 }

void Elevator::Runwinch(float wspd)
 {winchSpeed.SetSpeed(wspd);
 }
// Put methods for controlling this subsystem
// here. Call these from Commands.
