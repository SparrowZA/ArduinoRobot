/*
 * This function is used to measure the time taken for a pulse
 * to be received by the Rx mic
 */

 long obsticalDetect(int pinTrig, int pinEcho){
  long duration;

  while(duration==0){
    digitalWrite(pinTrig, LOW);
    delayMicroseconds(2);
    digitalWrite(pinTrig, HIGH);
    delayMicroseconds(10);
    digitalWrite(pinTrig, LOW);
    
    duration = pulseIn(pinEcho, HIGH);
  }

  return duration;
} //End obsticalDetect



