#ifndef MOTOR_H_
#define MOTOR_H_

class Motor {
  private:
    int pin1_;
    int pin2_;
    int pwm_pin_;
  public:
    Motor(int pin1, int pin2, int pwm_pin);
    void output(int spd, int dir);
};

#endif
