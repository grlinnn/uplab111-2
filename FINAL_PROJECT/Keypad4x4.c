#include <8051.h>
#include "Keypad4x4.h"

unsigned char detect_keypad()
{
    for (unsigned char row = 0; row < 4; row++)
    {
        P2 = ~(1 << row);   // Set the corresponding row to logic low by shifting '1' to the left and complementing the value.

        if ((P2 & 0xF0) != 0xF0) // If the upper 4 bits of P2 are not all high (0xFF), it means a button in this row is pressed.
        {
            for (unsigned char col = 0; col < 4; col++)
            {
                if (!(P2 & (0x10 << col)))   // If a button in this column is pressed, the corresponding bit in P2 will be logic low.
                {
                    // Map the row and column to the appropriate button value
                    unsigned char buttonValue = (3 - row) * 4 + (3 - col);
                    return buttonValue;  // Return the calculated button value.
                }
            }
        }
    }

    return 16;  // Return 16 if no button is pressed.
}