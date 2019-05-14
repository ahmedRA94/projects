/*
 * keypad.h
 *
 *  Created on: Apr 7, 2019
 *      Author: Ahmed
 */

#define keypad_DDR DDRB
#define keypad_PORT PORTB
#define keypad_PIN PINB

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include<avr/io.h>
#include<util/delay.h>

void keypad_init();
unsigned int keypad_press();


#endif /* KEYPAD_H_ */
