/*	Author: hcier001
 *  Partner(s) Name: none
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA =0X00; PORTA = 0XFF;
	DDRB =0XFF; PORTB =0X00;

	unsigned char tempA0 = 0x00; // pina0
	unsigned char tempA1 = 0x00; // pina1
	unsigned char tempB = 0x00; // portb
    /* Insert your solution below */
    while (1) {
	tempA0 = PINA & 0X01;
	tempA1 = PINA & 0X02;
	
	if(tempA0 == 0x01 && tempA1 == 0x00){
		tempB = 0x01;
    }
	PORTB = tempB;
}
    return 1;
}
