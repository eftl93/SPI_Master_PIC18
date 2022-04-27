
#include <htc.h>
#include <p18f4550.h>
#define _XTAL_FREQ 64000000
void spi_master_init();
unsigned char spi_data(unsigned char tx_data);
unsigned char spi_read_data;
void main(void)
{
spi_master_init();

while(1)
{
spi_read_data=spi_data(0xFE);
  
}
}


void spi_master_init()
{
SSPSTAT=0x00;
SSPCON1=0b00100010;
TRISC&=0b01111111;
TRISB&=0b11111101;
TRISA|=0b00100000;
ADCON0=0x00;
ADCON1=0x0F;
CMCON=0x00;
SPPCON=0x00;
TRISD&=0b11111110;
PORTD|=0x01;
}

unsigned char spi_data(unsigned char tx_data)
{
char data_read;
PORTD&=0b11111110;
SSPBUF=tx_data;
while(!SSPSTATbits.BF);
PORTD&=0b00000001;
data_read=SSPBUF;
return data_read;
}



