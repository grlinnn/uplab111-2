OBJ= main

all : intel-HEX.hex

intel-HEX.hex : $(OBJ).ihx
	packihx $(OBJ).ihx > intel-HEX.hex
$(OBJ).ihx : $(OBJ).c myIO.lib
	 sdcc $(OBJ).c myIO.lib

myIO.lib :LED_Display.rel Keypad4x4.rel
	sdar -o myIO.lib -rc LED_Display.rel Keypad4x4.rel
Keypad4x4.rel : Keypad4x4.c Keypad4x4.h
	sdcc -c Keypad4x4.c
LED_Display.rel : LED_Display.c LED_Display.h
	sdcc -c LED_Display.c
	
clean : 
	del *.asm *.rel *.sym *.lib *.lk *.rst *.lst *.mem *.ihx *.map *.hex


