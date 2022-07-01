#include "main.h"
#include "okapi/api.hpp"

using namespace okapi;
// Chassis Controller - lets us drive the robot around with open- or closed-loop control
	
	


	// int frontleft = 11;
	// int frontright = -12;
	// int backleft = 10;
	// int backright = -7;


	

	// std::shared_ptr<OdomChassisController> chassis =
	// 	ChassisControllerBuilder()
	// 		.withMotors(
	// 			-11,	 // top left
	// 			17, // top right
	// 			2,	 // bottom right
	// 			-7)	 // bottom left

	// 		.withGains(
	// 			{0.001, 0, 0.0001}, // distance controller gains
	// 			{0.001, 0, 0.0001}, // turn controller gains
	// 			{0.001, 0, 0.0001}	// angle controller gains (helps drive straight)
	// 			)
	// 		.withSensors(
	// 			ADIEncoder{'A', 'B'},		// left encoder in ADI ports G & H
	// 			ADIEncoder{'C', 'D', true}, // right encoder in ADI ports A & B (reversed)
	// 			ADIEncoder{'E', 'F'}		// middle encoder in ADI ports C & D
	// 			)
	// 		// green gearset, tracking wheel diameter (2.75 in), track (7 in), and TPR (360)
	// 		// 1 inch middle encoder distance, and 2.75 inch middle wheel diameter
			
	// 		.withDimensions(AbstractMotor::gearset::green, {{2.75_in, 13.4645669_in, 2.5_in, 3.25_in}, quadEncoderTPR})
	// 		.withOdometry()	  // use the same scales as the chassis (above)
	// 		.buildOdometry();// build an odometry chassis
			
			Controller controller;
			
	// 		std::shared_ptr<okapi::XDriveModel> driveTrain = std::dynamic_pointer_cast<XDriveModel>(chassis->getModel());
	// 		std::shared_ptr<AsyncMotionProfileController> profileController = AsyncMotionProfileControllerBuilder()
  //   .withLimits({
  //     1.0, // Maximum linear velocity of the Chassis in m/s
  //     2.0, // Maximum linear acceleration of the Chassis in m/s/s
  //     10.0 // Maximum linear jerk of the Chassis in m/s/s/s
  //   })
  //   .withOutput(chassis)
  //   .buildMotionProfileController();
/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button()
{
	static bool pressed = false;
	pressed = !pressed;
	if (pressed)
	{
		pros::lcd::set_text(2, "I was pressed!");
	}
	else
	{
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize()
{	
	pros::lcd::initialize();
	pros::lcd::set_text(1, "The 6408J goes brrr");
	pros::lcd::set_text(3,"the sensor are reseting");
	inertial.reset();
	L_Encoder.reset();
	//R_Encoder.reset();
	M_Encoder.reset();
	pros::delay(2000);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */

void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous()
{
	
	
	

	
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol()
{

	while (true)
	{
		setChassie();

		t_x_pos, t_y_pos, Delta_deg, last_lDelta,last_mDelta, last_Delta_deg  = odomtrack(t_x_pos, t_y_pos, Delta_deg, last_lDelta,last_mDelta, last_Delta_deg);
		
		// pros::lcd::print(2, "%f, %f, %f", state.x, state.y, state.theta.convert(1_deg));
		
	
		
		pros::delay(20);
	}
}
