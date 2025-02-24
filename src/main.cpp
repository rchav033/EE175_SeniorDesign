#include <Arduino.h>
#include <TinyGPS.h>

#include "LED_Control.h"
#include "GyroSensor.h"
#include "GPS_Module.h"

void setup() {
  LED_Control();
  initialize_gyro();
  setupGPS();

}
void loop() {
  gyro_signals();
    RateRoll -= RateCalibrationRoll;
    RatePitch -= RateCalibrationPitch;
    RateYaw -= RateCalibrationYaw;
    loopGPS();
}