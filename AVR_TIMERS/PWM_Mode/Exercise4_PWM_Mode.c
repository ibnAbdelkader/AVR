/*
 * Exercise4_PWM_Mode.c
 *
 * Created: 1/22/2015 6:15:47 PM
 *  Author: Ahmed Abdelkader
 */ 
/* Description: 
 * Application to generate a PWM signal with frequency 500Hz 
 * Timer0 will be used with pre-scaler F_CPU/8 
 * F_PWM=(F_CPU)/(256*N) = (10^6)/(256*8) = 500Hz
*/

#ifndef F_CPU
#define F_CPU 1000000UL // or whatever may be your frequency
#endif

#include <avr/io.h>
#include <util/delay.h>

void Timer0_PWM_Init(unsigned char set_duty_cycle){
	
	TCNT0 = 0; // Timer initial value
	
	OCR0  = set_duty_cycle; //compare value
	
	DDRB  = DDRB | (1<<PB3); //set OC0 as output pin --> pin where the PWM signal is generated from MC
	
	/* Configure timer control register 
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match (inverted mode) COM00=0 & COM01=1 
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */ 
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}
int main(void)
{
    Timer0_PWM_Init(128); //50% duty cycle
	_delay_ms(5000); //wait 5 seconds
	Timer0_PWM_Init(64); //25% duty cycle
	
	while(1)
	{
		
	}
}