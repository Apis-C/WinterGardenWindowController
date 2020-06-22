/*
 * temp.c
 *
 *  Created on: 21.06.2020
 *    @author: Bastian Teßin
 */

#include "adc.h"

uint8_t volatile temp_available;
uint8_t volatile temp_threshold;
uint8_t volatile hum_available;

uint16_t adc_filter[ADC_FILTER_SIZE];
uint8_t volatile adc_isr_decider;
enum
{
	NOTHING_ACTIVE, TEMP_ACTIVE, HUM_ACTIVE
};

/**
 * @brief Initializes the ADC.
 */
void adc_init(void)
{
	ADC_DDR &= ~((1 << TEMP_SENSOR_PIN) | (1 << TEMP_THRESHOLD_PIN)
			| (1 << HUM_SENSOR_PIN));
	ADC_DDR |= ((1 << TEMP_POWERPIN) | (1 << HUM_POWERPIN));
	ADCSRA |= ((1 << ADPS1) | (1 << ADPS0)); //Prescaler F_CPU / 8 => F_ADC = 125kHz
}

static inline void adc_start(uint8_t muxpin)
{
	ADCSRA |= ((1 << ADEN) | (1 << ADSC)(1 << ADIE)); //enable ADC, start conversions, enable ADC-Interrupts
	ADMUX |= (1 << muxpin);
}

/**
 * @brief Starts a temperature measurement and clears temp_available.
 */
void adc_temp_start_measurement(void)
{
	temp_available = 0;
	ADC_PORT |= (1 << TEMP_POWERPIN);				//turn on temperature sensor
	adc_start(TEMP_SENSOR_PIN);
	adc_isr_decider = TEMP_ACTIVE;
}

/**
 * @brief Starts a humidity measurement.
 */
void adc_hum_start_measurement(void)
{
	hum_available = 0;
	ADC_PORT |= (1 << HUM_POWERPIN);				//turn on humidity sensor
	adc_start(HUM_SENSOR_PIN);
	adc_isr_decider = HUM_ACTIVE;
}

/**
 * @brief Averages the ADC-measured values.
 * @param dst
 */
static void adc_average(auto *dst)
{
	for (uint8_t i = 0; i < ADC_FILTER_SIZE; ++i)
	{
		*dst += adc_filter[i];
	}
	*dst /= ADC_FILTER_SIZE; //TODO compute to real temperature
}

/**
 * @brief Returns the measured temperature and clears temp_available. If this is called while a conversion is running, nothing will be done.
 * @param dst The variable to write to.
 */
void adc_get_temperature(int16_t *dst)
{
	if (temp_available)
	{
		temp_available = 0;
		adc_average(dst);
	}
	//TODO compute to temperature
}

/**
 * @brief Returns the measured humidity and clears hum_available. If this is called while a conversion is running, nothing will be done.
 * @param dst The variable to write to.
 */
void adc_get_humidity(uint8_t *dst)
{
	if (temp_available)
	{
		temp_available = 0;
		adc_average(dst);
	}
	//TODO compute to humidity
}

ISR(ADC_vect) //add new value to the filter
{
	static uint8_t i = 0;
	if (i >= ADC_FILTER_SIZE)	//filter full
	{
		ADMUX &= ~((1 << MUX3) | (1 << MUX2) | (1 << MUX1) | (1 << MUX0)); //close connection to ADC
		ADCSRA &= ~((1 << ADEN) | (1 << ADSC)(1 << ADIE));		//shut down ADC
		ADC_PORT &= ((1 << TEMP_POWERPIN) | (1 << HUM_POWERPIN));//turn off sensors
		i = 0;

		switch (adc_isr_decider)
		{
		case NOTHING_ACTIVE:
			break;

		case TEMP_ACTIVE:
			temp_available = 1;
			break;

		case HUM_ACTIVE:
			hum_available = 1;
			break;

		default:
			break;
		}
	}
	else //filter not full
	{
		adc_filter[i] = ADC;
		++i;
	}
}
