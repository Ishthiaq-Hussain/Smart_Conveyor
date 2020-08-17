#include <Servo.h>
#include <motordrive.h>
#define trigPin D1
#define echoPin D2
int servoPin = 3;
long duration;
int distance;
Servo Servo1; 
motordrive md(9,10,11,12);
void setup() {
  // Define inputs and outputs:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  //Begin Serial communication at a baudrate of 9600:
  Serial.begin(9600);
   Servo1.attach(servoPin); 
   md.pinsetup();
}
void loop() {
  Servo1.write(0); 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(50);
  md.forward();
  if (distance<= 5)
  { 
    md.hault();
   Servo1.write(90); 
   delay(1000); 
   Servo1.write(0); 
   md.forward();
  }
}
