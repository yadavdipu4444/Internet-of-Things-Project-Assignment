//Include servo library to control the servo motor
#include <Servo.h>
Servo servo1;

//Define the pins for ultrasonic sensor
int trigPin = 10;
int echoPin = 8;
long distance;
long duration;

//Attach the servo motor and set the input and output
void setup() {
servo1.attach(11); 
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
}

//Call the ultra function to calcualte the distance
void loop() {
  ultra();
  servo1.write(0);

  //Condition to chekc the distacne is less than or equal to 10 cm
  if(distance <= 10){
  servo1.write(90);
  }
}
 

//Ultra finction for setting the pins and calculaitng the distance 
void ultra(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(200);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(300);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  }
