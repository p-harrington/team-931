#ifndef Elevator_H
#define Elevator_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "RotationCtr.h"
#include "LimitSwitch.h"

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

public:
	Elevator();
	void InitDefaultCommand();
  void Runwinch(float);
};

#endif
