//Program to Count external events at T0 pin (PB0)
#define LCD_PORTA
#define F_CPU 8000000ul //8mhz

#include <avr/io.h>
#include <util/delay.h>
#include <util/LCD.h>

char arr[3];

int main(void)
{
	DDRB&=~(1<<PB0);//T0 as input pin
	lcd_enable();
	lcd_string("Count=> ");
	lcd_cmd(0x88);	
	TCNT0=0;          // initial value
	OCR0=10;
	while(1)
	{
	 TCCR0=0b00001110; // Falling Edge Timer as Counter +ctc mode
	 sprintf(arr,"%d",TCNT0);
	 lcd_string(arr);
	 _delay_ms(100);
	 lcd_cmd(0x88);
	 lcd_string("    ");
	 lcd_cmd(0x88);
	 TIFR=0x02; //clear OCF0
	}
}


