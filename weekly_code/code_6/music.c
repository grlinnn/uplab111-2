#include <8051.h>
#define TIMECOUNT 3036	//625ms -> 65536-62500 = 3036 
#define hzcal(x) 65536 - 1000000 / (2 * x)
char counter = 0;	//TIMECOUNT 10times 625 ms -> 0.625 s
char flag = 0; 

const unsigned short key[] =
{
	hzcal(262),		//0		Do
	hzcal(294),		//1		Re
	hzcal(330),		//2		Mi
	hzcal(349),		//3		Fa
	hzcal(392),		//4		Sol
	hzcal(440),		//5		La
	hzcal(494),		//6		Si

	hzcal(524),		//7		1.
	hzcal(587),		//8		2.
	hzcal(659),		//9		3.
	hzcal(698),		//10	4.
	hzcal(784),		//11	5.
	hzcal(880),		//12	6.
	hzcal(988),		//13	7.
	hzcal(1047),	//14	1..
	hzcal(1175),	//15	2..
	hzcal(1319),	//16	3..

	hzcal(622),		//17	#2
	hzcal(1245),	//18	#2..
	hzcal(277),		//19	#1
	hzcal(554),		//20	#1.
	hzcal(1108),	//21	#1..
	hzcal(415),		//22	#5
	hzcal(831),		//23	#5.
	hzcal(466),		//24	#6

	hzcal(233)		//25	B7
};

// The Song 「愛的羅曼史」
const unsigned char keynote[] =
{
	// Page 1
	9,9,9, 9,8,7, 7,6,5, 5,7,9, 12,12,12, 12,11,10,

	// Page 2
	10,9,8, 8,9,10, 9,10,9, 23,10,9, 9,8,7, 7,6,5, 6,6,6, 6,7,6, 5,5,5, 5,5,5,

	// Page 3
	9,9,9, 9,8,7, 7,6,6, 6,24,6, 12,12,12, 12,13,12, 12,11,11, 11,12,13, 14,14,14,

	// Page 4
	14,13,13, 12,12,12, 12,11,10, 9,9,9, 9,10,8, 7,7,7, 7,7,7
};

// 計音符播放時間
void timer0_isr(void) __interrupt(1) __using(1)
{
	TL0 = TIMECOUNT & 0xff;	// reserve for the lower 8 bits
	TH0 = TIMECOUNT >> 8;	// reserve for the rest of upper 8 bits
	counter++;
}

// 產生每個音符所需的頻率
void timer1_isr(void) __interrupt(3) __using(3)
{
	TH1 = key[keynote[flag]] >> 8;
	TL1 = key[keynote[flag]] & 0xff;
	P0 = ~P0;
}

void main()
{
	TMOD = 0x11;	// configure Timer 0 and Timer 1 to operate in Mode 1
	TCON = 0x50;	// enable Timer 0 and Timer 1
	IE = 0x8a;		// set EA = 1, ET1 = 1, and ET0 = 1
	TL0 = TIMECOUNT & 0xff;
	TH0 = TIMECOUNT >> 8;

	TL1 = key[0] & 0xff;
	TH1 = key[0] >> 8;

	while (1)
	{
		// means we have passed 0.625s
		if (counter >= 10)
		{
			counter = 0;

			// passed one note
			flag += 1;

			// back to the first note
			if (flag >= 95)
			{
				flag = 0;
			}
		}
	}
}