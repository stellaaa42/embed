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
        napit = PIND; /*luetaan portista D 8-bittinen luku
                        S1 (PD02) painettuna 0000 0100
                        S2 (PD03) painettuna 0000 1000                       
                        Molemmat painettuna 0000 1100*/
        napit &= 0x0C; //00001100 -> 0x04 00000100
        PORTB = napit;
    }
}

// LSB(Least significant bit)
// Bit pos: 7 6 5 4 3 2 1 0
// Bit values:128 64 32 16 8 4 2 1
// Molemmat painettuna 00001100 & 00001100 = 00001100 bitit 2 ja 3 --> 00001100 & 00000100 = 00000100 vain bitin 2
// S1 (PD02) painettuna 0000 0100 & 0000 0100 = 0000 0100 vain bitin 3
// S2 (PD03) painettuna 0000 1000 & 0000 0100 = 0000 0000 nolla
// Koska JA-operaatio sälyttää vain ne, jotka ovat samat.
