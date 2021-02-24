/*
  GPS Location
  This sketch uses the GPS to determine the location of the board
  and prints it to the Serial monitor.
  Circuit:
   - MKR board
   - MKR GPS attached via I2C cable
  This example code is in the public domain.
*/

#include <Arduino_MKRGPS.h>

void setup() {
  // initialize serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // If you are using the MKR GPS as shield, change the next line to pass
  // the GPS_MODE_SHIELD parameter to the GPS.begin(...)
  if (!GPS.begin(GPS_MODE_SHIELD)) {
    Serial.println("Failed to initialize GPS!");
    while (1);
  }
  Serial.println("GPS Ready");

  Serial.println("standby");
  GPS.standby();
}

void loop() {

  // wait for 10 seconds
  delay(10000);

  // wake up the GPS
  Serial.println("wakeup");
  GPS.wakeup();

  // wait for new GPS data to become available
  Serial.println("wait location ... ");
  
  unsigned long startMillis = millis();
  while (!GPS.available());
  unsigned long endMillis = millis();

  Serial.print(endMillis - startMillis);
  Serial.println(" ms");
  
  // read GPS values
  float latitude   = GPS.latitude();
  float longitude  = GPS.longitude();
  float altitude   = GPS.altitude();
  float speed      = GPS.speed();
  int   satellites = GPS.satellites();

  // print GPS values
  Serial.print("Location: ");
  Serial.print(latitude, 7);
  Serial.print(", ");
  Serial.println(longitude, 7);

  Serial.print("Altitude: ");
  Serial.print(altitude);
  Serial.println("m");

  Serial.print("Ground speed: ");
  Serial.print(speed);
  Serial.println(" km/h");

  Serial.print("Number of satellites: ");
  Serial.println(satellites);  
  
  Serial.println("standby");
  GPS.standby();
}
