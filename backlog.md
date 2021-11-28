# Backlog
### Software
###### Pulse Detection
I have the hardware pressure sensor setup and a prototype program called pulse_1.ino, but 
this needs to be integrated into the main branch with a display and timer function. 
###### Dynamic Text Resizing
I'm looking for a way to write multiple sizes of text to the screen in one frame. There's 
a function which defines different font sizes, so first steps may be to see if that function
can be called in the middle of a frame.
###### Move high intensity tasks to core1
The ESP32 has two cores and the Arduino IDE is capable of taking advantage of this functionality,
so if certain tasks take longer than their blocking allows, it may be advantageous to move
those tasks to core1. 
### CAD
