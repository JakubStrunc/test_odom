#include "main.h"
using namespace pros;

//helps set up the power for motor faster
void MotorSet(int left_power, int right_power)
{
  fl.move(left_power);
  bl.move(left_power);
  fr.move(right_power);
  br.move(right_power);
}



// drive chassie control
void setChassie()
{
  int power = maincontroller.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
  int turn = maincontroller.get_analog(E_CONTROLLER_ANALOG_LEFT_X);

  int ls = power + turn;
  int rs = power - turn;

  //pros::lcd::print(4, "%f,%f", turn, power);
  MotorSet(ls, rs);
  
}