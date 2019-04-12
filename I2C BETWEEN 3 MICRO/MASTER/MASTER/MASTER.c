/*
 * MASTER.c
 *
 * Created: 8/1/2018 9:53:12 PM
 *  Author: Ahmed
 */ 

#define F_CPU 8000000ul
#include <avr/io.h>
#include <util/delay.h>
#include "I2C_MASTER.h"

int main(void)
{ DDRA&=0x00;
	I2C_Init();
	 char count=0;
	 char vtx=3;
    while(1)
    {	
	   if (PINA&(1<<PA0))
		{	vtx++;
		count++;
		I2C_Start(0x40);
		I2C_Write(count);
		I2C_Repeated_Start(0x50);
		I2C_Write(vtx);
		I2C_Stop();
		_delay_ms(500);
		while(PINA&(1<<PA0));
		}
        //TODO:: Please write your application code 
    }
}