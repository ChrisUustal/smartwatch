# Backlog
### Software
###### Pulse Detection
I have the hardware pressure sensor setup and a prototype program called pulse_1.ino, but 
this needs to be integrated into the main branch with a display and timer function. 
###### Move high intensity tasks to core1
The ESP32 has two cores and the Arduino IDE is capable of taking advantage of this functionality,
so if certain tasks take longer than their blocking allows, it may be advantageous to move
those tasks to core1. 
###### Add Settings Interface
It would be ideal to let the user configure some of the settings of the device like the 
text size, orientation, etc. through a settings interface. This will suck. 
###### Variable Sensor Sample Rate
The sensors are sampled at a constant rate now, but (if settings is added), then we can
also give the user the option to change the rate the sensors are sampled at 
###### Update FSM to Structures
The current implementation for the FSM uses a switch statement which has a hardcoded order
of states that are iterated through manually. It would be better if this was handled by some 
kind of struct that allows states to be added to and removed from a queue that is then iterated 
through. This would also allow it to be modified at run time
### CAD
