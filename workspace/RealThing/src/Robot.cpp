#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/TeleopDrive.h"
#include "CommandBase.h"

class Robot: public IterativeRobot
{
private:
	Command *autonomousCommand;
	LiveWindow *lw;
	//Encoder enc;
	void RobotInit()
	{
		CommandBase::init();
		autonomousCommand = new TeleopDrive(); //TODO: real autonomous
		lw = LiveWindow::GetInstance();
	}
	
	void DisabledPeriodic()
	{//SmartDashboard::PutNumber("encoder", enc.GetDistance());
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		if (autonomousCommand != NULL)
			autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();
	}

	void TeleopPeriodic()
	{
# if 1
	  if(CommandBase::oi->ElevStick().GetRawButton(1))
	  {CommandBase::elevator->Brake().Set(Relay::kForward);
	   SmartDashboard::PutString("Brake", "on");}
	 if(CommandBase::oi->ElevStick().GetRawButton(3))
	  {CommandBase::elevator->Brake().Set(Relay::kOff);
	   SmartDashboard::PutString("Brake", "off");}
	 SmartDashboard::PutNumber("LimitSwitch",
	   CommandBase::elevator->Limit().Get());
/*	 SmartDashboard::PutBoolean("sensor bad",
	   CommandBase::elevator->Sensor().IsBad());
*/
# endif
	 Scheduler::GetInstance()->Run();
	}

	void TestPeriodic()
	{
		lw->Run();
	}
public:
	//Robot(): enc(8,9){}
};

START_ROBOT_CLASS(Robot);

