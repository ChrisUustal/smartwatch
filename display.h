//display.h
#ifndef DISPLAY_H
#define DISPLAY_H

#define DISPLAY_LANDSCAPE 0
#define DISPLAY_PORTRAIT 1
#define DISPLAY_LANDSCAPE_FLIPPED 2
#define DISPLAY_PORTRAIT_FLIPPED 3

//Potrait: 16 rows 5 chars, Landscape: 4 rows 20 chars
#define DISPLAY_TEXT_SMALL 1
//Portrait: 8 rows 2 chars, Landscape: 2 rows 10 chars
#define DISPLAY_TEXT_MEDIUM 2
//Potrait: 4 rows 1 char, Landscape: 1 row 5 chars
#define DISPLAY_TEXT_LARGE 4

Adafruit_SSD1306 display0;

void display_setup();
void display_loop();

void battery_display();
void accel_display();
void temp_display();
void stopwatch_display();
void rtc_display();
void log_display();

#endif
