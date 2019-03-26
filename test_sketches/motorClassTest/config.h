#ifndef LINEFOLLOWER_CONF_H_
#define LINEFOLLOWER_CONF_H_

#include <Arduino.h>

//IR pins
#define IR1_PIN A0
#define IR2_PIN A1
#define IR3_PIN A2
#define IR4_PIN A3
#define IR5_PIN A4
#define IR6_PIN A5
#define IR7_PIN A6
#define IR8_PIN A7
#define IR9_PIN A8
#define NUM_SENSORS 5

#define PITCH 4 //distance between IR sensors in mm
#define CALIB_TO_LOW 1 //low value we want to map ir readings to
#define CALIB_TO_HIGH 1000 //high value we want to map ir readings to
#define CALIB_TIME 5000 //how long we want to calibrate for

//Motor pins
#define PWM_PIN_1 5
#define PWM_PIN_2 11
#define MOTOR_L_1 A9
#define MOTOR_L_2 A10
#define MOTOR_R_1 A11
#define MOTOR_R_2 A12
#define MAX_SPEED 255

//Controller parameters
#define K_P 1
#define K_I 1
#define K_D .01
#define I_LWR_BND -40
#define I_UPR_BND 40
#define SETPOINT 500

#endif
