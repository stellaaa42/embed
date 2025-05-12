#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    unsigned char i;

    unsigned char numerot[] = {
        0x06, // 1
        0x5B, // 2
        0x4F, // 3
        0x66, // 4
        0x6D, // 5
        0x7D  // 6
    };

    DDRB = 0xFF;  // output
    PORTB = 0x00;

    _delay_ms(1000);

    while (1)
    {
        for (i = 0; i < 6; i++)
        {
            PORTB = numerot[i];
            _delay_ms(500);
        }
    }
}

/*
a → PB0
b → PB1
c → PB2
d → PB3
e → PB4
f → PB5
g → PB6

     binary     hex
1	00000110	0x06
2	01011011	0x5B
3	01001111	0x4F
4	01100110	0x66
5	01101101	0x6D
6	01111101	0x7D
*/