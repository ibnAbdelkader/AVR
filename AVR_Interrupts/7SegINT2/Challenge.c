/*
 * challenge.c
 *
 * Created: 12/7/2014 9:08:25 PM
 *  Author: Ahmed Abdelkader
 */ 

#ifndef F_CPU
#define F_CPU 1000000UL // or whatever may be your frequency
#endif

#include <avr/io.h>
#include <avr/interrupt.h>

/* External INT2 Interrupt Service Routine */
ISR(INT2_vect){
	if(PORTC == 9)	PORTC=0;
	else PORTC++;		
}

/* External INT1 enable and configuration function */
void INT2_Init(void){
	cli(); // Disable interrupts
	GICR |= (1<<INT2); //enable external interrupt pin INT2
	MCUCSR |= (1<<ISC2); // Trigger INT2 with the rising edge
	sei(); // Enable interrupts
}

int main(void)
{
	DDRC = 0xFF; //configure all pins in PORTC as output pins.
	PORTC = 0; //initialization 7-seg display zero at the beginning.
	
	DDRB  &= (~(1<<PB2)); //configure INT2/PB2 as input pin 
	
	INT2_Init(); // enable and configure external INT2
	
    while(1)
    {
						
	}					
}