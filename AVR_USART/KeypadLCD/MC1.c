/*
 * MC1.c
 *
 * Created: 25/04/2015 11:09:26 ã
 *  Author: Ahmed Abdelkader
 */ 

#include "Keypad.h"
#include "UART.h"

int main(void)
{
	uint8 key;
	UART_init();
    while(1)
    {
		key = KeyPad_getPressedKey(); //get the pressed key
		UART_sendByte(key); //send the pressed key to the second MC using uart
		_delay_ms(500);
    }
}