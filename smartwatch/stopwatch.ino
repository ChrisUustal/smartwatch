//stopwatch.ino
#include "stopwatch.h"

void stopwatch_setup() {

  stopwatch0.init();
  
}

//Calculate timer val from millis()
void stopwatch_loop(){

  if(stopwatch0.enable){
    stopwatch0.val = float(millis())/1000 - stopwatch0.ref;
  }
  
}

void stopwatch_event() {
  
  //toggle timer1 enable 
  stopwatch0.enable = !stopwatch0.enable;
    
  //reset timer reference 
  if(stopwatch0.enable){
    stopwatch0.ref = float(millis())/1000;
  }
  
}
