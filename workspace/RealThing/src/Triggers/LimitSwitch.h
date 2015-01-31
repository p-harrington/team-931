#ifndef LimitSwitch_H
#define LimitSwitch_H

#include "WPILib.h"

class LimitSwitch: public Button, public DigitalInput
{
public:
	LimitSwitch(uint32_t channel);
	bool Get();
};

#endif
