#ifndef TM_LISR_REG
#define TM_LISR_REG

#include "LisrEnt.h"

/* This registry is somewhat a factory that generates LisrEnr for either time based oscilator or push button stream */
class LisrReg {
  private:
    LisrEnt* lisrArr[64] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
                            NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
                            NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
                            NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    int size = 0;
  public:  
    LisrReg();
    void setup();
    /* This constuctor takes two time periods, the first is for on-period and deafPrid is off period, it calls listener.onEvent(...) after all lisrEnt.howMany' 'on-periods' are executed */
    LisrEnt* regTmEnr(const char* name, unsigned int onPrid, unsigned int deafPrid, Listener* listener);
    /* This constuctor takes only on time periods, that makes 'on-period' and 'off-period' to be equal */
    LisrEnt* regTmEnr(char* name, unsigned int onPrid, Listener* listener);
    void feed(unsigned int tn);
    /* Finding the entry by a unique name */
    LisrEnt* findByName(char const *entNm);    
};

#endif
