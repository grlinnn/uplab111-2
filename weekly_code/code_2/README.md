# Given Problem
# Push Button Debouncing, LED Scanning, and Down CountingAssignment

# Check the Comment at the end of this README to see my code's problem from the feedback of the Teaching Assistant

 mov r7,#0x00
     mov r6,#0x09
00102$:
     mov a,r6
     add a,r7
     mov r7,a
     mov r5,r6
     mov a,r5
     add a,#0xfe
     mov r6,a
     jnz 00102$

本週實驗：以按鍵設定七段顯示器 (Seven-Segment LED Display) 之兩位十進位數字，然後自動倒數至零。

選擇兩個按鍵 (Push Button)，一個為作為 「+1」、另一個作為「設定」。

數字初始值為 00，壓「設定」鍵，進入設定模式，先由十進位開始閃爍，個位數不動，再壓「設定」鍵第二次，換為個位數閃爍。

每按 「+1」一次， 閃爍的位數數值加一： 0->1->...->8->9->0->...。

壓「設定」鍵第三次時，離開設定模式，開始進行倒數顯式，倒數至零停止。

請注意按鍵的 Debounce 處理！

評分標準：

1. 完成指定任務：87 分

2.  没有適當註解：扣 2 分

3. 程式没有適當對齊與縮排：扣 5 分

4. 使用過大變數：一個變數扣 1 分

5. Program Memory Size 最小的前5名的組別： 加 1 至 5 分

6. 前5名領先完成的組別： 加 1 至 5 分

# Comment : 	
None

# Grade : 87
