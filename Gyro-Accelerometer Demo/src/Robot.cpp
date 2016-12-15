#define _USE_MATH_DEFINES

#include "WPILib.h"

class Robot: public IterativeRobot
{
private:
	AnalogAccelerometer *ax;
	AnalogAccelerometer *az;

	ADXRS450_Gyro *gyro;

	void RobotInit()
	{
		ax = new AnalogAccelerometer(0);
		az = new AnalogAccelerometer(1);
		gyro = new ADXRS450_Gyro();
		gyro->Calibrate();
	}



	void AutonomousInit()
	{

	}

	void AutonomousPeriodic()
	{

	}

	void TeleopInit()
	{

	}

	void TeleopPeriodic()
	{
		float x = ax->GetAcceleration();
		float z = az->GetAcceleration();
		double g = sqrt(x*x+z*z);
		double thetax = -(180/M_PI)*asin(x/g);
		double thetaz = (180/M_PI)*acos(z/g);

		printf("G: %5.3f, Accel-x: %5.3f, Accel-z: %5.3f, Theta: %5.3f %5.3f\n", g, x, z, thetax, thetaz);
		printf("Angle: %7.3f, Rate: %7.3f\n", gyro->GetAngle(), gyro->GetRate());
	}

	void TestPeriodic()
	{
	}
};

START_ROBOT_CLASS(Robot)
