// Example of what our main file will look like
// Note this is not exact!

int target_position = 500;
int kp, ki, kd = blah blah blah;
int i_upperbound, i_lowerbound = blah blah;
int maxSpeed = 100;

void setup() {
  Motor motorLeft(pins); //create left and right motors, constructor takes pin names
  Motor motorRight(pins);
  irSensor irArray(num_IRs, pitch); // create ir sensor array, constructor takes how many IRs are on the board and the pitch between the IRs 
  Controller pos_ctrl(kp, ki, kd, i_upperbound, i_lowerbound); //create controller object, constructor takes gains and integral term bounds
}

void loop() {

  current_position = irArray.read(); //call irArray's read function which will read raw values then interpret them to usable values, maybe 1 - 1000
  
  speed_Diff = pos_ctrl.calc_speedDiff(current_position, target_position); // controller object calculates the speed difference needed to correct the linefollower
  
  rightSpeed = maxSpeed + speed_Diff; //calculate left and right speeds
  leftSpeed = maxSpeed - speed_diff;
  
  motorRight.output(rightSpeed);  // output left and right speeds to motors
  motorLeft.output(leftSpeed);
  

}
