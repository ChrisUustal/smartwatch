//stopwatch.h
#ifndef STOPWATCH_H
#define STOPWATCH_H

struct stopwatch {

  float val;
  float ref;
  bool enable;

  void init() {
    val = 0.0;
    ref = 0.0;
    enable = false;
  }
  
} stopwatch0;

void stopwatch_setup();
void stopwatch_loop();
void stopwatch_event();

#endif
