/*
 * utils.h
 *
 *  Created on: 22.06.2020
 *      Author: Bastian Teßin
 */

#ifndef SRC_LIB_UTILS_H_
#define SRC_LIB_UTILS_H_
#include <stdint.h>
#include <avr/io.h>

#define LED_DDR DDRD

typedef enum
{ST_GET_USER_OPEN,
	ST_GET_USER_CLOSE,
	ST_MEAS_HUM,
	ST_MEAS_TEMP,
	ST_SLEEP,
	ST_WAKEUP
} state_t;

typedef enum
{EV_TEMP_THRESH_OPEN,
	EV_TEMP_THRESH_CLOSE,
	EV_RAIN,
	EV_NO_RAIN,
	EV_WIN_CLOSED,
	EV_WIN_OPENED,
	EV_WAKEUP,
	EV_SLEEP,
	EV_NOTHING
} event_t;



void led_print(uint8_t val);
void queue_event(event_t ev);
event_t get_event(void);

#endif /* SRC_LIB_UTILS_H_ */
