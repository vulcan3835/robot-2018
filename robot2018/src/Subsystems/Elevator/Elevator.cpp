#include "Elevator.h"
#include <Constants.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Commands/Elevator/ManualElevator.h>

Elevator::Elevator() : frc::Subsystem("Elevator"),
	m_eng1(ELEV1_MOTOR),
    m_elevUp(ELEV_UP_SWITCH),
    m_elevDown(ELEV_DOWN_SWITCH){}

Elevator& Elevator::GetInstance(){
	static Elevator instance;
	return instance;
}

void Elevator::InitDefaultCommand(){
	SetDefaultCommand(new ManualElevator());
}

void Elevator::Periodic(){
	frc::SmartDashboard::PutNumber("elevator rate", m_eng1.Get());
	frc::SmartDashboard::PutBoolean("elev up", !m_elevUp.Get());
	frc::SmartDashboard::PutBoolean("elev down", !m_elevDown.Get());
}

void Elevator::Set(double val){
	m_eng1.Set(val);
}

bool Elevator::IsUp(){
	return !m_elevUp.Get();
}

bool Elevator::IsDown(){
	return !m_elevDown.Get();
}
