#include <Wire.h>
#include <Servo.h>


/* ----- Globals ----- */
int x = 0;
byte data;
int val;
int motion_time = 6;  // Time for each motion (s)
int clock_speed = 25; // Arduino clock speed (26 MHz)
int decrement = 2;    // Amount decreased each cycle

// Servos
Servo Servo1;
Servo Servo2;
Servo Servo3;
Servo Servo4;
Servo Servo5;
Servo Servo6;


// Servo Speeds
int speed1 = 68;      // NEED TO CHANGE
int speed2 = 204;     // NEED TO CHANGE
int speed3 = 50;      // NEED TO CHANGE
int speed4 = 50;      // NEED TO CHANGE
int speed5 = 50;      // NEED TO CHANGE
int speed6 = 50;      // NEED TO CHANGE

// Servo Stops
int stop1 = 47.5;     // NEED TO CHANGE
int stop2 = 84;       // NEED TO CHANGE
int stop3 = 0;        // NEED TO CHANGE
int stop4 = 0;        // NEED TO CHANGE
int stop5 = 0;        // NEED TO CHANGE
int stop6 = 0;        // NEED TO CHANGE


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
  pinMode(8, OUTPUT);     // Debug LED

  // Attach Servos
  //Servo2.attach(2);     // MIGHT NEED TO CHANGE PINS
  //Servo2.attach(2);
  //Servo3.attach(3);

}
void loop() {
  /* ----- Begin I2C ----- */
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(x);              // sends x 
  Wire.endTransmission();    // stop transmitting
  /* ----- End I2C ----- */

  // Read Serial Data
  if(Serial.available() > 0) {
    data = Serial.read();
    val = int(data);
    Serial.println(val);
  }

  x = val; 
  Serial.println(x); 


  /* ----- Start Servos ----- */
  // Servo 1
  if (x % 10 == 1) {
    s1 = clock_speed*motion_time;
    Servo1.attach(1);
    Servo1.write(speed1);
  }

  // Servo 2
  if ((x/10) % 10 == 1) {
    s2 = clock_speed*motion_time;
    Servo2.attach(2);
    Servo2.write(speed2);
  }

  // Servo 3
  if ((x/100) % 10 == 1) {
    s3 = clock_speed*motion_time;
    Servo3.attach(3);
    Servo3.write(speed3);
  }

  // Servo 4
  if ((x/1000) % 10 == 1) {
    s4 = clock_speed*motion_time;
    Servo4.attach(4);
    Servo4.write(speed4);
  }

  // Servo 5
  if ((x/10000) % 10 == 1) {
    s5 = clock_speed*motion_time;
    Servo5.attach(5);
    Servo5.write(speed5);
  }

  // Servo 6
  if ((x/100000) % 10 == 1) {
    s6 = clock_speed*motion_time;
    Servo6.attach(6);
    Servo6.write(speed6);
  }

  val = 0;  // Reset
  x = 0;    // Reset
  /* ----- End Servo Starting ----- */



  /* ----- Start Time Keeping ----- */
  // Servo 1
  if (s1 > 0) {
    Serial.print("Counter: ");
    Serial.println(s1);
    s1 = s1 - decrement;
  } else {
    //Servo1.write(stop1);      // May need to be commented out... -->
    Servo1.detach();
    s1 = 0;
  }

  // Servo 2
  if (s2 > 0) {
    s2 = s2 - decrement;
  } else {
    //Servo2.write(stop2);
    Servo2.detach();
    s2 = 0;
  }

  // Servo 3
  if (s3 > 0) {
    s3 = s3 - decrement;
  } else {
    //Servo3.write(stop3);
    Servo3.detach();
    s3 = 0;
  }

  // Servo 4
  if (s4 > 0) {
    s4 = s4 - decrement;
  } else {
    //Servo4.write(stop4);      // May need to be commented out... -->
    Servo4.detach();
    s4 = 0;
  }

  // Servo 5
  if (s5 > 0) {
    s5 = s5 - decrement;
  } else {
    //Servo4.write(stop4);      // May need to be commented out... -->
    Servo5.detach();
    s5 = 0;
  }

  // Servo 6
  if (s6 > 0) {
    s6 = s6 - decrement;
  } else {
    //Servo4.write(stop4);      // May need to be commented out... -->
    Servo6.detach();
    s6 = 0;
  }
  /* ----- End time tracking ----- */
  
}
