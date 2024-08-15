/*
 * MC2.c
 *
 * Created: 25/04/2015 11:32:23 م
 *  Author: Ahmed Abdelkader
 */ 

#include "SPI.h"
#include "LCD.h"

int main(void)
{
	uint8 key;
	LCD_init();
	SPI_initSlave(); //initialize salve MC
    while(1)
    {
		key = SPI_recieveByte();  //receive the pressed key from spi
		if((key>=0) && (key<=9))
		{
			LCD_intgerToString(key); //display the pressed key
		}
		else
		{
			LCD_displayCharacter(key);
		}	
    }
}