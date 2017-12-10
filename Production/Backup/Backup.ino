#include <Wire.h>
#include <Servo.h>


/* ----- Globals ----- */
int x = 0;
byte data;
int val;
int motion_time = 6;  // Time for each motion (s)
int clock_speed = 25; // Arduino clock speed (26 MHz)
int decrement = 2;    // Amount decreased each cycle


/* ----- Servo Definitions ----- */
Servo Servo1;
Servo Servo2;
Servo Servo3;
Servo Servo4;
Servo Servo5;
Servo Servo6;

/* ----- Servo Flags ----- */
/* 
 *  Flags determine which direction the servos should be turning
 *  0 = not turning
 *  1 = 0->130
 *  2 = 130->0
 */
int flag1 = 0;
int flag2 = 0;
int flag3 = 0;
int flag4 = 0;
int flag5 = 0;
int flag6 = 0;


/* ----- Servo Speeds ----- */
int speed1 = 68;      // NEED TO CHANGE
int speed2 = 204;     // NEED TO CHANGE
int speed3 = 50;      // NEED TO CHANGE
int speed4 = 50;      // NEED TO CHANGE
int speed5 = 50;      // NEED TO CHANGE
int speed6 = 50;      // NEED TO CHANGE

/* ----- Servo Stops ----- */
int stop1 = 47.5;     // NEED TO CHANGE
int stop2 = 84;       // NEED TO CHANGE
int stop3 = 0;        // NEED TO CHANGE
int stop4 = 0;        // NEED TO CHANGE
int stop5 = 0;        // NEED TO CHANGE
int stop6 = 0;        // NEED TO CHANGE


/* ----- Servo Counters ----- */
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

}
void loop() {
  /* ----- Begin I2C ----- */
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(x);              // sends x 
  Wire.endTransmission();    // stop transmitting
  /* ----- End I2C ----- */
  
  //char *buf = (char *)malloc(sizeof(int)*10);
  
  int ar[10];
  
  
  // Read Serial Data
  int bytes_read = 0;
  while(bytes_read < 6) {
    if(Serial.available() > 0) {
      data = Serial.read();
      int temp = int(data);
      //Serial.println(temp);
      ar[bytes_read] = temp;
      bytes_read++;
    }
  } 
  
  
  x = val; 
  
  Serial.print(flag1);
  Serial.print(", ");
  Serial.print(flag2);
  Serial.print(", ");
  Serial.print(flag3);
  Serial.print(", ");
  Serial.print(flag4);
  Serial.print(", ");
  Serial.print(flag5);
  Serial.print(", ");
  Serial.println(flag6);


  /* ----- Start Servos ----- */
  // Servo 1 -->
  if (ar[0] == 1) {
    if(flag1 == 0) {
      s1 = 1;
      flag1 = 1;
      Servo1.attach(1);
    }
  }
  // Servo 2 -->
  if (ar[1] == 1) {
    if(flag1 == 0) {
      s2 = 1;
      flag2 = 1;
      Servo2.attach(2);
    }
  }
  // Servo 3 -->
  if (ar[2] == 1) {
    if(flag1 == 0) {
      s3 = 1;
      flag3 = 1;
      Servo3.attach(3);
    }
  }
  // Servo 4 -->
  if (ar[3] == 1) {
    if(flag1 == 0) {
      s4 = 1;
      flag4 = 1;
      Servo4.attach(4);
    }
  }
  // Servo 5 -->
  if (ar[4] == 1) {
    if(flag1 == 0) {
      s5 = 1;
      flag5 = 1;
      Servo5.attach(5);
    }
  }
  // Servo 6 -->
  if (ar[5] == 1) {
    if(flag1 == 0) {
      s6 = 1;
      flag6 = 1;
      Servo6.attach(6);
    }
  }

  val = 0;  // Reset
  x = 0;    // Reset
  /* ----- End Servo Starting ----- */



  /* ----- Start Servos Moving ----- */
  // Servo 1 -->
  if(flag1 == 1) {
    // Open flower
    if( s1 < 130 ) {
      Servo1.write(s1);
      s1 = s1 + 1;
    } else {
      Servo1.write(130);
      flag1 = 2;
    }
  } else if(flag1 == 2) {
    // Close flower
    if( s1 > 0 ) {
      Servo1.write(s1);
      s1 = s1 - 1;
    } else {
      Servo1.write(0);
      flag1 = 0;
    }
  }
  // Servo 2 -->
  if(flag2 == 1) {
    // Open flower
    if( s2 < 130 ) {
      Servo2.write(s2);
      s2 = s2 + 1;
    } else {
      Servo2.write(130);
      flag2 = 2;
    }
  } else if(flag2 == 2) {
    // Close flower
    if( s2 > 0 ) {
      Servo2.write(s2);
      s2 = s2 - 1;
    } else {
      Servo2.write(0);
      flag2 = 0;
    }
  }
  // Servo 3 -->
  if(flag3 == 1) {
    // Open flower
    if( s3 < 130 ) {
      Servo3.write(s3);
      s3 = s3 + 1;
    } else {
      Servo3.write(130);
      flag3 = 2;
    }
  } else if(flag3 == 2) {
    // Close flower
    if( s3 > 0 ) {
      Servo3.write(s3);
      s3 = s3 - 1;
    } else {
      Servo3.write(0);
      flag3 = 0;
    }
  }
  // Servo 4 -->
  if(flag4 == 1) {
    // Open flower
    if( s4 < 130 ) {
      Servo4.write(s4);
      s4 = s4 + 1;
    } else {
      Servo4.write(130);
      flag4 = 2;
    }
  } else if(flag4 == 2) {
    // Close flower
    if( s4 > 0 ) {
      Servo4.write(s4);
      s4 = s4 - 1;
    } else {
      Servo4.write(0);
      flag4 = 0;
    }
  }
  // Servo 5 -->
  if(flag5 == 1) {
    // Open flower
    if( s5 < 130 ) {
      Servo5.write(s5);
      s5 = s5 + 1;
    } else {
      Servo5.write(130);
      flag5 = 2;
    }
  } else if(flag5 == 2) {
    // Close flower
    if( s5 > 0 ) {
      Servo5.write(s5);
      s5 = s5 - 1;
    } else {
      Servo5.write(0);
      flag5 = 0;
    }
  }
  // Servo 6 -->
  if(flag6 == 1) {
    // Open flower
    if( s6 < 130 ) {
      Servo6.write(s6);
      s6 = s6 + 1;
    } else {
      Servo6.write(130);
      flag6 = 2;
    }
  } else if(flag6 == 2) {
    // Close flower
    if( s6 > 0 ) {
      Servo6.write(s6);
      s6 = s6 - 1;
    } else {
      Servo6.write(0);
      flag6 = 0;
    }
  }

  delay(15);
  /* ----- End Servos Moving ----- */
  
}
