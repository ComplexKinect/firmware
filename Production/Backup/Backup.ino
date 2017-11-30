#include <Wire.h>
#include <Servo.h>

int x = 0;
byte data;
int val;
int motion_time = 6;  // Time for each motion (s)
int clock_speed = 16000000; // Arduino clock speed (16 MHz)
int decrement = 1;    // Amount decreased each cycle

// Servos
Servo Servo1;
Servo Servo2;
Servo Servo3;
Servo Servo4;
Servo Servo5;
Servo Servo6;


// Servo counter
int s1 = 0;
int s2 = 0;
int s3 = 0;
int s4 = 0;
int s5 = 0;
int s6 = 0;


void setup() {
  // Start the I2C Bus as Master
  Wire.begin();
  Serial.begin(9600);
  pinMode(8, OUTPUT);

  // Attach Servos
  Servo1.attach(1);     // MIGHT NEED TO CHANGE PINS
  Servo2.attach(2);
  Servo3.attach(3);
  Servo4.attach(4);
  Servo5.attach(5);
  Servo6.attach(6);

}
void loop() {
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(x);              // sends x 
  Wire.endTransmission();    // stop transmitting

  // Read Serial Data
  if(Serial.available() > 0) {
    data = Serial.read();
    val = int(data);
  }

  x = val;  

  // Start servo drive based off incoming message
  if (x == 1) {
    s1 = clock_speed*motion_time;
    Servo1.write(20);             // CHANGE SPEED
  } else if (x == 2) {
    s2 = clock_speed*motion_time;
    Servo1.write(20);             // CHANGE SPEED
  } else if (x == 3) {
    s3 = clock_speed*motion_time;
    Servo1.write(20);             // CHANGE SPEED
  } else if (x == 4) {
    s4 = clock_speed*motion_time;
    Servo1.write(20);             // CHANGE SPEED
  } else if (x == 5) {
    s5 = clock_speed*motion_time;
    Servo1.write(20);             // CHANGE SPEED
  } else if (x == 6) {
    s6 = clock_speed*motion_time;
    Servo1.write(20);             // CHANGE SPEED
  }

  val = 0;  // Reset
  x = 0;    // Reset

  // Keep servos running until out of time
  if (s1 > 0) {
    s1 = s1 - decrement;
  } else {
    Servo1.write(90)            // CHANGE SPEED
    s1 = 0;
  }
  if (s2 > 0) {
    s2 = s2 - decrement;
  } else {
    Servo1.write(90)            // CHANGE SPEED
    s2 = 0;
  }
  if (s3 > 0) {
    s3 = s3 - decrement;
  } else {
    Servo1.write(90)            // CHANGE SPEED
    s3 = 0;
  }
  if (s4 > 0) {
    s4 = s4 - decrement;
  } else {
    Servo1.write(90)            // CHANGE SPEED
    s4 = 0;
  }
  if (s5 > 0) {
    s5 = s5 - decrement;
  } else {
    Servo1.write(90)            // CHANGE SPEED
    s5 = 0;
  }
  if (s6 > 0) {
    s6 = s6 - decrement;
  } else {
    Servo1.write(90)            // CHANGE SPEED
    s6 = 0;
  }
  
}
