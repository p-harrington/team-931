#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
  Joystick driveStick, elevStick;
  JoystickButton straightenup;
public:
	OI();
	Joystick & DriveStick(), &ElevStick();
	JoystickButton & Straightenup();
};

inline Joystick & OI::DriveStick()
 {return driveStick;}

inline Joystick & OI::ElevStick()
 {return elevStick;}

inline JoystickButton & OI::Straightenup()
 {return straightenup;}
#endif
