#include <irArray.h>
#include <Arduino.h>
#include <irSensor.h>

class ir {
    
    int pitch_;
    char pins_[];
    int numSensors = 0;
    int i = 0;

    public:

    ir::ir(char pins[num_sensors], int pitch) {
        
        numSensors = sizeof(pins)/sizeof(char);

        pitch_ = pitch;

        for(i = 0; i <= numSensors; i++) {
            pins_[i] = pins[i];
        }
    }

    int ir::sensorDistance(int sensorNum) {
        sensor_dist = pitch*(5-sensorNum);
        return sensor_dist;
    }

    float ir::interpolate() {
        //interpolation code
        double num = 0;
        double den = 0;

        for(i = 0; i < int(numSensors/2); i++) {
            num += (pitch*((numSensors/2)-i)*(irVal[numSensors-i]-irVal[i]);
            den += irVal[i];
        }

       return num/den;
    }

    float ir::read() {
        float irVal[numSensors];
        int i = 0;
        
        for(i = 0; i < numSensors; i++) {
            irVal[i] = analogRead(pins_[i]);
        }

        return irVal;
    }

    int ir::WeightedAverage(float arr[]) {
        float sum_n = 0;
        float sum_d = 0;
        for (i=0; i < int(NUM_SENSORS/2); i++){
            sum_n += (pitch*((NUM_SENSORS/2)-i)) * (arr[NUM_SENSORS - i] - arr[i]); 
            sum_d += arr[i];
        }
        return sum_n/sum_d;

    }

    float ir::calibrate() {
        float calibratedVals[numSensors*2];

        int startTime = millis();
        int currentTime = millis();

        int initVal = analogRead(AnalogInputPin0);
        

        //intializing values in the array
        for(i = 0; i < numSensors*2; i++) {
            calibratedVals[i] = initVal;
        }


        while((currentTime - startTime) < 5000) {
            for(i = 0; i < numSensors; i+=2) {
                if(analogRead(pins_[i]) < calibratedVals[i]) {
                    calibratedVals[i] = analogRead(pins_[i])
                } else if(analogRead(pins_[i] > calibratedVals[i+1]) {
                    calibratedVals[i+1] = analogRead(pins_[i]);
                }
            }

            currentTime = millis();
        }

        return calibratedVals;

    }

    //map and constrain in read function
    //irval= map(<irval>, calibratedVals[<sensorNum>], calibratedVals[<sensorNum+1>], 0, 100)
    //irval= constrain(<irval>, 0, 100)

}