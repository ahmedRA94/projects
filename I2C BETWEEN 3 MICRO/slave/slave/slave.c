/*
 * slave.c
 *
 * Created: 8/1/2018 10:06:29 PM
 *  Author: Ahmed
 */ 

#define F_CPU 8000000ul
#include <avr/io.h>
#include <util/delay.h>
#include "I2C_SLAVE.h"

int main(void)
{I2C_Slave_Init(0x40);
	DDRB=0xff;
	PORTB=0x00;
    while(1)
    {   I2C_Slave_Listen();
		PORTB=I2C_Slave_Receive();
        //TODO:: Please write your application code 
    }
}