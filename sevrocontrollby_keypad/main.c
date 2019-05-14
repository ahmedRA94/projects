#include<avr/io.h>
#include<util/delay.h>
#include"driver/keypad.h"
#include"driver/ADC lib.h"
void servo_init();
void servo_set(int *valu);

int main(void){
int c,key,val;
volatile int num,xser;
servo_init();
ADC_Init();
DDRC=0xff;
val=0;

c=0;
while(1){
num=adc_Read(1);
PORTC=num;
servo_set(&xser);


}
}


void servo_init(){
	DDRD |= (1<<PD5);	/* Make OC1A pin as output */
		TCNT1 = 0;		/* Set timer1 count zero */
		ICR1 = 2499;		/* Set TOP count for timer1 in ICR1 register */

		/* Set Fast PWM, TOP in ICR1, Clear OC1A on compare match, clk/64 */
		TCCR1A = (1<<WGM11)|(1<<COM1A1);
		TCCR1B = (1<<WGM12)|(1<<WGM13)|(1<<CS10)|(1<<CS11);
}
void servo_set(int *valu){
	int se_v;
	se_v=*valu;
	OCR1A=se_v+125;
}
