/*
 * SPI_Master.c
 *
 * Created: 9/8/2017 10:26:26 PM
 *  Author: Ahmed
 */ 


#include "SPI_Master.h"
//function to SPI Initialization
//**************************************************************************************
void SPI_M_Init()					/* SPI Initialize function */
{
	DDRB = (1<<MOSI)|(1<<SCK)|(1<<SS);				/* Set MOSI and SCK output, all others input */												/* define reset pin as a output */
	DDRB &= ~(1<<MISO);												/* define MISO pin as a input */
	PORTB |= (1<<SS);												/* Make SS pin as a output */
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);							/* Enable SPE, MSTR and SPR0 bit in SPI control register */

}
//********************************************************************************************************
//SPI_Write function.
void SPI_M_Write(char data)		/* SPI write data function */
{
	
	SPDR = data;			/* Write data to SPI data register */
	while(!(SPSR & (1<<SPIF)));	/* Wait till transmission complete */
}
//********************************************************************************************************
//SPI_Read function
char SPI_M_Read()				/* SPI read data function */
{
	SPDR = 0xFF;
	while(!(SPSR & (1<<SPIF)));	/* Wait till reception complete */
	return(SPDR);			/* Return received data */
}
//**********************************************************************************************************
void SPI_SS_enable()
{
	PORTB&=~(1<<SS);
}
//**********************************************************************************************************
void SPI_SS_disable(){
	PORTB|=(1<<SS);
	}
//**********************************************************************************************************	