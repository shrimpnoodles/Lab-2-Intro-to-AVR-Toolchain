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
  
  unsigned char weightTotal = 0x00;
  unsigned char tracker = 0x00;
  
  
    /* Insert your solution below */
    while (1) {
	        weightTotal = PINA + PINB + PINC;
          
          if(weightTotal > 0x8c){
              tracker = (tracker & 0xFC) | 0x01;
              }
          weightTotal = weightTotal & 0xFC;
          if(PINA > PINC){
            if((PINA - PINC) > 0X50){
                tracker = (tracker & 0xFC) | 0x02;
                }
               }
          else if(PINC > PINA){
              if((PINC - PINA) > 0X50){
                  tracker = (tracker & 0xFC) | 0x02;
                  }
                 }
             PORTD = weightTotal + tracker;
             tracker = (tracker & 0xFC) | 0x00;
    return 1;
}
