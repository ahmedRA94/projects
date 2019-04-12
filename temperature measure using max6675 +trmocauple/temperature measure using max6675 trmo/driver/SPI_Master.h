/*
 * SPI_Master_LIB.h
 *
 * Created: 9/8/2017 10:34:09 PM
 *  Author: Ahmed
 */ 
#define F_CPU 8000000ul
#include <avr/io.h>
#define MOSI 3
#define MISO 4
#define SCK 5
#define SS 2
#ifndef SPI_MASTER_H_
#define SPI_MASTER_H_

void SPI_M_Init();
void SPI_M_Write(char data);
char SPI_M_Read();
void SPI_SS_enable();
void SPI_SS_disable();




#endif /* SPI_MASTER_H_ */