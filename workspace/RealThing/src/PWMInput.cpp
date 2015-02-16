/*
 * PWMInput.cpp
 *
 *  Created on: Jan 30, 2015
 *      Author: PIHarrington
 */

#include <PWMInput.h>

PWMInput::PWMInput(uint32_t channel, unsigned max, bool reversed) :
   rawsource(channel),
   updown(rawsource),
   downup(rawsource),
   maxval(max),
   reversed(reversed)
 {updown.SetSemiPeriodMode(true);
# if NotNewIdea // New idea, old way kept for reference
  downup.SetSemiPeriodMode(false);
# endif
 }

PWMInput::~PWMInput()
 {
  // Auto-generated destructor stub
 }

double PWMInput::bareInput()
 {double uptime = updown.GetPeriod(),
	 downtime=downup.GetPeriod();
# if NotNewIdea
 return uptime * (maxval + 1) / (uptime + downtime);
# else
 return uptime * (maxval + 1) / downtime;
# endif
 }

double PWMInput::PIDGet()
 {
  return reversed ? 1 - bareInput() / maxval : bareInput() / maxval;
 }

unsigned PWMInput::input()
 {return bareInput() - 1;
 }

bool PWMInput::IsBad()
 {SmartDashboard::PutNumber("sensor source", rawsource.Get());
/*  SmartDashboard::PutNumber("sensor up", rawsource.ReadRisingTimestamp());
  SmartDashboard::PutNumber("sensor down", rawsource.ReadFallingTimestamp());
*/
 return updown.GetStopped();
 }
