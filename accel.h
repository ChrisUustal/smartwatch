//accel.h
#ifndef ACCEL_H
#define ACCEL_H

//Accelerometer + Temp
Adafruit_MPU6050 mpu;
float acc;
float acc_raw;
float acc_offset;
float max_acc;
float temp_c;

void accel_setup();
void accel_loop();

#endif
