/*
 * main.c
 *
 * Created: 10/27/2022 12:43:56 AM
 *  Author: mohamed
 */ 

#include <xc.h>


#define F_CPU 8000000UL
#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)//=51
#define UDR   *((char*) 0xc6) 
#define UBRRH *((char*) 0xc5) 
#define UBRRL *((char*) 0xc4) 
#define UCSRC *((char*) 0xc2) 
#define UCSRB *((char*) 0xc1) 
#define UCSRA *((char*) 0xc0) 
int main(void){//intialize uart
	UCSRB |= (1 << 3);	/* Turn on transmission and reception */
	UBRRH = (BAUD_PRESCALE >> 8);//=0
	UBRRL = BAUD_PRESCALE;		//=51	/* Load lower 8-bits of the baud rate with value 51*/
	UCSRC=0b00100110;//8bit &even parity
    while(1)//super loop
    {while (! (UCSRA & (1<<5)));//polling == wating untile udr embty flag is set
		UDR=0xff;//sending 0
	}
}