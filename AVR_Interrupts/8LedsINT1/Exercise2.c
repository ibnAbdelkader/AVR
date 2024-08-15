/*
 * Exercise2.c
 *
 * Created: 12/7/2014 9:08:25 PM
 *  Author: Ahmed Abdelkader
 */ 

#ifndef F_CPU
#define F_CPU 1000000UL // or whatever may be your frequency
#endif

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

volatile unsigned char g_Interrupt_Flag = 0;

/* Externel INT1 Interrupt Service Routine */
ISR(INT1_vect)
{
	g_Interrupt_Flag = 1;		
}

/* External INT1 enable and configuration function */
void INT1_Init(void)
{
	cli(); // Disable interrupts by clearing I-bit
	GICR |= (1<<INT1); //enable external interrupt pin INT1
	MCUCR |= (1<<ISC11); // Trigger INT1 with the falling edge
	sei(); // Enable interrupts by setting I-bit
}

int main(void)
{
	DDRC = 0xFF; //configure all PORTC pins as output pins
	PORTC = 0x01; //first led is on at the beginning (Positive Logic configuration)
	
	DDRD  &= (~(1<<PD3)); //configure INT1/PD3 as input pin 
	PORTD |= (1<<PD3); //enable built in pull up resistor of INT1/PD3 pin.
	
	INT1_Init(); // enable and configure external INT1
	
	unsigned char Loop_idx;
	
    while(1)
    {
		if(g_Interrupt_Flag == 0)
		{
			_delay_ms(500);
			PORTC = (PORTC<<1); //every time only one led is ON
			if(PORTC == 0x00)
			{
				PORTC = 0x01;
			}
		}
		else
		{
			for(Loop_idx = 0 ; Loop_idx < 5 ; Loop_idx++)
			{
				PORTC = 0xFF;
				_delay_ms(500);
				PORTC = 0x00;
				_delay_ms(500);
			}
			g_Interrupt_Flag = 0; //after finish make flag = 0 again 
		}							
	}					
}