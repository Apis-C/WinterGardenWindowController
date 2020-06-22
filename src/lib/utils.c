/*
 * utils.c
 *
 *  Created on: 22.06.2020
 *      @author: Bastian Teßin
 */
#include "utils.h"

void led_print(uint8_t val)
{
	LED_DDR &= ~( (1<<PD4) | (1<<PD5) | (1<<PD6) | (1<<PD7) );

	if(val>0x10)
	{
		val=0x10;
	}

	LED_DDR |= val<<4;
}
