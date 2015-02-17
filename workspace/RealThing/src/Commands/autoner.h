#ifndef autoner_H
#define autoner_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Subsystems/SwerveDrive.h"

class autoner: public CommandBase
{
  float dist;
public:
	autoner(float dist);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
