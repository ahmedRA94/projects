/*
 * RTC_interfacing_with_atmega32.c
 *
 * Created: 10/14/2018 12:46:34 PM
 *  Author: Ahmed
 */ 

#define F_CPU 8000000ul
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <string.h>
#include "driver/I2C_MASTER.h"
#include "driver/lcd_4bit.h"

void RTC_Clock_Write(char _hour, char _minute, char _second,char AMPM);
void RTC_Calendar_Write(char _day, char _date, char _month, char _year);
void RTC_Read_Clock(char read_clock_address);
void RTC_Read_Calendar(char read_calendar_address);
unsigned char MSB(unsigned char x);
unsigned char LSB(unsigned char X);
#define Device_Write_address	0xD0	/* Define RTC DS1307 slave write address */
#define Device_Read_address	    0xD1	/* Make LSB bit high of slave address for read */
#define TimeFormat12		    0x40	/* Define 12 hour format */


unsigned char second,minute,hour,day,date,month,year;
unsigned int d;
char  time[9];
char dat[4];
char* monthe[13]={"jun","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"};
char* days[8]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};		
char nod[3];
int m;
int main(void)
{   I2C_Init();
	lcd_init();
RTC_Clock_Write(0X11,0X59,0X56,0x40);
    while(1)
    { RTC_Read_Clock(0x00);
	  time[0]=MSB(hour&0b00011111);
	  time[1]=LSB(hour);
		  if ((hour&(1<<5)))
		{ lcd_goto_xy(1,15);
		lcd_print("PM");}
        else if (!(hour&(1<<5)))
		{			 
		lcd_goto_xy(1,15);
		lcd_print("AM");}
	  time[2]=':';
	  time[3]=MSB(minute);
	  time[4]=LSB(minute);
	  time[5]=':';
	  time[6]=MSB(second);
	  time[7]=LSB(second);
	  lcd_goto_xy(1,1);
	  lcd_print("TIME:");
	    lcd_goto_xy(1,6);
		lcd_print(time);
		
	
		RTC_Read_Calendar(0x03);
		  d=day;
		  lcd_goto_xy(2,1);
		  lcd_print(days[d-1]);
		  dat[0]=MSB(date);
		  dat[1]=LSB(date);
		  dat[2]=' ';
		  nod[0]=MSB(month);
		  nod[1]=LSB(month);
		 m=atoi(nod);
		  lcd_goto_xy(2,5);
		  lcd_print(dat);
		  lcd_goto_xy(2,8);
		  lcd_print(monthe[m-1]);
		  _delay_ms(200);
		  lcd_CLEAR();
		}
	 	
		
        //TODO:: Please write your application code 
    }

void RTC_Read_Clock(char read_clock_address)
{
	I2C_Start(Device_Write_address);/* Start I2C communication with RTC */
	I2C_Write(read_clock_address);	/* Write address to read */
	I2C_Repeated_Start(Device_Read_address);/* Repeated start with device read address */

	second = I2C_Read_Ack();	/* Read second */
	minute = I2C_Read_Ack();	/* Read minute */
	hour = I2C_Read_Nack();		/* Read hour with Nack */
	I2C_Stop();			/* Stop i2C communication */
}
/* function for clock */

void RTC_Clock_Write(char _hour, char _minute, char _second,char timeformat)
{
	_hour=timeformat|_hour;               // ox00 for 24 ,0x40 for AM ,0x60 for PM 
	I2C_Start(Device_Write_address);/* Start I2C communication with RTC */
	I2C_Write(0x00);			/* Write 0 address for second */
	I2C_Write(_second);		/* Write second on 00 location */
	I2C_Write(_minute);		/* Write minute on 01(auto increment) location */
	I2C_Write(_hour);		/* Write hour on 02 location */
	I2C_Stop();			/* Stop I2C communication */
}
/* function for calendar */
void RTC_Calendar_Write(char _day, char _date, char _month, char _year)
{
	I2C_Start(Device_Write_address);/* Start I2C communication with RTC */
	I2C_Write(0x03);			/* Write 3 address for day */
	I2C_Write(_day);		/* Write day on 03 location */
	I2C_Write(_date);		/* Write date on 04 location */
	I2C_Write(_month);		/* Write month on 05 location */
	I2C_Write(_year);		/* Write year on 06 location */
	I2C_Stop();			/* Stop I2C communication */
}

void RTC_Read_Calendar(char read_calendar_address)
{
	I2C_Start(Device_Write_address);
	I2C_Write(read_calendar_address);
	I2C_Repeated_Start(Device_Read_address);

	day = I2C_Read_Ack();		/* Read day */
	date = I2C_Read_Ack();		/* Read date */
	month = I2C_Read_Ack();		/* Read month */
	year = I2C_Read_Nack();		/* Read the year with Nack */
	I2C_Stop();			/* Stop i2C communication */
}

unsigned char LSB(unsigned char X){
	return((X&0X0F) +'0');
}
unsigned char MSB(unsigned char x){
	return((x>>4) +'0' );
}