#include "irArray.h"
#include <Arduino.h>
#include "config.h"


irArray::irArray(int pins[], int pitch) {

    // number of IRs we are using and distance between them
    numSensors = NUM_SENSORS;
    pitch_ = pitch;

    // set each pin in the member array and set pinmodes
    for(int i = 0; i < numSensors; i++) {
        pins_[i] = pins[i];
        pinMode(pins_[i], INPUT);
    }
}

void irArray::calibrate() {
  
    int startTime = millis();
    int currentTime = millis();

    // initialize values in the calibration "from" array
    for(int i = 0; i < numSensors; i++) {
        initVal = analogRead(pins_[i]);
        calib_from_vals[2*i] = initVal;
        calib_from_vals[2*i+1] = initVal;
    }

    // generate calibration "from" values
    float current_value;
    while((currentTime - startTime) < CALIB_TIME) {
        for(int i = 0; i < numSensors; i++) {
            current_value = analogRead(pins_[i]);
            if(current_value < calib_from_vals[2*i]) {
                calib_from_vals[2*i] = current_value;
            } else if(current_value > calib_from_vals[2*i+1]) {
                calib_from_vals[2*i+1] = current_value;
            }
        }

        currentTime = millis();
    }
}


void irArray::read() {

    // read from the IRs and map them according to the calibration values
    for(int i = 0; i < numSensors; i++) {
        irVal[i] = analogRead(pins_[i]);
        irVal[i] = constrain(irVal[i], calib_from_vals[2*i], calib_from_vals[2*i+1]);
        irVal[i] = map(irVal[i], calib_from_vals[2*i], calib_from_vals[2*i+1], CALIB_TO_LOW, CALIB_TO_HIGH);
    }
    return irVal;
}

float irArray::interpolate() {
   
    double num = 0;
    double den = 0;

    // uses weighted average to produce one value that is indicative of where the robot is in relation to the line
    for(int i = 0; i < numSensors; i++) {
        den += irVal[i];
    }
    den -= irVal[int(numSensors/2)];

    for(int i = 0; i < int(numSensors/2); i++){
        num += (int(numSensors/2)-i)*pitch_*(irVal[numSensors-i-1]-irVal[i]);
    }

   return num/den;
}
