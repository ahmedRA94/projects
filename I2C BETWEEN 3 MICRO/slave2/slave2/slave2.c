/*
 * slave2.c
 *
 * Created: 8/3/2018 6:46:01 PM
 *  Author: Ahmed
 */ 

#define F_CPU 8000000ul
#include <avr/io.h>
#include <util/delay.h>
#include "I2C_SLAVE.h"

int main(void)
{   I2C_Slave_Init(0x50);
	DDRD=0xff;
	PORTD=0x00;
    while(1)
    {  I2C_Slave_Listen();
		PORTD=I2C_Slave_Receive();
        //TODO:: Please write your application code 
    }
}