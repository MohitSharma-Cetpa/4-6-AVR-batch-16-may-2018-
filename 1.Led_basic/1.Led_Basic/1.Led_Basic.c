#include <avr/io.h> //AVR Standard header file
#include <util/delay.h> //AVR Standard header file for delay

int main(void)
{
  DDRA=0b11111111;//PORTA as output port	
 while(1)
       {
         PORTA=0b11111111;//LED on
	     _delay_ms(1000);//wait for 1second
	
	 PORTA=0b00000000;//LED off
	     _delay_ms(1000);
	}
}
