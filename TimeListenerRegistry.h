#ifndef TIME_LISTENER_REGISTRY
#define TIME_LISTENER_REGISTRY

#include "TimeListenerEntry.h"

class TimeListenerRegistry {
  private:
    TimeListenerEntry* timeListenerArray[64] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
                                                NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
                                                NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
                                                NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    int size = 0;
  public:  
    TimeListenerRegistry();
    bool registerEntry(TimeListenerEntry* timeListenerEntry);
    void feed(unsigned int tickNumber);
    /* Finding the entry by a unique name */
    TimeListenerEntry* findByName(char const *tmEntryName);    
};

#endif
