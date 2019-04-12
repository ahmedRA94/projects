
#include"keypad.h"

void keypad_init(){
keypad_DDR|=0X0F;
keypad_PORT|=0XFF;
 }
 unsigned int keypad_press(){
	 unsigned int key;
keypad_PORT=0XFE;
if (!(keypad_PIN &(1<<4))){
_delay_ms(2);
while(!(keypad_PIN &(1<<4)));
key=1;
}
else if (!(keypad_PIN &(1<<5))){
	_delay_ms(2);
	while(!(keypad_PIN &(1<<5)));
	key=2;
	}
else if (!(keypad_PIN &(1<<6))){
	_delay_ms(2);
	while(!(keypad_PIN &(1<<6)));
	key=3;
	}
else if (!(keypad_PIN &(1<<7))){
	_delay_ms(2);
	while(!(keypad_PIN &(1<<7)));
	key=4;
	}
keypad_PORT=0XFD;
if (!(keypad_PIN &(1<<4))){
_delay_ms(2);
while(!(keypad_PIN &(1<<4)));
key=5;
}
else if (!(keypad_PIN &(1<<5))){
	_delay_ms(2);
	while(!(keypad_PIN &(1<<5)));
	key=6;
	}
else if (!(keypad_PIN &(1<<6))){
	_delay_ms(2);
	while(!(keypad_PIN &(1<<6)));
	key=7;
	}
else if (!(keypad_PIN &(1<<7))){
	_delay_ms(2);
	while(!(keypad_PIN &(1<<7)));
	key=8;
	}
keypad_PORT=0XFB;
if (!(keypad_PIN &(1<<4))){
_delay_ms(2);
while(!(keypad_PIN &(1<<4)));
key=9;
}
else if (!(keypad_PIN &(1<<5))){
	_delay_ms(2);
	while(!(keypad_PIN &(1<<5)));
	key=10;
	}
else if (!(keypad_PIN &(1<<6))){
	_delay_ms(2);
	while(!(keypad_PIN &(1<<6)));
	key=11;
	}
else if (!(keypad_PIN &(1<<7))){
	_delay_ms(2);
	while(!(keypad_PIN &(1<<7)));
	key=12;
	}
keypad_PORT=0XF7;
if (!(keypad_PIN &(1<<4))){
_delay_ms(2);
while(!(keypad_PIN &(1<<4)));
key=13;
}
else if (!(keypad_PIN &(1<<5))){
	_delay_ms(2);
	while(!(keypad_PIN &(1<<5)));
	key=14;
	}
else if (!(keypad_PIN &(1<<6))){
	_delay_ms(2);
	while(!(keypad_PIN &(1<<6)));
	key=15;
	}
else if (!(keypad_PIN &(1<<7))){
	_delay_ms(2);
	while(!(keypad_PIN &(1<<7)));
	key=16;
}
 return key; }
