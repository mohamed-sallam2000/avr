/*
 * main.c
 *
 * Created: 11/2/2022 7:55:45 PM
 *  Author: mohamed
 */ 

#include <xc.h>


#include<avr/interrupt.h>


volatile char f=0;

int main(void)
{SREG |=0b10000000;// enable global interrupt
	EICRA|=0x00;//external inturrupt control register a ==make interrupt happen when level zero on the pin 4pd2
	EIMSK|=(1<<INT0);//external interrupt mask 
//sei();
DDRB|=(1<<PB1);
DDRD=0;
PORTD|=(1<<PD2);
    while(1)
    {
        //TODO:: Please write your application code 
    }
}

ISR(INT0_vect){
	
	if (f==0)
	{PORTB|=(1<<PB1);
		f=1;
	
	}
	else
	{PORTB&=~(1<<PB1);
		f=0;
		
	}
	
	
}