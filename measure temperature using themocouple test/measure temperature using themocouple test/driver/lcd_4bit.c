/*
 * lcd_4bit.c
 *
 * Created: 7/24/2017 10:35:17 PM
 *  Author: Ahmed
 */ 
#include "lcd_4bit.h"
//**********************************************************************************************
void lcd_command(unsigned char cmd){
	lcd_PRT=(lcd_PRT & 0x0F)|(cmd & 0xF0);
	lcd_PRT&=~(1<<lcd_RS);
	lcd_PRT&=~(1<<lcd_RW);
	lcd_PRT|=(1<<lcd_EN);
	_delay_us(50);
	lcd_PRT&=~(1<<lcd_EN);
	_delay_us(50);
	lcd_PRT =(lcd_PRT & 0x0F)|(cmd<<4);
	lcd_PRT|=(1<<lcd_EN);
	_delay_us(50);
	lcd_PRT&=~(1<<lcd_EN);

}	
//********************************************************************************************
void lcd_data(unsigned char data){
	lcd_PRT=(lcd_PRT & 0x0F)|(data & 0xF0);
	lcd_PRT|=(1<<lcd_RS);
	lcd_PRT&=~(1<<lcd_RW);
	lcd_PRT|=(1<<lcd_EN);
	_delay_us(50);
	lcd_PRT&=~(1<<lcd_EN);
	_delay_us(50);
	lcd_PRT =(lcd_PRT & 0x0F)|(data<<4);
	lcd_PRT|=(1<<lcd_EN);
	_delay_us(100);
	lcd_PRT&=~(1<<lcd_EN);	
}
//***********************************************************************************************
//function for lcd initialize.
//lcd_init();
void lcd_init(){
_delay_ms(5);
	lcd_DDR|=0xff;
	lcd_PRT&=~(1<<lcd_EN);
	_delay_us(2000);
	lcd_command(0x33);
	_delay_us(50);
	lcd_command(0x32);
	_delay_us(50);
	lcd_command(0x28);
	_delay_us(50);
	lcd_command(0x0E);
	_delay_us(50);
	lcd_command(0x01);
	_delay_us(2000);
	lcd_command(0x06);
}
//*********************************************************************************************************
//function to locate the position.
//lcd_goto_xy(row,columm);
//line 1 of lcd=row 1. ,line2 of lcd=row2
//columm 1 of lcd =columm 1., columm 16 of lcd =columm 16.

void lcd_goto_xy(unsigned char row,unsigned char columm){
	unsigned char fristcharadr[]={0x80,0xC0,0x90,0xD0};
		lcd_command(fristcharadr[row-1]+(columm-1));
		_delay_us(100);
	}
//***********************************************************************************************************
//function to put what u need.
// lcd_print("hallo");
 void lcd_print(char *text){
	while(*text>0){
		lcd_data(*text++);
	}
}

//************************************************************************************************************
//function to clear lcd. 
//lcd_CLEAR();.
void lcd_CLEAR(){
	lcd_command(0x01);
	_delay_ms(2);}
//*************************************************************************************************************
//function to cancel the cursor.
//lcd_curcor_off();
void lcd_curcor_off(){
	lcd_command(0x0c);
	_delay_us(100);
}
//*************************************************************************************************************
	