#include "CommandBase.h"
#include "Commands/Scheduler.h"
#include "Commands/PIDAdjust.h"

// Initialize a single static instance of all of your subsystems to NULL
SwerveDrive* CommandBase::swerveDrive = NULL;
Elevator* CommandBase::elevator = NULL;
OI* CommandBase::oi = NULL;

CommandBase::CommandBase(char const *name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	swerveDrive = new SwerveDrive();
	elevator = new Elevator();
	SmartDashboard::PutData(swerveDrive);
	SmartDashboard::PutData(new PIDAdjust);
//	SmartDashboard::PutNumber("Drive P", .125);
//	SmartDashboard::PutNumber("Drive I", 0);
//	SmartDashboard::PutNumber("Drive D", 0);
	SmartDashboard::PutData(elevator);
	oi = new OI();
}
