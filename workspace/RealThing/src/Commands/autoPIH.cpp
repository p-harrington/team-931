# include "MoveElevator.h"
#include "autoPIH.h"

class DriveAmount: public CommandBase
{float xSpd, ySpd, rot;
public:
	DriveAmount(float xSpd, float ySpd, float rot, float dist);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

autoPIH::autoPIH(float dist)
{AddSequential(new MoveElevatorTo(-6));
 AddSequential(new MoveElevatorTo(2));
 AddSequential(new DriveAmount(-0.1, -.5, 0, dist));}

autonerbot::autonerbot(float dist)
{AddSequential(new MoveElevatorTo(-6));
 AddSequential(new MoveElevatorTo(4));
 AddSequential(new DriveAmount(.5, 0, 0, .6));
 AddSequential(new DriveAmount(0.1, -.5, 0, dist));}

inline DriveAmount::DriveAmount(float xSpd, float ySpd, float rot, float dist) :
  CommandBase(dist), xSpd(xSpd), ySpd(ySpd), rot(rot)
 {Requires(swerveDrive);}

 void DriveAmount::Initialize()
 {swerveDrive->Drive(xSpd, ySpd, rot, 1);
 }

 void DriveAmount::Execute()
 {}

 bool DriveAmount::IsFinished()
 {return IsTimedOut();}

 void DriveAmount::End()
 {swerveDrive->Drive(xSpd,ySpd,rot,1,true);}

 void DriveAmount::Interrupted()
 {End();}
