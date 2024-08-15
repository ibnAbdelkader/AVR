/*
 * ADC.c
 *
 * Created: 24/04/2015 02:56:13 م
 *  Author: Ahmed Abdelkader
 */ 

#include "ADC.h"

void ADC_init(void)
{
	/* Bits Description:
	 * REFS1:0=00 to choose to connect external reference voltage by input this voltage through AREF pin
	 * ADLAR = 0 right adjusted
	 * MUX4:0 = 00000 to choose channel 0 as initialization 
	 */
	ADMUX = 0;
	
	/* Bits Description:
	 * ADEN=1 enable ADC
	 * ADPS2:0=011 to choose ADC_Clock=F_CPU/8=1Mhz/8=125Khz --> ADC must operate in range 50-200Khz
	 */ 
	ADCSRA = (1<<ADEN) | (1<<ADPS1) | (1<<ADPS0);     
}

uint16 ADC_read(uint8 channel_num)
{
	channel_num &=0x07; //must be from 0 --> 7
	
	ADMUX &= 0xF8; //clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel  
	
	ADMUX = ADMUX | channel_num; //choose the correct channel by setting the channel number in MUX4:0 bits
	
	ADCSRA |= (1<<ADSC); //start conversion write '1' to ADSC
	
	while(!(ADCSRA & (1<<ADIF))); // wait for conversion to complete ADIF becomes '1'
	
	ADCSRA |=(1<<ADIF); //clear ADIF by write'1' to it :)
	
	return ADC; //return the data register
}