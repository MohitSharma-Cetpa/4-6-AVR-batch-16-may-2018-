

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC=0xff;//MOTOR are here
    while(1)
    {
     PORTC=0b00000101;
	    _delay_ms(75);
	 PORTC=0b00001010;
	   _delay_ms(25);
	}
}