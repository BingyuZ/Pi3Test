all: TestGPIO Test2812 TestI2C

TestGPIO: TestGPIO.c	
	gcc -Wall -o TestGPIO TestGPIO.c -lwiringPi

Test2812: Test2812.c	
	gcc -Wall -o Test2812 Test2812.c -lwiringPi

TestI2C: TestI2C.c	
	gcc -Wall -o TestI2C TestI2C.c -lwiringPi

clean:
	rm TestGPIO Test2812 TestI2C