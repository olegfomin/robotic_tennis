#ifndef TIME_LISTENER_ENTRY
#define TIME_LISTENER_ENTRY

#include <limits.h>
#include "Listener.h"

/* Time Entry contains two delay periods in ticks that are applied one after another*/
class TimeListenerEntry {
  private:
    char*        timeEntryName = const_cast<char*> ("unidentified"); // The unique name for the time entry
    unsigned int when = INT_MAX; // when it runs for the first time
    bool         isFirstPeriod = true; // 'true' means first period i.e. perion1 will be used otherwise period2 will be used to find the next 'when' value 
    unsigned int period1 = 10000; // Period in which it runs first time
    unsigned int period2 = 10000; // Period in which it runs second time
    Listener*    listener;        // the class that gets called if the time is due   
    bool         isActive=false;        // if true then active if false passive
    char* zero = const_cast<char*>("0");
    char* one  = const_cast<char*>("1");

  public:
    TimeListenerEntry(const char* timeEntryName, unsigned int when, unsigned int period, Listener* listener); // constructor with 'symmetrical' periods
    TimeListenerEntry(char* timeEntryName, unsigned int when, unsigned int period1, unsigned int period2, Listener* listener); // constructor with 'non-symmetrical' periods
    void feed(unsigned int tickNumber); // Decides whether to call listener depending upon 'when' value and then flips isFirstPeriod 
    void activate(); // activates the time entry thus feedTick call would call Listener when the time comes
    void deactivate(); // deactivate the time entry thus feedTick does nothing. It also sets isFirstPeriod flag to true 
    ~TimeListenerEntry();
};

#endif
