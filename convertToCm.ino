/*
 * This function is used to convert the duration value into
 * a useable distance of centimeters.
 */

double convertingToCm(int pinTrig, int pinEcho){
  double cm, duration;
  double speedOfSound = 0.034029;

  digitalWrite(pinTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);
  
  duration = pulseIn(pinEcho, HIGH);
  
  //Small if loop to deal with wrong readings 
  if(duration == 0){
    duration = 10000;
  }

  cm = speedOfSound * (duration/2) + 1.2 ;
    
  return cm;
}


