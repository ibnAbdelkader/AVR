/*
 * MC2.c
 *
 * Created: 25/04/2015 11:12:30 �
 *  Author: Ahmed Abdelkader
 */ 

#include "UART.h"
#include "LCD.h"

int main(void)
{
	uint8 key;
	UART_init();
	LCD_init();
    while(1)
    {
		key = UART_recieveByte(); //receive the pressed key from uart
		if( (key >= 0) && (key <= 9) )
		{
			LCD_intgerToString(key); //display the pressed keypad switch	
		}
		else
		{
			LCD_displayCharacter(key); //display the pressed keypad switch	
		}		 
    }
}