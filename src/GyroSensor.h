#ifndef GYRO_SENSOR_H
#define GYRO_SENSOR_H

#include <Wire.h>

// Global Variables for Gyroscope Data
extern float RateRoll, RatePitch, RateYaw;
extern float RateCalibrationRoll, RateCalibrationPitch, RateCalibrationYaw;
extern int RateCalibrationNumber;

// Function Declarations
void gyro_signals();
void initialize_gyro();

#endif  // GYRO_SENSOR_H
