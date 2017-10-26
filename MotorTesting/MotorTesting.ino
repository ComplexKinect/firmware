#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *M1 = AFMS.getMotor(1);
Adafruit_DCMotor *M2 = AFMS.getMotor(2);
Adafruit_DCMotor *M3 = AFMS.getMotor(3);
Adafruit_DCMotor *M4 = AFMS.getMotor(4);

int SPEED = 20;
int setPoint = 0;

void setup() {
  // put your setup code here, to run once:
  AFMS.begin();
  Serial.begin(9600);

  M1->setSpeed(SPEED);
  M2->setSpeed(SPEED);
  M3->setSpeed(SPEED);
  M4->setSpeed(SPEED);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  myMotor->run(FORWARD);
  delay(1000);
  myMotor->run(BACKWARD);

  // Read Serial Data
  if(Serial.available() > 0) {
    msg = Serial.read();
    setPoint = int(msg);
  }

  moveBall(setPoint)
}

void moveBall(int setPoint) {
  if(setPoint == 1) {
    M1->run(FORWARD);
    delay(500);
    M1->run(BACKWARD);
    delay(500);
  } elif(setPoint == 2) {
    M2->run(FORWARD);
    delay(500);
    M2->run(BACKWARD);
    delay(500);
  } elif(setPoint == 3) {
    M3->run(FORWARD);
    delay(500);
    M3->run(BACKWARD);
    delay(500);
  } elif(setPoint == 4) {
    M4->run(FORWARD);
    delay(500);
    M4->run(BACKWARD);
    delay(500);
  }
}

