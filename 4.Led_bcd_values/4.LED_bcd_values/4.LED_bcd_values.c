#include <avr/io.h>
#include <util/delay.h>

unsigned int array[8]={129,66,36,24,36,66,129,0};

int main(void)
{
	DDRA=0xff;
	
	while(1)
    {
		for (int i=0;i<8;i++)
		{
		 PORTA=array[i];
		 _delay_ms(1000);
		}
		
	}
	
}