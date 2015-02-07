#include "OI.h"
#include "Commands/Straightenup.h"

OI::OI() : driveStick(1), elevStick(2),
 straightenup(&driveStick, 6)
{
	// Process operator interface input here.
  straightenup.WhenPressed(new ::Straightenup);
}
