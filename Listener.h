#ifndef LISTENER
#define LISTENER

#include <Arduino.h>
#include "Menu.h"
#include "lcd16x2.h"

/* Set of Listener classes that are being invoked by the Observers as a result of some event like pushing of a button or certain time elapsed */
class Listener {
  public:
    virtual void onEvent(unsigned int tickNumber, char* entryName, char* param); 
};

/* This listener acts like mometory switch and it invokes digitalWrite(pinContactNumber, HIGH) when param='0' thus period1 starts */
class MomrSwitLisr : public Listener {
  private:
    int pcn=0;
    char* zero = const_cast<char*>("0");
    char* one  = const_cast<char*>("1");
  public: 
    MomrSwitLisr();
    MomrSwitLisr(int pinContactNumber);
    virtual void onEvent(unsigned int tn, char* entryName, char* param);
    ~MomrSwitLisr(); 
};

// Generic Button Push class. It holds Menu and Display. TODO: It is a beginning of spagetty code it should be refactored if this trend continue here  
class BtnLisr : public Listener {
  protected:
    Menu* menu;
    Lcd16x2* lcd16x2;
  public:
    BtnLisr(Menu* menu, Lcd16x2* lcd16x2);
};

/* When the button UP is pushed this listener receives onEvent(...)*/
class BtnUpLisr : public BtnLisr {
  public:
    BtnUpLisr(Menu* menu, Lcd16x2* lcd16x2);  
    virtual void onEvent(unsigned int tn, char* entryName, char* param);
    ~BtnUpLisr();
};

/* When the button DOWN is pushed this listener receives onEvent(...)*/
class BtnDownLisr : public BtnLisr {
  public: 
    BtnDownLisr(Menu* menu, Lcd16x2* lcd16x2);  
    virtual void onEvent(unsigned int tn, char* entryName, char* param);
};

/* when the button enter is pushed then this */ 
class BtnEnrLisr : public BtnLisr {
  public:  
    BtnEnrLisr(Menu* menu, Lcd16x2* lcd16x2);  
    virtual void onEvent(unsigned int tn, char* entryName, char* param);
};




#endif
