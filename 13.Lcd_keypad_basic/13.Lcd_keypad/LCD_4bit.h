#ifdef LCD_PORTA
 #define LCD_PORT     PORTA 
 #define LCD_PORT_dir DDRA
 #define RS PA0
 #define RW PA1
 #define EN PA2
#endif

#ifdef LCD_PORTB
 #define LCD_PORT     PORTB 
 #define LCD_PORT_dir DDRB
 #define RS PB0
 #define RW PB1
 #define EN PB2
#endif

#ifdef LCD_PORTC
 #define LCD_PORT     PORTC 
 #define LCD_PORT_dir DDRC
 #define RS PC0
 #define RW PC1
 #define EN PC2
#endif

#ifdef LCD_PORTD
 #define LCD_PORT     PORTD 
 #define LCD_PORT_dir DDRD
 #define RS PD0
 #define RW PD1
 #define EN PD2
#endif


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
