#include "Elevator.h"
#include "../RobotMap.h"
#include "commands/winchReset.h"
#include "commands/MoveElevator.h"

Elevator::Elevator() :
		Subsystem("Elevator"),
		winchSpeed(8), // PWM output 8;
					  // drive uses 0-7.
		sensor(8),//dio port 8
		ctrlr(-3,0,0,&sensor, &winchSpeed), // XXX adjust here
		baselmt(9), //dio port 9
		brake(0) // relay port 0
{
  ctrlr.SetAbsoluteTolerance(float (16)/256);
  baselmt.WhenInactive(new WinchReset);
}

void Elevator::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new OperateElevator());
  // xxx operator control?
 }

void Elevator::ZeroSensor()
 {ctrlr.Reset();
  ctrlr.SetInputRange(0,6);//XXX measure winch travel better
  ctrlr.SetSetpoint(ctrlr.GetSetpoint());
  sensor.Init();
 }

void Elevator::Runwinch(float wspd)
#if 1
// adjust this 1/35 for desired speed, - sign
 {SetTarget(ctrlr.GetSetpoint() - wspd / 35);
  //winchSpeed.SetSpeed(wspd);
 }
#else
{SmartDashboard::PutNumber("new winch", wspd);
 Run(wspd);}
#endif
void Elevator::SetTarget(float tgt)
 {
  ctrlr.SetSetpoint(tgt);
  SmartDashboard::PutNumber("winch setting", sensor.PIDGet());
  SmartDashboard::PutNumber("winch setpoint", tgt);
  SmartDashboard::PutNumber("ctrlr enabled", ctrlr.IsEnabled());
  SmartDashboard::PutNumber("brake setting", brake.Get());
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
void Elevator::Run(float x)
 {
  winchSpeed.Set(x);
 }

void Elevator::StopHere()
 {ctrlr.SetSetpoint(sensor.PIDGet());
  SetBrake();
 }
