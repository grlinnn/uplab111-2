#include <8051.h>

void main()
{
	unsigned d1, d2, i;
	unsigned led[8] = {0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};	//�����O������
	unsigned led1[8] = {0x7f,0xbf};
	while (1)
	{
		for (i = 1; i < 6; i++) {
			P0 = led[i];//�Ĥ@�ӿO~�ĤC�ӿO
			for (d1 = 0; d1 < 1024; d1++) {
				for (d2 = 0; d2 < 100; d2++) {
				}
			}
		}
		P0 = 0xff;
		for (i = 0; i < 8; i++) {
			P2 = led[i];//�ĤK�ӿO~�ĤQ���ӿO
			for (d1 = 0; d1 < 1024; d1++) {
				for (d2 = 0; d2 < 100; d2++) {
				}
			}
		}
		P2 = 0xff;
		for (i = 0; i < 8; i++) {
			P1 = led[i];//�ĤQ���ӿO~�ĤG�T�ӿO
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
		//�j��
		for (i = 8; i > 0; i--) {
			P1 = led[i - 1];//�ĤQ���ӿO~�ĤG�T�ӿO
			for (d1 = 0; d1 < 1024; d1++) {
				for (d2 = 0; d2 < 100; d2++) {
				}
			}
		}
		P1 = 0xff;
		for (i = 8; i > 0; i--) {
			P2 = led[i - 1];//�ĤK�ӿO~�ĤQ���ӿO
			for (d1 = 0; d1 < 1024; d1++) {
				for (d2 = 0; d2 < 100; d2++) {
				}
			}
		}
		P2 = 0xff;
		for (i = 8; i > 1; i--) {
			P0 = led[i - 1];//�Ĥ@�ӿO~�ĤC�ӿO
			for (d1 = 0; d1 < 1024; d1++) {
				for (d2 = 0; d2 < 100; d2++) {
				}
			}
		}
		P0 = 0xff;
	}
}

