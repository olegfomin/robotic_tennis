#include "LisrReg.h"
#include "TmLisrEnt.h"

LisrReg::LisrReg() {
  
}
LisrEnt* LisrReg::regTmEnr(const char* name, unsigned int onPrid, unsigned int deafPrid, Listener* listener) {
  TmLisrEnt* lisrEnt = NULL; 
  if(size < 64) {
    lisrEnt = new TmLisrEnt(name, onPrid, deafPrid, listener);
    lisrArr[size] = lisrEnt;
    size++;
  }
  return lisrEnt; 
};

LisrEnt* LisrReg::regTmEnr(char* name, unsigned int onPrid, Listener* listener) {
  return regTmEnr(name, onPrid, onPrid, listener);
}

void LisrReg::feed(unsigned int tn) {
  for(int i=0; i < size; i++) {
      lisrArr[i]->feed(tn);
  };
};

void LisrReg::setup() {
  for(int i=0; i < size; i++) {
      lisrArr[i]->setup();
  };
};

LisrEnt* LisrReg::findByName(char const* entNm) {
  LisrEnt* result = NULL;  
  for(int i=0; i < size; i++) {
    int cmpRes = strcmp(entNm,lisrArr[i]->getEntNm());
    if(cmpRes == 0) {
      result = lisrArr[i];
      break;
    };
  };
  return result;
};
