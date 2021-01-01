/*
  MKR IMU Shield - Interrupt Test
  This example use IMU Interrupt to call a function.
  The circuit:
  - Arduino MKR board
  - Arduino MKR IMU Shield attached
  This example code is in the public domain.
*/

#include "MKRIMU.h"

// Define a global volatile variable for the status of the LED
volatile byte state = LOW;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  // Set the pin for the LED as the output pin
  pinMode(LED_BUILTIN, OUTPUT);

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");

    while (1);
  }

  Serial.println("Setup Interrupt");
  IMU.attachInterrupt(highMotionAcceleration);

  Serial.println("Interrupt is ready for test");
}

void loop() {
  // Write the status of the LED back to the LED pin:
  // "Turn the LED on or off"
  digitalWrite(LED_BUILTIN, state);
}

void highMotionAcceleration() {
  Serial.println("Motion Detected");
  // Invertiere den Status: "Lass die LED blinken von HIGH auf LOW/ an auf aus"
  state = !state;
}
