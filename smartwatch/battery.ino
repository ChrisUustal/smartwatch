//battery.ino
#include "battery.h"
#include "soc.h"

//Check battery voltage and calculate battery state of charge
void battery_loop(){
  //Calculate battery voltage 
  vbat = 2*3.3*analogRead(bat_pin)/4096.0;
  battery_percentage = calc_soc(vbat);
}
