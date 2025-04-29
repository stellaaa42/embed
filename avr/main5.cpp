#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    unsigned char napit;

    DDRB = 0xFF;
    PORTB = 0x00;
    DDRD = 0x00;
    PORTD = 0x00;

    while(1)
    {
        napit = PIND;
        napit &= 0x0C;
        napit >>=2; //00001100 -> 00000011
        PORTB = napit;
    }
}

// Ennen ledit syttyivät samoissa bittikohdissa kuin napit olivat PIND:ssä.
// Nyt kun painat PD2, syttyy LED PORTB bit0:ssa, kun painat PD3, sytty LED PORTB bit1:ssä.
// Jos painat molempia, molemmat ledit syttyvät bitti 0 ja 1.
// <<=1 siirtää bittien arvot vasemmalle yhdella bitillä.
// napit <<= 4 00001100 -> 11000000