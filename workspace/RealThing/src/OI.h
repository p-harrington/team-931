#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
  Joystick driveStick, elevStick;
  JoystickButton straightenup,
# if ! usingnewstick
  speeder,
# endif
   elevUp, elevDown,
   elevStop;
public:
	OI();
	Joystick & DriveStick(), &ElevStick();
	JoystickButton & Straightenup();
# if ! usingnewstick
	JoystickButton & Speeder();
# endif
};

inline Joystick & OI::DriveStick()
 {return driveStick;}

inline Joystick & OI::ElevStick()
 {return elevStick;}

inline JoystickButton & OI::Straightenup()
 {return straightenup;}

# if ! usingnewstick
inline JoystickButton & OI::Speeder()
 {return speeder;}
# endif
#endif
