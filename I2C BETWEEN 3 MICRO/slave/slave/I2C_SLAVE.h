/*
 * I2C_SLAVE.h
 *
 * Created: 8/1/2018 7:08:27 PM
 *  Author: Ahmed
 */ 
#define F_CPU 8000000ul
#include <avr/io.h>
#ifndef I2C_SLAVE_H_
#define I2C_SLAVE_H_

void I2C_Slave_Init(uint8_t slave_address);      /* I2C slave initialize function with Slave address */
int8_t I2C_Slave_Listen();                       /* I2C slave listen function */
int8_t I2C_Slave_Transmit(char data);            /* I2C slave transmit function */
char I2C_Slave_Receive();						/* I2C slave receive function */

#endif /* I2C_SLAVE_H_ */