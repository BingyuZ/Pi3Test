// Simple program to demonstrate the use of PI & WS2812
#include <stdio.h>
#include <stdlib.h>

#include <wiringPi.h>

int main(int argc, char *argv[])
{
	wiringPiSetup();
	pinMode(21, OUTPUT);
	pinMode(22, OUTPUT);
	pinMode(23, INPUT);
	pinMode(24, INPUT);

	int i, oldPin = -1;

	puts("GPIO demo, press CTRL^C to quit.");
	while (1) {
		for (i=0; i<4; i++){
			digitalWrite(21, (i&1)?HIGH:LOW);
			digitalWrite(22, (i&2)?HIGH:LOW);
			int np = digitalRead(23)*2 + digitalRead(24);
			if (oldPin != np) {
				printf("SW Changed! SW1:%d, SW2:%d\n",
						(np&2)?0:1, (np&1)?0:1);
				oldPin = np;
			}
			delay(200);
		}
	}
	return 0;
}

