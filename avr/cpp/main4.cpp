#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    unsigned char napit;

    DDRD = 0x00;
    PORTD = 0x00;
    
    DDRB = 0xFF;
    PORTB = 0x00;

    while(1)
    {
        napit = PIND; /*S1 (PD02) 0000 0100
                        S2 (PD03) 0000 1000                       
                        S1 & S2 0000 1100*/
        napit &= 0x0C; //0x0C 00001100 -> 0x04 00000100
        // napit &= 0x04; //0x0C 00001100 -> 0x04 00000100
        PORTB = napit;
    }
}

// LSB(Least significant bit)
// Bit positions: 7 6 5 4 3 2 1 0
// Bit values:128 64 32 16 8 4 2 1
// 0x0C -> 00001100 & 00001100 = 00001100
// S1 (PD02) 0000 0100 & 0000 1100 = 0000 0100 
// S2 (PD03) 0000 1000 & 0000 1100 = 0000 1000  
// 0x04 --> 00001100 & 00000100 = 00000100
// S1 (PD02) 0000 0100 & 0000 0100 = 0000 0100 
// S2 (PD03) 0000 1000 & 0000 0100 = 0000 0000 
