all: TestGPIO

TestGPIO: TestGPIO.c	
	gcc -Wall -o TestGPIO TestGPIO.c -lwiringPi

