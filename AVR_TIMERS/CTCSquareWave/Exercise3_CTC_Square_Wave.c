/*
 * TIMER0_CTC_Square_Wave_AMIT.c
 *
 * Created: 3/6/2015 2:45:20 PM
 *  Author: Ahmed Abdelkader
 */ 

#ifndef F_CPU
#define F_CPU 1000000UL
#endif

#include <avr/io.h>

void Timer0_CTC_Square_Wave_Init(void){
	TCNT0 = 0; // initial value 0 
	OCR0 = 80; // compare value
	DDRB = DDRB | (1<<PB3); // OC0 Pin as output pin
	/* Configure timer control register 
	 * 1. Non PWM mode FOC0=1
	 * 2. CTC Mode WGM01=1 & WGM00=0
	 * 3. Toggle OC0 on compare match COM00=1 & COM01=0 
	 * 4. clock = CPU clock CS00=1 CS01=0 CS02=0
	 */ 
	TCCR0 = (1<<FOC0) | (1<<WGM01) | (1<<COM00) | (1<<CS00);
}

int main(void)
{
	Timer0_CTC_Square_Wave_Init();
    while(1)
    {
		
    }
}