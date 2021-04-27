/*	Name & E-mail: Adolfo Nieblas anieb001@ucr.edu
 *	Lab Section: 23
 *	Assignment: Lab 5  Exercise 2
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template 
 * 	or example code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum SM_STATES{SM_Start, SM_INIT, SM_Increment, SM_Decrement, SM_Reset} state;
//enum SM_STATES{SM_Start, SM_INIT, SM_Increment, SM_Decrement} state;

unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
//tmpA = PINA; //read all 8 pins, assign to tmpA. 

void Timer_Toggle() {
	switch(state) {
		case SM_Start:
			state = SM_INIT;
            PORTC = 0x07; //set while transition to INIT
			break;

        //inc,dec, and reset should return to SM_Wait. Multiple presses should be accounted for.
		case SM_INIT: 	//wait for A0||A1 to be pressed.
			if(tmpA & 0x01) { 
                state = SM_Increment;
                if(PORTC < 9) {
                    PORTC = PORTC + 1;  //add 1 during trans.
                }
			}
			else if(tmpA & 0x02) {
				state = SM_Decrement;
                if(PORTC > 0) {
                    PORTC = PORTC - 1;  //sub 1 during trans.
                }
			}
			else if(tmpA & 0x03) {  //both A0A1 on simultaneously, then reset
				state = SM_Reset;
			}
			else {
				state = SM_INIT; //loop until either is pressed
			}
			break;

		case SM_Increment: 
			if(!(tmpA & 0x01)) { //Do not change States until A0=0
				state = SM_INIT;
			}
			else if(tmpA & 0x02) { //If A1 is active, reset C to 0.
				state = SM_Reset;
			}
			else {
				state = SM_Increment; //stay in increment.
			}
			break;

		case SM_Decrement: 
			if(!(tmpA & 0x02)) { //Do not change states, until A1 = 0;
				state = SM_INIT; 
			}
			else if(tmpA & 0x01) { //Go to reset is A0 is pressed.
				state = SM_Reset; 
			}
			else {
				state = SM_Decrement; //Do not change
			}
			break;

		case SM_Reset: //C will equal 0
			if(!(tmpA & 0x03)) { //it can only return to INIT when both A0A1 are 0.
				state = SM_INIT;
			}
			else {
				state = SM_Reset; //stay in reset until A0/A1 are let go.
			}
			break;

		default:
			state = SM_Start;
			break;
	}//end-switch

	switch(state) {
		case SM_Start:
			//PORTC = 0x07;
			break;

		case SM_INIT: 
			PORTC = PORTC;
			break;

		case SM_Increment: 
			break;

		case SM_Decrement: 
			break;

		case SM_Reset: 
			PORTC = 0x00;
			break;

		default:
			PORTC = 0x07;
			break;
	}//end-switch

}//end Timer_Toggle()

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x00; // Output for PORTC is initially 7.

	tmpA = 0x00; // Temporary variable to hold the value of A
	//unsigned char tmpC = 0x00; // Temporary variable to hold the value of C

    /* Insert your solution below */
	while(1) {
		// 1) Read input
		//tmpA = PINA; //read all 8 pins, assign to tmpA. 
		tmpA = ~PINA; //need the ~ for button actions.

        // 2) Do calculations
		// Go to Timer_Toggle function
		Timer_Toggle();

		// 3) Write output
		//PORTB = tmpB;
	}

    return 1;
}
