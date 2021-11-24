//timer.h
#ifndef TIMER_H
#define TIMER_H

class Timer {
  public:
    long timer_ref; //Last time the timer was called 
    int loop_time_ms;
};

//Timers
//THIS NEEDS TO BE UPDATED WHEN YOU ADD MORE LOOPS
//THERE'S ALSO ONE IN THE TIMER_SETUP FUNCTION
const int num_timers = 7;
const int loop_time_ms_arr[num_timers] = {
  10,       //button
  10,       //sd
  10,       //accel
  100,      //stopwatch
  100,      //display
  1000,     //rtc
  5000      //battery
};

void (*function_ptr[num_timers])();
Timer timer_arr[num_timers];

void call_timer(int n);

void timer_setup();

#endif
