#include <Arduino.h>
#include "Listener.h"

void Listener::onEvent(unsigned int tickNumber, char* entryName, char* param) {
  Serial.println(entryName);
  Serial.println("Got Trigerred! That is unwanted behaviour");
};


/*                             */
MomentarySwitchListener::MomentarySwitchListener(int pinContactNumber) {
  this->pinContactNumber = pinContactNumber;
}

void MomentarySwitchListener::onEvent(unsigned int tickNumber, char* entryName, char* param) {
  Serial.println(param);
  int result = strcmp (param, zero);
  digitalWrite(pinContactNumber, result==0 ? HIGH : LOW);
}
