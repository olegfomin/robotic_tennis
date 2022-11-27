#include "TimeListenerEntry.h"
#include <strings.h>

// Making a time entry with symmetrical period
TimeListenerEntry::TimeListenerEntry(const char* timeEntryName, unsigned int when, unsigned int period, Listener* listener) {
  this->timeEntryName = const_cast<char*>(timeEntryName);
  this->when = when;
  this->period1 = period;
  this->period2 = period;
  this->listener = listener;
};

// Making a time entry with asymmetrical period
TimeListenerEntry::TimeListenerEntry(char* timeEntryName, unsigned int when, unsigned int period1, unsigned int period2, Listener* listener) {
  this->timeEntryName = timeEntryName;
  this->when = when;
  this->period1 = period1;
  this->period2 = period2;
  this->listener = listener;
};

// Triggers the listener if the tick is due and the entry is active
void TimeListenerEntry::feed(unsigned int crntTick) {
   unsigned int crntPrid = isFirstPeriod ? period1 : period2;
   if(crntTick%crntPrid == 0 && crntTick > when) {
    if(isActive) {
       listener->onEvent(crntTick, timeEntryName, (isFirstPeriod ? zero : one));
       isFirstPeriod =! isFirstPeriod;
    };
  };
};

/* Make entry susceptible to feedTick method that calls the listener */
void TimeListenerEntry::activate() {
  isActive = true;
};
/*  Switches the time entry off (by default) */
void TimeListenerEntry::deactivate() {
  isActive = false;
};

TimeListenerEntry::~TimeListenerEntry() {
  // Nothing to do here yet
}
