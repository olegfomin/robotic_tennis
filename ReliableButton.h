#ifndef RELIABLE_BUTTON_H
#define RELIABLE_BUTTON_H

#include <vector>

using namespace std;

typedef void (*buttonDownFunction)();

class ReliableButton {
  private:
    int TRANSACTION_COMPLETED_ON_COUNTER = 2584;
    volatile int start_counter=0;
    volatile bool isButtonToBePressed = false;
 
    
    buttonDownFunction buttonDown;

    void reset();
  public:
    ReliableButton(buttonDownFunction f); // button pressed function argument 
    void synch(int mainCounter);
    void pressReceived(int mainCounter);
    void buttonPressed();
      
};

#endif
