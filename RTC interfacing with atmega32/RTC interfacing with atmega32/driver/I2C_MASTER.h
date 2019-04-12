
/*
 * I2C_MASTER.h
 *
 * Created: 13/Nov/17 2:58:12 PM
 *  Author: Ahmed
 */ 
#define F_CPU 8000000ul		/* Define CPU clock Frequency 8MHz */
#define SCL_CLK 100000L	
#define BITRATE(TWSR) ((F_CPU/SCL_CLK)-16)/(2*pow(4,(TWSR&((1<<TWPS0)|(1<<TWPS1)))))
#include <avr/io.h>		    /* Include AVR std. library file */
#include <util/delay.h>		/* Include Delay header file */
#include <string.h>		    /* Include string header file */
#include <math.h>           /* Include math header file */

#ifndef I2C_MASTER_H_
#define I2C_MASTER_H_
/* Define bit rate */
void I2C_Init();
//****************************************************************************************************************************************
//This function initiate START condition.
uint8_t I2C_Start(char write_address);
//****************************************************************************************************************************************
//This function generates REPEATED START condition for read operation.
uint8_t I2C_Repeated_Start(char read_address);
//****************************************************************************************************************************************
//This function write data/address on bus
uint8_t I2C_Write(char data);
//****************************************************************************************************************************************
//This function read data available on SDA line and
 //returns its acknowledgment to slave device 
 //about data read successful and 
 //also tells slave to transmit another data.
char I2C_Read_Ack();
//****************************************************************************************************************************************
//This function read last needed data byte available on SDA line
// but do not returns acknowledgment of it.
// It used to indicate slave that master don’t want next data 
//and want to stop communication.
char I2C_Read_Nack();
//****************************************************************************************************************************************
//This function initiate STOP condition.
void I2C_Stop();
	
#endif /* I2C_MASTER_H_ */