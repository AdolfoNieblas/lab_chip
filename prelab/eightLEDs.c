/*	Name & E-mail: Adolfo Nieblas anieb001@ucr.edu
 *	Lab Section: 23
 *	Assignment: Lab 5  Exercise PRELAB-PORTC-Disabling JTG required
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

    unsigned char led = 0x00;
    unsigned char button = 0x00;
    /* Insert your solution below */
    while (1) {
        //if PA0 is 1, set PB1PB0=01, else =10
        //1) Read inputs
        button = ~PINA & 0x01; //button is connected to A0

        //2) Perform calculations
        if(button) { //True if button is pressed
            //led = (led&0xFC) | 0x01; //sets B to bbbbbb01
            led = 0xFF; //sets all 8 leds to on if button pressed
        }                           
        else {
            led = 0x00; //sets all 8 leds to off if not pressed
        }                           

        //3) Write output
        PORTC = led;   //Writes Port B's 8 pins with 00001111.

    }
    return 1;
}
