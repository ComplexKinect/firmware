#include <Servo.h>

Servo Servo1;
Servo Servo2;
Servo Servo3;

void setup() {
  // put your setup code here, to run once:
  pinMode(6, OUTPUT);

  //Servo1.attach(1);
  //Servo2.attach(2);
  //Servo3.attach(3);
}

void loop() {
  // put your main code here, to run repeatedly:
  Servo1.attach(2);
  Servo1.write(68);
  delay(500);
  Servo1.write(47.5);
  Servo1.detach();
  delay(500);
}
