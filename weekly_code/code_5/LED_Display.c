#include <8051.h>

void delay(unsigned count)
{
	unsigned d1, d2;
	for (d1 = 0; d1 < count; d1++)
	{
		for (d2 = 0; d2 < 1024; d2++)
		{

		}
	}
}

void LED_display(char index, char num) {
	P1 = 0xeF;
	P1 = ((P1 << index) & 0xF0) + num;
}