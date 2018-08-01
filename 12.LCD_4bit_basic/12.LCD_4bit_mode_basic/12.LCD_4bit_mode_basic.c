#include <avr/io.h>
#include <util/delay.h>

#define RS PC0
#define RW PC1
#define EN PC2

#define LCD_PORT     PORTC
#define LCD_PORT_dir DDRC

/***** Function protype **/
void lcd_cmd(char );       //to send cmd to lcd
void lcd_data(char );      //to send data to lcd
void lcd_string(char *);    //to display string on lcd
void lcd_enable();         //to enable lcd

void lcd_cmd(char x)
{
LCD_PORT=x&0xf0;                 //sending cmd to lcd
	LCD_PORT&=~(1<<RS);//RS=0   //selection of cmd mode
	LCD_PORT&=~(1<<RW);//RW=0
	LCD_PORT|=(1<<EN);//EN=1
	_delay_ms(40);
	LCD_PORT&=~(1<<EN);//EN=0

LCD_PORT=(x<<4)&0xf0;            //sending cmd to lcd
 	LCD_PORT&=~(1<<RS);//RS=0   //selection of cmd mode
 	LCD_PORT&=~(1<<RW);//RW=0
 	LCD_PORT|=(1<<EN);//EN=1
 	_delay_ms(40);
 	LCD_PORT&=~(1<<EN);//EN=0 	 
}

void lcd_data(char x)
{
LCD_PORT=x&0xf0;
	LCD_PORT|=(1<<RS);//RS=1
	LCD_PORT&=~(1<<RW);//RW=0
	LCD_PORT|=(1<<EN);//EN=1
	_delay_ms(40);
	LCD_PORT&=~(1<<EN);//EN=0

LCD_PORT=(x<<4)&0xf0;
	LCD_PORT|=(1<<RS);//RS=1
	LCD_PORT&=~(1<<RW);//RW=0
	LCD_PORT|=(1<<EN);//EN=1
	_delay_ms(40);
	LCD_PORT&=~(1<<EN);//EN=0
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
	LCD_PORT_dir=0xff;
	lcd_cmd(0x02);//return home
	lcd_cmd(0x28);//4bit mode
	lcd_cmd(0x0e);//display on ,cursor blink
	lcd_cmd(0x06);//increment cursor to right
}

int main(void)
{
	lcd_enable();
	lcd_string(" LCD 4 bit mode !");
	lcd_cmd(0xc0);//2nd line of lcd
	lcd_string(" i m 2nd line ");
}





