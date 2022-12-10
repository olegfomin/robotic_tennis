#include "LisrEnt.h"

LisrEnt::LisrEnt(char* entNm, unsigned int deafIntl, Listener* lisr) { // constructor
  this->entNm = entNm;  
  this->deafIntl = deafIntl;
  this->lisr = lisr;
}

// access methods below
char* LisrEnt::getEntNm() {
  return entNm; 
}

unsigned int LisrEnt::getDeafIntl() {
  return deafIntl;
}

Listener* LisrEnt::getLisr() {
  return lisr;
}

void LisrEnt::activate() { // Makes the method active
  isActive = true;
}; 

void LisrEnt::deactivate() { // deactivates the entry
  isActive = false;
}

void LisrEnt::feed(unsigned int tn) { // Gets invoked with every loop() tick
  if(isActive) {
    innerFeed(tn);
  }
  
};     
