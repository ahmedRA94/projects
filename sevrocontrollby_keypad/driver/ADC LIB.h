/*
 * ADC_LIB.h
 *
 * Created: 8/26/2017 1:35:21 AM
 *  Author: Ahmed
 */ 
#include <avr/interrupt.h>
#include <math.h>
unsigned int theTenBitResults;
int F;
uint8_t prescaler;
#ifndef ADCLIB_H_
#define ADCLIB_H_

void ADC_Init();
 unsigned int adc_Read(char ch);



#endif /* ADC LIB_H_ */
