#include "LisrEnt.h"

LisrEnt::LisrEnt(const char* entNm, unsigned int deafIntl, Listener* lisr) { // constructor
  this->entNm = const_cast<char*>(entNm);  
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

void LisrEnt::setup() {
  
}

     // Making a time entry with symmetrical period
TmLisrEnt::TmLisrEnt(const char* timeEntryName, unsigned int period, Listener* listener) : LisrEnt(timeEntryName, period, listener) {
  this->period1 = period;
};

// Making a time entry with asymmetrical period
TmLisrEnt::TmLisrEnt(const char* timeEntryName, unsigned int period1, unsigned int period2, Listener* listener) : LisrEnt(timeEntryName, period2, listener) {
  this->period1 = period1;
};

// Triggers the listener if the tick is due and the entry is active
void TmLisrEnt::innerFeed(unsigned int tn) {
   if(howMany > 0) {
     if(isFirstTime) {
         lisr->onEvent(tn, entNm, zero);
         isFirstTime = false;
     }
     if(cntrDown <= 0) { // time to flip the periods over
       if(isPrid1Engd) {
         lisr->onEvent(tn, entNm, one);
         cntrDown = deafIntl;     
         howMany = (howMany==INT_MAX) ? INT_MAX : --howMany;
       } else {
         lisr->onEvent(tn, entNm, zero);
         cntrDown = period1;     
       }
       isPrid1Engd =! isPrid1Engd;
     }
     cntrDown--; // reducing counter down
   };
};

/* Make entry susceptible to feedTick method that calls the listener */
void TmLisrEnt::activate() {
  howMany = INT_MAX;
  isActive = true;
  cntrDown = period1;
  isPrid1Engd = true;
  isFirstTime=true;
};

/* Make entry susceptible to feedTick method that calls the listener for so many times */
void TmLisrEnt::activate(unsigned int howMany) {
  activate();
  this->howMany = howMany;
};

/*  Switches the time entry off (by default) */
void TmLisrEnt::deactivate() {
  isActive = false;
};

TmLisrEnt::~TmLisrEnt() {
  // Nothing to do here yet
}
