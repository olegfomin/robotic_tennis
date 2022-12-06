#ifndef Menu_h
#define Menu_h

#include <vector>
#include <Arduino.h>

using namespace std;

struct TwoElms {
  public:
  char line1[21]={0};
  char line2[21]={0};
  int lineNumber = 1; // One or two
  int positionNumber = 0;
};

class Menu {
  private:
    char marker = '>';
    int pointer = 1; // pointer for the marker
    vector<char*> allItems; 
    int currentPosition=0;
    int size(); 
    void testPrint(TwoElements* twoElements);

  public:   
    TwoElms* valueAtCurrentPosition();

    Menu(); 

    TwoElms* moveUp();

    TwoElms* moveDown();
}; 

#endif
