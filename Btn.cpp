#include "Btn.h"

Btn::Btn(buttonDownFunction f) {
  buttonDown = f;
}

void Btn::synch(int mainCounter) {
  if(start_counter == 0) start_counter = mainCounter;
  if(mainCounter - start_counter > TRANSACTION_COMPLETED_ON_COUNTER) { 
    start_counter = mainCounter;
    if(isButtonToBePressed) buttonPressed();
  }
}

void Btn::pressReceived(int mainCounter) {
   isButtonToBePressed = true;
}

void Btn::buttonPressed() {
     buttonDown();
     isButtonToBePressed = false;
     reset();
}

void Btn::reset() {
    start_counter=0;
    isButtonToBePressed = false;
}
