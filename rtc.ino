//rtc.ino
/* ~~~~~~~~~~ Reference Libraries ~~~~~~~~~~ */
//Wifi Library
#include <WiFi.h>
//Time Management Library
#include "time.h"

/* ~~~~~~~~~~ Custom Libraries ~~~~~~~~~~ */
#include "rtc.h"
#include "display.h"

//Configure RTC and handle wifi connection issues
void rtc_setup(){

  my_hour = 0;
  my_minute = 0;
  my_second = 0;
  rtc_fails = 0;
  wifi_connected = false;
  
  //feedback to user
  display0.clearDisplay();
  display0.setCursor(0, 0);
  display0.print("Connecting to WiFi");
  display0.display();

  #ifdef SERIAL_DEBUG
  Serial.println("MAC: ");
  Serial.println(WiFi.macAddress());
  Serial.printf("Connecting to %s ", ssid);
  #endif
  WiFi.begin(ssid, password);
  int wifi_attempt_counter = 0;
  while (WiFi.status() != WL_CONNECTED) {
      if(wifi_attempt_counter >= 10){
        //user feedback
        display0.clearDisplay();
        display0.setCursor(0, 0);
        display0.print("Failed to Connect");
        display0.display();
        //serial debug feedback 
        #ifdef SERIAL_DEBUG
        Serial.println("Failed to connect to wifi");
        #endif
        //disable wifi
        WiFi.disconnect(true);
        WiFi.mode(WIFI_OFF);

        delay(1000);
        return;
      }
      delay(500);
      #ifdef SERIAL_DEBUG
      Serial.print(".");
      #endif
      wifi_attempt_counter++;
  }
  #ifdef SERIAL_DEBUG
  Serial.println(" CONNECTED");
  #endif
  wifi_connected = true;
  
  //init and get the time
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  //printLocalTime();
  rtc_loop();

  //disconnect WiFi as it's no longer needed
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);

}

//Get the current time and store the hr/min/sec
void rtc_loop(){
  if(!wifi_connected || (rtc_fails >= ALLOWED_RTC_FAILS)){
    return;
  }
  
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    #ifdef SERIAL_DEBUG
    Serial.println("Failed to obtain time");
    #endif
    rtc_fails++;
    return;
  }
  my_hour = timeinfo.tm_hour;
  my_minute = timeinfo.tm_min;
  my_second = timeinfo.tm_sec;
}
