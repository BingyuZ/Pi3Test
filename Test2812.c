// Simple program to demonstrate the use of PI & WS2812
#include <stdio.h>
#include <stdlib.h>

#include <wiringPi.h>
#include <wiringPiSPI.h>

unsigned char buffer[3500];
const unsigned int SPI_SPEED = 12000000;
const unsigned char SPI_LOW = 0xe0;		// High first
const unsigned char SPI_HIGH = 0xf8;	
const unsigned colors[] = {
	0x800000, 0x400400, 0x200800, 0x101000, 0x082000, 0x044000,
	0x008000, 0x004004, 0x002008, 0x001010, 0x000820, 0x000440,
	0x000080, 0x040040, 0x080020, 0x100010, 0x200008, 0x400004,
	0x800000, 0x400400, 0x200800, 0x101000, 0x082000, 0x044000,
	0x008000, 0x004004, 0x002008, 0x001010, 0x000820, 0x000440,
};

void SendGRB(unsigned char *buf, int pos, unsigned int grb)
{
	int i;
	buf += pos * 24;
	unsigned mask = 0x800000;
	for (i=0; i<24; i++) {
		*buf++ = (grb & mask)?SPI_HIGH:SPI_LOW;
		mask >>= 1;
	}
}

int main(int argc, char *argv[])
{
	wiringPiSetup();
	wiringPiSPISetup(0, SPI_SPEED);
	
	int i, j;
	for (i=0; i<20; i++) 
	  for (j=0; j<18; j++) {
		SendGRB(buffer, 0, colors[j]);
		SendGRB(buffer, 1, colors[j+6]);
		SendGRB(buffer, 2, colors[j+12]);
		SendGRB(buffer, 3, 0);
		wiringPiSPIDataRW(0, buffer, 4*24);
		delay(200);
	}
	SendGRB(buffer, 0, 0x050000);
	SendGRB(buffer, 1, 0x000500);
	SendGRB(buffer, 2, 0x000005);
	SendGRB(buffer, 3, 0);
	wiringPiSPIDataRW(0, buffer, 4*24);
	return 0;
}
