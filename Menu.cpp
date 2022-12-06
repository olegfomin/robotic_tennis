#include "Menu.h"


  Menu::Menu() {
    allItems.clear();
    
    allItems.push_back(" Reached borders");
    allItems.push_back(" Reached borders");
    allItems.push_back(" 10/10 forw bck"); // Go forward and then backward 10 left and 10 right revolutions
    allItems.push_back(" 10/11 forw bck");
    allItems.push_back(" 10/12 forw bck");
    allItems.push_back(" 11/10 forw bck");
    allItems.push_back(" 12/10 forw bck");
    allItems.push_back(" 8/13 forward 3"); // Go 3 laps forward with 8 left 13 right ratio
    allItems.push_back(" 13/8 forward 3");
    allItems.push_back(" 13/21 forward3"); // Go 3 laps forward with 13 left 21 right ratio
    allItems.push_back(" 21/13 forward3");

    allItems.push_back(" Left 0.1% slow");
    allItems.push_back(" Left 0.2% slow");
    allItems.push_back(" Left 0.3% slow");
    allItems.push_back(" Left 0.5% slow");
    allItems.push_back(" Left 0.8% slow");

    allItems.push_back(" Right 0.1% slw");
    allItems.push_back(" Right 0.2% slw");
    allItems.push_back(" Right 0.3% slw");
    allItems.push_back(" Right 0.5% slw");
    allItems.push_back(" Right 0.8% slw");

    allItems.push_back(" Show calibrati"); // Show calibration

    allItems.push_back(" Reached borders");
    allItems.push_back(" Reached borders");

  };

  void Menu::testPrint(TwoElements* twoElements) {
   Serial.println(twoElements->line1);
   Serial.println(twoElements->line2);
  }; 

  TwoElements* Menu::valueAtCurrentPosition() {
    TwoElements* theTwoElements = new TwoElements();

    pointer = currentPosition;
    
    strncpy(theTwoElements->line1, allItems.at(currentPosition), 21);
    strncpy(theTwoElements->line2, allItems.at(currentPosition+1), 21);
    

    if(currentPosition > 1 && currentPosition < 30) {
      theTwoElements->line1[0] = '>';
      theTwoElements->lineNumber= 1;
    } else {
      if(currentPosition == 1) { 
        theTwoElements->line2[0] = '>';
        pointer = currentPosition+1;   
        theTwoElements->lineNumber= 2;
      }
    }
    
    theTwoElements->positionNumber= pointer; 
    
    return theTwoElements; 
    
  };

  TwoElements* Menu::moveUp() {
    if(currentPosition > 0) currentPosition--;
    return valueAtCurrentPosition();
  };

  TwoElements* Menu::moveDown(){
    if(currentPosition < allItems.size()-2) currentPosition++;
    return valueAtCurrentPosition();
  };

  int Menu::size() {
     return allItems.size();
  };

  
