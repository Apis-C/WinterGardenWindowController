/*
 * utils.c
 *
 *  Created on: 22.06.2020
 *      @author: Bastian Teßin
 */
#include "utils.h"

/**
 * @breif prints the given code to the board-leds.
 * @param val A maximum of 15 is possible.
 */
void led_print(uint8_t val)
{
	LED_DDR &= ~(0x0F<<4);

	if(val>0x0F)
	{
		val=0x0F;
	}

	LED_DDR |= val<<4;
}

#define QUEUE_LEN  10
event_t event_queue[QUEUE_LEN];
uint8_t read;
uint8_t write;

/**
 * @brief Queues an event_t in a fifo-buffer
 * @param ev event_t
 */
void queue_event(event_t ev)
{
	event_queue[write] = ev;
	write = (write+1)%QUEUE_LEN;

}

/**
 * @brief Reads and returns an event_t from an event_t-fifo-buffer.
 * @return An unhandled event_t, EV_NOTHING else.
 */
event_t get_event(void)
{
	if (read!=write)
	{
		read = (read+1)%QUEUE_LEN;
		return event_queue[read];
	} else
	{
		return EV_NOTHING;
	}
}
