/*

  SigFox First Configuration

  This sketch demonstrates the usage of MKRFox1200 SigFox module.

  Since the board is designed with low power in mind, it depends directly on ArduinoLowPower library

  This example code is in the public domain.

*/

#include <SigFox.h>
#include <ArduinoLowPower.h>

#define LED 6         // This is the built_in led

void setup() {
   pinMode(LED,OUTPUT);
   digitalWrite(LED,LOW);
   Serial.begin(9600);
   //while (!Serial);
   if ( ! SigFox.begin() ) {
     Serial.println("Error ... rebooting");
     NVIC_SystemReset();
     while(1);
   }
   SigFox.reset();
   delay(100);
   SigFox.debug();
   SigFox.end();

   Serial.print("Module temperature: ");
   Serial.println(SigFox.internalTemperature());

   // We need to have to time to program the Arduino after a reset
   // Otherwise it does not respond when in low-power mode
   Serial.println("Booting...");
   digitalWrite(LED,HIGH);
   delay(5000);
   digitalWrite(LED,LOW);
}

typedef struct __attribute__ ((packed)) sigfox_message {
int8_t temp;
} SigfoxMessage;

void loop()
{
  sendStringAndGetResponse();
  delay(10*60*1000);
}

void sendStringAndGetResponse() {

  // Start the module
  SigFox.begin();

  // Wait at least 30mS after first configuration (100mS before)
  delay(100);

  // Clears all pending interrupts
  SigFox.status();

  delay(1);

  SigFox.beginPacket();
  
  SigfoxMessage msg;
  msg.temp = (int8_t)SigFox.internalTemperature();
  SigFox.write((uint8_t*)&msg,sizeof(msg));

  int ret = SigFox.endPacket(true);  // send buffer to SIGFOX network and wait for a response

  Serial.print("Response=");
  Serial.println(ret);

  if (ret > 0) {
    Serial.println("No transmission");
  } else {
    Serial.println("Transmission ok");
  }

  Serial.print("SIGFOX=");
  Serial.println(SigFox.status(SIGFOX));
  Serial.print("ATMEL=");
  Serial.println(SigFox.status(ATMEL));

  if (SigFox.parsePacket()) {
    Serial.println("Response from server:");
    while (SigFox.available()) {
      Serial.print("0x");
      Serial.println(SigFox.read(), HEX);
    }
  } else {
    Serial.println("Could not get any response from the server");
    Serial.println("Check the SigFox coverage in your area");
    Serial.println("If you are indoor, check the 20dB coverage or move near a window");
  }

  Serial.println();
  SigFox.end();
}
