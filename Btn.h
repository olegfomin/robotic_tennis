#ifndef BUTTON_H
#define BUTTON_H

using namespace std;

typedef void (*buttonDownFunction)();
/* This class is designed to listen to a button press event */
class Btn {
  private:
    int TRANSACTION_COMPLETED_ON_COUNTER = 2584;
    volatile int start_counter=0;
    volatile bool isButtonToBePressed = false;
 
    
    buttonDownFunction buttonDown;

    void reset();
  public:
    Btn(buttonDownFunction f); // button pressed function argument 
    void synch(int mainCounter);
    void pressReceived(int mainCounter);
    void buttonPressed();
      
};

#endif
