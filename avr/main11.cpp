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