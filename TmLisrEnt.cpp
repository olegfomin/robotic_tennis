#include "TmLisrEnt.h"
#include <strings.h>

// Making a time entry with symmetrical period
TmLisrEnt::TmLisrEnt(const char* timeEntryName, unsigned int period, Listener* listener) {
  this->timeEntryName = const_cast<char*>(timeEntryName);
  this->period1 = period;
  this->period2 = period;
  this->listener = listener;
};

// Making a time entry with asymmetrical period
TmLisrEnt::TmLisrEnt(const char* timeEntryName, unsigned int period1, unsigned int period2, Listener* listener) {
  this->timeEntryName = const_cast<char*>(timeEntryName);
  this->period1 = period1;
  this->period2 = period2;
  this->listener = listener;
};

// Triggers the listener if the tick is due and the entry is active
void TmLisrEnt::feed(unsigned int tn) {
   if(isActive) {
     if(howMany > 0) {
       if(isFirstTime) {
           listener->onEvent(tn, timeEntryName, zero);
           isFirstTime = false;
       }
       if(cntrDown <= 0) { // time to flip the periods over
         if(isPrid1Engd) {
           listener->onEvent(tn, timeEntryName, one);
           cntrDown = period2;     
           howMany = (howMany==INT_MAX) ? INT_MAX : --howMany;
         } else {
           listener->onEvent(tn, timeEntryName, zero);
           cntrDown = period1;     
         }
         isPrid1Engd =! isPrid1Engd;
       }
       cntrDown--; // reducing counter down
     } else {
       isActive = false;
     };
   };
};

char* TmLisrEnt::getEntryName() {
  return this->timeEntryName;
}

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
