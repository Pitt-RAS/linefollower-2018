#include "config.h"
#include "Controller.h"
#include "Motor.h"
#include "irArray.h"

// create left and right motor objects
Motor left_motor(MOTOR_L_1, MOTOR_L_2, PWM_PIN_1);
Motor right_motor(MOTOR_R_1, MOTOR_R_2, PWM_PIN_2);

// declare variables
int ir_pins[] = {IR1_PIN, IR3_PIN, IR5_PIN, IR7_PIN, IR9_PIN};
float current_position;
float speed_diff;
float speed_left;
float speed_right;

// create IR array board object
irArray ir_array(ir_pins, PITCH);

// create controller object
Controller ctrl(K_P, K_I, K_D, I_LWR_BND, I_UPR_BND);


void setup() {
  Serial.begin(9600);

  // start by running the calibration function
  // and move the robot back and forth over the black line by hand
  ir_array.calibrate();


  // here we tried to have the robot spin back and forth by itself but we couldn't quite get it to work how we wanted
  /*
  int startTime = millis();
  int currentTime = millis();
  
  while(currentTime - startTime < 5000){
    left_motor.output(50, LOW);
    right_motor.output(50, LOW);
    currentTime = millis();
  }
  startTime = millis();
  while(currentTime - startTime < 100){
    left_motor.output(25, LOW);
    right_motor.output(50, HIGH);
    currentTime = millis();
  }
  startTime = millis();
  while(currentTime - startTime < 100){
    left_motor.output(25, HIGH);
    right_motor.output(50, LOW);
    currentTime =s millis();
  }
  
  startTime = millis();
  while(currentTime - startTime < 50){
    left_motor.output(25, LOW);
    right_motor.output(50, HIGH);
    currentTime = millis();
  }
  */

}

void loop() {

  // read from the IR array
  ir_array.read();
  
  // calculate current position over the black line with the interpolate function
  current_position = ir_array.interpolate();

  // calculate the speed difference that will be added to left motor max speed and subtracted from right motor max speed
  speed_diff = ctrl.calc_speedDiff(current_position);

  // call the constrain function one last time just to make sure the motor speeds dont go below 0 or above 255
  speed_left = constrain(MAX_SPEED_L + speed_diff, 0, 255);
  speed_right = constrain(MAX_SPEED_R - speed_diff, 0, 255);

  // send the speeds to the motors with the motor output function
  right_motor.output(speed_right, 0);
  left_motor.output(speed_left, 0);

}
