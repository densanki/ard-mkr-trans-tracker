/*
  MKR IMU Shield - Simple Euler Angles
  This example reads the euler angle values from the IMU
  on the MKR IMU shield and continuosly prints them to the 
  Serial Monitor.
  The circuit:
  - Arduino MKR board
  - Arduino MKR IMU Shield attached
  This example code is in the public domain.
*/

#include <MKRIMU.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  Serial.print("Euler Angles sample rate = ");
  Serial.print(IMU.eulerAnglesSampleRate());
  Serial.println(" Hz");
  Serial.println();
}

void loop() {
  float heading, roll, pitch;

  if (IMU.eulerAnglesAvailable()) {
    IMU.readEulerAngles(heading, roll, pitch);
    Serial.println("Euler Angles in degrees Heading=" + String(heading) + "\tRoll=" + String(roll) + "\tPitch=" + String(pitch));
  }
}
