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

	unsigned char pin0 = 0x00; // pina0
	unsigned char pin1 = 0x00; // pina1
	unsigned char pin2 = 0x00; // pina2
	unsigned char pin3 = 0x00; // pina3
	unsigned char cntavail = 0x04;
    /* Insert your solution below */
    while (1) {
		pin0 = PINA & 0x01; // 01
		pin1 = PINA & 0x02; // 10
		pin2 = PINA & 0x04; // 100
		pin3 = PINA & 0x08; // 1000
		
		if(pin0==0x01){
			cntavail--;
		}
		if(pin1==0x01){
			cntavail--;
		}
		if(pin2==0x01){
			cntavail--;
		}
		if(pin3==0x01){
			cntavail--;
		}
		
		if(cntavail == 0x04){
			PORTC=0x04;
		}
		if(cntavail ==0x03){
			PORTC=0x03;
}
		if(cntavail==0x02){
			PORTC=0x02;
}
		if(cntavail==0x01){
			PORTC=0x01;
}
		if(cntavail==0x00){
			PORTC=0x40;
}
		else{
			cntavail=(cntavail & 0xFC) | 0x04;
			PORTC=0x04;
}
	}
    return 1;
}
