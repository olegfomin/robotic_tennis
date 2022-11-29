#include "SimpleMenu.h"


  SimpleMenu::SimpleMenu() {
    allItems.clear();
    
    allItems.push_back(" Reached borders");
    allItems.push_back(" Reached borders");
    allItems.push_back(" Slow left motrs");
    allItems.push_back(" Slow rite motrs");
    allItems.push_back(" Slow both motrs");
    allItems.push_back(" Med.left motors");
    allItems.push_back(" Med.rite motors");
    allItems.push_back(" Med. both motrs");
    allItems.push_back(" High left motrs");
    allItems.push_back(" High rite motrs");
    allItems.push_back(" High both motrs");

    allItems.push_back(" Count left mtrs");
    allItems.push_back(" Count rite mtrs");
    allItems.push_back(" Count both mtrs");

    allItems.push_back(" Stop left motrs");
    allItems.push_back(" Stop rite motrs");
    allItems.push_back(" Stop both motrs");

    allItems.push_back(" Auto Calibratin");
    allItems.push_back(" Left 0.1%  slow");
    allItems.push_back(" Left 0.2%  slow");
    allItems.push_back(" Left 0.3%  slow");
    allItems.push_back(" Left 0.5%  slow");
    allItems.push_back(" Left 0.8%  slow");

    allItems.push_back(" Right 0.1% slow");
    allItems.push_back(" Right 0.2% slow");
    allItems.push_back(" Right 0.3% slow");
    allItems.push_back(" Right 0.5% slow");
    allItems.push_back(" Right 0.8% slow");

    allItems.push_back(" Reset left motr");
    allItems.push_back(" Reset rite motr");

    allItems.push_back(" Reached borders");
    allItems.push_back(" Reached borders");

  };

  void SimpleMenu::testPrint(TwoElements* twoElements) {
   Serial.println(twoElements->line1);
   Serial.println(twoElements->line2);
  }; 

  TwoElements* SimpleMenu::valueAtCurrentPosition() {
    TwoElements* theTwoElements = new TwoElements();
//    Serial.println(currentPosition);

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
//    testPrint(theTwoElements);
    
    return theTwoElements; 
    
  };

  TwoElements* SimpleMenu::moveUp() {
    if(currentPosition > 0) currentPosition--;
    return valueAtCurrentPosition();
  };

  TwoElements* SimpleMenu::moveDown(){
    if(currentPosition < allItems.size()-2) currentPosition++;
    return valueAtCurrentPosition();
  };



  int SimpleMenu::size() {
     return allItems.size();
  };

  
