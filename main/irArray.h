#ifndef IR_ARRAY_H_
#define IR_ARRAY_H_
#include "config.h"

class irArray {
  private:
      int pitch_;
      int pins_[NUM_SENSORS];
      int numSensors;
      float calib_from_vals[CALIB_ARRAY_SIZE];
      float irVal[NUM_SENSORS];
      
  public:
      irArray(int pins[], int pitch);
      float interpolate(float irVal[]);
      void read();
      void calibrate();
};

#endif
