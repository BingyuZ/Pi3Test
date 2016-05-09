// Simple program to demonstrate the use of PI & PCF8591
#include <stdio.h>
#include <stdlib.h>

#include <wiringPi.h>
#include <pcf8591.h>

#define PCFBASE	100
#define LED	21

int sens[] = {110, 120, 130, 145, 160, 175, 190, 210, 230, 250};
char *desc[] = {"Light", "???", "Temper", "Volt"};

int main(int argc, char *argv[])
{
	wiringPiSetup();
	pcf8591Setup(PCFBASE, 0x48);
	printf("Pi ADDA board test\n");
	
	pinMode(LED, OUTPUT);
	
	while (1)
	{
		int i;
		digitalWrite(LED, 0);
		for (i=0; i<10; i++) {
			analogWrite(PCFBASE, sens[i]);
			delay(100);
		}
		digitalWrite(LED, 1);
		for (i=9; i>=0; i--) {
			analogWrite(PCFBASE, sens[i]);
			delay(100);
		}
		printf("Analog input: ");
		for (i=0; i<4; i++){
			int v = analogRead(PCFBASE+i);
			printf("  %s:%d", desc[i], v);
		}
		printf("\n");
	}
}
