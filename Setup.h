/* Here there are values and a factory that returns TimeListenerRegistry with all available structures pre-populated */
#ifndef SETUP
#define SETUP

#include "LisrReg.h"
#include "Listener.h"
#include "Menu.h"
#include "lcd16x2.h"


char* LEFT_REAR_LED_NAME   =  const_cast<char*>("LEFT_REAR_52");
char* RIGHT_REAR_LED_NAME  =  const_cast<char*>("RIGHT_REAR_49");
char* RIGHT_FRONT_LED_NAME =  const_cast<char*>("RIGHT_FRONT_51");
char* LEFT_FRONT_LED_NAME  =  const_cast<char*>("LEFT_FRONT_52");
char* RPi_RELAY_NAME       = const_cast<char*>("RELAY_PIN_8");
char* ARD_POWER_RELAY_NAME = const_cast<char*>("RELAY_PIN_7");
char* MOTOR_POWER_RELAY_NAME = const_cast<char*>("RELAY_PIN_6");
char* R2_RELAY_NAME        = const_cast<char*>("RELAY_PIN_5");

unsigned int LEFT_REAR_LED_PIN=52;
unsigned int RIGHT_REAR_LED_PIN=49;
unsigned int RIGHT_FRONT_LED_PIN=51;
unsigned int LEFT_FRONT_LED_PIN=52;
unsigned int RPI_RELAY_LED_PIN=8;
unsigned int ARD_POWER_RELAY_PIN=7;
unsigned int MOTOR_POWER_RELAY_PIN=6;
unsigned int R2_RELAY_PIN=5;

unsigned int BLINK_INTERVAL = 250;

char* TOP_BUTTON_NAME = const_cast<char*>("BUTTON_9");
char* MID_BUTTON_NAME = const_cast<char*>("BUTTON_10");
char* BOTTOM_BUTTON_NAME = const_cast<char*>("BUTTON_11");

unsigned int TOP_BUTTON_PIN=9;
unsigned int MID_BUTTON_PIN=10;
unsigned int BOTTOM_BUTTON_PIN=11;



// Creates the registry and prepopulates with all needed entries inside 
 LisrReg* setupEnv() {
  Menu* menu = new Menu(); 
  Lcd16x2* lcd = new Lcd16x2();

  LisrReg* lisrReg = new LisrReg();
  // PIN 52
  MomrSwitLisr* leftRearLisr = new MomrSwitLisr(LEFT_REAR_LED_PIN); 
  lisrReg->regTmEnr(LEFT_REAR_LED_NAME, BLINK_INTERVAL, leftRearLisr);
  MomrSwitLisr* rightRearLisr = new MomrSwitLisr(RIGHT_REAR_LED_PIN); 
  lisrReg->regTmEnr(RIGHT_REAR_LED_NAME, BLINK_INTERVAL, rightRearLisr);
  MomrSwitLisr* rightFrntLisr = new MomrSwitLisr(RIGHT_FRONT_LED_PIN); 
  lisrReg->regTmEnr(RIGHT_FRONT_LED_NAME, BLINK_INTERVAL, rightFrntLisr);
  MomrSwitLisr* leftFrntLisr = new MomrSwitLisr(LEFT_FRONT_LED_PIN);  
  lisrReg->regTmEnr(LEFT_FRONT_LED_NAME, BLINK_INTERVAL, leftFrntLisr);
  MomrSwitLisr* rpiRelayLisr = new MomrSwitLisr(RPI_RELAY_LED_PIN);
  lisrReg->regTmEnr(RPi_RELAY_NAME, rpiRelayLisr);
  MomrSwitLisr* ArdRelayLisr = new MomrSwitLisr(ARD_POWER_RELAY_PIN);
  lisrReg->regTmEnr(ARD_POWER_RELAY_NAME, ArdRelayLisr);
  MomrSwitLisr* MotoRelayLisr = new MomrSwitLisr(MOTOR_POWER_RELAY_PIN);
  lisrReg->regTmEnr(MOTOR_POWER_RELAY_NAME, MotoRelayLisr);
  MomrSwitLisr* R2RelayLisr = new MomrSwitLisr(R2_RELAY_PIN);
  lisrReg->regTmEnr(R2_RELAY_NAME, R2RelayLisr);
  BtnLisr* topBtnLisr = new BtnUpLisr(TOP_BUTTON_PIN, menu, lcd);
  lisrReg->regBtnEnr(TOP_BUTTON_NAME, TOP_BUTTON_PIN, topBtnLisr);
  BtnLisr* enrBtnLisr = new BtnEnrLisr(MID_BUTTON_PIN, menu, lcd);
  lisrReg->regBtnEnr(MID_BUTTON_NAME, MID_BUTTON_PIN, enrBtnLisr);
  BtnLisr* downBtnLisr = new BtnEnrLisr(BOTTOM_BUTTON_PIN, menu, lcd);
  lisrReg->regBtnEnr(BOTTOM_BUTTON_NAME, BOTTOM_BUTTON_PIN, downBtnLisr);

  return lisrReg;
}

#endif
