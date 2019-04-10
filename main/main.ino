#include "config.h"
#include "Controller.h"
#include "Motor.h"
#include "irArray.h"

//Declare calibration "from" values in global scope {ir1_from_low, ir1_from_high, ir2_from_low, ir2_from_high,...}
//float calib_from_vals[NUM_SENSORS*2];

Motor left_motor(MOTOR_L_1, MOTOR_L_2, PWM_PIN_1);
Motor right_motor(MOTOR_R_1, MOTOR_R_2, PWM_PIN_2);

int ir_pins[] = {IR1_PIN, IR3_PIN, IR5_PIN, IR7_PIN, IR9_PIN};
float* ir_values;
float current_position;
float speed_diff;

irArray ir_array(ir_pins, PITCH);

Controller ctrl(K_P, K_I, K_D, I_LWR_BND, I_UPR_BND);


void setup() {
  Serial.begin(9600);

  /*
  for (int i = 0; i < NUM_SENSORS; i++){
    pinMode(ir_pins[i], INPUT)  
  }
  */

  int startTime = millis();
  int currentTime = millis();
  ir_array.calibrate();
  while(currentTime - startTime < 833){
    left_motor.output(20);
    right_motor.output(0);
    currentTime = millis();
  }
  startTime = millis();
  while(currentTime - startTime < 1667){
    left_motor.output(0);
    right_motor.output(20);
    currentTime = millis();
  }
  while(currentTime - startTime < 1667){
    left_motor.output(20);
    right_motor.output(0);
    currentTime = millis();
  }
  while(currentTime - startTime < 833){
    left_motor.output(0);
    right_motor.output(20);
    currentTime = millis();
  }


}

void loop() {

  ir_values = ir_array.read();
  current_position = ir_array.interpolate(ir_values);
  speed_diff = ctrl.calc_speedDiff(SETPOINT, current_position);
  right_motor.output(MAX_SPEED + speed_diff);
  left_motor.output(MAX_SPEED - speed_diff);

}
