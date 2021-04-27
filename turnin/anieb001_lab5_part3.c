/*	Name & E-mail: Adolfo Nieblas anieb001@ucr.edu
 *	Lab Section: 23
 *	Assignment: Lab 5  Exercise 3
 *	Exercise Description: Create your own festive lights display w/ 6 LEDs B5-B0
 *                      lighting in some attractive sequence. Pressing A0 changes the lights
 *                      to the next configuration in the sequence.
 *	
 *	I acknowledge all content contained herein, excluding template 
 * 	or example code, is my own original work.
 */
#include <avr/io.h>
#include <util/delay.h> //to be able to use delay function. Pytests worked, but need to delay to see the changes in the LEDs.
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum SM_STATES{SM_Start, SM_INIT, SM_Trail, SM_Alternate, SM_OutToFill} state;

//unsigned char tmpA = 0x00;      //Temporary variable to hold the value of A
unsigned char button = 0x00;    //Button is A0. Assigned in main().
unsigned char counter = 0x00;   //want the lights to change every tick. A0 just changes the 

void Timer_Toggle() {
	switch(state) {
		case SM_Start:
			state = SM_INIT;
            //PORTC = 0x00; //set while transition to INIT
			break;

		case SM_INIT: 	  //wait for A0 to be pressed, else all lights off.
			if(button) {  //true if button is pressed.
                    state = SM_Trail;
                    counter = 0x00; //making sure counter was reset.
            }
            else{
                state = SM_INIT; //stay in init/off until A0 is pressed.
			}
			break;

		case SM_Trail: //Make it seems like the lights are going in one direction.
			if(button) { //Do not change States until A0=1
				state = SM_Alternate;
                counter = 0x00; //resetting counter again in transition.
			}
			else if(!button) { //while A) is not pressed, counter++ and loop.
				state = SM_Trail;
			}
			break;

		case SM_Alternate: //alternate between odd/even lights
			if(button) {
				state = SM_OutToFill;
                counter = 0x00;
			}
			else if(!button) { //stay in this state
				state = SM_Alternate; 
			}
			break;

		case SM_OutToFill: //start at outer lights, and fill inwards. vice-versa
			if(button) {
				state = SM_INIT; //turn_off lights if button is pressed
			}
			else if(!button) {
				state = SM_OutToFill; //stay in current state until button is pressed.
			}
			break;

		default:
			state = SM_Start;
			break;
	}//end-switch

	switch(state) {
		case SM_Start:
			PORTC = 0x00;
			break;

		case SM_INIT: 
			PORTC = 0x00;
			break;

		case SM_Trail: 
            //001001 -> 010010 -> 100100 -> 001001(reset counter)
            if(counter == 0x03) {
                counter = 0x00; //also resets the counter once we get to the last light
            }
            //if(counter < 0x03) {
            PORTC = 0x09 << counter;
            counter = counter + 1;
			break;

		case SM_Alternate: 
            //010101 -> 101010 (can shift 1 left, then right)
            //if(counter % 0x00) { //if counter is even( remainder 0) shift left
            if(counter == 0x00) { //if counter is even( remainder 0) shift left
                PORTC = 0x15 << 1;
                counter = counter + 1; //counter will be odd next tick.
            }
            else {  //counter is odd (remainder 1), shift 1 right,
                PORTC = PORTC >> 1;
                counter = 0x00; //resetting counter back to 0.
            }
			break;

		case SM_OutToFill: 
            // bb10 0001 -> bb11 0011 -> bb11 1111 -> bb01 1110 -> bb00 1100 ->bb00 0000
            if(counter == 0x00) {
                PORTC = 0x21;
                counter = counter + 1;
            }
            else if(counter == 0x01) {
                PORTC = 0x33;
                counter = counter + 1;
            }
            else if(counter == 0x02) {
                PORTC = 0x3F;
                counter = counter + 1;
            }
            else if(counter == 0x03) {
                PORTC = 0x1E;
                counter = counter + 1;
            }
            else if(counter == 0x04) {
                PORTC = 0x0C;
                counter = counter + 1;
            }
            else {
                PORTC = 0x00; //will go back to the beginning.
                counter = 0x00;
            }
			break;

		default:
			PORTC = 0x00;
			break;
	}//end-switch

}//end Timer_Toggle()

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x00; // Output for PORTC is initially 7.

	//tmpA = 0x00; // Temporary variable to hold the value of A

    /* Insert your solution below */
	while(1) {
		// 1) Read input
		//tmpA = PINA; //need the ~ for button actions.
		button = ~PINA & 0x01; //need the ~ for button actions.

        // 2) Do calculations
		// Go to Timer_Toggle function
		Timer_Toggle();

        _delay_ms(200); //delaying for 200ms.

		// 3) Write output
		//PORTB = tmpB;
	}

    return 1;
}
