//fsm.ino
#include "fsm.h"

void fsm_setup(){
display_fsm = acc_state;
}

void fsm_event() {

  switch(display_fsm) {
    case acc_state : 
      display_fsm = temp_state;
      break;
    case temp_state : 
      display_fsm = stopwatch_state;
      break;
    case stopwatch_state : 
      display_fsm = clock_state;
      break;
    case clock_state :
      display_fsm = battery_state;
      break;
    case battery_state : 
      display_fsm = log_state;
      break;
    case log_state : 
      display_fsm = acc_state;
      break;
    default:
      display_fsm = acc_state;
  }
   
}
