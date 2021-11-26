//display.ino
/* ~~~~~~~~~~ Reference Libraries ~~~~~~~~~~ */
//Display Library
#include <Adafruit_SSD1306.h>

/* ~~~~~~~~~~ Custom Libraries ~~~~~~~~~~ */
#include "display.h"
#include "accel.h"
#include "rtc.h"
#include "battery.h"
#include "stopwatch.h"
#include "fsm.h"
#include "sd.h"

//Configure OLED display settings 
void display_setup() {
  display0 = Adafruit_SSD1306(128, 32, &Wire);
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display0.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ; // Don't proceed, loop forever
  }
  display0.display();
  delay(500); // Pause for 1/2 second
  display0.setTextSize(DISPLAY_TEXT_MEDIUM);
  display0.setTextColor(WHITE);
  display0.setRotation(DISPLAY_LANDSCAPE);
}

//Display data to the screen
void display_loop(){
  //Clear display
  display0.clearDisplay();
  display0.setCursor(0, 0);
  
  switch(display_fsm) {
    case acc_state : 
      accel_display();
      break;
    case temp_state : 
      temp_display();
      break;
    case stopwatch_state : 
      stopwatch_display();
      break;
    case clock_state : 
      rtc_display();
      break;
    case battery_state : 
      battery_display();
      break;
    case log_state :
      log_display();
      break;
    default: 
      display0.println("Default");
  }
  
  //display image
  display0.display();
  //delay(100);
}

//Display accelerometer magnitude and maximum
void accel_display(){
  display0.println("Acc: m/s2");
  display0.printf("%4.1f(%4.1f)\r\n", acc, max_acc);
}

void battery_display(){
  display0.println("Bat%: ");
  display0.print(battery_percentage);
  display0.println("%");
}

//Display temperature 
void temp_display(){
  display0.println("Temp: ");
  switch (temp_unit){
    case f:
      display0.printf("%5.1f F\r\n", temp_c);
      break;
    case c:
      display0.printf("%5.1f C\r\n", temp_c);
      break;
    default:
      display0.printf("%5.1f C\r\n", temp_c);
  }
}

//Display stopwatch interface
void stopwatch_display(){
  display0.println("Stopwatch:");
  if(stopwatch0.val < 60.0){
    display0.printf("%8.1f s\r\n", stopwatch0.val);
  } else {
    display0.printf("%3d:%04.1f s\r\n", ((int)(stopwatch0.val))/60, fmod(stopwatch0.val, 60));
  }
  
}

//Display current time in the hr:min:sec format to screen
void rtc_display(){
  if(wifi_connected && (rtc_fails < ALLOWED_RTC_FAILS)){
    display0.println("Time:");
    display0.printf("%02d:%02d:%02d\r\n", my_hour, my_minute, my_second);
  } else {
    display0.println("Clock Fail");
  }
}

void log_display(){
  display0.println("Logging:");
  if(sd_installed) {
    if(log_enable){
      display0.println("true");
    } else {
      display0.println("false");
    }
  } else {
    display0.println("SD Ejected");
  }
}
