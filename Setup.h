/* Here there are values and a factory that returns TimeListenerRegistry with all available structures pre-populated */
#ifndef SETUP
#define SETUP

#include "LisrReg.h"


char* LEFT_REAR_LED_BLINK   =  const_cast<char*>("PIN52_B");
#define char* RIGHT_REAR_LED_BLINK  =  const_cast<char*>("PIN48_B");
#define char* RIGHT_FRONT_LED_BLINK =  const_cast<char*>("PIN51_B");
#define char* LEFT_FRONT_LED_BLINK  =  const_cast<char*>("PIN50_B");
#define char* LEFT_REAR_LED_STOP    =  const_cast<char*>("PIN52_S");
#define char* RIGHT_REAR_LED_STOP   =  const_cast<char*>("PIN48_S");
#define char* LEFT_REAR_LED_EMER    =  const_cast<char*>("PIN52_E"); // Emergency stop
#define char* RIGHT_REAR_LED_EMER   =  const_cast<char*>("PIN48_E");
#define char* RIGHT_FRONT_LED_EMER  =  const_cast<char*>("PIN51_E");
#define char* RIGHT_LEFT_LED_EMER  =   const_cast<char*>("PIN50_E");
#define char* RPi_RELAY         = const_cast<char*>("PIN8");
#define char* ARD_POWER_RELAY   = const_cast<char*>("PIN7");
#define char* MOTOR_POWER_RELAY = const_cast<char*>("PIN6");
#define char* R2_RELAY          = const_cast<char*>("PIN5");

unsigned int LEFT_REAR_LED_PIN=52;


unsigned int BLINK_INTERVAL = 250;

unsigned int STOP_INTERVAL_OFF = 30;
unsigned int STOP_INTERVAL_ON  = 500;


// Creates the registry and prepopulates with all needed entries inside 
 LisrReg* setupEnv() {
  LisrReg* lisrReg = new LisrReg();
  // PIN 52
  MomrSwitLisr* momrSwitLisrBlink = new MomrSwitLisr(LEFT_REAR_LED_PIN); 
  LisrEnt* leftLisrEntBlink = lisrReg->regTmEnr(LEFT_REAR_LED_BLINK, BLINK_INTERVAL, momrSwitLisrBlink) ;
  MomrSwitLisr* momrSwitLisrStop = new MomrSwitLisr(LEFT_REAR_LED_PIN); 
//  TimeListenerEntry* tmLisrEntStop = new TimeListenerEntry(LEFT_REAR_LED_STOP, STOP_INTERVAL_OFF, STOP_INTERVAL_ON, momrSwitLisrBlink);
//  tmLisrReg->registerEntry(tmLisrEntStop);
  

}

#endif
