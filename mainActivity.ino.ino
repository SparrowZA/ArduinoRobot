/*
 * This is the source code for the maze solving robot 
 * created for the CPUT Btech project in the  
 * subject of Micro Systems 4
 * 
 * Designer: Marc Geffroy
 * Date: 30 August 2016
 */

 //Arduino PWM Speed control
 #define E1 5
 #define M1 4
 #define E2 6
 #define M2 7

 //Digital pins for the sonic sensor
 #define CenterTrig 8
 #define CenterEcho 9
 #define RightTrig 12
 #define RightEcho 13
 #define LeftTrig 10
 #define LeftEcho 11

void setup() {
  //Set the I/O pins to INPUT or OUTPUT
  pinMode(E1, OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(E2, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(CenterTrig, OUTPUT);
  pinMode(CenterEcho, INPUT);
  pinMode(RightTrig, OUTPUT);
  pinMode(RightEcho, INPUT);
  pinMode(LeftTrig, OUTPUT);
  pinMode(LeftEcho, INPUT);
  
  Serial.begin(9600);
  
  delay(5000);
} //End setup

void loop() {
  //Local variables to be used
  long duration;
  double leftcm, rightcm, cm;

  //Check for obsticals around the robot 
  leftcm = convertingToCm(LeftTrig, LeftEcho);
  cm = convertingToCm(CenterTrig, CenterEcho);
  rightcm = convertingToCm(RightTrig, RightEcho);
    

  //No object infront, no opening on the right, slightly far to the right
  if(leftcm>=15 && leftcm<26 && cm>15){
    motorDriver(1,1,150,60);
    delay(200);
    motorDriver(0,0,0,0);
  }
  else if(leftcm<=7 && cm>15){
    motorDriver(1,1,60,150);
    delay(200);
    motorDriver(0,0,0,0);
  }

  //Right Corner
  else if(cm<15 && rightcm>=40 && leftcm<25){
    motorDriver(0,0,0,0);
    delay(333);
    motorDriver(0,1,20,240);
    delay(400);
    motorDriver(0,0,0,0);
    delay(333);
  }    
   //Left Corner
  else if(cm<15 && leftcm>=40 && rightcm<25){
    motorDriver(0,0,0,0);
    delay(333);
    motorDriver(1,0,240,20);
    delay(400);
    motorDriver(0,0,0,0);
    delay(333);
  }
  //U-turn
  else if(cm<15 && leftcm<20 && rightcm<20){
    motorDriver(0,0,0,0);
    delay(333);
    motorDriver(0,1,180,180);
    delay(700);
    motorDriver(0,0,0,0);
    delay(333);
  }
  //T-junction
  else if(cm<15 & leftcm>40 && rightcm>40){
    motorDriver(0,0,0,0);
    delay(333);
    motorDriver(1,0,240,20);
    delay(400);
    motorDriver(0,0,0,0);
    delay(1000);
  }
  else{
    motorDriver(1,1,105,100);
  }
} //End loop


