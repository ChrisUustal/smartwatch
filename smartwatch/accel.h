//accel.h
#ifndef ACCEL_H
#define ACCEL_H

enum TempUnit {f, c};
TempUnit temp_unit;

Adafruit_MPU6050 mpu;

bool accel_present;

float acc;
float acc_raw;
float acc_offset;
float max_acc;
float temp_c;

void accel_setup();
void accel_loop();
void accel_zero_event();
void accel_unzero_event();
void temp_toggle_unit();

#endif
