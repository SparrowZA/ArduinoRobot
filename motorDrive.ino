/*
 * This function is used to drive the motors. It gets sent 
 * the PWM values and the direction of the motors.
 */
 
void motorDriver(int M1Lvl, int M2Lvl, int E1Lvl, int E2Lvl){
  digitalWrite(M1, M1Lvl);
  digitalWrite(M2, M2Lvl);
  analogWrite(E1, E1Lvl);
  analogWrite(E2, E2Lvl);
}



