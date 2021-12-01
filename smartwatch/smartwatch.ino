/*********************************************
* Project DataRacer: 
* by Chris Uustal | Fall '21 | Northwestern U CE395 - Wearables & Embedded Computing
* Free for non-commercial use
* GitHub: https://github.com/ChrisUustal/smartwatch
**********************************************/

/* ~~~~~~~~~~ Reference Libraries ~~~~~~~~~~ */
//Accelerometer Library
#include <Adafruit_MPU6050.h>
//Display Library
//128x32 lib
//#include <Adafruit_SSD1306.h>
//128x64 lib
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
//idk what this library does tbh 
#include <Adafruit_Sensor.h>
//Wifi Library
#include <WiFi.h>
//Time Management Library
#include "time.h"
//SD libraries
#include "FS.h"
#include "SD.h"
#include "SPI.h"

/* ~~~~~~~~~~ Custom Libraries ~~~~~~~~~~ */
#include "soc.h"
#include "battery.h"
#include "sleep.h"
#include "accel.h"
#include "rtc.h"
#include "custom_sd.h"
#include "stopwatch.h"
#include "display.h"
#include "timer.h"
#include "fsm.h"
#include "button_handler.h"
#include "settings.h"

/* ~~~~~~~~~~ Defines ~~~~~~~~~~ */
#define SERIAL_SPEED 115200
//#define SERIAL_DEBUG

/* ~~~~~~~~~~ Setup ~~~~~~~~~~ */
void setup() {

  Serial.begin(SERIAL_SPEED);
  
  sleep_setup();
  fsm_setup();
  settings_setup();
  accel_setup();
  stopwatch_setup();
  display_setup();
  rtc_setup();
  sd_setup();
  button_setup();
  battery_loop();//Populate the value initially
  
  timer_setup();//I should be last
}

/* ~~~~~~~~~~ Main Loop ~~~~~~~~~~ */
void loop() {

  for(int i = 0; i < num_timers; i++){
    call_timer(i);
  }
  
}
