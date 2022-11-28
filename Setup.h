/* Here there are values and a factory that returns TimeListenerRegistry with all available structures pre-populated */
#ifndef SETUP
#define SETUP

unsigned int LEFT_REAR_LED_PIN=52;

char* LEFT_REAR_LED_BLINK   =  const_cast<char*>("PIN52_B");
char* RIGHT_REAR_LED_BLINK  =  const_cast<char*>("PIN48_B");
char* RIGHT_FRONT_LED_BLINK =  const_cast<char*>("PIN51_B");
char* LEFT_FRONT_LED_BLINK  =  const_cast<char*>("PIN50_B");
char* LEFT_REAR_LED_STOP    =  const_cast<char*>("PIN52_S");
char* RIGHT_REAR_LED_STOP   =  const_cast<char*>("PIN48_S");
char* LEFT_REAR_LED_EMER    =  const_cast<char*>("PIN52_E"); // Emergency stop
char* RIGHT_REAR_LED_EMER   =  const_cast<char*>("PIN48_E");
char* RIGHT_FRONT_LED_EMER  =  const_cast<char*>("PIN51_E");
char* RIGHT_LEFT_LED_EMER  =   const_cast<char*>("PIN50_E");

unsigned int BLINK_INTERVAL = 50;

unsigned int STOP_INTERVAL_OFF = 30;
unsigned int STOP_INTERVAL_ON  = 500;

char* RPi_RELAY         = const_cast<char*>("PIN8");
char* ARD_POWER_RELAY   = const_cast<char*>("PIN7");
char* MOTOR_POWER_RELAY = const_cast<char*>("PIN6");
char* R2_RELAY          = const_cast<char*>("PIN5");

// Creates the registry and prepopulates with all needed entries inside 
TimeListenerRegistry* setupEnv() {
  TimeListenerRegistry* tmLisrReg = new TimeListenerRegistry();
  // PIN 52
  MomentarySwitchListener* momrSwitLisrBlink = new MomentarySwitchListener(LEFT_REAR_LED_PIN); 
  TimeListenerEntry* tmLisrEntBlink = new TimeListenerEntry(LEFT_REAR_LED_BLINK, BLINK_INTERVAL, momrSwitLisrBlink);
  tmLisrReg->registerEntry(tmLisrEntBlink);
  MomentarySwitchListener* momrSwitLisrStop = new MomentarySwitchListener(LEFT_REAR_LED_PIN); 
//  TimeListenerEntry* tmLisrEntStop = new TimeListenerEntry(LEFT_REAR_LED_STOP, STOP_INTERVAL_OFF, STOP_INTERVAL_ON, momrSwitLisrBlink);
//  tmLisrReg->registerEntry(tmLisrEntStop);
  

}

#endif
