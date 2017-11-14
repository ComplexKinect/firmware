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
  //Wire.beginTransmission(9); // transmit to device #9
  //Wire.write(x);              // sends x 
  //Wire.endTransmission();    // stop transmitting

  // Read Serial Data
  if(Serial.available() > 0) {
    data = Serial.read();
    val = int(data);
  }


  // Send command over I2C
  
  if(val == 1 || val == 2 || val == 3 || val == 4 || val == 5 || val == 6 || val == 7)
  {
    Wire.beginTransmission(9);
    x = val;
    Wire.write(x);
    Wire.endTransmission();
  }
  

  /*
  // Decide which node to trigger
  if(val == 11) {
    Wire.beginTransmission(9);
    x = 1;
    Wire.write(x);
    Wire.endTransmission();
  } else if(val == 21) {
    Wire.beginTransmission(9);
    x = 2;
    Wire.write(x);
    Wire.endTransmission();
  } else if(val == 31) {
    Wire.beginTransmission(9);
    x = 3;
    Wire.write(x);
    Wire.endTransmission();
  }
  */
  val = 0;
  x = 0;
}
