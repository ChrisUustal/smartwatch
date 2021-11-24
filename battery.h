//battery.h
#ifndef BATTERY_H
#define BATTERY_H

//Battery 
const int bat_pin = A13;
float vbat;
int battery_percentage;

void battery_loop();

#endif
