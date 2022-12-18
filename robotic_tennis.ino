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
 *  enr  - entry
 *  ent  - entry
 *  elm  - element
 *  engd - engaged
 *  frnt - front
 *  idx  - index
 *  inrl - interval
 *  lisr - listener
 *  mk   - make
 *  momr - momentary
 *  nm   - name
 *  obsr - Observer
 *  pcn  - Pin Contact Number (Arduino or RPi depending on context)
 *  pos  - position 
 *  prid - period
 *  prs  - press
 *  reg -  registry             
 *  res  - result
 *  str  - string
 *  stat - static
 *  subj - subject (Observable)
 *  swit - switch              
 *  tm   - time                
 *  tn   - tick number (counter that stores the number of times the Arduino loop() got called)
 *  It is allowed to use full names for any of the words above provided the compound length will not exceed 13 characters
 *  The static final entries can use this contractions if their length exceed 21 charcters, otherwise contractions must be used 
 *  
*/

#include "LisrReg.h"
#include "LisrEnt.h"
#include "Listener.h"
#include "Setup.h"
#include "Menu.h"
#include "lcd16x2.h"

unsigned int tickCntr = 0;

void setup() {

Serial.begin(9600); // Debugging UART
delay(1000);
Serial3.begin(9600); //Menu's Lcd16x2 UART
delay(1000);

LisrReg* lisrReg = setupEnv();
lisrReg->setup(); // It supposed to register all PINs involved

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

/*   ------  */
/*   |    |  */
/*   |    |  */
/*   |    |  */
/*   |    |  */ 
/*   ----49  */

/*   -----51 */
/*   |    |  */
/*   |    |  */
/*   |    |  */
/*   |    |  */ 
/*   ------  */

/*  50-----  */
/*   |    |  */
/*   |    |  */
/*   |    |  */
/*   |    |  */ 
/*   ------  */  

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

}

void loop() {
  Serial.println("Before the render ");

/*  lcd->setLine1(">To From 8ft");
  lcd->setLine2(" To From 13ft");
  lcd->render();*/
  delay(1000);
  Serial3.print("Haha");
  delay(1000);
  
/*  tmLisrReg->feed(tickCntr);
  subject->feed(tickCntr);
  tickCntr++;
  delay(1); */
}
