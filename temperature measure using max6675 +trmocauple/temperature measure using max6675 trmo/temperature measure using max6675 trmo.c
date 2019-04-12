/*
 * temperature_measure_using_max6675_trmo.c
 *
 * Created: 12/30/2018 5:02:51 PM
 *  Author: Ahmed
 */ 

#define F_CPU 8000000ul
#include <avr/io.h>
#include <util/delay.h>
#include "driver/lcd_4bit.h"
#include "driver/SPI_Master.h"

uint8_t hbyte,lbyte;
uint16_t raw;
uint16_t result;
unsigned int temprature;

char T_value[6];

int main(void)
{
	lcd_init();
	SPI_M_Init();
	
    while(1)
    {
		lcd_goto_xy(1,1);
		lcd_print("temp. =");
		SPI_SS_enable();
		_delay_ms(1);
		raw=SPI_M_Read();
		raw<<=8;
		raw|=SPI_M_Read();
		SPI_SS_disable();
		raw&=0b0111111111111111;
		raw>>=2;
		temprature=(raw*0.25)-25;
		lcd_goto_xy(2,1);
		itoa(temprature,T_value,10);
		lcd_print(T_value);
		_delay_ms(300);
        lcd_CLEAR();
		
		
        //TODO:: Please write your application code 
    }
}