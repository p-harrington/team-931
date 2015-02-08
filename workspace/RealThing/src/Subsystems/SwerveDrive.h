#ifndef SWERVE_DRIVE_H
#define SWERVE_DRIVE_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "complex"
typedef std::complex<float> complex;

static const unsigned numWheels=4;

class SwerveDrive: public Subsystem
{
private:
	// Wheel is a private member class, since we don't
	// expect any more to be created than these.
  class Wheel: public PIDController, public PIDSource
   {
# if OldEncoder
   Encoder encoder;
# else
   AnalogInput encoder;
# endif
   Talon rotSpeed, drvSpeed; /*the motors are cims and pg (34?) .*/
   complex speedGoal;
   static uint32_t ix;
   uint32_t this_ix;
/*   size_t GetIx();  */ // I got too clever
   static constexpr double maxRot =
# if OldEncoder
	 206.75; // actually 1/2 of 413.5 rot
# else
     2.5; // 1/2 of 5 Volts
# endif
	 // The encoder output is wrapped at 206.75 by PIDGet -CHECK NUMBER!
   static constexpr double pi = M_PI /*3.14159265*/;
   static constexpr double piRatio = pi/maxRot;
   double GetAngle(){return piRatio*encoder.
# if OldEncoder
	 GetDistance();
# else
	 GetVoltage();
# endif
   }
	public:
   Wheel(): PIDController(.02,0,0,this,&rotSpeed),
# if OldEncoder
	  encoder(2*ix,2*ix+1),
# else
	  encoder(ix),
# endif
	  rotSpeed(ix/*2*ix+1*/),drvSpeed(numWheels + ix/*2*ix++*/),
	  this_ix(ix++)
	//, speedGoal(0)
	 {SetContinuous();
	  SetInputRange(0, maxRot);
	  SetPercentTolerance(12.5);
	  Enable();}
   void Drive(complex, bool);
   //void SetSpeedGoal(float);
   void InitDefaultCommand();
    protected:
   double PIDGet();
   /*void PIDWrite(double);*/} wheels[numWheels];
public:
	SwerveDrive();
	void InitDefaultCommand();
/* @param  */
	void Drive(float, float, float, bool=false);
	bool OnTarget();
};

#endif
