#include <8051.h>
#define SegOne   0xfe
#define SegTwo   0xfd
#define SegThree 0xfb
#define SegFour  0xf7	

void msdelay(unsigned int time)  // Function for creating delay in milliseconds.
{
	unsigned i, j;

	for (i = 0; i < time; i++)

		for (j = 0; j < 1275; j++);

}

void LED_display_READY(unsigned char digit[])
{
	P0 = SegOne;
	P1 = digit[0];
	msdelay(1);

	P0 = SegTwo;
	P1 = digit[1];
	msdelay(1);

	P0 = SegThree;
	P1 = digit[2];
	msdelay(1);

	P0 = SegFour;
	P1 = digit[3];
	msdelay(1);
}

void LED_display_PLAY(unsigned char digit[])
{
	P0 = SegOne;
	P1 = digit[0];
	msdelay(100);

	P0 = SegTwo;
	P1 = digit[1];
	msdelay(100);

	P0 = SegThree;
	P1 = digit[2];
	msdelay(100);

	P0 = SegFour;
	P1 = digit[3];
	msdelay(100);
}

void LED_display_REC(unsigned char digit[])
{
	P0 = SegOne;
	P1 = digit[0];
	msdelay(100);

	P0 = SegTwo;
	P1 = digit[1];
	msdelay(100);

	P0 = SegThree;
	P1 = digit[2];
	msdelay(100);

	P0 = SegFour;
	P1 = digit[3];
	msdelay(100);
}

void LED_display_STOP(unsigned char digit[])
{
	P0 = SegOne;
	P1 = digit[0];
	msdelay(100);

	P0 = SegTwo;
	P1 = digit[1];
	msdelay(100);

	P0 = SegThree;
	P1 = digit[2];
	msdelay(100);

	P0 = SegFour;
	P1 = digit[3];
	msdelay(100);
}

void LED_display(unsigned char digit[])
{
	P0 = SegOne;
	P1 = digit[0];
	msdelay(1);

	P0 = SegTwo;
	P1 = digit[1];
	msdelay(1);

	P0 = SegThree;
	P1 = digit[2];
	msdelay(1);

	P0 = SegFour;
	P1 = digit[3];
	msdelay(1);
}