#ifndef GPS_MODULE_H
#define GPS_MODULE_H

#include <TinyGPS.h>
#include <SoftwareSerial.h>

// Define the GPS object and SoftwareSerial
extern TinyGPS gps;
extern SoftwareSerial ss;

// Function prototypes
void setupGPS();
void loopGPS();

#endif // GPS_MODULE_H
