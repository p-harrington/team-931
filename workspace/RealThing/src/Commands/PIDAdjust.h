#ifndef PIDAdjust_H
#define PIDAdjust_H

#include "../CommandBase.h"
#include "WPILib.h"

class PIDAdjust: public CommandBase
{
public:
	PIDAdjust();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
