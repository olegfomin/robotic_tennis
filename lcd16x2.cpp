#include "lcd16x2.h"

#include <string>
#include <Arduino.h>
using namespace std;


Lcd16x2::Lcd16x2() {
};

void Lcd16x2::init() {
  Serial3.begin(9600);
  delay(1000);
};

void Lcd16x2::setLine1(char* line1) {
  strcpy(this->line1, line1);
  isDirty = true;
};

void Lcd16x2::setLine2(char* line2) {
  strcpy(this->line2, line2);
  isDirty = true;
}

void Lcd16x2::sound() {
  playSound = true; // 294 D note
  isDirty = true;
}

void Lcd16x2::backLit() {
  cyclesToLight = DEFAULT_CYCLES_TO_LIGHT; 
}

void Lcd16x2::render() {
 
  if(isDirty) {
     Serial3.write(12);
     delay(10);
     Serial3.write(22);
     delay(10);
     Serial3.write(line1);
     Serial3.write(line2);
     if(playSound) {
        Serial3.write(144);
        Serial3.write(17);
        delay(144);
        Serial3.write(18);
        delay(21); 
        playSound = false;
     } 
     delay(144);
  } 
  isDirty = false;   
}
