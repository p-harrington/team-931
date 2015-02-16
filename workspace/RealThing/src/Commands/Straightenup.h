#ifndef Straightenup_H
#define Straightenup_H

#include "../CommandBase.h"
#include "WPILib.h"

class Straightenup: public CommandBase
{
public:
	Straightenup();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
# if ! newdrivestick
class SpeedToggle: public CommandBase
{
public:
	SpeedToggle();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
# endif

#endif
