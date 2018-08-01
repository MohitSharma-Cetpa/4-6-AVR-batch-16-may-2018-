
#include <avr/io.h>
#include <util/delay.h>

int max=8,y=0;

int main(void)
{
  DDRA=0xff;
    while(1)
    {
       for (int i=0;i<max;i++)
       {
		   PORTA=y|(1<<i);
		   _delay_ms(100);
       }
       --max;
	   y=128+y/2;
	   
	   if (max==0)
	      {
		   max=8;
	       y=0;
		  }
	}
}