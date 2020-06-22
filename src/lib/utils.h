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

void led_print(uint8_t val);

#endif /* SRC_LIB_UTILS_H_ */
