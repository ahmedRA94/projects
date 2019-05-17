/*
 * password.c
 *
 * Created: 7/24/2017 11:17:32 PM
 *  Author: Ahmed
 */ 

#define F_CPU 8000000ul
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include "KEYPAD.h"
#include "lcd_4bit.h"

char s7eg[10]={0x00,0x01,0x02,0x03,0x04,0x5,0x06,0x07,0x08,0x09};
char inpass[4];
char pasodd[4]={'0','0','0','0'};
char key;
int main(void)
{   lcd_init();
	keypad_init();
	DDRB=0x0f;
	PORTB|=(1<<PB5);
	int i,j;
    while(1)
    { if (!(PINB &(1<<PB5))){
		 lcd_CLEAR();
		 lcd_goto_xy(1,1);
		 lcd_print("enter the new pass");
		 j=0;
		 lcd_goto_xy(2,5);
		 do
		 {
			 key=KeyPad_getpressedkey();
			    switch(key){
			    case 0:{lcd_goto_xy(2,5+j);pasodd[j]='0'; lcd_data(pasodd[j]);j++;break;}
		        case 1:{lcd_goto_xy(2,5+j);pasodd[j]='1'; lcd_data(pasodd[j]);j++;break;}
	            case 2:{lcd_goto_xy(2,5+j);pasodd[j]='2'; lcd_data(pasodd[j]);j++;break;}
                case 3:{lcd_goto_xy(2,5+j);pasodd[j]='3'; lcd_data(pasodd[j]);j++;break;}
				case 4:{lcd_goto_xy(2,5+j);pasodd[j]='4'; lcd_data(pasodd[j]);j++;break;}
				case 5:{lcd_goto_xy(2,5+j);pasodd[j]='5'; lcd_data(pasodd[j]);j++;break;}
				case 6:{lcd_goto_xy(2,5+j);pasodd[j]='6'; lcd_data(pasodd[j]);j++;break;}
				case 7:{lcd_goto_xy(2,5+j);pasodd[j]='7'; lcd_data(pasodd[j]);j++;break;}
				case 8:{lcd_goto_xy(2,5+j);pasodd[j]='8'; lcd_data(pasodd[j]);j++;break;}
				case 9:{lcd_goto_xy(2,5+j);pasodd[j]='9'; lcd_data(pasodd[j]);j++;break;}
				default:
				break;
				}
			} while (j<4);
			eeprom_write_block(pasodd,0,strlen(pasodd));
			_delay_ms(500);
			lcd_CLEAR();
			lcd_goto_xy(1,1);
			lcd_print("pass has saved");
			lcd_goto_xy(2,1);
			lcd_print(pasodd);
			
			_delay_ms(500);
			}			
		else {
		 lcd_CLEAR();
		lcd_goto_xy(1,1);
		lcd_print("enter the pass:");
		i=0;
		lcd_goto_xy(2,5);
		do
		{   
			key=KeyPad_getpressedkey();
			switch(key){
				case 0:{lcd_goto_xy(2,5+i);inpass[i]='0'; lcd_data(inpass[i]);i++;break;}		    	
				case 1:{lcd_goto_xy(2,5+i);inpass[i]='1'; lcd_data(inpass[i]);i++;break;}			
				case 2:{lcd_goto_xy(2,5+i);inpass[i]='2'; lcd_data(inpass[i]);i++;break;}		
				case 3:{lcd_goto_xy(2,5+i);inpass[i]='3'; lcd_data(inpass[i]);i++;break;}			
				case 4:{lcd_goto_xy(2,5+i);inpass[i]='4'; lcd_data(inpass[i]);i++;break;}
				case 5:{lcd_goto_xy(2,5+i);inpass[i]='5'; lcd_data(inpass[i]);i++;break;}
				case 6:{lcd_goto_xy(2,5+i);inpass[i]='6'; lcd_data(inpass[i]);i++;break;}
				case 7:{lcd_goto_xy(2,5+i);inpass[i]='7'; lcd_data(inpass[i]);i++;break;}
				case 8:{lcd_goto_xy(2,5+i);inpass[i]='8'; lcd_data(inpass[i]);i++;break;}
				case 9:{lcd_goto_xy(2,5+i);inpass[i]='9'; lcd_data(inpass[i]);i++;break;}
				default:
				break;
				}
			} while (i<4);
			_delay_ms(500);
			eeprom_read_block(pasodd,0,strlen(pasodd));
			if (inpass[0]==pasodd[0] && inpass[1]==pasodd[1] && inpass[2]==pasodd[2]&& inpass[3]==pasodd[3])
			{lcd_CLEAR();
				lcd_goto_xy(1,5);
				lcd_print("correct ");
				for(int f=0;f<9;f++){
					PORTB=s7eg[f];
					_delay_ms(200);
				}
				_delay_ms(500);
				} 
				else
			{   lcd_CLEAR();
				lcd_goto_xy(2,2);
				lcd_print("wrong password");
				_delay_ms(500);
				}}
				
				
		}					
        //TODO:: Please write your application code 
    }