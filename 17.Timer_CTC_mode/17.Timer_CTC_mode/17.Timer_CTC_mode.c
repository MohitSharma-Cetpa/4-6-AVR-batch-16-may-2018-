//Program to provide delay of 1ms using timer0 in CTC mode
#define LCD_PORTA

#define F_CPU 8000000ul //8mhz

#include <avr/io.h>
#include <util/delay.h>
#include <util/LCD.h>

#define n 125
#define clocks n-1
char arr[3];

int main(void)
{
 lcd_enable();
 lcd_string("TCNT0 => ");
 lcd_cmd(0xc0);//2nd line of lcd
 
 TCNT0=0;//initial value
 TCCR0=0b00001011; //  clk/64 + CTC mode + Oc0 disconnected
 OCR0=clocks;
	while(1)
	{
     sprintf(arr,"%d",TCNT0);
     lcd_string(arr);
     	 _delay_ms(1000);
	 lcd_cmd(0xc0);
	 while ((TIFR&(1<<OCF0))==0);//monitor Compare Match flag bit
	 TIFR=0x02; //clear OCF0
	 TCCR0=0;   //Timer off

	}
}


