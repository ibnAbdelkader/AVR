/*
 * Exercise2_CTC_Mode.c
 *
 * Created: 1/21/2015 11:29:49 PM
 *  Author: Ahmed Abdelkader
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#define NUMBER_OF_OVERFLOWS_PER_HALF_SECOND 2

volatile unsigned char g_tick = 0;

/* For clock=1Mhz and prescale F_CPU/1024 every count will take 1ms
 * so we just need 250 counts to get 250ms every overflow. put initial timer counter=0  
 * and output compare register=250 0 --> 250 (250ms per overflow)
 * so we need timer to overflow 2 times to get a 0.5 second 
 */
 
void timer0_init_CTC_mode(unsigned char tick)
{
	TCNT0 = 0; //timer initial value
	OCR0  = tick; //compare value
	TIMSK = (1<<OCIE0); //enable compare interrupt
	/* Configure timer0 control register 
	 * 1. Non PWM mode FOC0=1
	 * 2. CTC Mode WGM01=1 & WGM00=0
	 * 3. No need for OC0 in this example so COM00=0 & COM01=0 
	 * 4. clock = F_CPU/1024 CS00=1 CS01=0 CS02=1
	 */
	TCCR0 = (1<<FOC0) | (1<<WGM01) | (1<<CS02) | (1<<CS00);
}

/* Interrupt Service Routine for timer0 compare mode */
ISR(TIMER0_COMP_vect)
{
	g_tick++;
	if(g_tick == NUMBER_OF_OVERFLOWS_PER_HALF_SECOND)
	{
		PORTC = PORTC ^ (1<<PC0); //toggle led every 0.5 second
		g_tick = 0; //clear the tick counter again to count a new 0.5 second
	}	
}

int main(void)
{
	DDRC  |= (1<<PC0); //configure the led pin to be output pin.
	PORTC &= ~(1<<PC0); //LED is off at the beginning(Positive Logic).
	sei(); //enable global interrupts in MC.
	timer0_init_CTC_mode(250); //start the timer.
    while(1)
    {			
       
    }
}