#ifndef Elevator_H
#define Elevator_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "RotationCtr.h"
#include "Triggers/LimitSwitch.h"

class Elevator: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
  Talon winchSpeed;
  RotationCtr sensor;
  PIDController ctrlr;
  LimitSwitch baselmt;
//TODO consequences of baselmt pressed- stop winch, reinit sensor
//TODO joystick runs winch speed, unless _buttons_ have chosen height
  Relay brake;
public:
	Elevator();
	void InitDefaultCommand();
	void ZeroSensor();
  void Runwinch(float); // xxx ???
  void SetTarget(float); //unsets brake
   void SetBrake();
   bool OnTarget() {return ctrlr.OnTarget();}
   float GetTarget() {return ctrlr.GetSetpoint();}
   void Run(float);
   void StopHere();
# if 1
   Relay& Brake() {return brake;}
   RotationCtr& Sensor() {return sensor;}
# endif
};

#endif
