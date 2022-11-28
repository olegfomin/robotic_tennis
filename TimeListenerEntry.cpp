#include "TimeListenerEntry.h"
#include <strings.h>

// Making a time entry with symmetrical period
TimeListenerEntry::TimeListenerEntry(const char* timeEntryName, unsigned int period, Listener* listener) {
  this->timeEntryName = const_cast<char*>(timeEntryName);
  this->period1 = period;
  this->period2 = period;
  this->listener = listener;
};

// Making a time entry with asymmetrical period
TimeListenerEntry::TimeListenerEntry(const char* timeEntryName, unsigned int period1, unsigned int period2, Listener* listener) {
  this->timeEntryName = const_cast<char*>(timeEntryName);
  this->period1 = period1;
  this->period2 = period2;
  this->listener = listener;
};

// Triggers the listener if the tick is due and the entry is active
void TimeListenerEntry::feed(unsigned int crntTick) {
   if(isActive) {
     if(howMany > 0) {
       if(isFirstTime) {
           listener->onEvent(crntTick, timeEntryName, zero);
           isFirstTime = false;
       }
       if(cntrDown <= 0) { // time to flip the periods over
         if(isPeriod1Engaged) {
           listener->onEvent(crntTick, timeEntryName, one);
           cntrDown = period2;     
           howMany = (howMany==INT_MAX) ? INT_MAX : --howMany;
         } else {
           listener->onEvent(crntTick, timeEntryName, zero);
           cntrDown = period1;     
         }
         isPeriod1Engaged =! isPeriod1Engaged;
       }
       cntrDown--;
     } else {
       isActive = false;
     };
   };
};

char* TimeListenerEntry::getEntryName() {
  return this->timeEntryName;
}

/* Make entry susceptible to feedTick method that calls the listener */
void TimeListenerEntry::activate() {
  howMany = INT_MAX;
  isActive = true;
  cntrDown = period1;
  isPeriod1Engaged = true;
  isFirstTime=true;
};

/* Make entry susceptible to feedTick method that calls the listener for so many times */
void TimeListenerEntry::activate(unsigned int howMany) {
  activate();
  this->howMany = howMany;
};

/*  Switches the time entry off (by default) */
void TimeListenerEntry::deactivate() {
  isActive = false;
};

TimeListenerEntry::~TimeListenerEntry() {
  // Nothing to do here yet
}
