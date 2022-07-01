// #include "main.h"
// #include "math.cpp"

// using namespace pros;

// float desire_pos_in_inch = 0.00f;
// float desire_turn_in_deg = 0.00f;
// //variable for PID

// float kP = 0.0f;
// //float kI = 0.0;
// float kD = 0.0f;

// float turn_kP = 0.0f;
// //float turn_kI = 0.0f;
// float turn_kD = 0.0f;

// int error; //difference between desire and current position
// int prev_error = 0; // position 20 milliseconds ago
// int deriative; //difference between error and previous error
// int total_error = 0;

// int turn_error; 
// int turn_prev_error = 0; 
// int turn_deriative; 
// int turn_total_error = 0;

// int deg_per_turn = 3260; // how much need to middle encoder wheel to turn to make 360 degrees

// bool enablePID = false;
// bool resetPID = false;

// int PIDdrive()
// {
//   //convert my desire possition to side encoders value
//   float desire_pos_in_enc_deg = desire_pos_in_inch*degrees_side_per_inch;
//   //convert my desire degree to the middle encoders value
//   float desire_turn_in_enc_deg = desire_turn_in_deg * (deg_per_turn/360);
//   while(enablePID)
//   { 
//     if (resetPID)
//     {
//       L_Encoder.reset();
//       R_Encoder.reset();
//       M_Encoder.reset();
//       inertial.reset();
//     }

//     //track the position of the robot 
//     odomtrack();
    
//     /*************************************************
//      * Lateral part (forward,backward)
//      ***********************************************/
//     int Avg_Position = (L_Encoder.get_value()+ R_Encoder.get_value())/2;

//     //Potential 
//     error = Avg_Position - desire_pos_in_enc_deg;

//     //Derivative
//     deriative = error - prev_error;

//     //Integral
//     total_error += error;

    
//    //calculate the power to the motors 
//     float Power = (error *kP + deriative*kD);
//    // float Power = (error *kP + deriative*kD + total_error*kI)

//     /*************************************************
//      * Turning part (left,right)
//      ************************************************/
    
//     int turn_Difference = (L_Encoder.get_value()- R_Encoder.get_value());

//     //Potential 
//     turn_error = turn_Difference - desire_turn_in_enc_deg;

//     //Derivative
//     turn_deriative = turn_error - turn_prev_error;

//     //Integral
//     turn_total_error += turn_error;

//     //calculate the power to the motors for turn
//     float turn_Power = (turn_error *turn_kP + turn_deriative*turn_kD);
//    // float turn_Power = (error *kP + deriative*kD + total_error*kI)
   
//     MotorSet(Power + turn_Power, Power-turn_Power);


//     prev_error = error;
//     pros::delay(20);
//   }
//   return 1;
// }