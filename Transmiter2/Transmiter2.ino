#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

const int finger1 = A0; // Pin connected to voltage divider output
const int finger2 = A1; // Pin connected to voltage divider output
const int finger3 = A2; // Pin connected to voltage divider output
const int finger4 = A3; // Pin connected to voltage divider output
const int finger5 = A4; // Pin connected to voltage divider output
const float VCC = 4.41; // Measured voltage of Ardunio 5V line
const float R_DIV = 45200.0; // Measured resistance of 3.3k resistor(average)
const float STRAIGHT_RESISTANCE = 22700.0; // resistance when straight(average)
const float BEND_RESISTANCE = 55200.0; // resistance at 90 deg(average)
int angle1,angle2,angle3,angle4,angle5,angle0;

void setup() {
  Serial.begin(9600);
  pinMode(finger2, INPUT);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}
void loop() {
  angle1=angle_1();
  angle2=angle_2();
  angle3=angle_3();
  angle4=angle_4();
  angle5=angle_5();
  String co = ",";
  const char text[] = {angle1, angle2, angle3, angle4, angle5};
  radio.write(&text, sizeof(text));
  Serial.print(angle1);
  Serial.print(",");
  Serial.print(angle2);
  Serial.print(",");
  Serial.print(angle3);
  Serial.print(",");
  Serial.print(angle4);
  Serial.print(",");
  Serial.println(angle5);
  delay(100);
}

int angle_1()
{
  int flexADC = analogRead(finger1);
  float flexV = flexADC * VCC / 1023.0;
  float flexR = 261 * (VCC / flexV - 1.0);
  float angle = map(flexADC, 0, 1023,
                   0, 180);
  //angle = regulator(angle);
  return angle;
}
int angle_2()
{
  int flexADC = analogRead(finger2);
  float flexV = flexADC * VCC / 1023.0;
  float flexR = 265 * (VCC / flexV - 1.0);
  float angle = map(flexADC, 0, 1023,
                   0, 180);
  //angle = regulator(angle);
  return angle;
}
int angle_3()
{
  int flexADC = analogRead(finger3);
  float flexV = flexADC * VCC / 1023.0;
  float flexR = 261 * (VCC / flexV - 1.0);
  float angle = map(flexADC, 0, 1023,
                   0, 180);
  //angle = regulator(angle)*0;
  return angle;
}
int angle_4()
{
  int flexADC = analogRead(finger4);
  float flexV = flexADC * VCC / 1023.0;
  float flexR = 260 * (VCC / flexV - 1.0);
  float angle = map(flexADC, 0, 1023,
                   0, 180);
  //angle = regulator(angle);
  return angle;
}
int angle_5()
{
  int flexADC = analogRead(finger5);
  float flexV = flexADC * VCC / 1023.0;
  float flexR = 257 * (VCC / flexV - 1.0);
  int angle = map(flexR, 4140, 4190,
                   0, 90.0);
  //angle = regulator(angle);
  return angle;
}

float regulator(float angle0)
{
  if (angle0<0){
    angle0=abs(angle0)*0.25;
  }
  if (angle0==0){
    angle0=0;
    }
  if (0<angle0<80){
    angle0=angle0;
    }
  if (80<=angle0<=120){
    angle0= 0.09*angle0 + 80;
    }
  if (angle0>120){
    angle0=90;
    }
  else{
    angle0=angle0;
    }  
  return angle0;
}

float versor(float angle0)
{
  if (5<=angle0<15){
    angle0=10;
  }
  if (15<=angle0<25){
    angle0=20;
  }
  if (25<=angle0<35){
    angle0=30;
  }
  if (35<=angle0<45){
    angle0=40;
  }
  if (45<=angle0<55){
    angle0=50;
  }
  if (55<=angle0<65){
    angle0=60;
  }
  if (65<=angle0<75){
    angle0=70;
  }
  if (75<=angle0<85){
    angle0=80;
  }
  if (85<=angle0<95){
    angle0=90;
  }
  return angle0;
}
