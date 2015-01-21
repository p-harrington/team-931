#ifndef Elevator_H
#define Elevator_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Elevator: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
  Talon winchSpeed;

public:
	Elevator();
	void InitDefaultCommand();
  void Runwinch(float);
};

#endif
