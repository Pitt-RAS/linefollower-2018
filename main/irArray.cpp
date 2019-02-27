#include <irArray.h>
#include <Arduino.h>

class irArray {

    int pitch_;
    int pins_[];
    int numSensors;

public:

    irArray::irArray(int pins[], int pitch) {

        numSensors = sizeof(pins)/sizeof(int);

        pitch_ = pitch;

        for(int i = 0; i <= numSensors; i++) {
            pins_[i] = pins[i];
        }
    }

    int irArray::sensorDistance(int sensorNum) {
        sensor_dist = pitch*(5-sensorNum);
        return sensor_dist;
    }

    float irArray::interpolate(float irVal[]) {
        //interpolation code
        double num = 0;
        double den = 0;

        for(int i = 0; i < int(numSensors/2); i++) {
            num += (pitch*((numSensors/2)-i)*(irVal[numSensors-i]-irVal[i]);
            den += irVal[i];
        }

       return num/den;
    }

    float irArray::read() {
        float irVal[numSensors];

        for(int i = 0; i < numSensors; i++) {
            irVal[i] = constrain(analogRead(pins_[i]), calib_from_vals[i], calib_from_vals[i+1])
            irVal[i] = map(irVal[i], calib_from_vals[i], calib_from_vals[i+1], CALIB_TO_LOW, CALIB_TO_HIGH);
        }

        return irVal;
    }

    void irArray::calibrate(float &calibratedVals) {
        float calibratedVals[numSensors*2];

        int startTime = millis();
        int currentTime = millis();

        int initVal = analogRead(AnalogInputPin0);

        //intializing values in the array
        for(int i = 0; i < numSensors*2; i++) {
            calibratedVals[i] = initVal;
        }

        while((currentTime - startTime) < CALIB_TIME) {
            for(int i = 0; i < numSensors; i+=2) {
                current_value = analogRead(pins_[i]);
                if(current_value < calibratedVals[i]) {
                    calibratedVals[i] = current_value;
                } else if(current_value > calibratedVals[i+1]) {
                    calibratedVals[i+1] = current_value;
                }
            }

            currentTime = millis();
        }

    }

    //map and constrain in read function
    //irval= map(<irval>, calibratedVals[<sensorNum>], calibratedVals[<sensorNum+1>], 0, 100)
    //irval= constrain(<irval>, 0, 100)

};
