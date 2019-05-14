/*
 * ADC_LIB.h
 *
 * Created: 8/26/2017 1:35:21 AM
 *  Author: Ahmed
 */ 
#define F_CPU 8000000ul
#include <avr/interrupt.h>
#include <math.h>
uint16_t theTenBitResults;
int F;
uint8_t prescaler;
#ifndef ADCLIB_H_
#define ADCLIB_H_

void ADC_Init(uint32_t F_ADC);
 uint16_t adc_Read(uint8_t ch);



#endif /* ADC LIB_H_ */