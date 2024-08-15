/*
 * SPI_Test.c
 *
 * Created: 4/11/2015 8:20:28 PM
 *  Author: Ahmed Abdelkader
 */ 

#include "SPI.h"

#define SWITCH_PRESSED 1
#define SWITCH_NOT_PRESSED 0

int main(void)
{
	SPI_initMaster();
	DDRA = DDRA & (~(1<<PA0)); //configure PA0 as input pin
    while(1)
    {
		if(PINA & (1<<PA0)) //if switch is pressed
		{
			SPI_sendByte(SWITCH_PRESSED);
		}
		else
		{
			SPI_sendByte(SWITCH_NOT_PRESSED);
		}						
    }
}