
 
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC=0x00;
	DDRA=0xff;
    while(1)
    {
     if (PINC==0x01)
     {
		PORTA=0xff;//led on
		_delay_ms(100); 3.
     }
	 else
	    PORTA=0;//led off
	}
}