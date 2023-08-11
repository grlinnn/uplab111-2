#include <8051.h>

char detect_keypad()
{
	for (char row = 0; row < 4; row++)
	{
		P0 = ~(1 << row);	// row to left shift, then complement the value.
		if ((P0 & 0xF0) != 0xF0)	// let P0 != 0xff, means a button in this row is pressed
		{
			for (char col = 0; col < 4; col++)
			{
				if (!(P0 & (0x10 << col)))
				{
					return col * 4 + row;
				}
			}
		}
	}
	return 16;                                                             
}