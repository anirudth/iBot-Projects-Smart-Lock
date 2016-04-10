#include <SoftwareSerial.h>
#include <Servo.h>
SoftwareSerial BTSerial(10, 11); // RX, TX for Bluetooth Module
Servo myservo;// Initializing servo
int pos = 0;// Default position for servo
void setup() {
  Serial.begin(9600);
  pinMode(7,OUTPUT);//PIN 7 - GREEN LED 
  pinMode(8,OUTPUT);//PIN 8 - RED LED
  BTSerial.begin(9600);
  digitalWrite(7,LOW);// GREEN by default low
  digitalWrite(8,HIGH);// RED by default high
  myservo.attach(9);// Servo attached at pin 9 to Atmega328
  myservo.write(pos);// Initial position of servo I

}

void loop() {
  if (BTSerial.available()) { // If input available
    char a = BTSerial.read();
    if(a=='0') //If Input is 0, unlock
    {
    myservo.write(100); 
    Serial.write("unlock\n");
    digitalWrite(7,HIGH); // GREEN high
    digitalWrite(8,LOW);// RED low
    }
    else //else stay locked
    {
    myservo.write(0);
    Serial.write("lock\n");
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
      
    }

  } 

  

}
