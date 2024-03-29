//button_handler.h
#ifndef BUTTON_HANDLER_H
#define BUTTON_HANDLER_H

#define BUTTON_A_PIN 15
#define BUTTON_B_PIN 32
#define BUTTON_C_PIN 14

//button structure
struct _button{

  int pin;
  bool previous_state;
  bool current_state;
  unsigned long press_ref;
  unsigned long press_duration = 0;
  unsigned long press_threshold = 500;

//  unsigned long release_ref;
//  unsigned long release_duration = 0;
//  unsigned long release_threshold = 500;

  void (*short_press_handler)();
  void (*long_press_handler)();
  void (*press_handler)();

  bool pressed(){
    return !current_state;
  }
  
  //Initialize button input
  void init(int pin_input){
    //Set pin and confiure as input
    pin = pin_input;
    pinMode(pin, INPUT_PULLUP);
    //Set initial button state at startup
    previous_state = digitalRead(pin);
    current_state = previous_state;
    //Set reference point
    press_ref = millis();
    //release_ref = millis();
  };

  void init(int pin_input, unsigned long threshold_input){
    //Set pin and confiure as input
    init(pin_input);
    //Set custom threshold
    press_threshold = threshold_input;
  }

  //Detect rising or falling edge 
  bool edge(){
    current_state = digitalRead(pin);
    return (previous_state != current_state);
  };

  void timingHandler(){
    if(edge()){
      previous_state = current_state;
      if(current_state){ //NOT PRESSED; PRESS ENDED
        //release_ref = millis();
        press_duration = millis() - press_ref;
        if(press_duration < press_threshold) {
          (*short_press_handler)();
        } else {
          (*long_press_handler)();
        }
      } else { //PRESSED; PRESS STARTED
        press_ref = millis();
        (*press_handler)();
        //release_duration = millis() - release_ref;
        //(*button_handler_ptr)();
      }
    }
  };
  
} button_a, button_b, button_c;

void button_setup();

void button_loop();

void a_press_handler();
void short_a_press_handler();
void long_a_press_handler();
void b_press_handler();
void short_b_press_handler();
void long_b_press_handler();
void c_press_handler();
void short_c_press_handler();
void long_c_press_handler();

#endif
