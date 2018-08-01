#define LCD_PORTC
#define F_CPU 8000000ul
#include <avr/io.h>
#include <util/delay.h>
#include <util/LCD.h>
#include <D:\AVR_classes\Project\13.home_automation\13.home_automation\13.home_automation\uart.h>

int main(void)
{
	DDRA=0x00;
	lcd_enable();
	uart_enable();
	lcd_cmd(0x01);lcd_cmd(0x80);
	lcd_string("  GAS LEAKAGE");
	lcd_cmd(0xc0);
	lcd_string("DETECTOR SYSTEM");
	_delay_ms(100);
	while (1)
	{
	if (PINA&(1<<PA0))
	{
	 lcd_cmd(0x01);	
	 lcd_string("GAS LEAK");
	 lcd_cmd(0x01);
	 lcd_string("DETECTED");	
	 send_message();
	 while (PINA&(1<<PA0));
	} 
	else
	{
    lcd_cmd(0x01);
	lcd_cmd(0x80);
    lcd_string("  GAS LEAKAGE");
    lcd_cmd(0xc0);
    lcd_string("DETECTOR SYSTEM");
    _delay_ms(100);		
	}
		
	}
}

void send_message()
{
	tx_string("AT");
	_delay_ms(1000);
	tx(0x0d);
	
	lcd_cmd(0x01);lcd_string("Sending Report");
	tx_string("ATE0");
	_delay_ms(1000);
	tx(0x0d);
	
	tx_string("AT+CMGF=1");
	_delay_ms(1000);
	tx(0x0d);
	
	lcd_cmd(0X01);lcd_string("ALERT !!!");
	tx_string("AT+CMGS=");
	tx_string("\"8948949611\"");
	tx(0x0d);
	
	lcd_cmd(0XC0);lcd_string("BE ALERT !!!");
	_delay_ms(500);
	
	tx_string("BE ALERT ! \n DANGER IN ROOM ");
	tx_string(" send by: \n SHUBHAM HOME AUTOMATION ");
	tx_string("   ");
	
	tx(0x0d);
	tx(26);
	
	_delay_ms(100);
	lcd_cmd(0x01);
	lcd_string("Msg Sent !");
}



