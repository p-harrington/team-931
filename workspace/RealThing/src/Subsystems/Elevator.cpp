#include "Elevator.h"
#include "../RobotMap.h"
#include "commands/winchReset.h"

Elevator::Elevator() :
		Subsystem("Elevator"),
		winchSpeed(8), // PWM output 8;
					  // drive uses 0-7.
		sensor(8),//dio port 0
		ctrlr(1,0,0,&sensor, &winchSpeed),
		baselmt(9), //dio port 1
		brake(0) // port 0
{
  ctrlr.SetInputRange(0,7);//XXX measure winch travel better
  ctrlr.SetAbsoluteTolerance(float (1)/256);
  baselmt.WhileHeld(new WinchReset);
}

void Elevator::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new OperateElevator());
  // xxx operator control?
 }

void Elevator::ZeroSensor()
 {
  sensor.Init();
 }

void Elevator::Runwinch(float wspd)
//xxx adjust this 1/50 for desired speed
 {SetTarget(ctrlr.GetSetpoint() + wspd / 50);
  //winchSpeed.SetSpeed(wspd);
 }

void Elevator::SetTarget(float tgt)
 {
  ctrlr.SetSetpoint(tgt);
  if(brake.Get() != (Relay::kForward))
  {brake.Set (Relay::kForward);
   Wait (.25);
  }
  ctrlr.Enable();
 }

void Elevator::SetBrake()
 {ctrlr.Disable();
  brake.Set(Relay::kOff);
 }
// Put methods for controlling this subsystem
// here. Call these from Commands.
