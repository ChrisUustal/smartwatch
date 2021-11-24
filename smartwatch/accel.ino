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
  
   if (!mpu.begin()) {
    #ifdef SERIAL_DEBUG
    Serial.println("Sensor init failed");
    #endif
    while (1)
      yield();
  }
  #ifdef SERIAL_DEBUG
  Serial.println("Found a MPU-6050 sensor");
  #endif
}

//Poll accel values, then calculate magnitude and max
void accel_loop(){
  //Read Acceleration & Temp Sensor
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  //Calculate Acceleration
  acc_raw = sqrt(a.acceleration.x * a.acceleration.x + 
  a.acceleration.y * a.acceleration.y + 
  a.acceleration.z * a.acceleration.z);

  acc = acc_raw  - acc_offset;

  //Calculate temp
  temp_c = temp.temperature;

  //Calculate max acceleration 
  if(acc > max_acc){
    max_acc = acc;
  }
}
