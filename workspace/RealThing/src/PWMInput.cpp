/*
 * PWMInput.cpp
 *
 *  Created on: Jan 30, 2015
 *      Author: PIHarrington
 */

#include <PWMInput.h>

PWMInput::PWMInput(uint32_t channel, unsigned max) :
   rawsource(channel),
   updown(rawsource),
   downup(rawsource),
   maxval(max)
 {updown.SetSemiPeriodMode(true);
  downup.SetSemiPeriodMode(false);
 }

PWMInput::~PWMInput()
 {
  // TODO Auto-generated destructor stub
 }

double PWMInput::bareInput()
 {double uptime = updown.GetPeriod(),
	 downtime=downup.GetPeriod();
  return uptime * (maxval + 1) / (uptime + downtime);
 }

double PWMInput::PIDGet()
 {return bareInput() / maxval;
 }

unsigned PWMInput::input()
 {return bareInput() - 1;
 }
