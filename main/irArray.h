class irArray {
    private:
        int pitch_;
        char pins_[];
        int numSensors;


    public:
        
        //constructor and functions
        irArray::irArray(char pins[], int pitch);
        int irArray::sensorDistance(int sensorNum);
        float irArray::interpolate(float irVal[]);
        float irArray::read();
        void irArray::calibrate(float &calibratedVals);


};