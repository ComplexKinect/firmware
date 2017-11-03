#include <Wire.h>
#include <Servo.h>

int LED = 8;
int x = 0;

Servo S1;
Servo S2;
Servo S3;
int pos = 0;

void setup() {
  // Begin Serial to print debug
  Serial.begin(9600);

  // Attach a servo
  S1.attach(9);
  S1.attach(10);
  S1.attach(11);
  
  // Define the LED pin as Output
  pinMode (LED, OUTPUT);
  // Start the I2C Bus as Slave on address 9
  Wire.begin(9); 
  // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);
}
void receiveEvent(int bytes) {
  x = Wire.read();    // read one character from the I2C
  if(x != NULL) {
    digitalWrite(LED, HIGH);
    delay(15);
    digitalWrite(LED, LOW);
  }
  Serial.println(x);
}
void loop() {

  if (x == 1) {
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      S1.write(pos);              // tell servo to go to position in variable 'pos'
      // delay(15);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      S1.write(pos);              // tell servo to go to position in variable 'pos'
      // delay(15);                       // waits 15ms for the servo to reach the position
    }
  } else if (x == 2) {
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      S2.write(pos);              // tell servo to go to position in variable 'pos'
      // delay(15);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      S2.write(pos);              // tell servo to go to position in variable 'pos'
      // delay(15);                       // waits 15ms for the servo to reach the position
    }
  } else if (x == 3) {
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      S3.write(pos);              // tell servo to go to position in variable 'pos'
      // delay(15);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      S3.write(pos);              // tell servo to go to position in variable 'pos'
      // delay(15);                       // waits 15ms for the servo to reach the position
    }
  }
}
