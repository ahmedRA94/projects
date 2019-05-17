/*
 * lcd_4bit.h
 *
 * Created: 7/24/2017 10:38:39 PM
 *  Author: Ahmed
 */
/*you should
#define lcd_DDR DDRx      whire x is {a,b,c,d,e}
#define lcd_PRT PORTx 
in lcd_4bit.c	
connect            
for data register for LCD (D4-D7) to AVR pinx (px4: :px7)
and 
(px0==lcd_RS, px1==lcd_RW ,px2==lcd_EN) 
 */
//#define F_CPU 1000000ul
#define lcd_DDR DDRA
#define lcd_PRT PORTA
#include <avr/io.h>
#include <util/delay.h>

#define lcd_RS 0
#define lcd_RW 1
#define lcd_EN 2
#ifndef LCD_4BIT_H_
#define LCD_4BIT_H_

void lcd_command(unsigned char cmd);
void lcd_data(unsigned char data);
//***********************************************************************************************
//function for lcd initialize.
//lcd_init();
void lcd_init();
//*********************************************************************************************************
//function to locate the position.
//lcd_goto_xy(row,columm);
//line 1 of lcd=row 1. ,line2 of lcd=row2
//columm 1 of lcd =columm 1., columm 16 of lcd =columm 16.
void lcd_goto_xy(unsigned char row,unsigned char columm);
//***********************************************************************************************************
//function to put what u need.
// lcd_print("hallo");
void lcd_print(char *text);
//************************************************************************************************************
//function to clear lcd.
//lcd_CLEAR();.
void lcd_CLEAR();
//*************************************************************************************************************
//function to cancel the cursor.
//lcd_curcor_off();
void lcd_curcor_off();



#endif /* LCD_4BIT_H_ */
