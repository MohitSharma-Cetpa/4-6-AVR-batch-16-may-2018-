
	
#ifdef LCD_4bit 
     lcd_enable();
#endif

	 
#ifdef LCD_8bit
     lcd_enable();
#endif

   
/*
void lcd_8bit_fun()
{
   #define LCD_Cnt_dir DDRA
   #define LCD_Cnt    PORTA 
      
   #define LCD_dat_dir DDRB
   #define LCD_dat    PORTB
}
*/
/*
 #ifdef LCD_PORTA
	#define LCD_PORT_dir DDRA
	#define LCD_PORT     PORTA
	#define RS PA0
	#define RW PA1
	#define EN PA2
#endif

#ifdef LCD_PORTB
	#define LCD_PORT_dir DDRB
	#define LCD_PORT     PORTB
	#define RS PB0
	#define RW PB1
	#define EN PB2
#endif

*/

#ifdef LCD_PORTC
	#define LCD_PORT_dir DDRC
	#define LCD_PORT     PORTC
	#define RS PC0
	#define RW PC1
	#define EN PC2
#endif

/*
#ifdef LCD_PORTD
	#define LCD_PORT_dir DDRD
	#define LCD_PORT     PORTD
	#define RS PD0
	#define RW PD1
	#define EN PD2
#endif
*/
/*

void lcd_enable()
{
 #ifdef LCD_8bit 	
	 lcd_8bit_fun();
	 LCD_Cnt_dir|=(1<<RS)|(1<<RW)|(1<<EN);
	 LCD_dat_dir=0xff;
	 lcd_cmd(0x38);
	 lcd_cmd(0x06);
	 lcd_cmd(0x0e);	
 #endif
 
 #ifdef LCD_4bit
	//lcd_4bit_fun();
	//LCD_PORT_dir=0xff;
	#define LCD_PORT PORTC
	#define RS PC0
	#define RW PC1
	#define EN PC2
	
	DDRC=0xff;
	lcd_cmd(0x02);
	lcd_cmd(0x28);
	lcd_cmd(0x06);
	lcd_cmd(0x0e);
 #endif
}
*/

//#define LCD_PORT PORTC


void lcd_enable()
{
	LCD_PORT_dir=0xff;
	lcd_cmd(0x02);
	lcd_cmd(0x28);
	lcd_cmd(0x06);
	lcd_cmd(0x0e);
}

void lcd_cmd(char x)
{
	LCD_PORT=x&0xf0;
	LCD_PORT&=~(1<<PC0);//rs=0;
    LCD_PORT&=~(1<<PC1);//rw=0;
    LCD_PORT|=(1<<PC2);//en=1;
    _delay_ms(40);
	LCD_PORT&=~(1<<PC2);//en=0;

	LCD_PORT=(x<<4)&0xf0;
	LCD_PORT&=~(1<<PC0);//rs=0;
	LCD_PORT&=~(1<<PC1);//rw=0;
	LCD_PORT|=(1<<PC2);//en=1;
	_delay_ms(40);
	LCD_PORT&=~(1<<PC2);//en=0;

}

void lcd_data(char x)
  {
	LCD_PORT=x&0xf0;
	LCD_PORT|= (1<<PC0);//rs=1;
	LCD_PORT&=~(1<<PC1);//rw=0;
	LCD_PORT|=(1<<PC2);//en=1;
	_delay_ms(40);
	LCD_PORT&=~(1<<PC2);//en=0;
  
	LCD_PORT=(x<<4)&0xf0;
    LCD_PORT|= (1<<PC0);//rs=1;
	LCD_PORT&=~(1<<PC1);//rw=0;
	LCD_PORT|=(1<<PC2);//en=1;
	_delay_ms(40);
	LCD_PORT&=~(1<<PC2);//en=0;
  
  }

void lcd_string(char *ptr)
{
	while(*ptr)
	{
	 lcd_data(*ptr);
	 ptr++; 	
	}
}
/*
void lcd_Dis_Num(int row, int col, char num)
{
  unsigned int arr[3];	
  unsigned int arr_16_4[3]={0x80,0xc0,0x90,0xd0};
  unsigned int arr_20_4[3]={0x80,0xc0,0x94,0xd4};
  sprintf(arr,"%d",num);
  lcd_Display(arr);
}


void lcd_Display(int row, int col, char * ptr)
  {
	 unsigned int arr_16_4[]={0x80,0xc0,0x90,0xd0};
	 unsigned int arr_20_4[]={0x80,0xc0,0x94,0xd4};	  
  
   while (*ptr)
   { 
	++row;
	++col;   
    for ( ;col<17;col++)
        {
	     lcd_cmd(arr_16_4[row+col]);  
         lcd_data(*ptr);
	     ptr++;
	    }      	
	}
}
*/