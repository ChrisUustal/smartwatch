//settings.ino
/* ~~~~~~~~~~ Reference Libraries ~~~~~~~~~~ */
//Display Library
//#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

/* ~~~~~~~~~~ Custom Libraries ~~~~~~~~~~ */
#include "settings.h"
#include "fsm.h"
#include "display.h"

void settings_setup(){
  settings_fsm = setting1;
}

void settings_scroll_event(){
  switch (settings_fsm){
    case setting1:
      settings_fsm = setting2;
      break;
    case setting2:
      settings_fsm = setting3;
      break;
    case setting3:
      settings_fsm = setting4;
      break;
    case setting4:
      settings_fsm = setting5;
      break;
    case setting5:
      settings_fsm = setting1;
      break;
    default:
      settings_fsm = setting1;
  }
}

void settings_select_event(){
  
}

void settings_display_adv(){
  
  print_setting_selector(setting1);
  
  display0.print("Text Size: ");
  switch (text_size) {
    case DISPLAY_TEXT_SMALL :
      display0.printf("S\r\n");
      break;
    case DISPLAY_TEXT_MEDIUM : 
      display0.printf("M\r\n");
      break;
    case DISPLAY_TEXT_LARGE : 
      display0.printf("L\r\n");
      break;
    default:
      display0.printf("?\r\n");
  }

  print_setting_selector(setting2);
  
  display0.printf("Orientation: ");
  switch (text_rotation) {
    case DISPLAY_LANDSCAPE : 
      display0.printf("L\r\n");
      break;
    case DISPLAY_PORTRAIT : 
      display0.printf("P\r\n");
      break;
    case DISPLAY_LANDSCAPE_FLIPPED : 
      display0.printf("LF\r\n");
      break;
    case DISPLAY_PORTRAIT_FLIPPED :
      display0.printf("PF\r\n");
      break;
    default:
      display0.printf("?\r\n");
  }

  print_setting_selector(setting3);
  
  display0.printf("Coming Soon: X\r\n");
  print_setting_selector(setting4);
  display0.printf("Coming Soon: X\r\n");
  print_setting_selector(setting5);
  display0.printf("Coming Soon: X\r\n");
}

void print_setting_selector(settings_fsm_enum state){
  if(settings_fsm == state){
    display0.print("-");
  } else {
    display0.print(" ");
  }
}
