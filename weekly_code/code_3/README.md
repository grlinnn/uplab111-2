# Given Problem
# 4x4 Keypad

# Check the Comment at the end of this README to see my code's problem from the feedback of the Teaching Assistant

本週的實驗是要讓各位同學瞭解矩陣式鍵盤的原理與掃描方法，它的目的是要降低 I/O 接腳的使用量。請試著回答下列問題，看看你是否都瞭解了。

問題: 設有一鍵盤上有 m x n 個按鍵，若使用傳統技術，每一按鍵使用一條 I/O 接腳，則共需 ____ 個 I/O 接腳，反之若使用掃描式的矩陣鍵盤，則需 ____ 條線。

本周實驗時有許多組同學是使用暴力比對的方式來決定那一個鍵被按下，這樣的寫法會耗掉大量程式記憶體，而且不像是專業程式設計師的作品，請試著改成較精簡的程式。

4x4 Keypad pinout:

==== THERE SHOULD BE AN IMAGE ABOUT THE KEYPAD PIN ====

本週實驗: 讀取 4x4 矩陣式鍵盤之輸入，處理 Debounce ，並將結果顯示於七段顯示器上。4x4 矩陣式鍵盤之按鍵個數共十六個，以十六進位表示剛好為 0-F 之數字。請直接將數字送至74LS47，以下列結果顯示即可。

==== THERE SHOULD BE AN IMAGE ABOUT 7-SEG DISPLAY REPRESENTATION FOR EACH NUMBER 0-9 AND THE REST 5 SYMBOLS ====

LED的初始狀態為四個 F，操作方式如同使用計算機，新輸入的數字將會出現在最右邊，其餘的數字則左移一位，而最左邊的數字會消失。程式需滿足下列要求：

1. 不可使用 switch/case 或一系列 if/else 來讀取 keypad 輸入

2. 需分為 LED_Display.c/LED_Display.h, Keypad4x4.c/Keypad4x4.h 以及 Lab3-main.c 等三個程式。

3. LED_Display.c 與 Keypad4x4.c 必須編在 myIO.lib 中

4. Lab3-main.c 透過 include LED_Display.h 與 Keypad4x4.h 兩個 header files 取得定義在 myIO.lib 中的函數宣告。並必須透過聯結 myIO.lib 中的程式以產生 intel-HEX (.hex) file。

5. 請改寫 Makefile 以便自動產生 .hex file。

Note: Use sdar to create and update a library and then use sdranlib to add/update index information in the library.

# Comment : 	
沒有註解-5

# Grade : 82
