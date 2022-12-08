#ifndef SUBJECT
#define SUBJECT

#include "Listener.h"

/* Pin number with the period during which this pin becomes insensitive */
struct PinInrl{
  int pcn; // Pin contact number
  unsigned int muteInrl = 50; // the interval in ticks during which the data from the pin is not accepted
  unsigned when; // When in fires next time
  Listener* listener; 
  bool highButMuted=false;
};


/* Observable class registres the pin numbers, delays and listeners so if the button or hall effect sensor or sonar are up then the listener gets called */ 
class Subj {
  private:
    static const int MAX_SIZE = 32;
    int arrSize=0;
    PinInrl *pinInrl[MAX_SIZE] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
                                 NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };
  public:
    Subj();
    void setup();
    bool reg(int pcn, unsigned int muteInrl, Listener* listener);
    void feed(unsigned int tn); // feeding with the current tick number 
};

#endif
