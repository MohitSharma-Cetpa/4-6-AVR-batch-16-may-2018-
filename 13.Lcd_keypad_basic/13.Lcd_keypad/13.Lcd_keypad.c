//Program to interface keypad with atmega16

#define LCD_PORTA

#include "avr/io.h"
#include "util/delay.h"
#include "LCD_4bit.h"
#include "Keypad_header.h"

int main(void)
{
 main_display();
   while (1)
     {
      keypad_scan();	 
     }
}


void main_display()
{k
	 lcd_enable();
	 lcd_string("Enter key: ");
	 lcd_cmd(0xc0);                //2nd line of lcd
	 lcd_string(">");
}


