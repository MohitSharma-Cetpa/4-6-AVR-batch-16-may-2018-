#include <avr/io.h>
#include <util/delay.h>

#define RS PA0
#define RW PA1
#define EN PA2

/***** Function protype **/
void lcd_cmd(char );       //to send cmd to lcd
void lcd_data(char );      //to send data to lcd
void lcd_string(char *);    //to display string on lcd
void lcd_enable();         //to enable lcd

void lcd_cmd(char x)
 {
  PORTB=x;//sending cmd to lcd
	PORTA&=~(1<<PA0);//RS=0   //selection of cmd mode
	PORTA&=~(1<<PA1);//RW=0
	PORTA|=(1<<PA2);//EN=1
	_delay_ms(40);
	PORTA&=~(1<<PA2);//EN=0	
}

void lcd_data(char x)
{
 PORTB=x;
	PORTA|=(1<<PA0);//RS=1
	PORTA&=~(1<<PA1);//RW=0
	PORTA|=(1<<PA2);//EN=1
	_delay_ms(40);
	PORTA&=~(1<<PA2);//EN=0
}

void lcd_string(char *ptr)
{
	while(*ptr)    //checking for NULL
	{
		lcd_data(*ptr); // passing values to lcd
		ptr++; //increment address of ptr variable
	}
}

void lcd_enable()
{
 DDRA=DDRB=0xff;
 lcd_cmd(0x38);
 lcd_cmd(0x0e);
 lcd_cmd(0x06);	
}

int main(void)
{
  lcd_enable();
  lcd_string("hello World !");
  lcd_cmd(0xc0);//2nd line of lcd
  lcd_string(" i m 2nd line ");		
}





