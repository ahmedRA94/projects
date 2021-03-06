/*
 * ADC_LIB.c
 *
 * Created: 8/26/2017 1:32:38 AM
 *  Author: Ahmed
 */ 

#include <avr/io.h>

//you should define the prescaler before include the library
//#define prescaler x
//x = F_CPU/F_ADC
#include "ADC LIB.h"
//*****************************************************************************************************************************************************************
//function to initialize ADC
void ADC_Init()
{
	 //PART A as input
	DDRA =0x00;
	// AREF = AVcc
	ADMUX = (1<<REFS0);
	
	// ADC Enable and prescaler of 
	ADCSRA |= (1<<ADEN)|(1<<ADIE)|(prescaler<<7);
	sei();

}
//******************************************************************************************************************************************************************
//function to read adc value
// a=ADC_Read (channel num)
  unsigned int adc_Read(char ch)
 {
	 // select the corresponding channel 0~7
	 // ANDing with '7' will always keep the value
	 // of 'ch' between 0 and 7
	 ch &= 0b00000111;  // AND operation with 7
	 ADMUX = (ADMUX & 0xF8)|ch;     // clears the bottom 3 bits before ORing
	 // start single conversion
	 // write '1' to ADSC
	 ADCSRA |= (1<<ADSC);
	 return (theTenBitResults);
 }
 //***************************************************************************************************************************************************************************
ISR(ADC_vect)
{
	int theLowADC = ADCL;
	theTenBitResults = ADCH<<8|theLowADC;
	ADCSRA |= 1<<ADSC;
} 
	


