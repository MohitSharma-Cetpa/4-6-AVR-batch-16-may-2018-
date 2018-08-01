#define LCD_PORTA

#include <avr/io.h>
#include <util/delay.h>
#include <util/LCD.h>


void i2c_init()
{
	TWSR=0X00;//no Prescaler
	TWBR=0X0C;//bit rate 18(100khz)
	TWCR=(1<<TWEN)|(1<<TWEA);
}

int  i2c_start(void)//check
{
	TWCR=(1<<TWEN)|(1<<TWINT)|(1<<TWSTA);//start condition
	while( (TWCR&(1<<TWINT))==0); //wait here till Bus is busy i.e. TWINT0==0;
	switch(TWSR)
	{
		case 0x08:LCD_cmd(0x01);LCD_string("START sent ");break;
		case 0x10:LCD_cmd(0x01);LCD_string("RSTART ");break;
		default:LCD_cmd(0x01);LCD_string("ERROR in STart");break;
	}
}

int i2c_write(unsigned char X)
{
	TWDR=X;
	TWCR=(1<<TWEN)|(1<<TWINT)|(1<<TWEA);
	while((TWCR&(1<<TWINT))==0);// wait here till Bus is busy i.e. TWINT0==0;
	switch(TWSR)
	{
		case 0x18:LCD_cmd(0x01);LCD_string("SLA+W success\r ");
		          LCD_cmd(0xc0);LCD_string("ACK received\r");
				  TWDR='A';
                  TWCR=(1<<TWEN)|(1<<TWINT);
  		          while((TWCR&(1<<TWINT))==0);// wait here till Bus is busy i.e. TWINT0==0;
				  switch(TWSR)
				  {
                   		case 0x20:LCD_cmd(0x01); LCD_string("SLA+W sucess\r"); LCD_string(" but NOT ACK received\r ");break;
                   		case 0x38:LCD_cmd(0x01); LCD_string("Arbitration lost\r");break;
                   		case 0x40:LCD_cmd(0x01); LCD_string("SLA+R ACK RECEIVED\r");break;
                   		case 0x48:LCD_cmd(0x01); LCD_string("SLA+R  NOT ACK RECEIVED\r");break;
                   		case 0x28:LCD_cmd(0x01); LCD_string("data tx ");LCD_cmd(0xc0);LCD_string("ACK has been received\r");break;
                   		case 0x30:LCD_cmd(0x01); LCD_string("data tx"); LCD_cmd(0xc0);LCD_string(" not ACK\r");break;
                   		case 0x60:LCD_cmd(0x01); LCD_string("data nt by master");break;
                   		case 0x58:LCD_cmd(0x01); LCD_string("not ack ");break;
                   		case 0x50:LCD_cmd(0x01); LCD_string("data received");break;
                   		default: LCD_cmd(0x01);  LCD_string("ERROR in SLA+W\r ");
					  
				  }
				  break;
		case 0x20:LCD_cmd(0x01); LCD_string("SLA+W sucess\r"); LCD_string(" but NOT ACK received\r ");break;
		case 0x38:LCD_cmd(0x01); LCD_string("Arbitration lost\r");break;
		case 0x40:LCD_cmd(0x01); LCD_string("SLA+R ACK RECEIVED\r");break;
		case 0x48:LCD_cmd(0x01); LCD_string("SLA+R  NOT ACK RECEIVED\r");break;
		case 0x28:LCD_cmd(0x01); LCD_string("data tx ");LCD_cmd(0xc0);LCD_string("ACK has been received\r");break;
		case 0x30:LCD_cmd(0x01); LCD_string("data tx"); LCD_cmd(0xc0);LCD_string(" not ACK\r");break;
		case 0x60:LCD_cmd(0x01); LCD_string("data nt by master");break;
		case 0x58:LCD_cmd(0x01); LCD_string("not ack ");break;
		case 0x50:LCD_cmd(0x01); LCD_string("data received");break;
		default: LCD_cmd(0x01);  LCD_string("ERROR in SLA+W\r ");
	}
}



void i2c_stop()
{
	TWCR=(1<<TWEN)|(1<<TWSTO)|(1<<TWINT);
	for(int k=0;k<100;k++);
}


int main()
{
  LCD_enable();
  LCD_cmd(0xc0);
  LCD_string("sending data");
  i2c_init();
  i2c_start();
  i2c_write(0xfe);
 // i2c_stop();
  while(1);	
}