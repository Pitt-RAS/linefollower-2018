#include "irArray.h"
#include <Arduino.h>
#include "config.h"


irArray::irArray(int pins[], int pitch) {
    
    //numSensors = sizeof(pins)/sizeof(char);
    numSensors = NUM_SENSORS;
    //Serial.print(NUM_SENSORS);
    pitch_ = pitch;

    for(int i = 0; i < numSensors; i++) {
        
        pins_[i] = pins[i];

        pinMode(pins_[i], INPUT);
        
        //Serial.print(pins_[i]);
        //Serial.print("\n");
    }
}

float irArray::interpolate(float irVal[]) {
    
    //interpolation code
    double num = 0;
    double den = 0;

    for(int i = 0; i < numSensors; i++) {
        den += irVal[i];
    }
    den -= irVal[numSensors/2]; //exclude middle sensor

    for(int i = 0; i < int(numSensors/2); i++){
      num += (int(numSensors/2)-i)*PITCH*(irVal[numSensors-i-1]-irVal[i]);
    }

   return num/den;
}

float* irArray::read() {
    
    //Serial.print(numSensors);
    for(int i = 0; i < numSensors; i++) {
        irVal[i] = analogRead(pins_[i]);
        //Serial.print(irVal[i]);
        //Serial.print(" index:");
        //Serial.println(i);
        //Serial.print(irVal[i]);
        irVal[i] = constrain(irVal[i], calib_from_vals[2*i], calib_from_vals[2*i+1]);
        irVal[i] = map(irVal[i], calib_from_vals[2*i], calib_from_vals[2*i+1], CALIB_TO_LOW, CALIB_TO_HIGH);
    }
    return irVal;
}

void irArray::calibrate() {

    //Serial.print("hello\n");
    
    //Serial.print("hi\n");
    int startTime = millis();
    int currentTime = millis();

    int initVal = analogRead(pins_[0]);
    
    //intializing values in the array
    for(int i = 0; i < numSensors*2; i++) {
        calib_from_vals[i] = initVal;
    }

    while((currentTime - startTime) < CALIB_TIME) {
        //Serial.print("hi\n");
        for(int i = 0; i < numSensors; i++) {
            float current_value = analogRead(pins_[i]);
            if(current_value < calib_from_vals[2*i]) {
                calib_from_vals[2*i] = current_value;
            } else if(current_value > calib_from_vals[2*i+1]) {
                calib_from_vals[2*i+1] = current_value;
            }
        }

        currentTime = millis();
    }
    //Serial.print("numSensors");
}

float* irArray::get_calib(){
  return calib_from_vals;
}
