#include <Wire.h>
#include <Servo.h>

int x = 0;
byte data;
int val;
int motion_time = 6;  // Time for each motion (s)
int clock_speed = 25; // Arduino clock speed (16 MHz)
int decrement = 1;    // Amount decreased each cycle

// Servos
Servo Servo1;
Servo Servo2;
Servo Servo3;

// Servo Speeds
int speed1 = 68;      // NEED TO CHANGE
int speed2 = 104;      // NEED TO CHANGE
int speed3 = 50;      // NEED TO CHANGE

// Servo Stops
int stop1 = 47.5;       // NEED TO CHANGE
int stop2 = 84;       // NEED TO CHANGE
int stop3 = 0;       // NEED TO CHANGE

// Servo counter
int s1 = 0;
int s2 = 0;
int s3 = 0;


void setup() {
  // Start the I2C Bus as Master
  Wire.begin();
  Serial.begin(9600);
  pinMode(8, OUTPUT);

  // Attach Servos
  Servo1.attach(4);     // MIGHT NEED TO CHANGE PINS
  Servo2.attach(5);
  Servo3.attach(7);

}
void loop() {
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(x);              // sends x 
  Wire.endTransmission();    // stop transmitting

  // Read Serial Data
  if(Serial.available() > 0) {
    data = Serial.read();
    val = int(data);
    Serial.println(val);
  }

  x = val; 
  Serial.println(x); 

  // Start servo drive based off incoming message
  if (x == 1) {
    s1 = clock_speed*motion_time;
    Serial.println(s1);
    Servo1.attach(4);
    Servo1.write(speed1);
  } else if (x == 2) {
    s2 = clock_speed*motion_time;
    Servo2.attach(5);
    Servo2.write(speed2);
  } else if (x == 3) {
    s3 = clock_speed*motion_time;
    Servo3.attach(7);
    Servo3.write(speed3);
  } else if (x == 4) {
    s2 = clock_speed*motion_time;
    s3 = clock_speed*motion_time;
    Servo2.attach(5);
    Servo3.attach(7);
    Servo2.write(speed2);
    Servo3.write(speed3);
  } else if (x == 5) {
    s1 = clock_speed*motion_time;
    s3 = clock_speed*motion_time;
    Servo1.attach(4);
    Servo3.attach(7);
    Servo1.write(speed1);
    Servo3.write(speed3);
  } else if (x == 6) {
    s1 = clock_speed*motion_time;
    s2 = clock_speed*motion_time;
    Servo1.attach(4);
    Servo2.attach(5);
    Servo1.write(speed1);
    Servo2.write(speed2);
  } else if (x == 7) {
    s1 = clock_speed*motion_time;
    s2 = clock_speed*motion_time;
    s3 = clock_speed*motion_time;
    Servo1.attach(4);
    Servo2.attach(5);
    Servo3.attach(7);
    Servo1.write(speed1);
    Servo2.write(speed2);
    Servo3.write(speed3);
  }

  val = 0;  // Reset
  x = 0;    // Reset

  // Keep servos running until out of time
  if (s1 > 0) {
    Serial.print("Counter: ");
    Serial.println(s1);
    s1 = s1 - decrement;
  } else {
    //Servo1.write(stop1);
    Servo1.detach();
    s1 = 0;
  }
  if (s2 > 0) {
    s2 = s2 - decrement;
  } else {
    //Servo2.write(stop2);
    Servo2.detach();
    s2 = 0;
  }
  if (s3 > 0) {
    s3 = s3 - decrement;
  } else {
    //Servo3.write(stop3);
    Servo3.detach();
    s3 = 0;
  }
  
}
