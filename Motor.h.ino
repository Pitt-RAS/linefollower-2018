class Motor
{
  private:
    int IN1, IN2, PWM;
  public:
    Motor(int IN1, int IN2, int PWM);
    void output(int dif);
}
