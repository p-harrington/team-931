#ifndef autoner_H
#define autoner_H

#include "WPILib.h"

class autoPIH: public CommandGroup
{
public:
	autoPIH(float dist);
};
class autonerbot: public CommandGroup
{
public:
	autonerbot(float dist);
};

#endif
