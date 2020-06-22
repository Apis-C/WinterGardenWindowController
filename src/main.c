/*
 * main.c
 *
 *  Created on: 18.06.2020
 *      @author: Bastian Teßin
 *      @brief This embedded code controlls the indoor-temprature and (outdoor-)rain based opening
 *      and closing of widows. The underlaying board is a Microchip ATMega328P. There is no communiction but the UART.
 */

#include <avr/io.h>
#include "lib/utils.h"
#include <stdlib.h>
#include <stdint.h>
#include <avr/interrupt.h>


void main(void)
{
	//Init LEDs
	DDRD |= ((1<<PD4) | (1<<PB5) | (1<<PD6) | (1<<PD7));

	//get hum manually
	//get temperature manually
	sei();
	while(1)
	{

	}
}
