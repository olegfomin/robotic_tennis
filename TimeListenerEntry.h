#ifndef TIME_LISTENER_ENTRY
#define TIME_LISTENER_ENTRY

#include <limits.h>
#include "Listener.h"

/* Time Entry contains two delay periods in ticks that are applied one after another*/
class TimeListenerEntry {
  private:
    char*        timeEntryName = const_cast<char*> ("unidentified"); // The unique name for the time entry
    unsigned int howMany = INT_MAX; // how many times it switches on and off (on->off sequence is cosidered to decrement one) 
    bool         isPeriod1Engaged = true; // 'true' means first period i.e. perion1 will be used otherwise period2 will be used to find the next 'when' value 
    unsigned int period1 = INT_MAX; // Period in which it runs first time
    unsigned int period2 = INT_MAX; // Period in which it runs second time
    Listener*    listener;        // the class that gets called if the time is due   
    bool         isActive=false;        // if true then active if false passive
    bool         isFirstTime=true;
    char* zero = const_cast<char*>("0");
    char* one  = const_cast<char*>("1");
    unsigned int cntrDown = INT_MAX; // count down for periods

  public:
    TimeListenerEntry( const char* timeEntryName, unsigned int period, Listener* listener); // constructor with 'symmetrical' periods
    TimeListenerEntry(const char* timeEntryName, unsigned int period1, unsigned int period2, Listener* listener); // constructor with 'non-symmetrical' periods
    char* getEntryName();
    void feed(unsigned int tickNumber); // Decides whether to call listener depending upon 'when' value and then flips isFirstPeriod 
    void activate(); // activates the time entry thus feedTick call would call Listener
    void activate(unsigned int howMany); // activates the time entry for the certain amount of ON and OFFs thus feedTick would call Listener for so many times 
    void deactivate(); // deactivate the time entry thus feedTick does nothing. It also sets isFirstPeriod flag to true 
    ~TimeListenerEntry();
};

#endif
