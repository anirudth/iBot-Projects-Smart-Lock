#include <SoftwareSerial.h>
#include <Servo.h>
SoftwareSerial BTSerial(10, 11); // RX, TX
Servo myservo;
int pos = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  BTSerial.begin(9600);
  myservo.attach(9);
  myservo.write(0);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  if (BTSerial.available()) {
    char a = BTSerial.read();
    if(a=='0')
    {myservo.write(100); Serial.write("unlock\n");
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    }
    else 
    {myservo.write(0);Serial.write("lock\n");
    digitalWrite(7,LOW);
  digitalWrite(8,HIGH);}

  } 

  

}
