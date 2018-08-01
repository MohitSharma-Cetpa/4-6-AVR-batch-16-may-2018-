
#define R1 PD0
#define R2 PD1
#define R3 PD2
#define R4 PD3

#define C1 PD4
#define C2 PD5
#define C3 PD6
#define C4 PD7

//DDRD =0b11110000;//row as input and column as output
//PORTD=0b00001111;

#define  keypad_PORT     PORTD
#define  keypad_PORT_dir DDRD
#define  key_check       PIND

void keypad_scan()
{
	keypad_PORT_dir=0b11110000;//row as input and column as output
	keypad_PORT=0b00001111;//col-> low and row -> high

	//c1 (7 4 1 ON)
	keypad_PORT&=~(1<<C1);//c1=0
	keypad_PORT|=(1<<C2)|(1<<C3)|(1<<C4);//c2=c3=c4=1
	
	if(!(key_check &(1<<R1)))
	{
		lcd_string("7");
		_delay_ms(100);
	}
	
	if(!(key_check & (1<<R2)))
	{
		lcd_string("4");
	}
	
	if(!(key_check &(1<<R3)))
	{
		lcd_string("1");
	}
	
	if(!(key_check & (1<<R4)))
	{
		lcd_string("ON");
	}
	
	
	//c2 (8 5 2 0)
	keypad_PORT&=~(1<<C2);//c2=0
	keypad_PORT|=(1<<C1)|(1<<C3)|(1<<C4);//c1=c3=c4=1
	
	if(!(key_check &(1<<R1)))
	{
		lcd_string("8");
		_delay_ms(100);
	}
	
	if(!(key_check & (1<<R2)))
	{
		lcd_string("5");
	}
	
	if(!(key_check &(1<<R3)))
	{
		lcd_string("2");
	}
	
	if(!(key_check & (1<<R4)))
	{
		lcd_string("0");
	}
	
	//c3 (9 6 3 =)
	keypad_PORT&=~(1<<C3);//c3=0
	keypad_PORT|=(1<<C2)|(1<<C1)|(1<<C4);//c2=c1=c4=1
	_delay_ms(100);
	if(!(key_check &(1<<R1)))
	{
		lcd_string("9");
		_delay_ms(100);
	}
	
	if(!(key_check & (1<<R2)))
	{
		lcd_string("6");
	}
	
	if(!(key_check &(1<<R3)))
	{
		lcd_string("3");
	}
	
	if(!(key_check & (1<<R4)))
	{
		lcd_string("=");
	}
	
	
	//c4 (/ * - +)
	keypad_PORT&=~(1<<C4);//c4=0
	keypad_PORT|=(1<<C1)|(1<<C3)|(1<<C2);//c2=c3=c1=1
	
	if(!(key_check &(1<<R1)))
	{
		lcd_string("/");
		_delay_ms(100);
	}
	
	if(!(key_check & (1<<R2)))
	{
		lcd_string("*");
	}
	
	if(!(key_check &(1<<R3)))
	{
		lcd_string("-");
	}
	
	if(!(key_check & (1<<R4)))
	{
		lcd_string("+");
	}
}//                             The end 