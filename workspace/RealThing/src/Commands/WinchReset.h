#ifndef WinchReset_H
#define WinchReset_H

#include "../CommandBase.h"
#include "WPILib.h"

class WinchReset: public CommandBase
{
public:
	WinchReset();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
