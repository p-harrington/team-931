#include "LimitSwitch.h"
#include "commands/WinchReset.h"

LimitSwitch::LimitSwitch(uint32_t channel) : DigitalInput(channel)
{
  WhileHeld(new WinchReset);
}

bool LimitSwitch::Get()
{
	return DigitalInput::Get();
}

