/*
 * MC2.c
 *
 * Created: 4/11/2015 8:32:25 PM
 *  Author: Ahmed Abdelkader
 */ 

#include "SPI.h"

#define SWITCH_PRESSED 1
#define SWITCH_NOT_PRESSED 0

int main(void)
{
	char data_received;
	SPI_initSlave();
	DDRC = DDRC | (1<<PC3); //configure PC3 as output pin 
    while(1)
    {
		data_received = SPI_recieveByte(); //receive data from the master Micro-controller
		if(data_received == SWITCH_PRESSED)
		{
			PORTC = PORTC | (1<<PC3); //Led on
		}
		else if(data_received == SWITCH_NOT_PRESSED)
		{
			PORTC = PORTC & (~(1<<PC3)); //Led off
		}						
    }
}