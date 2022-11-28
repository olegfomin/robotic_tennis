/* 
 *  Agreement
 *  No variable name can exceed 13 characters in length here below is an accepted dictionary of contractions. It is allowed using entire word instead of contraction i9f the entire word length do not exceed 13 characters  
 *  
 *  Dictionary of contructions in variable names: 
 *  
 *  reg - registry             crnt - current
 *  swit - switch              prid - period
 *  lisr - listener            nm   - name
 *  tm   - time                mk   - make
 *  momr - momentary           str  - string
 *  cmp  - compare             res  - result
 *  ent  - entry
 *  cntr - counter
 *  conr - controller
 *  
*/

#include "TimeListenerRegistry.h"
#include "TimeListenerEntry.h"
#include "Listener.h"
#include "Setup.h"


TimeListenerRegistry* tmLisrReg = new TimeListenerRegistry();
MomentarySwitchListener* momrSwitLisr52 = new MomentarySwitchListener(52);
TimeListenerEntry* tmLisrEnt52 = new TimeListenerEntry("LED52", 1000, 250, momrSwitLisr52); 

MomentarySwitchListener* momrSwitLisr49 = new MomentarySwitchListener(49);
TimeListenerEntry* tmLisrEnt49 = new TimeListenerEntry("LED49", 50, momrSwitLisr49); 


unsigned int tickCntr = 0;

void setup() {
tmLisrEnt52->activate();
tmLisrReg->registerEntry(tmLisrEnt52);
tmLisrReg->registerEntry(tmLisrEnt49);

TimeListenerEntry* timeEntry = tmLisrReg->findByName("LED52");
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

}

void loop() {
  tmLisrReg->feed(tickCntr);
  tickCntr++;
  delay(5);
}
