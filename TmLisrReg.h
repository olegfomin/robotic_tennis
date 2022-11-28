#ifndef TM_LISR_REG
#define TM_LISR_REG

#include "TmLisrEnt.h"

class TmLisrReg {
  private:
    TmLisrEnt* tmLisrArr[64] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
                                NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
                                NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
                                NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    int size = 0;
  public:  
    TmLisrReg();
    bool regEntry(TmLisrEnt* tmLisrEnt);
    void feed(unsigned int tn);
    /* Finding the entry by a unique name */
    TmLisrEnt* findByName(char const *tmEntNm);    
};

#endif
