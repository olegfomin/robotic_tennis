#include "ReliableButton.h"

ReliableButton::ReliableButton(buttonDownFunction f) {
  ; // button pressed function argument 
  buttonDown = f;
}

void ReliableButton::synch(int mainCounter) {
  if(start_counter == 0) start_counter = mainCounter;
  if(mainCounter - start_counter > TRANSACTION_COMPLETED_ON_COUNTER) { 
    start_counter = mainCounter;
    if(isButtonToBePressed) buttonPressed();
  }
}

void ReliableButton::pressReceived(int mainCounter) {
   isButtonToBePressed = true;
}

void ReliableButton::buttonPressed() {
     buttonDown();
     isButtonToBePressed = false;
     reset();
}

void ReliableButton::reset() {
    start_counter=0;
    isButtonToBePressed = false;
}
