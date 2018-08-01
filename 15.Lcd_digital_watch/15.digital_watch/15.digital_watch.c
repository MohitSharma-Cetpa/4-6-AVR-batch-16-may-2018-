#define LCD_PORTA
#include <avr/io.h>
#include <util/delay.h>
#include <util/LCD.h>

char arr_s[3];
char arr_m[3];
char arr_h[3];

int s,h,m;

int main(void)
{
 lcd_enable();
 lcd_string("DIGITAL WATCH");
 lcd_cmd(0xc0);
 lcd_string(" 00:00:00 ");   
	while(1)
    {
     while(s<60)
	    {
		 sprintf(arr_s,"%d",s);
		  if(s<10)
		   {
		    lcd_cmd(0xc6);
		    lcd_string(":0");
		   }
		   else
		   lcd_cmd(0xc7);
		   lcd_string(arr_s);
		 _delay_ms(1); 
        s++;
		}
	if(s>59)//minute....>>>>
	{	
	 s=0;
	 lcd_cmd(0xc6);
	 lcd_string(":00");	  
	 ++m;
	 sprintf(arr_m,"%d",m);
	   	 if(m<10)
	   	   {
		   	 lcd_cmd(0xc3);
		   	 lcd_string(":0");
	   	   }
	   	 else
	   	    lcd_cmd(0xc4);
	   	    lcd_string(arr_m);
	   	    _delay_ms(1);
	}

if(m>59)//hours.....>>>>>>>>
	{
		s=0;m=0;
			lcd_cmd(0xc3);
			lcd_string(":00:00");
			++h;
			sprintf(arr_h,"%d",h);
			if(h<10)
			{
				lcd_cmd(0xc1);
				lcd_string("0");
			}
			else
			lcd_cmd(0xc1);
			lcd_string(arr_m);
			_delay_ms(1);
		}
		
		
		
	}
}