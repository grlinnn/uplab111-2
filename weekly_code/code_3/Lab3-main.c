#include <8051.h>
#include "LED_Display.h"
#include "Keypad4x4.h"

void main() 
{
	unsigned flag_input = 0;
	unsigned digit[4] = { 15,15,15,15 };
	while (1)
	{
		char num = detect_keypad();
		if (flag_input == 1 && num != 16) {
			digit[3] = digit[2];
			digit[2] = digit[1];
			digit[1] = digit[0];
			digit[0] = num;
			flag_input = 0;
		}
		if (num == 16) {
			flag_input = 1;
		}
		LED_display(digit);
	}
	
}