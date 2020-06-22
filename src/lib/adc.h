/*
 * temp.h
 *
 *  Created on: 21.06.2020
 *      @author: Bastian Teßin
 *      @brief This is the code for getting the temperature of a connected NTC on PIN PC2/ADC2.
 */

#ifndef LIB_TEMP_H_
#define LIB_TEMP_H_

#include <avr/io.h>
#include <stdint.h>
#include "utils.h"

#define ADC_PORT PORTC
#define ADC_DDR DDRC
#define TEMP_POWERPIN PC3
#define HUM_POWERPIN PC1
#define TEMP_SENSOR_PIN PC2			//NTC
#define HUM_SENSOR_PIN PC0
#define TEMP_THRESHOLD_PIN PC4		//POTI
#define ADC_FILTER_SIZE 16

extern volatile uint8_t temp_available;
extern volatile uint8_t hum_available;
extern volatile uint8_t temp_threshold;

void adc_init(void);
void adc_temp_start_measurement(void);
void adc_hum_start_measurement(void);
void adc_get_temperature(int16_t* dst);
void adc_get_humidity(uint8_t* dst);



#endif /* LIB_TEMP_H_ */
