#ifndef LISTENER
#define LISTENER

#include <Arduino.h>

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

/* When the button UP is pushed this listener receives onEvent(...)*/
class BtnUpLisr : public Listener {
  int pcn=0;
  public:
    BtnUpLisr(int pcn);  
    virtual void onEvent(unsigned int tn, char* entryName, char* param);
    ~BtnUpLisr();
};

/* When the button DOWN is pushed this listener receives onEvent(...)*/
class BtnDownLisr : public Listener {
  int pcn=0;
  public: 
    BtnDownLisr(int pcn);  
    virtual void onEvent(unsigned int tn, char* entryName, char* param);
};

/* when the button enter is pushed then this */ 
class BtnEnrLisr : public Listener {
  int pcn=0;
  public:  
    BtnEnrLisr(int pcn);  
    virtual void onEvent(unsigned int tn, char* entryName, char* param);
};




#endif
