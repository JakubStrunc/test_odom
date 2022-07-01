#include "main.h"
using namespace pros;

//Motors define
Motor fl(11, E_MOTOR_GEARSET_18, false);
Motor bl(7, E_MOTOR_GEARSET_18, false);
Motor fr(17, E_MOTOR_GEARSET_18, true);
Motor br(2, E_MOTOR_GEARSET_18, true);


//Sensor define

Imu inertial(9);
// Imu inertial_r(15);


ADIEncoder L_Encoder('C','D', true);
ADIEncoder M_Encoder('E','F');

Controller maincontroller(E_CONTROLLER_MASTER);