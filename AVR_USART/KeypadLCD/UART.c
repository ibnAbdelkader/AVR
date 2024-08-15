/*
 * USART.c
 *
 * Created: 2/19/2015 8:07:58 PM
 * Author: Ahmed Abdelkader
 */

#include "UART.h"
 
void UART_init(void)
{

	UCSRA = (1<<U2X); //double transmission speed
	
	UCSRB = (1<<RXEN) | (1<<TXEN); //enable UART as transmitter and receiver.
	
	UCSRC = (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1); //8-bit data, NO parity, one stop bit and asynch 
	
	/* baud rate=9600 & Fosc=1MHz -->  UBBR=( Fosc / (8 * baud rate) ) - 1 = 12 */  
	UBRRH = 0;
	UBRRL = 12;
}
	
void UART_sendByte(const uint8 data)
{
	while(!(UCSRA & (1<<UDRE))){} //UDRE flag is set when the buffer is empty and ready for transmitting a new byte so wait until this flag is set to one.
	UDR = data;
}

uint8 UART_recieveByte(void)
{
	while(!(UCSRA & (1<<RXC))){} //RXC flag is set when the UART receive data so until this flag is set to one
    return UDR;		
}

void UART_sendString(const uint8 *Str)
{
	uint8 i = 0;
	while(Str[i] != '\0')
	{
		UART_sendByte(Str[i]);
		i++;
	}
}

void UART_receiveString(uint8 *Str)
{
	uint8 i = 0;
	Str[i] = UART_recieveByte();
	while(Str[i] != '#')
	{
		i++;
		Str[i] = UART_recieveByte();
	}
	Str[i] = '\0';
}