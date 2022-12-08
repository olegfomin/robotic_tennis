/* Subject or Observable calls an appropriate Listener if the associated pin goes up */

#include "Subj.h"
#include <Arduino.h>

Subj::Subj() {
  
}

void Subj::setup() {
  for(int i=0; i < arrSize; i++) {
    PinInrl* pinInrl = this->pinInrl[i];
    pinMode(pinInrl->pcn, INPUT);
  };   
};

bool Subj::reg(int pcn, unsigned int muteInrl, Listener* listener) {
  PinInrl* pinInrl = new PinInrl();
  pinInrl->pcn = pcn; // Pin contact number
  pinInrl->muteInrl = muteInrl; // the interval in ticks during which the data from the pin is not accepted
  pinInrl->when = 0; // When in fires next time
  pinInrl->listener = listener; 
    
  if(arrSize > MAX_SIZE-1) return false; 
  this->pinInrl[arrSize] = pinInrl;
  arrSize++;
};

void Subj::feed(unsigned int tn) {
  for(int i=0; i < arrSize; i++) {
    PinInrl* pinInrl = this->pinInrl[i];
    int pin = pinInrl->pcn;
    int value = digitalRead(pin);
    if(value == HIGH) {
      if(tn > pinInrl->when) {
        char* pchar="          ";
        itoa(pin, pchar, 10);
        pinInrl->listener->onEvent(tn, pchar, "HIGH");
        pinInrl->when = tn+pinInrl->muteInrl;
        pinInrl->highButMuted = false; 
      } else {
        pinInrl->highButMuted = true;
      }
    } else {
/*      if(pinInrl->highButMuted) {
        pinInrl->highButMuted = false; // button has been released so the new events are welcome
        pinInrl->when = tn; 
      }  */
    }
  }
};
