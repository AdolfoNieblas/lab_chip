/*	Name & E-mail: Adolfo Nieblas anieb001@ucr.edu
 *	Lab Section: 23
 *	Assignment: Lab 5  Exercise 1
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template 
 * 	or example code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF; //Configure Port A's 8 pins as inputs.
    //DDRB = 0xFF; PORTB = 0x00; //Configure Port B's 8 pins as outputs.
    DDRC = 0xFF; PORTC = 0x00; //Configure Port C's 8 pins as outputs.

	unsigned char tmpC = 0x00; // Temporary variable to hold the value of B
	unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
	//unsigned char tmpB = 0x00; // Temporary variable to hold the value of A

	while(1) {
		// 1) Read input
		tmpA = ~PINA & 0x0F; //read first 4 pins, ~ for the physical button press
		
		// 2) Perform computation
		if((tmpA & 0x0F) <= 0) {
			tmpC = ((tmpC & 0x00) | 0x40); //PC5 ON and PC6
		}
		else if((tmpA & 0x0F) <= 2) {
			tmpC = ((tmpC & 0x00) | 0x60); //PC5 ON and PC6
		}
		else if((tmpA & 0x0F) <= 4) {
			tmpC = ((tmpC & 0x00) | 0x70); //PC5,PC4 ON and PC6
		}
		else if((tmpA & 0x0F) <= 6) {
			tmpC = ((tmpC & 0x00) | 0x38); //PC6 is 0 for anything greater than 4
		}
		else if((tmpA & 0x0F) <= 9) {
			tmpC = ((tmpC & 0x00) | 0x3C); //PC5...PC2
		}
		else if((tmpA & 0x0F) <= 12) {
			tmpC = ((tmpC & 0x00) | 0x3E); //PC5...PC1
		}
		else if((tmpA & 0x0F) <= 15) {
			tmpC = ((tmpC & 0x00) | 0x3F); //PC5...PC0
		}
		else {
			tmpC = 0x40;
		}

		// 3) Write output
		PORTC = tmpC;

    }
    return 1;
}
