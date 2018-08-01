#include <avr/io.h>
#include <util/delay.h>

int count=0;

int main(void)
{
  DDRA&=~(1<<PA0);//PAO as input 	
  DDRA|=(1<<PA1)|(1<<PA7); // PA1 and PA7 as output
  PORTA|=(1<<PA1);//Status LED ON 
	while(1)
    {
      if(PINA&(1<<PA0))
       {
        ++count;
		 while (PINA&(1<<PA0));//to avoid debounce condition
	   }
	   if (count==1)
	   {
		PORTA|=(1<<PA7);
	   }
	   if(count==2)
	   {
	    PORTA&=~(1<<PA7);//LED off
	    count=0;
	   }
	}
}