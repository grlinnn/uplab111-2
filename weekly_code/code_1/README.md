# Given Problem
# 跑馬燈

# Check the Comment at the end of this README to see my code's problem from the feedback of the Teaching Assistant

本週實驗題目是使用 8051 控制廣告燈模組，由3點鐘方向開始點亮LED，經適當時間延遲後熄滅，再依順時針方向對下一顆 LED 點亮、延遲、熄滅，並依此類推，造成LED灯順時跑動的感覺。一直至回到3點鐘方向同一顆LED，然後開始逆時鐘轉。如此週而復始，每次碰到那一顆LED就會反轉。

評分標準：

1. 完成指定任務：87 分

2.  没有適當註解：扣 2 分

3. 程式没有適當對齊與縮排：扣 5 分

4. 使用過大變數：一個變數扣 1 分

5. Program Memory Size 最小的前5名的組別： 加 1 至 5 分

6. 前5名領先完成的組別： 加 1 至 5 分

Mark as done
1. Bit masking: e.g., mask = 0b00011100;  P0 = (P0 & ~mask) | (Val & mask);

2. Bit-fields + union:

typedef struct {
   unsigned char a : 3;
   unsigned char b : 2;
   unsigned char c : 3;
} ioSample;

union {
   ioSample bitfields;
   unsigned char byte;
} U;
U.byte = 0;
U.bitfields.a = 7;
printf("0x%02X\n", U.byte);
U.byte = 0;
U.bitfields.b = 3;
printf("0x%02X\n", U.byte);
U.byte = 0;
U.bitfields.c = 7;
printf("0x%02X\n", U.byte);
U.byte = 0;
U.bitfields.a = 7;
U.bitfields.b = 3;
U.bitfields.c = 7;
printf("0x%02X\n", U.byte);

3. Left/right shift operations:  P0 = ~(1 << n);  P0 = (0x80 >> n);

# Comment : 	
makefile 有錯 -5
