#ifndef lcd16x2_h
#define lcd16x2_h

#include <string>

using namespace std;

class Lcd16x2 {
  private:
    int DEFAULT_CYCLES_TO_LIGHT = 50;
    bool   isDirty = false;
    bool   playSound = false;
    bool   lightIsOn = false;
    int    cyclesToLight = 1000; 
    char*  line1;
    char*  line2;
  public:
    Lcd16x2();
    void init();
    void setLine1(char* line1);
    void setLine2(char* line2);
    void sound();
    void backLit();
    void render();
//    void lightControl(int aMainCounter);    
    
};

char* stringIntoCharArray(string s);

#endif
