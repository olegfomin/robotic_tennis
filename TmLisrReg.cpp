#include "TmLisrReg.h"

TmLisrReg::TmLisrReg() {
  
}

bool TmLisrReg::regEntry(TmLisrEnt* tmLisrEnt) {
  if(size < 64) {
    tmLisrArr[size] = tmLisrEnt;
    size++;
    return true;
  } else {
    return false;  
  }
}

void TmLisrReg::feed(unsigned int tn) {
  for(int i=0; i < size; i++) {
      tmLisrArr[i]->feed(tn);
  };
};

TmLisrEnt* TmLisrReg::findByName(char const* tmEntNm) {
  TmLisrEnt* result = NULL;  
  for(int i=0; i < size; i++) {
    int cmpRes = strcmp(tmEntNm,tmLisrArr[i]->getEntryName());
    if(cmpRes == 0) {
      result = tmLisrArr[i];
      break;
    };
  };
  return result;
};
