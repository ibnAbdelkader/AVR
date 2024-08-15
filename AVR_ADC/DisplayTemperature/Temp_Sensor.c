/*
 * Temp_Sensor.c
 *
 * Created: 24/04/2015 02:55:48 م
 *  Author: Ahmed Abdelkader
 */ 

#include "ADC.h"
#include "LCD.h"

int main(void)
{
	uint32 temp;
	LCD_init();
	ADC_init();
	LCD_clearScreen(); //clear LCD at the beginning
	LCD_displayString("Temp = ");
	LCD_goToRowColumn(0,10);
	LCD_displayCharacter('C');
    while(1)
    {
		LCD_goToRowColumn(0,7); //to display the number
		temp = ADC_read(0); //Read channel zero where the temp sensor is connect
		temp = (temp*150*5)/(1023*1.5); //calculate the temp
		LCD_intgerToString(temp); //display the temp on LCD screen 
    }
}