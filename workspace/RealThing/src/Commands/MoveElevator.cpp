#include "MoveElevator.h"

MoveElevator::MoveElevator() :CommandBase(2)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(elevator);
	SetInterruptible(true);
}


// Called repeatedly when this Command is scheduled to run
void MoveElevator::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool MoveElevator::IsFinished()
{
	return elevator->OnTarget() || IsTimedOut();
}

// Called once after isFinished returns true
void MoveElevator::End()
{
  elevator->SetBrake();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveElevator::Interrupted()
{

 }

MoveElevatorBy::MoveElevatorBy(double chge) :
  chge(chge)
 {
 }

// Called just before this Command runs the first time
void MoveElevatorBy::Initialize()
 {elevator->SetTarget(elevator->GetTarget() + chge);
 }

MoveElevatorTo::MoveElevatorTo(double endpt) :
  endpt(endpt)
 {
 }

// Called just before this Command runs the first time
void MoveElevatorTo::Initialize()
 {elevator->SetTarget(endpt);
 }

OperateElevator::OperateElevator()
 {Requires(elevator);
 }

void OperateElevator::Initialize()
 {
 }

void OperateElevator::Execute()
 {elevator->Runwinch(oi->ElevStick().GetY());}

bool OperateElevator::IsFinished()
 {return ! RobotBase::getInstance().IsOperatorControl();}

void OperateElevator::End()
 {
 }

void OperateElevator::Interrupted()
 {
 }

StopElev::StopElev()
 {Requires(elevator);
 }

void StopElev::Initialize()
 {elevator->StopHere();
 }

void StopElev::Execute()
 {
 }

bool StopElev::IsFinished()
 {return true;
 }

void StopElev::End()
 {
 }

void StopElev::Interrupted()
 {
 }
