#include"LED_Control.h"
#include <Arduino.h>
void LED_Control() {
  pinMode(5, OUTPUT);
  digitalWrite(5,HIGH);

  delay(4000);
  
  digitalWrite(5,LOW);
  pinMode(6, OUTPUT);
  digitalWrite(6,HIGH);
}
