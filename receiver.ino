#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

Servo myservo;
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
int val1,val2,val3,val4,val5;

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  myservo.attach(10);  // attaches the servo on pin 9 to the servo object
  myservo1.attach(9);
  myservo2.attach(6);
  myservo3.attach(5);
  myservo4.attach(3);
}
void loop() {
  if (radio.available()) {
    char text[5] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
    myservo.write(text[1]);             
    delay(15);
    myservo1.write(text[2]);              
    delay(15);   
    myservo2.write(text[3]);              
    delay(15);   
    myservo3.write(text[4]);              
    delay(15);   
    myservo4.write(text[5]); 

   
  }
}
