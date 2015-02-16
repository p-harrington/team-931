/*
 * PWMInput.h
 *
 *  Created on: Jan 30, 2015
 *      Author: Deveveloper
 */

#ifndef SRC_PWMINPUT_H_
#define SRC_PWMINPUT_H_

#include <WPILib.h>

/* Thanks to this thread:
 * http://forums.usfirst.org/showthread.php?12086-Measuring-PWM-input-signals/page2
 * for the technique. */
class PWMInput: public PIDSource
 {DigitalInput rawsource;
  Counter updown, downup;
  const unsigned maxval;
  const bool reversed;

 public:
  PWMInput(uint32_t channel, unsigned max, bool reversed = false);
  virtual ~PWMInput();
  double bareInput();
  double PIDGet();
  unsigned input();
  bool IsBad();
 };

#endif /* SRC_PWMINPUT_H_ */
