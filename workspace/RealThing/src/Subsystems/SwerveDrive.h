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
   {AnalogInput encoder;
   Talon rotSpeed, drvSpeed; /*the motors are cims and pg (34?) .*/
   complex speedGoal;
   static uint32_t ix;
/*   size_t GetIx();  */ // I got too clever
   static constexpr double maxVolts = 2.5; // actually 1/2 of 5 V
	 // The encoder output is wrapped at 2.5 by PIDGet
   static constexpr double pi = M_PI /*3.14159265*/;
   static constexpr double piRatio = pi/maxVolts;
   double GetAngle(){return piRatio*encoder.GetVoltage();}
	public:
   Wheel(): PIDController(1,0,0,this,&rotSpeed),
	  encoder(ix), rotSpeed(ix/*2*ix+1*/),drvSpeed(numWheels + ix++/*2*ix++*/)
	//, speedGoal(0)
	 {SetContinuous();
	  SetInputRange(0, maxVolts);
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
};

#endif
