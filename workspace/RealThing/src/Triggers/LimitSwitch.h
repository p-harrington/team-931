#ifndef LimitSwitch_H
#define LimitSwitch_H

#include "WPILib.h"
/********
 * The switch, connected to Signal and Ground, reports true when
 * open, false when closed. I.e. WhenActive(cmd) runs cmd until
 * the switch closes the circuit.
 **********************************************/
class LimitSwitch: public Button, public DigitalInput
{
public:
	LimitSwitch(uint32_t channel);
	bool Get();
};

#endif
