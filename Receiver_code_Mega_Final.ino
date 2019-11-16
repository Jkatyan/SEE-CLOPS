#include <math.h>
#include <Pixy2.h>
#define gyroPin 0            //Gyro is connected to analog pin 0
#define buzzer1 2
#define buzzer2 4

int p;
float gyroVoltage = 5;         //Gyro is running at 5V
float gyroZeroVoltage = 2.5;   //Gyro is zeroed at 2.5V
float gyroSensitivity = .007;  //Our example gyro is 7mV/deg/sec
float rotationThreshold = 1;   //Minimum deg/sec to keep track of - helps with gyro drifting
#define buzzer1 2
#define buzzer2 3
float currentAngle = 0;          //Keep track of our current angle
float currentAngleGyro = 0;
Pixy2 pixy;

void aim(double targetX, double targetY){//Coordinate of Table
  while(false){ //change this later (obejct not in frame)
  ///int theta = round(atan2 ((targetY), (targetX)) * 180/3.14159265);
  int theta = 104;
  float currentAngleTemp;
  if(180 > currentAngle >= 0){
  currentAngleTemp = 90 - currentAngle;
  }
  else{
  currentAngleTemp = 360 - currentAngle + 90;
  }
  float error = abs(theta - currentAngleTemp);
  if (error <= 5){
    digitalWrite(buzzer2,HIGH);
    digitalWrite(buzzer1,LOW);
    delay(1);
  }
  if (currentAngleTemp >= (theta+5)){
    for(int i=0;i<80;i++)
   {
    digitalWrite(buzzer1,HIGH);
    delay(1);//wait for 1ms
    digitalWrite(buzzer1,LOW);
    delay(1);//wait for 1ms
    }
    digitalWrite(buzzer1, LOW);
    delay(500);
  }
  if(currentAngleTemp <= (theta-5)){
    for(int i=0;i<80;i++)
   {
    digitalWrite(buzzer2,HIGH);
    delay(1);//wait for 1ms
    digitalWrite(buzzer2,LOW);
    delay(1);//wait for 1ms
    }
    digitalWrite(buzzer2, LOW);
    delay(500);
  }
  return 0;
  }
}

void setup() {
  Serial.begin (9600);
  
  pinMode(buzzer1,OUTPUT);//initialize the buzzer pin as an output
  pinMode(buzzer2,OUTPUT);
  pinMode(gyroPin, INPUT);
  pixy.init();
}

void loop() {
  if (p == 0){
      for(int i=0;i<80;i++)
   {
    digitalWrite(buzzer1,HIGH);
    delay(1);//wait for 1ms
    digitalWrite(buzzer1,LOW);
    delay(1);//wait for 1ms
    }
    digitalWrite(buzzer1, LOW);
    delay(100);
    Serial.println("Buzzin");

     for(int i=0;i<80;i++)
   {
    digitalWrite(buzzer1,HIGH);
    delay(1);//wait for 1ms
    digitalWrite(buzzer1,LOW);
    delay(1);//wait for 1ms
    }
    digitalWrite(buzzer1, LOW);
    delay(100);
    Serial.println("Buzzin");

     for(int i=0;i<80;i++)
   {
    digitalWrite(buzzer1,HIGH);
    delay(1);//wait for 1ms
    digitalWrite(buzzer1,LOW);
    delay(1);//wait for 1ms
    }
    digitalWrite(buzzer1, LOW);
    delay(100);
    Serial.println("Buzzin");
    for(int i=0;i<80;i++)
   {
    digitalWrite(buzzer1,HIGH);
    delay(1);//wait for 1ms
    digitalWrite(buzzer1,LOW);
    delay(1);//wait for 1ms
    }
    digitalWrite(buzzer1, LOW);
    delay(100);
    Serial.println("Buzzin");

     for(int i=0;i<80;i++)
   {
    digitalWrite(buzzer1,HIGH);
    delay(1);//wait for 1ms
    digitalWrite(buzzer1,LOW);
    delay(1);//wait for 1ms
    }
    digitalWrite(buzzer1, LOW);
    delay(100);
    Serial.println("Buzzin");

     for(int i=0;i<80;i++)
   {
    digitalWrite(buzzer1,HIGH);
    delay(1);//wait for 1ms
    digitalWrite(buzzer1,LOW);
    delay(1);//wait for 1ms
    }
    digitalWrite(buzzer1, LOW);
    delay(100);
    Serial.println("Buzzin");
    for(int i=0;i<80;i++)
   {
    digitalWrite(buzzer1,HIGH);
    delay(1);//wait for 1ms
    digitalWrite(buzzer1,LOW);
    delay(1);//wait for 1ms
    }
    digitalWrite(buzzer1, LOW);
    delay(100);
    Serial.println("Buzzin");

     for(int i=0;i<80;i++)
   {
    digitalWrite(buzzer1,HIGH);
    delay(1);//wait for 1ms
    digitalWrite(buzzer1,LOW);
    delay(1);//wait for 1ms
    }
    digitalWrite(buzzer1, LOW);
    delay(100);
    Serial.println("Buzzin");

     for(int i=0;i<80;i++)
   {
    digitalWrite(buzzer1,HIGH);
    delay(1);//wait for 1ms
    digitalWrite(buzzer1,LOW);
    delay(1);//wait for 1ms
    }
    digitalWrite(buzzer1, LOW);
    delay(100);
    Serial.println("Buzzin");
    for(int i=0;i<80;i++)
   {
    digitalWrite(buzzer1,HIGH);
    delay(1);//wait for 1ms
    digitalWrite(buzzer1,LOW);
    delay(1);//wait for 1ms
    }
    digitalWrite(buzzer1, LOW);
    delay(100);
    Serial.println("Buzzin");

    p = 1;
  }
  //This line converts the 0-1023 signal to 0-5V
  float gyroRate = (analogRead(gyroPin) * gyroVoltage) / 1023;

  //This line finds the voltage offset from sitting still
  gyroRate -= gyroZeroVoltage;

  //This line divides the voltage we found by the gyro's sensitivity
  gyroRate /= gyroSensitivity;

  //Ignore the gyro if our angular velocity does not meet our threshold
  if (gyroRate >= rotationThreshold || gyroRate <= -rotationThreshold) {
    //This line divides the value by 100 since we are running in a 10ms loop (1000ms/10ms)
    gyroRate /= 100;
    currentAngle += gyroRate;
  }

  //Keep our angle between 0-359 degrees
  if (currentAngle < 0){
    currentAngle += 360;}
  else if (currentAngle > 359){
    currentAngle -= 360;
}

  pixy.ccc.getBlocks();
  int i;
  int pixValX = pixy.ccc.blocks[i].m_x;

  if(pixValX >= 158){
    Serial.println("go right");
     delay(10);
     int pixValX = pixy.ccc.blocks[i].m_x;
    
     for(int i=0;i<80;i++)
   {
    digitalWrite(buzzer1,HIGH);
    delay(1);//wait for 1ms
    digitalWrite(buzzer1,LOW);
    delay(1);//wait for 1ms
    }
    digitalWrite(buzzer1, LOW);
    delay(100);
    Serial.println("Right");
    }
  else if (pixValX = pixy.ccc.blocks[i].m_x){
    //Left Buzzer
     digitalWrite(buzzer2, HIGH);
     delay(80);
     digitalWrite(buzzer2, LOW);
     delay(100);
    int pixValX = pixy.ccc.blocks[i].m_x;
  }
  else {
    Serial.println("Nothing");
  }
  //DEBUG
  //int thetaTest = aim(0,0,4,3);
  //Serial.println(thetaTest);
  delay(10);
}
