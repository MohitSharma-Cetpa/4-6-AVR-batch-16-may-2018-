//Program to display 'A' on lcd

#include <avr/io.h>
#include <util/delay.h>
#include "LCD_headerfile.h"

#define LCD_4bit
#define LCD_PORTC

int main()
{
 lcd_enable();
 lcd_cmd(0x80);
 lcd_string("hello");
}
 
/*
#define RS PA0
#define RW PA1
#define EN PA2

int main(void)
{
  DDRA=0xff;// Lcd cmd pins are here
  DDRB=0xff;// Lcd data pins are here	
    
  //send cmd to lcd
  PORTB=0x38; // 8bit mode
  select_cmd_mode();  
  PORTB=0x06;//increment cursor towards right
  select_cmd_mode();
  PORTB=0x0e;//display on ,cursor blink
  select_cmd_mode();
  
  
  //send data to lcd
  PORTB='A';//display A on lcd
  select_data_mode(); 

  PORTB=0xc9;
  select_cmd_mode();
  
  PORTB='+';//display B on lcd
  select_data_mode();
  //select_data_mode();	
}


void select_cmd_mode()
  {
   PORTA&=~(1<<RS);//rs=0;
   PORTA&=~(1<<RW);//rw=0;
   PORTA|= (1<<EN);//en=1;
   _delay_ms(40);
   PORTA&=~(1<<EN);//en=0;
  }
  
void select_data_mode()
{
	PORTA|= (1<<RS);//rs=1;
	PORTA&=~(1<<RW);//rw=0;
	PORTA|= (1<<EN);//en=1;
	_delay_ms(40);
	PORTA&=~(1<<EN);//en=0;
} 
*/ 