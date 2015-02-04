#ifndef MoveElevator_H
#define MoveElevator_H

#include "../CommandBase.h"
#include "WPILib.h"


class OperateElevator: public CommandBase
{
public:
    OperateElevator();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

class MoveElevator: public CommandBase
{
public:
    MoveElevator();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

class MoveElevatorBy: public MoveElevator
{double chge;
public:
	MoveElevatorBy(double);
	void Initialize();
};

class MoveElevatorTo: public MoveElevator
{double endpt;
public:
	MoveElevatorTo(double);
	void Initialize();
};

#endif
