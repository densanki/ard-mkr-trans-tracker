# ard-mkr-trans-tracker
Arduino MKR Transport Tracker

## Testsetup

### Test Boards
* https://store.arduino.cc/arduino-mkr-fox-1200-1408
* https://store.arduino.cc/arduino-mkr-nb-1500-1413

### Test Shields
* https://store.arduino.cc/arduino-mkr-imu-shield
 
## Board Preparation  

* Arduino Genuino 1.8.13
* Board Driver: Arduino SAMD Boards (32-bits ARM Cortex-M0+)

## Lib Preparation if needed

* Lib: Arduino SigFox for MKRFox1200
``` 
#include <SigFox.h>
``` 

* Lib: MKRNB (https://www.arduino.cc/en/Reference/MKRNB)

Enales NB/GRPS network connection using the Arduino MKR NB 1500 board. This also allows you to connect to internet throught NarrowBand IoT or LTE Cat M1 networks.

``` 
#include <SigFox.h>
``` 

* Lib: Arduino Low Power 
``` 
#include <ArduinoLowPower.h>
``` 
* Lib MKRIMU (https://github.com/arduino-libraries/MKRIMU)

``` 
#include <MKRIMU.h>
``` 

Interrupt https://github.com/arduino-libraries/MKRIMU/pull/2

* Lib BNO055 (https://github.com/arduino-libraries/BNO055)
``` 
#include "BNO055_support.h"
``` 
