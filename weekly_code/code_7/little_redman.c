#include <8051.h>

unsigned char display_vertical[][8] =
{
	{0x7f, 0xbf, 0xdf, 0xef, 0xf7, 0xfb, 0xfd, 0xfe}	// row
};

unsigned char display_horizontal[][8] =
{
	//{0xfb, 0xf5, 0xfb, 0xfb, 0xfb, 0xfb, 0xf3, 0xef},
	//{0xfb, 0xf5, 0xfb, 0xf3, 0xeb, 0xfb, 0xfb, 0xfb};
	{0xcf,0xb7,0xcf,0xe7,0xeb,0xd7,0xe3,0xeb},
	{0xcf,0xb7,0xcf,0xe7,0xe7,0xe3,0xe3,0xf3},
	{0xcf, 0xb7, 0xcf, 0xe7, 0xeb, 0xd7, 0xf7, 0xeb}
};

void main()
{
	P0 = 0x00;
	P1 = 0x00;
	for (unsigned z = 0; z < 1024; z++) {
		for (unsigned y = 0; y < 1024; y++) {
			
		}
	}

	while (1)
	{
		for (char k = 0; k < 10; k++)
		{
			for (char i = 0; i < 8; i++)
			{
				P0 = display_vertical[0][i];
				P1 = display_horizontal[0][i];
				// delay
				for (char a = 0; a < 200; a++)
				{
					for (char b = 0; b < 10; b++)
					{
					}
				}
			}
		}
		
		for (char k = 0; k < 10; k++)
		{
			for (char i = 0; i < 8; i++)
			{
				P0 = display_vertical[0][i];
				P1 = display_horizontal[1][i];

				// delay
				for (char a = 0; a < 200; a++)
				{
					for (char b = 0; b < 10; b++)
					{
					}
				}
			}
		}
		for (char k = 0; k < 10; k++)
		{
			for (char i = 0; i < 8; i++)
			{
				P0 = display_vertical[0][i];
				P1 = display_horizontal[2][i];

				// delay
				for (char a = 0; a < 200; a++)
				{
					for (char b = 0; b < 10; b++)
					{
					}
				}
			}
		}
	}
}