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

void LED_display(unsigned digit[])
{
	P1 = 0xe0 + digit[0];
	delay(5);
	P1 = 0xd0 + digit[1];
	delay(5);
	P1 = 0xb0 + digit[2];
	delay(5);
	P1 = 0x70 + digit[3];
	delay(5);
}