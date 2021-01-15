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
  DDRC = 0x00; PORTC = 0XFF;
	DDRD = 0XFF; PORTD =0X00;
  
  unsigned char weightTotal = 0x00;
  unsigned char tracker = 0x00;
  unsigned char pinA =0x00;
unsigned char pinB = 0x00;
unsigned char pinC = 0x00;
  
    /* Insert your solution below */
    while (1) {
	        pinA = PINA;
	    	pinB = PINB;
	    	pinC = PINC;
	    
	    weightTotal = pinA + pinB + pinC; //get total weight of 3 pins
         
	   if(weightTotal > 0x8C){
		   tracker = (tracker & 0xFC) | 0x01;
	   }
	    if(abs(pinA - pinC) > 0x50){
		    tracker = (tracker & 0xFD) | 0x02;
	    }
	   // PORTD = tracker; // setting d0 and d1 to tracker values
	    weightTotal = (weightTotal & 0xFC) | tracker; // bbbb bb00
	    PORTD = weightTotal;// + tracker;
	    tracker = (tracker & 0xFC) | 0x00; //reset tracker
	    weightTotal = (weightTotal & 0xFC) | 0x00; // reset weight
    }
    return 1;
}
