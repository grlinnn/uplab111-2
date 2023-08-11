# Given Problem
# ISR

# Check the Comment at the end of this README to see my code's problem from the feedback of the Teaching Assistant

#include <8051.h>

#define T0VAL (65536-50000)

unsigned char ticks = 0;

void Timer0_ISR(void) __interrupt(1) __using(1)
{
   __asm
   mov TH0, #(T0VAL >> 8)
   mov TL0, #(T0VAL)
   mov A, _ticks
   inc A
   mov _ticks, A
   __endasm;
}

void main()
{
   while(1) {
      if (ticks >= 10) {
         ticks = 0;
         // ...
      }
   }
}

群組作業是要將 Keypad 與 7-seg Display 的程式改在 interrupt service routine 中來完成。 interrupt frequency 設為 80 Hz，每次 interrupt 顯示一個位數（共四個 digits，所以掃描顯示輪的頻率為 20 Hz)，每四次 interrupts 掃一次 keypad。

評分標準：

1. 完成指定任務：87 分

2.  没有適當註解：扣 5 分

3. 程式没有適當對齊與縮排：扣 10 分

4. 使用過大變數：一個變數扣 1 分

5. Program Memory Size 最小的前5名的組別： 加 1 至 5 分

6. 前5名領先完成的組別： 加 1 至 5 分

# Comment : 	
None

# Grade : 92
