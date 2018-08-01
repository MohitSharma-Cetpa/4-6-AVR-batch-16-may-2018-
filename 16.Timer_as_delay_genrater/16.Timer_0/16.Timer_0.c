//Program to provide delay of 1ms using timer0 

#define F_CPU 8000000ul //8mhz
#include <avr/io.h>   
#define n 125
#define clocks  (256-n) 


void Delay_ms(int count)
  {
	for (int i=0;i<count;i++)
	{
	TCCR0=0b00000011;//clk/64 + Normal mode + Oc0 disconnected
	TCNT0=clocks;//initial value 
	while ((TIFR&(1<<TOV0))==0);//monitor overflow flag bit
	TIFR=0x01;//clear TIFR
	TCCR0=0;//Timer off
	}
  }


int main(void)
{
    DDRA=0xff;
	while(1)
	  {
       PORTA=0xff;
	   Delay_ms(1000);
	   PORTA=0x00;
	   Delay_ms(1000);
      }
}


