/*
 * DC_Motor_PWM.c
 *
 * Created: 11/23/2014 1:36:59 AM
 *  Author: Ahmed Abdelkader
 */
 
 /* Description: 
  * Control the DC Motor direction using L293D H-bridge.
  * Control The DC Motor Speed using PWM from MC. connect the
  * PWM PIN of Timer0 OC0(PB3) to the enable of the Motor. 
  * duty cycle 100% --> Maximum Speed 
  * duty cycle 50%  --> Half Maximum Speed
  * duty cycle 0%   --> Motor Stop
  */
 
#include <avr/io.h>

void PWM_Timer0_Init(unsigned char set_duty_cycle){
	
	TCNT0 = 0; //initial timer value
	
	OCR0  = set_duty_cycle; 
	
	DDRB  = DDRB | (1<<PB3); //set OC0 as output pin --> pin where the PWM signal is generated from MC.
	
	/* Pin Description:
	 * FOC0 = 0 for PWM Mode 
	 * WGM01:0=11 for Fast PWM Mode
	 * COM01:0=10 Clear OC0 on compare match(Non-Inverting Mode)
	 * CS02:0=010 freq=F_CPU/8
	 */ 
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}

int main(void)
{ 
	PWM_Timer0_Init(255); //generate duty cycle 50% to get half motor speed
	
	DDRA = DDRA & (~(1<<PA0)); // configure pin 0 of PORTA as input pin
	DDRA = DDRA & (~(1<<PA1)); // configure pin 1 of PORTA as input pin
	DDRA = DDRA & (~(1<<PA2)); // configure pin 2 of PORTA as input pin
	DDRC = DDRC | (1<<PC0);    // configure pin 3 of PORTC as output pin
	DDRC = DDRC | (1<<PC1);    // configure pin 4 of PORTC as output pin
	
	//Motor is stop at the beginning
	PORTC &= ~((1<<PC0) | (1<<PC1));
	 
    while(1)
    {
		// check if the first switch is pressed (Rotate clock wise)
		if(PINA & (1<<PA0))
		{
			PORTC = PORTC & (~(1<<PC0));
			PORTC = PORTC | (1<<PC1);
		}
		
		// check if the second switch is pressed (Rotate anti-clock wise)
		else if(PINA & (1<<PA1))
		{
			PORTC = PORTC | (1<<PC0);
			PORTC = PORTC & (~(1<<PC1));	
		}
				
		// check if the third switch is pressed (turn off the motor)
		else if(PINA & (1<<PA2))
		{
			PORTC = PORTC & (~(1<<PC0));
			PORTC = PORTC & (~(1<<PC1));
		}				    
    }
}