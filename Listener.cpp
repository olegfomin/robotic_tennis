#include <Arduino.h>
#include "Listener.h"

Listener::Listener(int pcn) {
  this->pcn = pcn;
}

int Listener::getPcn() {
  return pcn;
}

void Listener::onEvent(unsigned int tickNumber, char* entryName, char* param) {
  Serial.println(entryName);
  Serial.println("Got Trigerred! That is an unwanted behaviour");
};

/* Constuctor storing Pin Contact Number as an attribute */
MomrSwitLisr::MomrSwitLisr(int pcn) : Listener(pcn) {
  
}

void MomrSwitLisr::onEvent(unsigned int tn, char* entryName, char* param) {
  int result = strcmp (param, zero);
  digitalWrite(pcn, result==0 ? HIGH : LOW);
}

BtnLisr::BtnLisr(unsigned int pcn, Menu* menu, Lcd16x2* lcd16x2) : Listener(pcn) {
/*  Serial.println("Pre-Before");
  delay(500);
  this->menu = menu;
  this->lcd16x2 = lcd16x2;
  Serial.println("Before");
  delay(500);
  TwoElms* twoElms = this->menu->valueAtCurrentPosition();
  Serial.println("After");
  delay(500);
  lcd16x2->setLine1(twoElms->line1);
  lcd16x2->setLine1(twoElms->line2);
  lcd16x2->render();
  delete twoElms->line1;
  delete twoElms->line2;
  delete twoElms; */ 
};

void BtnLisr::onEvent(unsigned int tickNumber, char* entryName, char* param) {
  Serial.println(entryName);
  Serial.println("Got Trigerred from BtnLisr::onEvent! That is an unwanted behaviour");
}


BtnUpLisr::BtnUpLisr(int pcn, Menu* menu, Lcd16x2* lcd16x2) : BtnLisr(pcn, menu, lcd16x2) {
};

void BtnUpLisr::onEvent(unsigned int tickNumber, char* entryName, char* param) {
  Serial.println("Up");
/*  TwoElms* twoElms = menu->moveUp();
  if(twoElms->isJumpedOver) lcd16x2->sound();
  lcd16x2->setLine1(twoElms->line1);
  lcd16x2->setLine1(twoElms->line2);
  lcd16x2->render();
  delete twoElms->line1;
  delete twoElms->line2;
  delete twoElms; */ 
}

BtnUpLisr::~BtnUpLisr() {

};

BtnDownLisr::BtnDownLisr(int pcn, Menu* menu, Lcd16x2* lcd16x2) : BtnLisr(pcn, menu, lcd16x2) {
};

void BtnDownLisr::onEvent(unsigned int tickNumber, char* entryName, char* param) {
  Serial.println("Down");
/*  TwoElms* twoElms = menu->moveDown();
  if(twoElms->isJumpedOver) lcd16x2->sound();
  lcd16x2->setLine1(twoElms->line1);
  lcd16x2->setLine1(twoElms->line2);
  lcd16x2->render();
  delete twoElms->line1;
  delete twoElms->line2;
  delete twoElms; */ 
}



BtnEnrLisr::BtnEnrLisr(int pcn, Menu* menu, Lcd16x2* lcd16x2) : BtnLisr(pcn, menu, lcd16x2) {
};

/* when the button Enter is pushed then this method is called */ 
void BtnEnrLisr::onEvent(unsigned int tn, char* entryName, char* param) {
    Serial.println("Enter");
};
