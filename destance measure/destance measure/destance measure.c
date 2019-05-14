/*
 * destance_measure.c
 *
 * Created: 7/30/2018 8:33:44 PM
 *  Author: Ahmed
 */ 

#define F_CPU 8000000ul
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "lcd_4bit.h"

char destance[6];
 volatile unsigned int des;
double time;
int TimerOverflow =0;

ISR(TIMER1_OVF_vect)
{
	TimerOverflow++;	/* Increment Timer Overflow count */
}



int main(void)
{   DDRD=0xf0;
	lcd_init();
    while(1)
    { lcd_goto_xy(1,1);
		lcd_print("destance=");
		PORTD |= (1 << PD0);
	    _delay_us(10);
	    PORTD &= (~(1 << PD0));
	    
	    TCNT1 = 0;	/* Clear Timer counter */
	    TCCR1B = 0x42;	/* Capture on rising edge,f_cpu/8 */
	    TIFR = 1<<ICF1;	/* Clear ICP flag (Input Capture flag) */
	    TIFR = 1<<TOV1;	/* Clear Timer Overflow flag */

	    /*Calculate width of Echo by Input Capture (ICP) */ 
	    while ((TIFR & (1 << ICF1)) == 0);/* Wait for rising edge */
	    TCNT1 = 0;	/* Clear Timer counter */
	    TCCR1B = 0x01;	/* Capture on falling edge, No prescaler */
	    TIFR = 1<<ICF1;	/* Clear ICP flag (Input Capture flag) */
	    TIFR = 1<<TOV1;	/* Clear Timer Overflow flag */
	    TimerOverflow = 0;/* Clear Timer overflow count */
	    while ((TIFR & (1 << ICF1)) == 0);/* Wait for falling edge */
	    time = ICR1 + (65535 * TimerOverflow);	/* take time */
		des=time/58;
		itoa(des,destance,10);
		lcd_goto_xy(1,10);
		lcd_print(destance);
		_delay_ms(700);
		lcd_CLEAR();
		
    }
}