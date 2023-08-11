#include <8051.h>
#include "LED_Display.h"
#define timecount 15536	// have passed 0.05s
char counter = 0;
char start = 0;


void timer0_isr(void) __interrupt(1) __using(1)
{
	TL0 = timecount & 0xff;
	TH0 = timecount >> 8;
	if (counter == 0)
	{	
		start = 1;		// performs addition
		counter = 10;	// when counter = 10, means we have passed 0.5s
	}
	counter--;
}



void main()
{
	TMOD = 0x11;	// configure Timer 0 to operate in Mode 1
	TCON = 0x10;	// enable Timer 0
	IE = 0x82;		// set EA = 1, and ET0 = 1
	TL0 = timecount&0xff;
	TH0 = timecount>>8;

	char num[2] = {0,0};
	while (1)
	{
		
		if (start == 1) {
			num[0]++;
			// 加十位數
			if (num[0] > 9) {
				num[1]++;
				num[0] = 0;
			}

			// when the number has reached 99, then reset it to 00
			if (num[1] > 9) {
				num[1] = 0;
				num[0] = 0;
			}

			// reset the interrupt
			start = 0;
		}

		// display the current number
		for (int i = 0; i < 2; i++) {
			LED_display(i, num[i]);
			delay(5);
		}
	}
}