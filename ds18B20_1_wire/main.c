/*
 * main.c
 *
 *  Created on: May 14, 2019
 *      Author: Ahmed
 */




#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include "driver/ds18b20.h"
#include "driver/lcd_4bit.h"


int main(void){

	lcd_init();
	double temp;
	char t_val[10];
	while(1){
		lcd_goto_xy(1,1);
	lcd_print("the temp is=");
	lcd_goto_xy(2,4);
	temp=ds18b20_gettemp();
	dtostrf(temp,5,3,t_val);
	lcd_print(t_val);
	_delay_ms(150);




	}





}


