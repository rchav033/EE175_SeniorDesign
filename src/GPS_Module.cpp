#include "GPS_Module.h"
#include <SoftwareSerial.h>
// Define the GPS object and SoftwareSerial
TinyGPS gps;
SoftwareSerial ss(0, 1); // RX, TX pins

// Setup function to initialize GPS and serial communication
void setupGPS() {
  Serial.begin(9600);
  ss.begin(9600);
  
  Serial.print("Simple TinyGPS library v. "); 
  Serial.println(TinyGPS::library_version());
  Serial.println("by Mikal Hart");
  Serial.println();
}

// Loop function to read GPS data and print it
void loopGPS() {
  bool newData = false;
  unsigned long chars;
  unsigned short sentences, failed;

  // For one second we parse GPS data and report some key values
  for (unsigned long start = millis(); millis() - start < 1000;) {
    while (ss.available()) {
      char c = ss.read();
      //Serial.println(c);
      if (gps.encode(c)) // Did a new valid sentence come in?
        newData = true;
    }
  }

  if (newData) {
    float flat, flon;
    unsigned long age;
    gps.f_get_position(&flat, &flon, &age);
    Serial.print("LAT= ");
    Serial.println(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6);
    Serial.print(" LON= ");
    Serial.println(flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6);
    Serial.print(" SAT= ");
    Serial.println(gps.satellites() == TinyGPS::GPS_INVALID_SATELLITES ? 0 : gps.satellites());
    Serial.print(" PREC= ");
    Serial.println(gps.hdop() == TinyGPS::GPS_INVALID_HDOP ? 0 : gps.hdop());
  }

  gps.stats(&chars, &sentences, &failed);
  Serial.print(" CHARS= ");
  Serial.println(chars);
  Serial.print(" SENTENCES= ");
  Serial.println(sentences);
  Serial.print(" CSUM ERR= ");
  Serial.println(failed);

  if (chars == 0)
    Serial.println("** No characters received from GPS: check wiring **");
}
