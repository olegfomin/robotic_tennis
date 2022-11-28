#include <Arduino.h>
#include "Listener.h"

void Listener::onEvent(unsigned int tickNumber, char* entryName, char* param) {
  Serial.println(entryName);
  Serial.println("Got Trigerred! That is unwanted behaviour");
};


/* Constuctor storing Pin Contact Number as an attribute */
MomrSwitLisr::MomrSwitLisr(int pcn) {
  this->pcn = pcn;
}

void MomrSwitLisr::onEvent(unsigned int tn, char* entryName, char* param) {
  int result = strcmp (param, zero);
  digitalWrite(pcn, result==0 ? HIGH : LOW);
}
