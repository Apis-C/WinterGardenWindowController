/*
 * temp.c
 *
 *  Created on: 21.06.2020
 *    @author: Bastian Teßin
 */

#include "adc.h"

/**
 * @brief Initializes the ADC.
 */
void adc_init(void)
{
	ADC_DDR &= ~((1 << TEMP_SENSOR_PIN) | (1 << TEMP_THRESHOLD_PIN)
			| (1 << HUM_SENSOR_PIN));
	ADC_DDR |= ((1 << TEMP_POWERPIN) | (1 << HUM_POWERPIN));
	ADCSRA |= ((1 << ADPS1) | (1 << ADPS0)); //Prescaler F_CPU / 8 => F_ADC = 125kHz (F_CPU 1MHz)
}

static inline void adc_start(uint8_t muxpin)
{
	ADCSRA |= ((1 << ADEN) | (1 << ADSC)); //enable ADC, start conversions
	ADMUX |= (1 << muxpin);
}

static inline adc_stop(uint8_t muxpin)
{
	ADCSRA &= ~((1 << ADEN) | (1 << ADSC));
	ADMUX &= ~(1 << muxpin);
}

/**
 * @brief Reads from ADC on the specified pin, filters the value and stores it in dst.
 * @param pin ADC-Pin.
 * @param dst uint16_t to store the value in.
 */
void analog_read_filtered(uint8_t pin, uint16_t *dst)
{
	*dst=0;
	adc_start(pin);
	for (uint8_t i = 0; i < ADC_FILTER_SIZE; ++i)
	{
		while (!(ADCSRA & (1 << ADIF)));
		*dst += ADC;
	}
	*dst /= ADC_FILTER_SIZE;
	adc_stop(pin);
}

