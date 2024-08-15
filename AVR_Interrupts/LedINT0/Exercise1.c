/*
 * Exercise1.c
 *
 * Created: 3/3/2015 9:45:25 PM
 *  Author: Ahmed Abdelkader
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

/* External INT0 Interrupt Service Routine */
ISR(INT0_vect)
{
	PORTC = PORTC ^ (1<<PC0); //toggle led state		
}

/* External INT0 enable and configuration function */
void INT0_Init(void)
{
	cli(); // Disable interrupts by clearing I-bit
	GICR |= (1<<INT0); //enable external interrupt pin INT0
	MCUCR |= (1<<ISC01); // Trigger INT0 with the falling edge
	sei(); // Enable interrupts ny setting I-bit
}

int main(void)
{
	DDRC  = DDRC | (1<<PC0); //configure pin PC0 in PORTC as output pin
	PORTC = PORTC | (1<<PC0); //initialization Led is off at the beginning(Negative Logic)
	
	DDRD  &= (~(1<<PD2)); //configure INT0/PD2 as input pin
	PORTD |= (1<<PD2); //enable built in pull up resistor of INT0/PD2 pin.
	INT0_Init(); // enable external INT0
	
    while(1)
    {
							
	}					
}