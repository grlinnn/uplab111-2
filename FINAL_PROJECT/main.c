#include <8051.h>
#include "LED_Display.h"
#include "Keypad4x4.h"

#define SegOne   0xfe
#define SegTwo   0xfd
#define SegThree 0xfb
#define SegFour  0xf7	

#define TIMECOUNT 3036	//625ms -> 65536-62500 = 3036 
#define hzcal(x) 65536 - 1000000 / (2 * x)

#define TRUE    1
#define FALSE   0

// THE ELEMENT OF KEY ARRAY WHICH HAS FREQUENCY OF 0
#define NOTE_DEFAULT_INITIAL_VALUE  26

// THE MAXIMUM AVAILABLE RECORDED NOTES
#define MAXIMUM_RECORDED_NOTES 49

char counter = 0;	// TIMECOUNT 10times 625 ms -> 0.625 s
char flag = 0;
unsigned char key_input;

// INITIALIZATION OF THE NOTE TO NO SOUND
char note = NOTE_DEFAULT_INITIAL_VALUE;

// THE RECORDED NOTES THAT PLAYED BY THE USER
//AUXR &= 0x00; //clear AUXR.1 for on-chip XRAM 
__xdata char recorded_note[MAXIMUM_RECORDED_NOTES];

// SET RECORDING MODE
char isRecording = FALSE;

// SET PLAYBACK MODE
char isPlaybackMode = FALSE;

const unsigned short key[] =
{
    hzcal(262),		//0		Do
    hzcal(294),		//1		Re
    hzcal(330),		//2		Mi
    hzcal(349),		//3		Fa
    hzcal(392),		//4		Sol
    hzcal(440),		//5		La
    hzcal(494),		//6		Si

    hzcal(524),		//7		1.
    hzcal(587),		//8		2.
    hzcal(659),		//9		3.
    hzcal(698),		//10	4.
    hzcal(784),		//11	5.
    hzcal(880),		//12	6.
    hzcal(988),		//13	7.
    hzcal(1047),	//14	1..
    hzcal(1175),	//15	2..
    hzcal(1319),	//16	3..

    hzcal(622),		//17	#2
    hzcal(1245),	//18	#2..
    hzcal(277),		//19	#1
    hzcal(554),		//20	#1.
    hzcal(1108),	//21	#1..
    hzcal(415),		//22	#5
    hzcal(831),		//23	#5.
    hzcal(466),		//24	#6

    hzcal(233),		//25	B7
    hzcal(7.62939453125)        //26        // SET AS THE DEFAULT VALUE ( NO SOUND )
};

void timer0_isr(void) __interrupt(1) __using(1)
{
    TL0 = TIMECOUNT & 0xff;	// reserve for the lower 8 bits
    TH0 = TIMECOUNT >> 8;	// reserve for the rest of upper 8 bits
    counter++;
}

void timer1_isr(void) __interrupt(3) __using(3)
{
    /*if (isPlaybackMode)
    {
        P3 = ~P3;
        TH1 = key[recorded_note[flag] >> 8;
        TL1 = key[recorded_note[flag] & 0xff;

    }
    else
    {
        P3 = ~P3;
        TH1 = key[note] >> 8;
        TL1 = key[note] & 0xff;
    }*/
    
    P3 = ~P3;
    TH1 = key[note] >> 8;
    TL1 = key[note] & 0xff;
}

