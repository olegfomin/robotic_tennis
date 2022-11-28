#include "TimeListenerRegistry.h"

TimeListenerRegistry::TimeListenerRegistry() {
  
}

bool TimeListenerRegistry::registerEntry(TimeListenerEntry* timeListenerEntry) {
  if(size < 64) {
    timeListenerArray[size] = timeListenerEntry;
    size++;
    return true;
  } else {
    return false;  
  }
}

void TimeListenerRegistry::feed(unsigned int tickNumber) {
  for(int i=0; i < size; i++) {
      timeListenerArray[i]->feed(tickNumber);
  };
};

TimeListenerEntry* TimeListenerRegistry::findByName(char const* tmEntNm) {
  TimeListenerEntry* result = NULL;  
  for(int i=0; i < size; i++) {
    int cmpRes = strcmp(tmEntNm,timeListenerArray[i]->getEntryName());
    if(cmpRes == 0) {
      result = timeListenerArray[i];
      break;
    };
  };
  return result;
};
