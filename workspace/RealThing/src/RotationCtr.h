/*
 * RotationCtr.h
 *
 *  Created on: Jan 30, 2015
 *      Author: Deveveloper
 */

#ifndef SRC_ROTATIONCTR_H_
#define SRC_ROTATIONCTR_H_
#include "PWMInput.h"

class RotationCtr : public PIDSource
 {PWMInput angle;
  int rotCtr;
  double firstAngle, lastAngle;

 public:
  RotationCtr(uint32_t channel);
  virtual ~RotationCtr();
  void Init();
  double PIDGet();
  bool IsBad();
 };

#endif /* SRC_ROTATIONCTR_H_ */
