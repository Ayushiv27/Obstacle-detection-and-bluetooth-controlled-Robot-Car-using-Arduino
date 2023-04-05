#include<Servo.h>
Servo s1;
int trigPin = 9;   
int echoPin = 8;   
float c;
int distanceR,distanceL;
int distance();
int forward();
int stopu();
int back();
int right();
int left();
int leftd();
int rightd();


void setup() {
 pinMode(2,OUTPUT);
 pinMode(3,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
  // begin serial port
 Serial.begin (9600);
 s1.attach(10);
  // configure the trigger pin to output mode
  pinMode(trigPin, OUTPUT);
  // configure the echo pin to input mode
  pinMode(echoPin, INPUT);
  pinMode(13,OUTPUT);
}

void loop(){
  
//  digitalWrite(2,HIGH);
//  digitalWrite(3,LOW);
//  digitalWrite(4,HIGH);
//  digitalWrite(5,LOW);


 c=distance();
 Serial.println(c);

 if(c<20){
  stopu();
  delay(500);
  back();
  delay(500);
  stopu();
  delay(500);
  distanceR=rightd();
  distanceL=leftd();
  if(distanceR<distanceL)
  {
    left();
  }
  else{
    right();
  }
 }
 else{
  forward();
 }
}

int distance(){
  float duration_us=0,distance_cm;
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(echoPin, HIGH);

  // calculate the distance
  distance_cm = 0.017 * duration_us;

 return distance_cm;

  delay(500);

}
//LEFT SIDE FORWARD-5
//RIGHT SIDE FORWARD-2
 int forward(){
 digitalWrite(2,1);
 digitalWrite(5,1);
 }
 //LEFT SIDE BACKWARD-3
//RIGHT SIDE BACKWARD-4
  int back(){
 digitalWrite(3,1);
 digitalWrite(4,1);
 }
   int stopu(){
 digitalWrite(2,0);
 digitalWrite(3,0);
 digitalWrite(4,0);
 digitalWrite(5,0);
 }
 int right(){
  digitalWrite(5,1);
  delay(200);
  stopu();
 }
 int left(){
  digitalWrite(2,1);
  delay(200);
  stopu();


}
int leftd(){
  s1.write(180);
  int v=distance();
  delay(600);
  s1.write(90);
  return v;
}
int rightd(){
  s1.write(0);
  int v=distance();
    delay(600);
  s1.write(90);
  return v;
}
