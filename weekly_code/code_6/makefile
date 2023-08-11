OBJ= music

all : intel-HEX.hex

intel-HEX.hex : $(OBJ).ihx
	packihx $(OBJ).ihx > intel-HEX.hex
$(OBJ).ihx : $(OBJ).c myIO.lib
	 sdcc $(OBJ).c myIO.lib

myIO.lib :music.rel
	sdar -o myIO.lib -rc music.rel

music.rel : music.c
	sdcc -c music.c
	
clean : 
	del *.asm *.rel *.sym *.lib *.lk *.rst *.lst *.mem *.ihx *.map *.hex


