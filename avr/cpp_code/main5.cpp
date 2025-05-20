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
        napit = PIND;
        napit &= 0x0C; //0b1100
        napit <<= 4; //00001100 -> 00000011
        PORTB = napit;
    }
}

// >>=2 00001100 -> 00000011
// <<=1 00001100 -> 00011000
//  <<= 4 00001100 -> 11000000 to the leftmost