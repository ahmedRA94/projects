/*
 * camira_move_by_joysteck.c
 *
 * Created: 4/16/2019 12:52:57 PM
 *  Author: Ahmed
 */ 


#define F_CPU 8000000ul
#include <avr/io.h>
#include <util/delay.h>
#include "driver/ADC_LIB.h"

void sevro_in();
void sevr_set1(int *val);
void sevr_set2(int *val);

int main(void)
{  volatile int vx,vy;
	 int vax,vay;
	ADC_Init();
	sevro_in();
	while(1)
	{ vx=adc_Read(1);
		vax=vx/8;
		sevr_set1(&vax);
		_delay_ms(150);
		vy=adc_Read(0);
		vay=vy/8;
		sevr_set2(&vay);
		_delay_ms(100);
		//TODO:: Please write your application code
	}
}

void sevro_in(){
	DDRD |= (1<<PD5)|(1<<PD4);	/* Make OC1A pin as output */
	TCNT1 = 0;		/* Set timer1 count zero */
	ICR1 = 2499;		/* Set TOP count for timer1 in ICR1 register */
	/* Set Fast PWM, TOP in ICR1, Clear OC1A on compare match, clk/64 */
	TCCR1A = (1<<WGM11)|(1<<COM1A1)|(1<<COM1B1);
	TCCR1B = (1<<WGM12)|(1<<WGM13)|(1<<CS10)|(1<<CS11);
}
void sevr_set1(int *val)
{
	OCR1A=*val+125;
}
void sevr_set2(int *vau){
	OCR1B=*vau+125;
}
