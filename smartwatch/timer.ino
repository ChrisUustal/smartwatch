//timer.ino
#include "timer.h"
#include "accel.h"
#include "battery.h"
#include "rtc.h"
#include "display.h"
#include "custom_sd.h"
#include "stopwatch.h"

//Handler for calling timed events 
void call_timer(int n) {
  
  if(millis() >= timer_arr[n].timer_ref + timer_arr[n].loop_time_ms){
    //timer_arr[n].timer_ref = millis();
    timer_arr[n].timer_ref += timer_arr[n].loop_time_ms;
    (*function_ptr[n])();
  }
  
}

//Configures the timed events handler
void timer_setup(){
  for(int i = 0; i < num_timers; i++){
    timer_arr[i].timer_ref = millis();
    timer_arr[i].loop_time_ms = loop_time_ms_arr[i];
  }
  //NEW LOOPS NEED TO BE ADDED HERE
  function_ptr[0] = button_loop;
  function_ptr[1] = sd_loop;
  function_ptr[2] = accel_loop;
  function_ptr[3] = stopwatch_loop;
  function_ptr[4] = display_loop;
  function_ptr[5] = rtc_loop;
  function_ptr[6] = battery_loop;
  function_ptr[7] = sd_periodic_save;
  
}
