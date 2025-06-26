
#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    unsigned char luku, suunta;

    DDRB = 0xff;
    PORTB = 0xff;
    _delay_ms(1000);

    luku = 0x01;
    suunta = 0;

    while(1)
    {
        PORTB = luku;
        if(suunta == 1)
            luku <<= 1;
        else
            luku >>= 1;

        if(luku == 0)
        {
            if(suunta == 1)
            {
                suunta = 0;
                luku = 0x40;
            }
            else
            {
                suunta = 1;
                luku = 0x02;
            }
        }
        _delay_ms(200);
    }
}

// 0x80 -> 0x40 still shifting, no stop
// 0x01 -> 0x02 
