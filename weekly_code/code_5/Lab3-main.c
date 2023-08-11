#include <8051.h>
#include "LED_Display.h"
#include "Keypad4x4.h"
#define TIMECOUNT (65536-12500)

char keypad_counter = 0;
unsigned flag_input = 0;
unsigned digit[4] = { 15,15,15,15 };
unsigned char input;
char digit_display_index = 0;

void timer0_isr(void) __interrupt(1) __using(1)
{
	TL0 = TIMECOUNT & 0xff;
	TH0 = TIMECOUNT >> 8;

	// we go back displaying the rightmost digit
	if (digit_display_index > 3)
	{
		digit_display_index = 0;
	}

	// display one digit at every interrupt
	switch (digit_display_index)
	{
	case 0:
		LED_display(digit_display_index, digit[digit_display_index]);
		break;
	case 1:
		LED_display(digit_display_index, digit[digit_display_index]);
		break;
	case 2:
		LED_display(digit_display_index, digit[digit_display_index]);
		break;
	case 3:
		LED_display(digit_display_index, digit[digit_display_index]);
		break;
	}

	// display the next upper digit level at next interrupt
	digit_display_index++;
	
	// add 1 at each interrupt
	keypad_counter++;

	// means we have passed 4 interruprs
	if (keypad_counter == 4)
	{
		/*keypad_counter = 0;
		input = detect_keypad();*/

		// to detect if a key has been pressed and released.
		if (flag_input == 1 && input != 16)
		{
			digit[3] = digit[2];
			digit[2] = digit[1];
			digit[1] = digit[0];
			digit[0] = input;
			flag_input = 0;
		}

		if (input == 16)
		{
			flag_input = 1;
		}
	}
}

void main() 
{
	TMOD = 0x11;	// configure Timer 0 to operate in Mode 1
	TCON = 0x10;	// enable Timer 0
	IE = 0x82;		// set EA = 1, and ET0 = 1
	/*TL0 = TIMECOUNT & 0xff;
	TH0 = TIMECOUNT >> 8;*/

	TL0 = 176;
	TH0 = 60;

	while (1)
	{
		if (keypad_counter == 4)
		{
			keypad_counter = 0;
			input = detect_keypad();
		}
	}
}