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
# if NotNewIdea // New idea, old way kept for reference
  downup.SetSemiPeriodMode(false);
# endif
 }

PWMInput::~PWMInput()
 {
  // TODO Auto-generated destructor stub
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
 {return bareInput() / maxval;
 }

unsigned PWMInput::input()
 {return bareInput() - 1;
 }

bool PWMInput::IsBad()
 {/*SmartDashboard::PutNumber("sensor", rawsource.Get());
  SmartDashboard::PutNumber("sensor up", rawsource.ReadRisingTimestamp());
  SmartDashboard::PutNumber("sensor down", rawsource.ReadFallingTimestamp());
*/
 return updown.GetStopped();
 }
