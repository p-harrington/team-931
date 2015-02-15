/*
 * RotationCtr.cpp
 *
 *  Created on: Jan 30, 2015
 *      Author: Deveveloper
 */

#include <RotationCtr.h>

RotationCtr::RotationCtr(uint32_t channel) :
  angle(channel, 256), // using as5030 -- 256 outputs
  firstAngle(0), lastAngle(0), rotCtr(0)
 {}

RotationCtr::~RotationCtr()
 {
  // TODO Auto-generated destructor stub
 }

void RotationCtr::Init()
 {//XXX: when can we first read the angle?
 firstAngle = lastAngle = angle.PIDGet();
 rotCtr = 0;
 }

static const double near0 = (double)1/16,
                    near1 = 1 - near0;

double RotationCtr::PIDGet()
 {double newAngle = angle.PIDGet();
  if (newAngle <= near0 && lastAngle > near1)
   ++ rotCtr;
  else if (newAngle > near1 && lastAngle <= near0)
   -- rotCtr;
  SmartDashboard::PutNumber("new angle", newAngle);
  SmartDashboard::PutNumber("last angle", lastAngle);
  SmartDashboard::PutNumber("first angle", firstAngle);

  lastAngle = newAngle;
  return newAngle - firstAngle + rotCtr;
 }

bool RotationCtr::IsBad()
 {return angle.IsBad();
 }
