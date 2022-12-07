#ifndef Menu_h
#define Menu_h

#include <vector>
#include <Arduino.h>

using namespace std;

struct TwoElms {
  public:
  char line1[21]={0};
  char line2[21]={0};
};

class Menu {
  private:
    static const char MARKER = '>'; 
    vector<char*> allItems;
    int crntPos = 0; 
    int idx1    = 0;
    int idx2    = 1;
    int size(); 

  public:   
    TwoElms* valueAtCurrentPosition();

    Menu(); 

    TwoElms* moveUp();

    TwoElms* moveDown();
}; 

#endif
