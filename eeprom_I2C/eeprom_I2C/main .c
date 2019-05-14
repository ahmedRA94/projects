/*
 * eeprom_I2C.c
 *
 * Created: 8/1/2018 3:13:19 PM
 *  Author: Ahmed
 */ 

#define F_CPU 8000000ul
#include <avr/io.h>
#include <util/delay.h>
#include "lcd_4bit.h"
#include "I2C_MASTER.h"

#define EEPROM_Write_Addess		0xA0
#define EEPROM_Read_Addess		0xA1


int main(void)
{ lcd_init();
	I2C_Init();
	char txt[6]="12345";
	char rxt[7];
    lcd_goto_xy(1,1);
	    lcd_print("massage is ");		
		I2C_Start(EEPROM_Write_Addess);   /* Start I2C with device write address */
		I2C_Write(0x00);                /* Write start memory address for data write */  
        for (int i=0;i<strlen(txt);i++)/* Write array data */
        {
	        I2C_Write(txt[i]);
        }
        I2C_Stop();			              /* Stop I2C */
        _delay_ms(10);
		I2C_Start(EEPROM_Write_Addess);   /* Start I2C with device write address */
		I2C_Write(0x00);
		lcd_goto_xy(2,5);
		I2C_Repeated_Start(EEPROM_Read_Addess);	            /* Write start memory address */
		 for (int i = 0; i<strlen(txt); i++)                /* Read data with acknowledgment */
		 {
		     rxt[i]=I2C_Read_Ack();
		 }
		 I2C_Read_Nack();	/* Read flush data with nack */
		  I2C_Stop();
		  _delay_ms(1200);
		  lcd_print(rxt);       /* Stop I2C */
		return 0;		
	//TODO:: Please write your application code 
    }
