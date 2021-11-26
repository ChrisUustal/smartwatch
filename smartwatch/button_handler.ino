//button_handler.ino
#include "button_handler.h"
#include "sleep.h"
#include "fsm.h"
#include "stopwatch.h"

//Can the stopwatch be toggled from any screen?
//I've determined that this functionality is non-scalable 
//#define STOPWATCH_GLOBAL false
//#define LOG_GLOBAL false

void button_setup(){

  button_a.init(BUTTON_A_PIN, 1000);
  button_b.init(BUTTON_B_PIN);
  button_c.init(BUTTON_C_PIN);

  button_a.press_handler = a_press_handler;
  button_a.short_press_handler = short_a_press_handler;
  button_a.long_press_handler = long_a_press_handler;

  button_b.press_handler = b_press_handler;
  button_b.short_press_handler = short_b_press_handler;
  button_b.long_press_handler = long_b_press_handler;

  button_c.press_handler = c_press_handler;
  button_c.short_press_handler = short_c_press_handler;
  button_c.long_press_handler = long_c_press_handler;
  
}

void button_loop(){

  button_a.timingHandler();
  button_b.timingHandler();
  button_c.timingHandler();
  
}

void a_press_handler(){
  
}

void short_a_press_handler() {
  fsm_backward_event();
}

void long_a_press_handler() {
  sleep_event();
}

void b_press_handler(){
  
}

void short_b_press_handler() {
  fsm_forward_event();
}

void long_b_press_handler() {
 
}

//THIS CAN HAPPEN CONCURRENTLY W/ SHORT PRESS AND LONG PRESS EVENTS
void c_press_handler(){
    switch(display_fsm) {
      case stopwatch_state :
        stopwatch_event();
        break;
      //default:
    }
}

void short_c_press_handler() {
  switch (display_fsm) {
    case log_state : 
      sd_event();
      break;
    case acc_state :
      accel_zero_event();
      break;
    case temp_state : 
      temp_toggle_unit();
      break;
    //default: 
  }
}

void long_c_press_handler() {
  switch (display_fsm) {
    case acc_state : 
      accel_unzero_event();
      break;
    //default: 
  }
}
