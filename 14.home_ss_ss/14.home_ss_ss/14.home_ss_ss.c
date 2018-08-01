#define LCD_PORTA

#include <avr/io.h>
#include <util/delay.h>
#include "D:\Summer_training_CETPA\3-5 AVR batch (16 may 2018)\13.Lcd_keypad_basic\13.Lcd_keypad\LCD_4bit.h"

int main(void)
{
	 lcd_enable();
	 lcd_string("hello");
    
}