
#include <avr/io.h>      //header file 
#include <util/delay.h>  //header file for delay

int main()
{
 DDRA=0xff;
  PORTA=0b00001000;
  while (1)
  {  
	PORTA|=(1<<0);//LED on
	_delay_ms(1000);
	PORTA&=~(1<<0);//LED off
	_delay_ms(1000); 
  }
	
}