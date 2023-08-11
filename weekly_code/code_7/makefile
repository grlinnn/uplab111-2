OBJ= little_redman

all : intel-HEX.hex

intel-HEX.hex : $(OBJ).ihx
	packihx $(OBJ).ihx > intel-HEX.hex
$(OBJ).ihx : $(OBJ).c myIO.lib
	 sdcc $(OBJ).c myIO.lib

myIO.lib :little_redman.rel
	sdar -o myIO.lib -rc little_redman.rel

little_redman.rel : little_redman.c
	sdcc -c little_redman.c
	
clean : 
	del *.asm *.rel *.sym *.lib *.lk *.rst *.lst *.mem *.ihx *.map *.hex


