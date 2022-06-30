#define echoPin 9
#define trigPin 8
#include <Servo.h>
const int Red = 7;
const int Green = 6;
const int Blue = 5;
Servo myservo; 
int pos = 0;    

long duration; 
long distance; 


void setup() {
  Serial.begin(9600);
  pinMode(echoPin,INPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(Red,OUTPUT);
  pinMode(Green,OUTPUT);
  pinMode(Blue,OUTPUT);
  myservo.attach(4);
}


void loop() {
  
digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  distance = duration/58.2;
  Serial.println(distance);
  delay(50);

if (distance <= 5) {
  digitalWrite(Blue,HIGH);
  for (pos = 0; pos <= 30; pos += 1) { 
    myservo.write(pos);                            
  }
    delay(10000);
  digitalWrite(Blue,LOW);
  for (pos = 30; pos <= 270; pos += 1) { 
    myservo.write(pos);
    digitalWrite(Red,HIGH);
}

}
else {digitalWrite(Blue,LOW)}

}
 