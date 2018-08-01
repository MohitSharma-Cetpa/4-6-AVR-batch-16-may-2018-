//Program to transmit a letter 'A' to the PC
#define F_CPU 8000000ul //8mhz
#include <avr/io.h>
#include <util/delay.h>

int usart_enable()
 {
  UCSRB=(1<<TXEN);//AVR as tx
  UCSRC=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);//8bit data size
  UBRRL=51;//9600 buad rate	
 }

void tx(char data)
 {
  UDR=data;	
  while (!(UCSRA&(1<<UDRE)));
 }

void tx_string(char *msg)
{
 while (*msg)
 {
  tx(*msg);
  msg++;	 
 }
}


int main(void)
{
  usart_enable();	
   // while(1)
    {
     tx('A');
	 tx('B');
	 
	 tx_string("Your Name : "); 
    }
}