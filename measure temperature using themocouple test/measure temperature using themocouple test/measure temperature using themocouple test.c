/*
 * measure_temperature_using_themocouple_test.c
 *
 * Created: 12/28/2018 9:12:35 PM
 *  Author: Ahmed
 */ 

#define F_CPU 8000000ul
#include <avr/io.h>
#include <util/delay.h>
#include "driver/ADC LIB.h"
#include "driver/lcd_4bit.h"
volatile unsigned int adc_val;
unsigned int temprature_val;
char temp[5];

int main(void)
{
	ADC_Init(125000);
	lcd_init();
    while(1)
    {
		lcd_goto_xy(1,1);
		lcd_print("temperatur=");
		adc_val=adc_Read(0);       /* store the analog data from channel 0 on  a variable */
		temprature_val=((500.0 *adc_val)/1024.0) -25;	 /* convert analog voltage into ºC and subtract the offset voltage */
		itoa(temprature_val,temp,10);
		lcd_goto_xy(1,13);
		lcd_print(temp);
		_delay_ms(500);
		lcd_CLEAR(); 
		 
		
		
        //TODO:: Please write your application code 
    }
}