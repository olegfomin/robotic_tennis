#ifndef LISR_ENT
#define LISR_ENT


#include "Listener.h"
#include <Arduino.h>
#include <limits.h>

/* The listener entry contains the common attributes for both digitalRead and Time elapsed/period entries.
   It is used as a super class that is then used inside LisrReg (Listener Register) method */

class LisrEnt {
  protected:
    char*        entNm = const_cast<char*> ("unidentified"); // entry name
    Listener*    lisr; // event Listener
    bool         isActive; // if true then this entry is active
    unsigned int deafIntl; // Deaf interval during which the entry becomes insensitive to any signals  
    virtual void innerFeed(unsigned int tn);   
  public:  
    LisrEnt(const char* entNm, unsigned int deafIntl, Listener* lisr); // constructor 
    char* getEntNm(); // access methods
    unsigned int getDeafIntl();
    Listener*    getLisr();
    virtual void activate(); // Makes the method active
    void         deactivate(); // deactivates the entry
    void         feed(unsigned int tn); // Gets invoked with every loop() tick
    virtual void setup();
};


/* Time Entry contains two delay periods in ticks that are applied one after another*/
class TmLisrEnt : public LisrEnt {
  private:
    unsigned int howMany = INT_MAX; // how many times it switches on and off (on->off sequence is cosidered to decrement one) 
    bool         isPrid1Engd = true; // 'true' means first period i.e. perion1 will be used otherwise period2 will be used to find the next 'when' value 
    unsigned int period1 = INT_MAX; // Period in which it runs first time
    bool         isFirstTime=true;
    char* zero = const_cast<char*>("0");
    char* one  = const_cast<char*>("1");
    unsigned int cntrDown = INT_MAX; // count down for periods
  protected:
     virtual void innerFeed(unsigned int tn);   
  public:
    TmLisrEnt(const char* timeEntryName, Listener* listener); // The timer is infinity, it shall never flip by itself
    TmLisrEnt(const char* timeEntryName, unsigned int period, Listener* listener); // constructor with 'symmetrical' periods
    TmLisrEnt(const char* timeEntryName, unsigned int period1, unsigned int period2, Listener* listener); // constructor with 'non-symmetrical' periods
    char* getEntNm();
    void feed(unsigned int tickNumber); // Decides whether to call listener depending upon 'when' value and then flips isFirstPeriod 
    void activate(); // activates the time entry thus feedTick call would call Listener
    void activate(unsigned int howMany); // activates the time entry for the certain amount of ON and OFFs thus feedTick would call Listener for so many times 
    void deactivate(); // deactivate the time entry thus feedTick does nothing. It also sets isFirstPeriod flag to true 
    ~TmLisrEnt();
    virtual void setup();

};

class BtnLisrEnt : public LisrEnt {
  private:
    int pcn; // Pin contact number
  protected:
    unsigned when=0; // When in fires next time
    virtual void innerFeed(unsigned int tn);   
  public:
    BtnLisrEnt(const char* entNm, int pcn, unsigned int deafIntl, Listener* lisr);
    virtual void setup(); 
};

#endif
