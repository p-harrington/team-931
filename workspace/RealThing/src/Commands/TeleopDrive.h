#ifndef TELEOP_DRIVE_H
#define TELEOP_DRIVE_H

#include "../CommandBase.h"
#include "WPILib.h"

class TeleopDrive: public CommandBase
{
public:
	TeleopDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
