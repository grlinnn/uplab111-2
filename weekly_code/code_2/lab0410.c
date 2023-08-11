#include <8051.h>

#define count 5000

void delay(unsigned int count1);
int setting();

int mode = 0;

void main()
{
	unsigned  num = 0, indexf = 0,indexl=0;
	unsigned ledf[10] = { 0xe0,0xe1,0xe2,0xe3,0xe4,0xe5,0xe6,0xe7,0xe8,0xe9 };//
	unsigned ledl[10] = { 0xd0,0xd1,0xd2,0xd3,0xd4,0xd5,0xd6,0xd7,0xd8,0xd9 };//
	unsigned display1, display2, temp = 0;
	int flashcount = 0,mincount=100;
	int delay1 = 0, delay2 = 0;
	//start
	display1 = ledf[indexf];
	display2 = ledl[indexl];
	while (1)
	{
		//代刚

		
		setting();
		if (mode == 1)//计
		{
			if (P1_1 != 1)////秙1
			{
				//debounce
				while (P1_1 == 0) {
					P0 = display1;
					delay(20);
					P0 = display2;
					delay(20);
				};

				if (indexl == 9)
					indexl = 0;
				else
					indexl += 1;
				display2 =ledl[indexl];
				delay(count);
			}
			P0 = display1;
			delay(3000);
			P0 = display2;
			delay(400);
		}
		if (mode == 2)//计
		{
			if (P1_1 != 1)//秙1
			{
				//debounce
				while (P1_1 == 0) {
					P0 = display1;
					delay(20);
					P0 = display2;
					delay(20);
				};
				if (indexf == 9)
					indexf = 0;
				else
					indexf += 1;
				display1 = ledf[indexf];
				delay(count);
			}
			P0 = display2;
			delay(3000);
			P0 = display1;
			delay(400);
		}
		if (mode == 3)//璸
		{
			if (mincount == 0)//计┑筐
			{
				if (indexf == 0)//计0
				{
					if (indexl == 0)//计0
						mode = 0;//挡计
					else
					{
						indexl -= 1;//计-1
						indexf = 9;
					}
				}
				else
					indexf -= 1;//计-1
				mincount = 100;
			}
			display2 = ledl[indexl];
			display1 = ledf[indexf];
			mincount--;
		}

		//陪ボ
		P0 = display1;
		delay(20);
		//P0 = ledl[mode];
		P0 = display2;
		delay(20);
	}
}

int setting()
{
	if (P1_0 != 1)
	{
		if (mode == 0)
			mode = 1;
		else if (mode == 1)
			mode = 2;
		else if (mode == 2)
			mode = 3;
		delay(5000);
	}
	return mode;
}

void delay(unsigned int count1)
{
	unsigned d1,de;
	for (d1 = 0; d1 < count1; d1++) {
		for (de = 0; de < 10; de++)
		{
		}
	}
}