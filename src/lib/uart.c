/*
 * uart.c
 *
 *  Created on: 21.06.2020
 *     @author: Bastian Teßin
 */

#include "uart.h"

static uint8_t pos;
static char* buffer;


void uart_init(uint16_t baud)
{
	cli();
	while (!(UCSR0A & (1 << TXC0)))
		;
	UBRR0 = (F_CPU / (baud << 4)) - 1;
	UCSR0A |= (1 << U2X0); //double speed operation => less error

	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00); //8 bit character size, 1 stop bit
	sei();
}



void uart_prints(const char *s)
{
	while(!(UCSR0A & (1<<UDRE0)));
	buffer = s;
	UCSR0B |= (1 << TXEN0);
	UBRR0 = buffer[0];
	pos = 1;
}

void uart_printi(int32_t i)
{
	uart_prints("uart_printi() nicht implementiert\n");

	/*
	intbuffer = 0;
	for (uint8_t i = 0; i<size; ++i)
	{
		intbuffer[i]
	}
	*/
}

ISR(USART_UDRE_vect)
{
	if(buffer[pos] != '\0'){
		UBRR0 = buffer[pos++];
	}
	else
	{
		UCSR0B &= ~(1 << TXEN0);
	}
}
