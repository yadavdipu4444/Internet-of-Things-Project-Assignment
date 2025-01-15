// Arduino built library
#include <Arduino.h> 
#include <Wire.h> 
// TX RX software library for bluetooth
#include <SoftwareSerial.h> 
#include <Servo.h> 
Servo servoDoor; 

// Declaring pins for the LEDs
int ledOne = 5; 
int ledTwo = 6; 
int ledThree = 7;

// Declaring pins for the Ultrasonic Sensor
int echoPin = 8; 
int trigPin = 10; 
long distance; 
long duration;

// Declaring pins for RX, TX
SoftwareSerial Bluetooth(0, 1); 
char Data;

// Function to transmit/send data
void sendData(String transmitData){ 
Bluetooth.println(transmitData); 
}

// Setting up the inputs and outputs
void setup(){
    //Initialize bluetooth port to connect with android
    Bluetooth.begin(9600); 
    pinMode(ledOne,OUTPUT); 
    pinMode(ledTwo,OUTPUT); 
    pinMode(ledThree,OUTPUT); 

    // Initialize pin for Servo Motor
    servoDoor.attach(11); 
    pinMode(trigPin, OUTPUT); 
    pinMode(echoPin, INPUT); 
}


// Setting the loop function
void loop(){
  ultrasonicSensor();
  servoDoor.write(0); // Rotating back to normal position 
  if(distance <= 10){ // If condition where the distance is less than 10 cm
  servoDoor.write(90);
  }

    // Loop for different LEDs
    if(Bluetooth.available()){ 
        // Reading the data from bluetooth
        Data=Bluetooth.read(); 
        if(Data==('4')){ 
            digitalWrite(ledOne,1); // Turn ON Led one
            sendData("Led One Light ON");
        }
        if(Data==('1')){ 
            digitalWrite(ledOne,0); // Turn OFF Led one  
            sendData("Led One Light OFF"); 
        }
        if(Data==('5')){ 
            digitalWrite(ledTwo,1); // Turn ON Led two
            sendData("Bedroom Light ON");
        }
        if(Data==('2')){ 
            digitalWrite(ledTwo,0); // Turn OFF Led two 
            sendData("Led Two Light OFF"); 
        }
        if(Data==('6')){ 
            digitalWrite(ledThree,1); // Turn ON Led three
            sendData("Led Three Light ON"); 
        }
        if(Data==('3')){
            digitalWrite(ledThree,0); // Turn OFF Led three
            sendData("Led Three Light OFF"); 
        } 
        if(Data==('9')){ 
            digitalWrite(ledOne,1);
            digitalWrite(ledTwo,1);
            digitalWrite(ledThree,1);
            sendData("All Lights ON"); // Turn ON all Leds at one click
        }
        if(Data==('0')){ 
            digitalWrite(ledOne,0);
            digitalWrite(ledTwo,0);
            digitalWrite(ledThree,0);
            sendData("All Lights OFF"); // Turn OFF all Led at one click
        }
    }
}

// Setting the ultra function for Servo Motor
void ultrasonicSensor(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(200); // Waiting for 200 millisecond(s)
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(300); // Waiting for 300 millisecond(s)
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  }
