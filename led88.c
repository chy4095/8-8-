#include <REGX52.H>
#include "delay.h"

sbit RCK=P3^5;		//RCLK
sbit SCK=P3^6;		//SRCLK
sbit SER=P3^4;		//SEK

#define LED_PORT	P0


void _74HC595_byte(unsigned char byte)		  //74HC595写入一个字节
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		SER=byte&(0x80>>i);
		SCK=1;
		SCK=0;	
	}
	RCK=1;
	RCK=0;
}


void init()
{
	SCK=0;
	RCK=0;
}

void LED_showcol(unsigned char lie,date)	  //LED显示屏显示一列数据
{
	_74HC595_byte(date);
	if(lie==0);
	LED_PORT=~(0x80>>lie);
	delay(1);
	LED_PORT=0xff;

}

