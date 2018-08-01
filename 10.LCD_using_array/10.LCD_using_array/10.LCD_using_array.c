#include <avr/io.h>
#include <util/delay.h>

unsigned int data1[]={'W','E','L','C','O','M','E'};
unsigned int data2[]={'H','E','L','L','O'};

unsigned int cmd[]={0x38,0x06,0x0e,0x01};

int main(void)
{
 DDRA=DDRB=0xff;
 for (int i=0;i<4;i++)
  {
   PORTB=cmd[i];
   select_cmd_mode();
  }
  
 for (int i=0;i<7;i++)
   {
	PORTB=data1[i];
	select_data_mode();
   }
PORTB=0xc0;
select_cmd_mode();
	for(int i=0;i<5;i++)
	{
		PORTB=data2[i];
		select_data_mode();
	}
}
void select_cmd_mode()
 {
  PORTA&=~(1<<PA0);//RS=0
  PORTA&=~(1<<PA1);//RW=0
  PORTA|=(1<<PA2);//EN=1
  _delay_ms(40);
  PORTA&=~(1<<PA2);//EN=0	
}

void select_data_mode()
{
	PORTA|=(1<<PA0);//RS=1
	PORTA&=~(1<<PA1);//RW=0
	PORTA|=(1<<PA2);//EN=1
	_delay_ms(40);
	PORTA&=~(1<<PA2);//EN=0
}
