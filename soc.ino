//soc.ino
#include "soc.h"

//Calculate the charge of the battery as a percentage based on voltage 
int calc_soc(float bat_voltage)
{

  int bat_percentage = 0;
  
  if(bat_voltage>4.15) bat_percentage = 100;
  else if(bat_voltage>4.07) bat_percentage = 95;
  else if(bat_voltage>4.00) bat_percentage = 90;
  else if(bat_voltage>3.97) bat_percentage = 85;
  else if(bat_voltage>3.92) bat_percentage = 80;
  else if(bat_voltage>3.87) bat_percentage = 75;
  else if(bat_voltage>3.84) bat_percentage = 70;
  else if(bat_voltage>3.81) bat_percentage = 65;
  else if(bat_voltage>3.78) bat_percentage = 60;
  else if(bat_voltage>3.76) bat_percentage = 55;
  else if(bat_voltage>3.75) bat_percentage = 50;
  else if(bat_voltage>3.73) bat_percentage = 45;
  else if(bat_voltage>3.72) bat_percentage = 40;
  else if(bat_voltage>3.71) bat_percentage = 35;
  else if(bat_voltage>3.68) bat_percentage = 30;
  else if(bat_voltage>3.66) bat_percentage = 25;
  else if(bat_voltage>3.63) bat_percentage = 20;
  else if(bat_voltage>3.58) bat_percentage = 15;
  else if(bat_voltage>3.50) bat_percentage = 10;
  else if(bat_voltage>3.35) bat_percentage = 5;
  else bat_percentage = 0;

  return bat_percentage;

}
