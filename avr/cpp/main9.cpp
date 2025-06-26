#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

int main(void)
{
    unsigned char luku;
    
    DDRB  = 0xFF;
    PORTB = 0x00;
    
    srand(1234);   

    while (1)
    {
        // 1..6
        luku   = (rand() % 6) + 1;  //  0..5 +1 → 1..6
        PORTB  = luku;
        _delay_ms(500);
    }
}

// 1...6 0000 0001 0010 0011 0100 0101 0110
