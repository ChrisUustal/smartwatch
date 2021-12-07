# DataRacer
### A Wrist-Mounted Data Logger for Race Car Drivers
###### By Chris Uustal | Fall '21 | CE395 - Wearables & Embedded Computing
## Executive Summary
#### Motivation: Why am I doing this? 
I'm taking a class (duh). But actually, I'm a member of the Formula SAE team here
at Northwestern University, and we've spent years collecting data on our vehicle
while never collecting data on our drivers. I wanted to change that. 
#### Problem: What am I fixing? 
Collecting meaningful data from a driver is HARD. They need to wear a very particular
racing suit and the environment they are operating in is... less than forgiving. The
solution also has to be very user friendly and reliable, because if it isn't then
they just won't use it. 
#### Solution: How am I fixing it? 
I designed a smart watch platform capable of collecting and logging sensor data that
has a simple user interface, logs data to a removable microSD card, and can be easily
scaled to include whatever sensors are needed by the driver (whenever those sensors
are back in stock). 
#### Impact: The bigger picture 
The team spends thousands of hours every year trying to tune every ounce of performance 
out of our vehicle, but the driver is picked based off knowledge--not skill. If 
we can find meaningful ways to improve the skills of our drivers based off this data,
then that could make bigger improvements to the performance of our vehicle than some 
projects ever could. 
## Design: 
#### Block Diagram
![image info](./images/dataracer_hw_block_diagram.png)
#### What parts did I use? 
- ESP32 Feather by Adafruit
- OLED FeatherWing by Adafruit
- MicroSD Breakout Board by Adafruit
- MPU6050 9DOF+Temp Sensor by ??? (idk, I found it in a box)
- Pulse Sensor by PulseSensor.com
- 500mAh LiPoly Battery by Adafruit
#### Implementation
This is gonna be long af since the software is hella complicated. 
#### Pictures
Still need to figure out how to add a picture lol
#### Lessons Learned
1. Once you've got a basic idea of the direction you want to go in, just start moving. 
The easiest way to run out of time and kill a design is by not giving yourself
as much time as possible with the hardware. The sooner you have it in your hands 
and either get something working or realize that it's way too hard and you need 
to change direction the better. The biggest thing that killed the momentum in this
project was waiting for components to be ordered that never arrived. Burn the money, 
but the components, get them here tomorrow and start working immediately. It's worth it. 
2. When you're coding, steal as much as possible. Someone else already did something 
kind of similar? Cool, don't reinvent the wheel. Build something cooler off the back 
of what they already did rather than wasting time doing the same thing. If you're 
writing official code for a company, that's something different, but the gloves come off 
when you're just prototyping alone, and the only goal is to produce something that works
as fast as possible by any means necessary. 
3. Always have multiple parts of a project that could use improvement--it avoids blockers. 
It might seem good to really focus in on one particular element of a project and polish 
it to completion, but that's terrible for prototyping, because sometimes things get stuck. 
Sometimes things don't work or they get stuck or you get frustrated or shipping takes 2 weeks. 
Rather than having nothing to do for that time, always have another direction to start
developing in, so when that blocker becomes unblocked you have something fresh to pivot back to. 
4. (If you really want to try this yourself) Packaging a wearable is *very* hard. 
Everyone you show it to is going to expect it to be this slim, tiny little magic device
that is *not* prototype friendly at all. What I have right now works fine, but if you want
to take this any further than I already have, then wait until after the global chip shortage, 
design a custom debug-friendly PCB, and then you might have something people will
actually want to look at. An 18mm thicc watch is *not* attractive. 
## Non-Class Things:  
#### Will I support this project? 
No, don't assume I will. I might update it in the future, and if so, cool! But 
I also might not, so don't hold your breath. 
#### Can you use this? 
Of course, everything is open source and you're free to use it for your own personal non-commercial
projects. If you want to use it to start a company or sell a product or something, shoot 
me a message and I'm sure we can work something out. 