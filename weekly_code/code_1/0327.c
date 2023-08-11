#include <8051.h>

void main()
{
	unsigned d1, d2, i;
	unsigned led[8] = {0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};	//走馬燈的順序
	unsigned led1[8] = {0x7f,0xbf};
	while (1)
	{
		for (i = 1; i < 6; i++) {
			P0 = led[i];//第一個燈~第七個燈
			for (d1 = 0; d1 < 1024; d1++) {
				for (d2 = 0; d2 < 100; d2++) {
				}
			}
		}
		P0 = 0xff;
		for (i = 0; i < 8; i++) {
			P2 = led[i];//第八個燈~第十五個燈
			for (d1 = 0; d1 < 1024; d1++) {
				for (d2 = 0; d2 < 100; d2++) {
				}
			}
		}
		P2 = 0xff;
		for (i = 0; i < 8; i++) {
			P1 = led[i];//第十五個燈~第二三個燈
			for (d1 = 0; d1 < 1024; d1++) {
				for (d2 = 0; d2 < 100; d2++) {
				}
			}
		}
		P1 = 0xff;
		for (int i = 0; i < 2; i++) {
			P0 = led1[i];	
			for (d1 = 0; d1 < 1024; d1++) {
				for (d2 = 0; d2 < 100; d2++) {
				}
			}
		}
		for (d1 = 0; d1 < 1024; d1++) {
			for (d2 = 0; d2 < 100; d2++) {
			}
		}
		P0 = 0xff;
		//迴轉
		for (i = 8; i > 0; i--) {
			P1 = led[i - 1];//第十五個燈~第二三個燈
			for (d1 = 0; d1 < 1024; d1++) {
				for (d2 = 0; d2 < 100; d2++) {
				}
			}
		}
		P1 = 0xff;
		for (i = 8; i > 0; i--) {
			P2 = led[i - 1];//第八個燈~第十五個燈
			for (d1 = 0; d1 < 1024; d1++) {
				for (d2 = 0; d2 < 100; d2++) {
				}
			}
		}
		P2 = 0xff;
		for (i = 8; i > 1; i--) {
			P0 = led[i - 1];//第一個燈~第七個燈
			for (d1 = 0; d1 < 1024; d1++) {
				for (d2 = 0; d2 < 100; d2++) {
				}
			}
		}
		P0 = 0xff;
	}
}

