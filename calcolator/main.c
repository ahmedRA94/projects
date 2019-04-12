#include<stdio.h>
#include<stdlib.h>
#include<avr/io.h>
#include<util/delay.h>
#include"driver/keypad.h"
#include"driver/lcd_4bit.h"

double operat(int *frist,int *last,int *opr);

int main(void){

int  fnum,lnum,num,val;
double equan;
int x,key,op,n;
lcd_init();
char finum[10];
keypad_init();

while (1){

	lcd_goto_xy(1,1);
	int y=0;
do{
	do{ if (y==14)
	{y=0;}
	key=keypad_press();
switch(key){
case 1:lcd_goto_xy(1,2+y);lcd_print("7");val=7;num=num*10+val;x++;y++;break;
case 2:lcd_goto_xy(1,2+y);lcd_print("8");val=8;num=num*10+val;x++;y++;break;
case 3:lcd_goto_xy(1,2+y);lcd_print("9");val=9;num=num*10+val;x++;y++;break;
case 4:lcd_goto_xy(1,2+y);lcd_print("/");fnum=num;lcd_goto_xy(1,x);op=1;x=8;num=0;y++;break;
case 5:lcd_goto_xy(1,2+y);lcd_print("4");val=4;num=num*10+val;x++;y++;break;
case 6:lcd_goto_xy(1,2+y);lcd_print("5");val=5;num=num*10+val;x++;y++;break;
case 7:lcd_goto_xy(1,2+y);lcd_print("6");val=6;num=num*10+val;x++;y++;break;
case 8:lcd_goto_xy(1,2+y);lcd_print("X");fnum=num;lcd_goto_xy(1,y);y++;op=2;x=8;num=0;;break;
case 9:lcd_goto_xy(1,2+y);lcd_print("1");val=1;num=num*10+val;x++;y++;break;
case 10:lcd_goto_xy(1,2+y);lcd_print("2");val=2;num=num*10+val;x++;y++;break;
case 11:lcd_goto_xy(1,2+y);lcd_print("3");val=3;num=num*10+val;x++;y++;break;
case 12:lcd_goto_xy(1,2+y);lcd_print("-");fnum=num;lcd_goto_xy(1,y);y++;op=3;x=8;num=0;break;
case 13:lcd_CLEAR(); x=0;lcd_goto_xy(1,2+y);n=0;lnum=0;equan=0;y=0;break;
case 14:lcd_goto_xy(1,2+y);lcd_print("0");val=0;num=num*10+val;x++;y++;break;
case 15:lcd_goto_xy(1,2+y);lcd_print("=");x=8;lnum=num;equan=operat(&fnum,&lnum,&op);y=0;n=1;break;
case 16:lcd_goto_xy(1,2+y);lcd_print("+");fnum=num;lcd_goto_xy(1,y);op=4;x=8;num=0;y++;break;
default:;
}
}while(x<8);}
while (n<1);
lcd_goto_xy(2,4);
dtostrf(equan,10,3,finum);
lcd_print(finum);
}
}

 double operat(int *frist,int *last,int *opr){
	double result;
	if (*opr==4){
	result=*frist+*last;
	}
else if(*opr==3){
result=*frist-*last;
	}
else if(*opr==2){
result=(*frist)*(*last);
	}
else{
result=(*frist*1.00)/(*last*1.00);

}
return (result);
}
