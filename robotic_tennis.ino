/* 
 *  Agreement
 *  No variable name can exceed 13 characters in length here below is an accepted dictionary of contractions. It is allowed using entire word instead of contraction i9f the entire word length do not exceed 13 characters  
 *  
 *  Dictionary of contructions in variable names: 
 * 
 *  arr  - array 
 *  btn  - button
 *  blnk - blick
 *  crnt - current
 *  cntr - counter
 *  conr - controller
 *  cmp  - compare
 *  enr  - enter
 *  ent  - entry
 *  elm  - element
 *  engd - engaged
 *  lisr - listener
 *  mk   - make
 *  momr - momentary
 *  nm   - name
 *  oble - Observable
 *  obsr - Observer
 *  pcn  - Pin Contact Number (Arduino or RPi depending on context)
 *  prid - period
 *  prs  - press
 *  reg -  registry             
 *  res  - result
 *  str  - string
 *  stat - static
 *  swit - switch              
 *  tm   - time                
 *  tn   - tick number (counter that stores the number of times the Arduino loop() got called)
 *  It is allowed to use full names for any of the words above provided the compound length will not exceed 13 characters
 *  The static final entries can use this contractions if their length exceed 21 charcters, otherwise contractions must be used 
 *  
*/

#include "TmLisrReg.h"
#include "TmLisrEnt.h"
#include "Listener.h"
#include "Setup.h"
#include "Btn.h"
#include "Menu.h"
#include "lcd16x2.h"

/*ReliableButton* rbUp = new ReliableButton(buttonUp); 
ReliableButton* rbEnter = new ReliableButton(buttonEnter); 
ReliableButton* rbDown = new ReliableButton(buttonDown);*/
Menu* menu = new Menu(); 
Lcd16x2* lcd = new Lcd16x2();

TmLisrReg* tmLisrReg = new TmLisrReg();
MomrSwitLisr* momrSwitLisr52 = new MomrSwitLisr(52);
TmLisrEnt* tmLisrEnt52 = new TmLisrEnt("LED52", 1000, 250, momrSwitLisr52); 

MomrSwitLisr* momrSwitLisr49 = new MomrSwitLisr(49);
TmLisrEnt*    tmLisrEnt49 = new TmLisrEnt("LED49", 50, momrSwitLisr49);

BtnUpLisr* btnUpLisr   = new BtnUpLisr(9);
BtnDownLisr* btnDownLisr = new BtnDownLisr(10);
BtnEnrLisr* btnEnrLisr  = new BtnEnrLisr(11);

unsigned int tickCntr = 0;

void setup() {
tmLisrEnt52->activate();
tmLisrReg->regEntry(tmLisrEnt52);
tmLisrReg->regEntry(tmLisrEnt49);

TmLisrEnt* timeEntry = tmLisrReg->findByName("LED52");
if(timeEntry != NULL) timeEntry->activate(5);



/*tmLisrEnt49->activate();
*/
  
  //  LED to PIN Map:
/*************/
/*   ------  */
/*   |    |  */
/*   |    |  */
/*   |    |  */
/*   |    |  */ 
/*   52---   */
/*************/  
  pinMode(52, OUTPUT); // Rear Left

/*   ------  */
/*   |    |  */
/*   |    |  */
/*   |    |  */
/*   |    |  */ 
/*   ----49  */
  pinMode(49, OUTPUT); // Rear Right

/*   -----51 */
/*   |    |  */
/*   |    |  */
/*   |    |  */
/*   |    |  */ 
/*   ------  */
  pinMode(51, OUTPUT); // Head Right

/*  50-----  */
/*   |    |  */
/*   |    |  */
/*   |    |  */
/*   |    |  */ 
/*   ------  */  
  pinMode(50, OUTPUT); // Head Left

/* Relay to PIN Map: 
-------------
|\^^^^^^^^^ |\
| \^^^^^^^^^||\
|R2\ ^^^^^^^|||\
| R3\-------||||-
|w   |bottom|||||0
| a  |bottom|||||
|  l |bottom|||||
|R1 l|bottom|||||
|    |bottom|||||
\------------\|||
 \transparent \||
  \^^R5^^R4^^^^\|
   \^^^^wall^^^^\0
     ^ ^    ^ ^
     | |    | | 
*/  
  pinMode(8, OUTPUT); // Rapberry Pi Power Relay (R5)
  pinMode(7, OUTPUT); // The Arduino Due Power Relay (R4)
  pinMode(6, OUTPUT); // The Motor power Relay (R3)
  pinMode(5, OUTPUT); // The Reserved R2 Relay (Speakers?)

  

  Serial.begin(9600);

//  lcd->init();


/**************************************************************/
/*         *************************************************   *
 * ******  *                    HDMI                       *   *
 * * 9  *  *                                               *   *
 * ******  *                                               *   *
 *   |     *                                               *   *
 *   |     *                                               *   *
 * ******  *                                               *   *
 * * 10 *  *                                               *   *
 * ******  *                                               *   *
 *   |     *                                               *   *
 *   |     *                                               *   *
 * ******  *************************************************   *
 * * 11 *                                                      *
 * ******       **************************************         *
 *   |          *               TX3 14               *         *
 *   ---------> *                                    *         *
 *              **************************************         *
/***************************************************************/

  attachInterrupt(digitalPinToInterrupt(9),  onUpBtnPrs, HIGH);
  attachInterrupt(digitalPinToInterrupt(10), onEnrBtnPrs, HIGH);
  attachInterrupt(digitalPinToInterrupt(11), onDownBtnPrs, HIGH);

/*  pinMode(8, OUTPUT);
  digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000); */    
  

}

void loop() {
/*  Serial3.write(12);
  delay(10);
  Serial3.write(22);
  delay(10);
  Serial3.write("Line one");
  Serial3.write("Line two");
  Serial3.write(12);
  delay(1000); */
 

  
  tmLisrReg->feed(tickCntr);
  tickCntr++;
  delay(5);
}

void onUpBtnPrs() {
  btnUpLisr->onEvent(tickCntr, "UpButton", "");
}

void onEnrBtnPrs() {
  btnEnrLisr->onEvent(tickCntr, "EnterButton", "");
}

void onDownBtnPrs() {
  btnDownLisr->onEvent(tickCntr, "DownButton", "");
}
