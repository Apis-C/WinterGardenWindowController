/*
 * uart.h
 *
 *  Created on: 21.06.2020
 *      Author: Bastian Teßin
 */

#ifndef LIB_UART_H_
#define LIB_UART_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

void uart_init(uint16_t baud);
void uart_prints(const char *s);
void uart_printi(int32_t i);

#endif /* LIB_UART_H_ */
