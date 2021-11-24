# ESP32 Smartwatch Project
###### by Chris Uustal | Fall '21 | Northwestern University: CE395 - Wearables 
### What is this? 
This is my (admittedly weak) attempt at designing my own prototype-friendly smartwatch. 
It's specifically intended for use by the driver of our Formula SAE team to track information
about them as they're driving the car. 
### What can it do? 
Currently, not much. It tracks acceleration and ambient temperature, displays it to a screen, 
and logs it to an SD card. It can also connect to the internet to display real time, has an
internal stopwatch, calculates state of charge, sleeps, supports semi-hotswappable SD cards, 
and manages its running tasks with a set of virtual timers. 
### What parts am I using? 
ESP32 Feather by Adafruit
OLED FeatherWing by Adafruit
MicroSD Card Shield by Adafruit
MPU6050 9DOF IMU w/ Temperature by ??? (idk, I found it in a bin)
500mAh LiPoly Battery by Adafruit 
### Why am I making this? 
I'm enrolled in a class, duh. I also find consumer tech and wearables really cool. 
### Can you use this? 
Sure, all of this is open source--that's why I put it on GitHub.
### Will I support this? 
Definitely not. Don't assume this project will ever be updated. I might, but I also might not. 