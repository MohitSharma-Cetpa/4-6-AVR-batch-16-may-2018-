//SLave as Reciver

#define LCD_PORTA

#include <avr/io.h>
#include <util/delay.h>
#include <util/LCD.h>

void i2c_init_slave();

void i2c_init_slave()
{
	TWAR=0xFE;//Slave address
	TWSR=0X00;//no Prescaler
	TWCR=(1<<TWEN)|(1<<TWEA);
    while((TWCR&(1<<TWINT))==0);//wait for SLA+W //SR mode
	switch(TWSR)
	 {
	 case 0x60: LCD_cmd(0x01);LCD_string("SLA+W , +ACK");_delay_ms(1000);LCD_data(TWDR);break; 
	 case 0x68: LCD_cmd(0x01);LCD_string("Arbitration LOST");break;
	 case 0x50: LCD_cmd(0x01);LCD_string("data rx");break;
	 //default:   LCD_cmd(0x01);LCD_string("ERROR !!! ");break;  	 
	 }
}

int main()
{
	LCD_enable();
	LCD_cmd(0xc0);
	LCD_string("DATA:");
    while(1)
	 {
	  i2c_init_slave();
	 }
}