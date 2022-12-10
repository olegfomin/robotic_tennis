#ifndef LISR_ENT
#define LISR_ENT

#include "Listener.h"
#include <Arduino.h>

/* The listener entry contains the common attributes for both digitalRead and Time elapsed/period entries.
   It is used as a super class that is then used inside LisrReg (Listener Register) method */

class LisrEnt {
  private:
    char*        entNm; // entry name
    unsigned int deafIntl; // Deaf interval during which the entry becomes insensitive to any signals  
    Listener*    lisr; // event Listener
    bool         isActive; // if true then this entry is active
  protected:
    virtual void innerFeed(unsigned int tn);   
  public:  
    LisrEnt(char* entNm, unsigned intdeafIntl, Listener* lisr); // constructor 
    char* getEntNm(); // access methods
    unsigned int getDeafIntl();
    Listener*    getLisr();
    void         activate(); // Makes the method active
    void         deactivate(); // deactivates the entry
    void         feed(unsigned int tn); // Gets invoked with every loop() tick    
};

#endif
