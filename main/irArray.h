class irArray {
    private:
        int pitch_;
        int pins_[];
        int numSensors;


    public:
        
        //constructor and functions
        irArray::irArray(int pins[], int pitch);
        int irArray::sensorDistance(int sensorNum);
        float irArray::interpolate(float irVal[]);
        float irArray::read();
        void irArray::calibrate(float &calibratedVals);


};