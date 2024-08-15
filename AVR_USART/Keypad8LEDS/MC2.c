/*
 * MC2.c
 *
 * Created: 9/19/2014 10:25:58 PM
 *  Author: Ahmed Abdelkader
 */ 

#include "UART.h"

int main(void)
{
	uint8 key_num;
	UART_init();
	
	DDRC  = 0xFF; //configure PORTC as output port
    while(1)
    {
        key_num = UART_recieveByte(); //Receive LED number that required to be ON
		PORTC = (1<<key_num); 
    }
}