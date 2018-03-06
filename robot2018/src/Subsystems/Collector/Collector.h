#ifndef Collector_H
#define Collector_H

#include <Commands/Subsystem.h>
#include <memory>
#include <DigitalInput.h>
#include <DoubleSolenoid.h>
#include <AnalogInput.h>
#include "ctre/phoenix/MotorControl/CAN/WPI_VictorSPX.h"

using ctre::phoenix::motorcontrol::can::WPI_VictorSPX;

class Collector : public frc::Subsystem {
private:
	Collector();

	std::unique_ptr<WPI_VictorSPX> m_rCollector;
	std::unique_ptr<WPI_VictorSPX> m_lCollector;
	std::unique_ptr<frc::DigitalInput> m_collectSwitch;

	std::unique_ptr<WPI_VictorSPX> m_rotor;
	std::unique_ptr<frc::DigitalInput> m_downSwitch;
	std::unique_ptr<frc::DigitalInput> m_upSwitch;
	std::unique_ptr<frc::AnalogInput> m_potentiometer;

	std::unique_ptr<frc::DoubleSolenoid> m_claw;
public:
	static Collector& GetInstance();

	enum ROTOR_POS {UP, DOWN};
	enum COLLECTMODE {EJECT, COLLECT};
	enum CLAWMODE {OPEN, CLOSE};

	bool manualRotor = false; //indicates if driver has direct control of rotor

	const double ROTOR_VOLT_UP; //potentiometer value at top position
	const double ROTOR_VOLT_DOWN; //at bottom position

	void InitDefaultCommand();
	void Periodic();

	void Collect(COLLECTMODE mode);
	void StopCollect(); //stops collectors

	void Rotate(double val);
	double GetRotorPos() const; //returns potentiometer voltage

	bool IsUp();
	bool IsDown();
	bool CubeIn();

	void SwitchClaw(CLAWMODE mode);

	CLAWMODE GetClawMode() const;
};

#endif  // Collector_H
