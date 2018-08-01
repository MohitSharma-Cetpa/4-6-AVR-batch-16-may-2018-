//Program to display 0-9 values on 7segment
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
 DDRD=0xff;
    while(1)
    {
     PORTD=0b00111111;//numeric 0
	 _delay_ms(1000);
	 PORTD=0b00000110;//numeric 1
     _delay_ms(1000);
	}
}