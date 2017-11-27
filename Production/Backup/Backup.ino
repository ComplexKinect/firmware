#include <Wire.h>
int x = 0;
byte data;
int val;

void setup() {
  // Start the I2C Bus as Master
  Wire.begin();
  Serial.begin(9600);
  pinMode(8, OUTPUT);
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

  // Determine which servo to drive
  if (x == 1) {
    for (pos = 0; pos <= 100; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      S1.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 100; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      S1.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
  } else if (x == 2) {
    for (pos = 0; pos <= 100; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      S2.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 100; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      S2.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
  } else if (x == 3) {
    for (pos = 0; pos <= 100; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      S3.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 100; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      S3.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
  } else if (x == 4) {
    for (pos = 0; pos <= 100; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      S3.write(pos);              // tell servo to go to position in variable 'pos'
      S2.write(pos);
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 100; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      S3.write(pos);              // tell servo to go to position in variable 'pos'
      S2.write(pos);
      delay(15);                       // waits 15ms for the servo to reach the position
    }
  } else if (x == 5) {
    for (pos = 0; pos <= 100; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      S1.write(pos);              // tell servo to go to position in variable 'pos'
      S3.write(pos);
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 100; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      S1.write(pos);              // tell servo to go to position in variable 'pos'
      S3.write(pos);
      delay(15);                       // waits 15ms for the servo to reach the position
    }
  } else if (x == 6) {
    for (pos = 0; pos <= 100; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      S1.write(pos);              // tell servo to go to position in variable 'pos'
      S2.write(pos);
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 100; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      S1.write(pos);              // tell servo to go to position in variable 'pos'
      S2.write(pos);
      delay(15);                       // waits 15ms for the servo to reach the position
    }
  } else if (x == 7) {
    for (pos = 0; pos <= 100; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      S1.write(pos);              // tell servo to go to position in variable 'pos'
      S2.write(pos);
      S3.write(pos);
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 100; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      S1.write(pos);              // tell servo to go to position in variable 'pos'
      S2.write(pos);
      S3.write(pos);
      delay(15);                       // waits 15ms for the servo to reach the position
    }
  }

  val = 0;
  x = 0;
}
