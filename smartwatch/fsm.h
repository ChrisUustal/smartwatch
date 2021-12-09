//fsm.h
#ifndef FSM_H
#define FSM_H

enum display_fsm_enum {acc_state, temp_state, stopwatch_state, clock_state, battery_state, log_state, settings_state};
enum settings_fsm_enum {setting1, setting2, setting3, setting4, setting5};

//FSM (Finite State Machine) 
display_fsm_enum display_fsm;
settings_fsm_enum settings_fsm;

void fsm_setup();
void fsm_forward_event();
void fsm_backward_event();

#endif
