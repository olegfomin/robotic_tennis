#include "Menu.h"



  Menu::Menu() {
    
    allItems[0] = " To From 8ft"; // Straignt going to and then returning from
    allItems[1]=" To From 13ft";
    allItems[2]=" To From 21ft";
    allItems[3]=" To From 34ft";
    allItems[4]=" To From 55ft";
    allItems[5]=" Right turn 8ft"; // start sharp turn rigth
    allItems[6]=" Right turn 13ft"; // 
    allItems[7]=" Right turn 21ft"; // 
    allItems[8]=" Right turn 34ft"; // 
    allItems[9]=" Rigth turn 55ft"; // start long turn rigth
    allItems[10]=" Left turn 8ft"; // start sharp turn left
    allItems[11]=" Left turn 13ft"; // 
    allItems[12]=" Left turn 21ft"; // 
    allItems[13]=" Left turn 34ft"; // 
    allItems[14]=" Left turn 55ft"; // start long turn left 
    allItems[15]=" Circle 13ft cw"; // Making 3 circles 13ft clock wise 
    allItems[16]=" Circle 21ft cw"; // 
    allItems[17]=" Circle 34ft cw"; // 
    allItems[18]=" Circle 13ft acw"; // Making 3 circles 13ft anti-clock wise
    allItems[19]=" Circle 21ft acw"; // 
    allItems[20]=" Circle 34ft acw"; // 
    allItems[21]=" Serpent > 21ft"; // Serpentine route starting with turn right 
    allItems[22]=" Serpent > 34ft"; // 
    allItems[23]=" Serpent > 55ft"; //
    allItems[24]=" Serpent < 21ft"; // Serpentine route starting with turn left 
    allItems[25]=" Serpent < 34ft"; // 
    allItems[26]=" Serpent < 55ft"; //  
    allItems[27]=" Number 8> 21ft"; // Number 8 first turn right 
    allItems[28]=" Number 8> 34ft"; // 
    allItems[29]=" Number 8> 55ft"; //  
    allItems[30]=" Number 8< 21ft"; // Number 8 first turn left 
    allItems[31]=" Number 8< 34ft"; // 
    allItems[32]=" Number 8< 55ft"; //  
    allItems[33]=" Shutdown";
    allItems[34]=" Reset"; 

  };

  TwoElms* Menu::valueAtCurrentPosition() {
    TwoElms* theTwoElements = new TwoElms();

    strncpy(theTwoElements->line1, allItems[idx1], 16);
    strncpy(theTwoElements->line2, allItems[idx2], 16);
    
    theTwoElements->line1[0] = MARKER;
    
    return theTwoElements; 
    
  };

  TwoElms* Menu::moveUp() {
    bool isJumpedOver = false;
    crntPos--;
    if(crntPos < 0) { 
      crntPos = size()-1;
      idx1 = crntPos;
      idx2 = 0;
      isJumpedOver = true;
    } else {
      idx1 = crntPos;
      idx2 = idx1 + 1;     
    }
    TwoElms* retTwoElems = valueAtCurrentPosition();
    retTwoElems->isJumpedOver = isJumpedOver; 
    return retTwoElems;
  };

  TwoElms* Menu::moveDown(){
    bool isJumpedOver = false;
    crntPos++;
    if(crntPos > size()-2) {
      crntPos = 0;
      idx1 = size()-1;
      idx2 = 0;
      isJumpedOver = true;
    } else {
      idx1 = crntPos;
      idx2 = idx1 + 1;     
    }
    TwoElms* retTwoElems = valueAtCurrentPosition();
    retTwoElems->isJumpedOver = isJumpedOver; 
    return retTwoElems;
  };

  int Menu::size() {
     return SIZE;
  };

  
