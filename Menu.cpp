#include "Menu.h"



  Menu::Menu() {
    allItems.clear();
    
    allItems.push_back(" Left speed 3"); // 
    allItems.push_back(" Left speed 5");
    allItems.push_back(" Left speed 8");
    allItems.push_back(" Left speed 13");
    allItems.push_back(" Left speed 21");
    allItems.push_back(" Left speed 34"); // 
    
    allItems.push_back(" Right speed 3"); // 
    allItems.push_back(" Right speed 5"); // 
    allItems.push_back(" Right speed 8"); // 
    allItems.push_back(" Right speed 13"); // 
    allItems.push_back(" Right speed 21"); // 
    allItems.push_back(" Right speed 34"); // 
    
    allItems.push_back(" Time 8 second"); // 
    allItems.push_back(" Time 13 second"); // 
    allItems.push_back(" Time 21 second"); // 
    allItems.push_back(" Time 34 second"); // 
    allItems.push_back(" Time 55 second"); // 
    allItems.push_back(" Time 89 second"); // 
    allItems.push_back(" Time 144 secnd"); // 

    allItems.push_back(" Direct forward");
    allItems.push_back(" Direct backwrd");
    allItems.push_back(" Stop");
    

    allItems.push_back(" Then ...");
    allItems.push_back(" Reset"); 
    allItems.push_back(" Start in 3 sec"); // Default speed 5,13,21,forward
    allItems.push_back(" Show route"); 

  };

  TwoElms* Menu::valueAtCurrentPosition() {
    TwoElms* theTwoElements = new TwoElms();

    strncpy(theTwoElements->line1, allItems.at(idx1), 16);
    strncpy(theTwoElements->line2, allItems.at(idx2), 16);
    
    theTwoElements->line1[0] = MARKER;
    
    return theTwoElements; 
    
  };

  TwoElms* Menu::moveUp() {
    crntPos--;
    if(crntPos < 0) { 
      crntPos = size()-1;
      idx1 = crntPos;
      idx2 = 0;
    } else {
      idx1 = crntPos;
      idx2 = idx1 + 1;     
    }
  };

  TwoElms* Menu::moveDown(){
    crntPos++;
    if(crntPos > size()-2) {
      crntPos = 0;
      idx1 = size()-1;
      idx2 = 0;
    } else {
      idx1 = crntPos;
      idx2 = idx1 + 1;     
    }
    
    if(crntPos > allItems.size()-1) crntPos=0;   
  };

  int Menu::size() {
     return allItems.size();
  };

  
