#include <Arduino.h>
#include "Listener.h"

void Listener::onEvent(unsigned int tickNumber, char* entryName, char* param) {
  Serial.println(entryName);
  Serial.println("Got Trigerred! That is an unwanted behaviour");
};

MomrSwitLisr::MomrSwitLisr() {
  
}

/* Constuctor storing Pin Contact Number as an attribute */
MomrSwitLisr::MomrSwitLisr(int pcn) {
  this->pcn = pcn;
}

void MomrSwitLisr::onEvent(unsigned int tn, char* entryName, char* param) {
  int result = strcmp (param, zero);
  digitalWrite(pcn, result==0 ? HIGH : LOW);
}

BtnLisr::BtnLisr(Menu* menu, Lcd16x2* lcd16x2) {
  this->menu = menu;
  this->lcd16x2 = lcd16x2;
};


BtnUpLisr::BtnUpLisr(Menu* menu, Lcd16x2* lcd16x2) : BtnLisr(menu, lcd16x2)  {
};

BtnUpLisr::~BtnUpLisr() {

};

BtnDownLisr::BtnDownLisr(Menu* menu, Lcd16x2* lcd16x2) : BtnLisr(menu, lcd16x2) {
};


BtnEnrLisr::BtnEnrLisr(Menu* menu, Lcd16x2* lcd16x2) : BtnLisr(menu, lcd16x2) {
};

/* When the button UP is pushed this method is called.  */
void BtnUpLisr::onEvent(unsigned int tn, char* entryName, char* param) {
  Serial.println("On Up Button press");
}  

/* When the button DOWN is pushed this method is called */
void BtnDownLisr::onEvent(unsigned int tn, char* entryName, char* param) {
    Serial.println("On Down Button press");
};

/* when the button Enter is pushed then this method is called */ 
void BtnEnrLisr::onEvent(unsigned int tn, char* entryName, char* param) {
    Serial.println("On Enter Button press");
};
