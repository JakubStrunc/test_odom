#include "main.h"


using namespace pros;


float x_pos = 0.0;
float y_pos = 0.0;

float odomtrack(float t_x_pos, float t_y_pos, int Delta_deg, int last_lDelta, int  last_mDelta, int last_Delta_deg)

{
  //getting values from encoders
  int lDelta = L_Encoder.get_value() - last_lDelta;
  int mDelta = M_Encoder.get_value() - last_mDelta;

   

  // trasform values to inches
  float lDist = (float)lDelta / degrees_side_per_inch;
  float mDist = (float)mDelta / degrees_side_per_inch;

  // getting angle of the robot and convert to rad
  Delta_deg = int(inertial.get_yaw()) - last_Delta_deg;
  float Delta_rad = Delta_deg * drive_pi / 180;
  

 // if there is no angle change, there is only change in y-position
  if(Delta_deg == 0)
  {
    x_pos = mDist;
    y_pos = lDist;

    
  }
  // calculate the x-position and y-position
  else
  {
    y_pos = (lDist/Delta_rad + dRobotSide) * (2*sinf(Delta_rad/2));
    x_pos = (mDist/Delta_rad + dRobotMiddle) * (2*sinf(Delta_rad/2));
    
  }

  //total position
    if(abs(lDelta) > 1.0 || abs(mDelta) > 1.0 ){ //if there is any movement
    t_x_pos += x_pos;
    t_y_pos += y_pos;

    //make my current values previous 
    last_lDelta = (int)lDelta;
    //last_rDelta = (int)rDelta;
    last_mDelta = (int)mDelta;
    last_Delta_deg = (int)Delta_deg;

  }

  //printing the values 
  lcd::print(3, "x:%f, y:%f, ang:%d", t_x_pos, t_y_pos, Delta_deg);
  lcd::print(4, "%d, :%d, %d", last_lDelta, last_mDelta, last_Delta_deg);
  lcd::print(5,"%d, %d", M_Encoder.get_value(),L_Encoder.get_value());
  

  


  //Delta_deg = inertial.get_heading();
  
  
  return  t_x_pos, t_y_pos, Delta_deg, last_lDelta, last_mDelta, last_Delta_deg;
    
    // lcd::set_text(4,std::to_string(lDelta)); // display the left tracking wheel distance
    // lcd::set_text(2,std::to_string(rDelta)); // display the right tracking wheel distance
    // lcd::set_text(3,std::to_string(mDelta));

    
}