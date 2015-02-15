#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
  Joystick driveStick, elevStick;
  JoystickButton straightenup,
   speeder,
   elevUp, elevDown,
   elevStop;
public:
	OI();
	Joystick & DriveStick(), &ElevStick();
	JoystickButton & Straightenup();
	JoystickButton & Speeder();
};

inline Joystick & OI::DriveStick()
 {return driveStick;}

inline Joystick & OI::ElevStick()
 {return elevStick;}

inline JoystickButton & OI::Straightenup()
 {return straightenup;}

inline JoystickButton & OI::Speeder()
 {return speeder;}
#endif
