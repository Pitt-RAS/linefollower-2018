#include "config.h"

//Declare calibration "from" values in global scope {ir1_from_low, ir1_from_high, ir2_from_low, ir2_from_high,...}
float calib_from_vals[NUM_SENSORS*2];

Motor left_motor(MOTOR_L_1, MOTOR_L_2, PWM_PIN_1);
Motor right_motor(MOTOR_R_1, MOTOR_R_2, PWM_PIN_2);

int ir_pins[] = {IR1_PIN, IR2_PIN, IR3_PIN, IR4_PIN, IR5_PIN, IR6_PIN, IR7_PIN, IR8_PIN, IR9_PIN};

irArray ir_array(ir_pins, PITCH);

Controller ctrl(K_P, K_I, K_D, I_LWR_BND, I_UPR_BND);


void setup() {
  Serial.begin(9600);
  
  for (int i = 0; i < NUM_SENSORS; i++){
    pinMode(ir_pins[i], INPUT)  
  }

  ir_array.calibrate(calib_from_vals);
  

}

void loop() {

  float ir_values[] = ir_array.read();
  float current_position = ir_array.interpolate(ir_values);
  speed_diff = ctrl.calc_speedDiff(SETPOINT, current_position);
  right_motor.output(MAX_SPEED + speed_diff);
  left_motor.output(MAX_SPEED - speed_diff);

}
