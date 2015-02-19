#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/TeleopDrive.h"
# define PIH 1
# if PIH
#include "Commands/autoPIH.h"
typedef autoPIH autoner;
# else
#include "Commands/autoner.h"
# endif
#include "CommandBase.h"
/*
class LowerElev : public CommandBase
{public:
	LowerElev() {Requires(elevator);}
	void Initialize() {elevator->SetTarget(-6);}
	void Execute() {}
	bool IsFinished() {return elevator->Limit().Get() == false;}
	void End() {}
	void Interrupted() {}
} lowerElev;
*/
class Robot: public IterativeRobot
{
private:
	Command *autonomousCommand;
	SendableChooser autoChooser;
	LiveWindow *lw;
	void RobotInit()
	{
		CommandBase::init();
		autonomousCommand = 0; //TODO: real autonomous
		autoChooser.AddObject("totefield", new autoner(2.65)/*new Auto1*/);
		autoChooser.AddObject("toteramp", new autoner(3)/*new Auto2*/);
		autoChooser.AddObject("totebinfield", new autonerbot(2.85)/*new Auto3*/);
		autoChooser.AddObject("totebinramp", new autonerbot(3.25)/*new Auto4*/);
		autoChooser.AddDefault("nothing",0);
		SmartDashboard::PutData("Which autonomous?", &autoChooser);
		lw = LiveWindow::GetInstance();
	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
	  autonomousCommand = static_cast<Command*>(autoChooser.GetSelected());
		if (autonomousCommand != NULL)
			autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{SmartDashboard::PutNumber("elev on target", CommandBase::elevator->OnTarget());
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
};

START_ROBOT_CLASS(Robot);

