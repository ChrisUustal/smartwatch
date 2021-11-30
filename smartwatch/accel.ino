//accel.ino
//Accelerometer Library
#include <Adafruit_MPU6050.h>
#include "accel.h"

//Configure accelerometer + temp sensor
void accel_setup() {
    
    acc = 0.0;
    acc_raw = 0.0;
    acc_offset = 0.0;
    max_acc = 0.0;
    temp_c = 0.0;
    temp_unit = c;
  
   if (!mpu.begin()) {
    #ifdef SERIAL_DEBUG
    Serial.println("Sensor init failed");
    #endif
    accel_present = false;
//    while (1)
//      yield();
    } else {
      accel_present = true;
    }
  #ifdef SERIAL_DEBUG
  Serial.println("Found a MPU-6050 sensor");
  #endif
}

//Poll accel values, then calculate magnitude and max
void accel_loop(){
  if(accel_present){
    //Read Acceleration & Temp Sensor
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);
  
    //Calculate Acceleration
    acc_raw = sqrt(a.acceleration.x * a.acceleration.x + 
    a.acceleration.y * a.acceleration.y + 
    a.acceleration.z * a.acceleration.z);
  
    acc = acc_raw  - acc_offset;
  
    //Calculate temp
    switch (temp_unit) {
      case c: 
        temp_c = temp.temperature;
        break;
      case f:
        temp_c = (temp.temperature*9/5)+32;
        break;
      default:
        temp_c = temp.temperature; //default to C
    }
  
    //Calculate max acceleration 
    if(acc > max_acc){
      max_acc = acc;
    }
  }
}

void accel_zero_event(){
  if(accel_present){
    acc_offset = acc_raw;
  }
}

void accel_unzero_event(){
  if(accel_present){
    acc_offset = 0.0;
  }
}

void temp_toggle_unit(){
  if(accel_present){
    switch (temp_unit){
    case c :
      temp_unit = f;
      break;
    case f :
      temp_unit = c;
      break;
    default:
      temp_unit = c;
  }
  }
}
