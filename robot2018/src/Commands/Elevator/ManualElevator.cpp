#include "ManualElevator.h"
#include <Subsystems/Elevator/Elevator.h>
#include <Subsystems/Collector/Collector.h>
#include <OI.h>

ManualElevator::ManualElevator() {
	// Use Requires() here to declare subsystem dependencies
	Requires(&Elevator::GetInstance());
}

// Called just before this Command runs the first time
void ManualElevator::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ManualElevator::Execute() {
	double val = OI::GetInstance().GetOPLY();
	if(val < 0){
		if(Elevator::GetInstance().IsUp() ||
				(Collector::GetInstance().IsUp() &&
						Elevator::GetInstance().IsDown()))
			val = 0;
	}
	else
		if(Elevator::GetInstance().IsDown())
			val = 0;
	Elevator::GetInstance().Set(val);
}

// Make this return true when this Command no longer needs to run execute()
bool ManualElevator::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ManualElevator::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ManualElevator::Interrupted() {

}