void main()
{
    unsigned flag_input         = 0;

    // THE 7-SEGMENT DISPLAY GRAPHICAL REPRESENTATION FROM "0" TO "F"
    unsigned char no_code[]     = { 0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E };

    // THE 7-SEGMENT DISPLAY GRAPHICAL REPRESENTATION FOR 4 DIGITS TO BE DISPLAYED
    unsigned char digit[4]      = { 0xC0, 0xC0, 0xC0, 0xC0 };

    // THE 7 - SEGMENT DISPLAY GRAPHICAL REPRESENTATION FOR "RDY"
    unsigned char LED_graphical_READY[] = 
    {
        0xCE,   // r
        0xA1,   // d
        0x91,   // Y
        0xFF    // BLANK SPACE
    };

    // THE 7 - SEGMENT DISPLAY GRAPHICAL REPRESENTATION FOR "PLAY"
    unsigned char LED_graphical_PLAY[] = {
    0x8C, // P
    0xC7, // L
    0x88, // A
    0x91, // Y
    };

    unsigned char LED_graphical_REC[] = {
    0xCE, // r
    0x86, // E
    0xC6, // C
    0xFF  // BLANK SPACE
    };

    unsigned char LED_graphical_STOP[] = {
    0x92, // S
    0x87, // t
    0xA3, // o
    0x8C  // P
    };


    // the last key pressed by the user
    char last_pressed_key   = -1;
    char key_isReleased     = FALSE;    // Set to FALSE

    // PLAYBACK INDICES
    /*unsigned long xdata     recorded_note[MAXIMUM_RECORDED_NOTES];*/
    unsigned playback_note_index = 0;
    unsigned last_played_note_playback_note_index = 0;


    TMOD    = 0x11;	    // configure Timer 0 and Timer 1 to operate in Mode 1
    TCON    = 0x50;	    // enable Timer 0 and Timer 1
    IE      = 0x8a;		// set EA = 1, ET1 = 1, and ET0 = 1
    TL0     = TIMECOUNT & 0xff;
    TH0     = TIMECOUNT >> 8;
    TL1     = 0x00;
    TH1     = 0x00;
    
    //AUXR = 0x00;  // Clear EXTRAM bit to enable access to on-chip XRAM

    while (1)
    {   
        char num = detect_keypad();

        // TO DISPLAY "RDY" MEANS IT IS IN IDLE/READY MODE
        if (!isRecording && !isPlaybackMode)
        {

            LED_display_READY(LED_graphical_READY);

        }
        // WHEN A BUTTON IS PRESSED
        if (flag_input == 1 && num != 16)
        {
            flag_input  = 0;

            // THE BUTTON JUST PRESSED IS PUT INTO THE VARIABLE 'NOTE'
            note        = num;

            // RECORDING MODE IS ACTIVE
            if (isRecording)
            {
                // PUT THE LATEST PRESSED BUTTON INTO THE PLAYBACK NOTE ARRAY
                recorded_note[playback_note_index] = note;
                playback_note_index++;

                // IF THE RECORDED NOTES HAS BEEN FULL
                if (playback_note_index >= MAXIMUM_RECORDED_NOTES)
                {
                    isRecording                             = FALSE;
                    last_played_note_playback_note_index    = playback_note_index;
                    playback_note_index                     = 0;

                    // CLEAR THE NOTES PLAYED ( FOR DISPLAY PURPOSE )
                    for (unsigned index = 0; index < 4; index++)
                    {
                        digit[index]    =   0xC0;
                    }

                    // DISPLAY "STOP" TO LET USER KNOW THE RECORDING MODE IS TERMINATED
                    LED_display_STOP( LED_graphical_STOP );
                    LED_display_STOP( LED_graphical_STOP );
                }

                // DISPLAY THE CURRENT NOTES PLAYED BY THE USER
                digit[3] = digit[2];
                digit[2] = digit[1];
                digit[1] = digit[0];
                digit[0] = no_code[num];
            }

            // PLAYBACK MODE IS ACTIVE
            if (isPlaybackMode)
            {
                LED_display_PLAY ( LED_graphical_PLAY );

                while (1)
                {
                    // means we have passed 0.625s
                    if ( counter    >=  10 )
                    {
                        counter     =   0;

                        // passed one note
                        flag        +=  1;

                        // END THE PLAYBACK MODE
                        if (flag    >=  last_played_note_playback_note_index)
                        {
                            flag    =   0;
                            break;
                        }
                    }
                }
            }


            // THE BUTTON FOR RECORDING MODE (BUTTON "E") IS PRESSED
            if (num == 14)
            {
                // THE USER WANTS TO TURN OFF THE RECORDING MODE
                if (isRecording)
                {
                    isRecording                             = FALSE;

                    last_played_note_playback_note_index    = playback_note_index;

                    playback_note_index                     = 0;

                    // CLEAR THE NOTES PLAYED ( FOR DISPLAY PURPOSE )
                    for (unsigned index = 0; index < 4; index++)
                    {
                        digit[index] = 0xC0;
                    }

                    // DISPLAY "STOP" TO LET USER KNOW THE RECORDING MODE IS TERMINATED
                    LED_display_STOP(LED_graphical_STOP);

                    LED_display_STOP(LED_graphical_STOP);
                }

                // THE USER WANTS TO TURN ON THE RECORDING MODE
                else
                {
                    isRecording = TRUE;

                    LED_display_REC(LED_graphical_REC);

                    LED_display_REC(LED_graphical_REC);
                }
                
            }

            // THE BUTTON FOR PLAYBACK MODE (BUTTON "F") IS PRESSED
            if (num == 15)
            {
                // THE USER WANTS TO TURN OFF THE PLAYBACK MODE
                if (isPlaybackMode)
                {
                    isPlaybackMode = FALSE;

                    // DISPLAY "STOP" TO LET USER KNOW THE PLAYBACK MODE IS TERMINATED
                    LED_display_STOP(LED_graphical_STOP);

                    LED_display_STOP(LED_graphical_STOP);
                }

                // THE USER WANTS TO TURN ON THE PLAYBACK MODE
                else
                {
                    isPlaybackMode = TRUE;

                    LED_display_PLAY(LED_graphical_PLAY);

                    LED_display_PLAY(LED_graphical_PLAY);
                }

            }
            
            // INDICATE THAT A BUTTON IS BEING PRESSED DOWN.
            key_isReleased      = FALSE;
            last_pressed_key    = num;
        }

        // CURRENTLY THERE IS NO BUTTON BEING PRESSED DOWN.
        if (num == 16) 
        {
            flag_input      = 1;
            key_isReleased  = TRUE; // THE CURRENTLY PRESSED BUTTON HAS BEEN RELEASED BY THE USER
        }

        // Stop playing the note after the specified duration
        if (counter >= 10 && key_isReleased)
        {
            counter = 0;

            note = NOTE_DEFAULT_INITIAL_VALUE;
            TH1 = 0;
        }

        // TO DISPLAY THE CURRENT 4 NOTES PRESSED BY THE USER
        if (isRecording)
        {
            LED_display(digit);
        }
        //LED_display(digit);
    }

}