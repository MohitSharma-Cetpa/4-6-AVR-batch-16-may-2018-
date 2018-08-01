//Program to receive data from PC
#define F_CPU 8000000ul //8mhz
#define LCD_PORTA
#include <avr/io.h>
#include <util/delay.h>
#include <util/LCD.h>
int data;

int usart_enable()
{
	UCSRB=(1<<RXEN);//AVR as Rx
	UCSRC=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);//8bit data size
	UBRRL=51;//9600 buad rate
}

void rx_data()
{
 while (!(UCSRA&(1<<RXC)));
 data=UDR;
 lcd_data(data);
}

int main(void)
{
	usart_enable();
	lcd_enable();//LCd is at PORTA
	while(1)
	   {
		 rx_data(); 
	   }
}