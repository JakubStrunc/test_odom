#include "main.h"

using namespace pros;

//creates a constant for robot sizes(distance from the one side encoder to the centre, distance from the middle to the centre)
const float dRobotSide = 13.4645669/2;
const float dRobotMiddle = 2.95275591;

//Creates a constant for side wheels diameter
const float side_wheel_diam = 2.75;


//Creates a constant for pi
const float drive_pi = 3.14159265359;

//Calculates a constant wheel circumference using diameter and pi
const float side_wheel_circ = side_wheel_diam * drive_pi;


//Encoder degrees in circumference
const float degrees_per_circ = 360.0;

//Encoder degrees per inch
const float degrees_side_per_inch = degrees_per_circ / side_wheel_circ;


//variables for x-position and y-position
float t_x_pos = 0.0f;
float t_y_pos = 0.0f;
int Delta_deg = 0.0;

int last_lDelta = 0.0;

int last_mDelta = 0.0;
int last_Delta_deg = 0.0;