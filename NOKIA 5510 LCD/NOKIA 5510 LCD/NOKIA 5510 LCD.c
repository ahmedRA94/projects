/*
 * NOKIA_5510_LCD.c
 *
 * Created: 9/25/2017 1:23:21 AM
 *  Author: Ahmed
 */ 

#define F_CPU 8000000ul
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>
#include "Font.h"

#define MOSI 5
#define MISO 6
#define SCK 7
#define SS 4
#define DC 1
#define RST 0



void SPI_M_Init()					/* SPI Initialize function */
{
	DDRB = (1<<MOSI)|(1<<SCK)|(1<<SS)|(1<<RST)|(1<<DC);				/* Set MOSI and SCK output, all others input */
	PORTB |= (1<<RST);												/* define reset pin as a output */
	DDRB &= ~(1<<MISO);												/* define MISO pin as a input */
	PORTB |= (1<<SS);												/* Make SS pin as a output */
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);							/* Enable SPE, MSTR and SPR0 bit in SPI control register */
}
void SPI_M_Write(char write_data)		/* SPI write data function */
{
	
	SPDR = write_data;
	while(!(SPSR & (1<<SPIF)));
}
void SPI_SS_enable()
{
	PORTB&=~(1<<PB4);
}
void SPI_SS_disable(){
	PORTB|=(1<<PB4);
}
void N5110_Reset()					/* reset the Display at the beginning of initialization */
{
	PORTB &= ~(1<<RST);
	_delay_ms(100);
	PORTB |= (1<<RST);
}

void N5110_Cmnd(char DATA)
{
	PORTB &= ~(1<<DC);				/* make DC pin to logic zero for command operation */
	SPI_SS_enable();				/* enable SS pin to slave selection */
	SPI_M_Write(DATA);				/* send data on data register */
	PORTB |= (1<<DC);				/* make DC pin to logic high for data operation */
	SPI_SS_disable();
}
void N5110_init()
{
	SPI_M_Init();
	N5110_Reset();					/* reset the display */
	N5110_Cmnd(0x21);				/* command set in addition mode */
	N5110_Cmnd(0xC0);				/* set the voltage by sending C0 means VOP = 5V */
	N5110_Cmnd(0x07);				/* set the temp. coefficient to 3 */
	N5110_Cmnd(0x13);				/* set value of Voltage Bias System */
	N5110_Cmnd(0x20);				/* command set in basic mode */
	N5110_Cmnd(0x0C);				/* display result in normal mode */
}
void N5110_Data(char *DATA)
{
	PORTB |= (1<<DC);									/* make DC pin to logic high for data operation */
	SPI_SS_enable();									/* enable SS pin to slave selection */
	int lenan = strlen(DATA);							/* measure the length of data */
	for (int g=0; g<lenan; g++)
	{
		for (int index=0; index<5; index++)
		{
			SPI_M_Write(ASCII[DATA[g] - 0x20][index]);	/* send the data on data register */
		}
		SPI_M_Write(0x00);
	}
	SPI_SS_disable();
}
void N5110_clear()					/* clear the Display */
{
	SPI_SS_enable();
	PORTB |= (1<<DC);
	for (int k=0; k<=503; k++)
	{
		SPI_M_Write(0x00);
	}
	PORTB &= ~(1<<DC);
	SPI_SS_disable();
}
void N5110_setXY(char x, char y)		/* set the column and row */
{
	N5110_Cmnd(0x40+x);
	N5110_Cmnd(0x80+y);
}
void N5110_image(const unsigned char *image_data)		/* clear the Display */
{
	SPI_SS_enable();
	PORTB |= (1<<DC);
	for (int k=0; k<=503; k++)
	{
		SPI_M_Write(image_data[k]);
	}
	PORTB &= ~(1<<DC);
	SPI_SS_disable();
}

void lcd_drow_line(char u,char fon){
	N5110_Cmnd(0x40+u);
	N5110_Cmnd(0x80);
	SPI_SS_enable();
	PORTB |= (1<<DC);
	for (int k=0; k<=83;k++)
	{
		SPI_M_Write(fon);
	}
	PORTB &= ~(1<<DC);
	SPI_SS_disable();
}
void lcd_drow_colum(char l){
	N5110_Cmnd(0x80+l);
	SPI_SS_enable();
	PORTB |= (1<<DC);
	for (int k=0; k<=5;k++)
	{N5110_Cmnd(0x40+k);
		N5110_Cmnd(0x80+l);
		SPI_SS_enable();
		SPI_M_Write(0xff);
	}
	PORTB &= ~(1<<DC);
	SPI_SS_disable();
}
void N5110_frame(){
	lcd_drow_line(0,0x01);
	lcd_drow_line(5,0x80);
	lcd_drow_colum(83);
	lcd_drow_colum(0);
}

int i;
char rxt[4];


int main(void)
{ 
	 N5110_init();
	N5110_setXY(1,40);
	N5110_Data("Hallo ahmed 1234567890+=*/.-");
	N5110_setXY(3,0);
	N5110_Data("abcdefghkilmno");
	
	_delay_ms(1000);
	N5110_clear();
	
    while(1)
    { N5110_frame();
		for (i=0;i<5;i++)
    { N5110_setXY(1,(i*7)+3);
		itoa(i,rxt,10);
		N5110_Data(rxt);
		_delay_ms(1000);
		
    }
	
        //TODO:: Please write your application code 
    }
}