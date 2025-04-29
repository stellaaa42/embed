#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

int main(void)
{
    unsigned char luku;
    
    DDRB  = 0xFF;  // PORTB ulos
    PORTB = 0x00;  // kaikki LEDit pois päältä
    
    srand(1234);   // siemen, voi käyttää esim. kellotaulua tai ADC-lukemaa

    while (1)
    {
        // Satunnainen 8-bittinen malli LEDeille (0..255)
        luku   = rand() & 0xFF;  // rand() voi olla 0..RAND_MAX, &0xFF pakkaa 0..255
        PORTB  = luku;
        _delay_ms(500);

        // Satunnaisluku väliltä 1..6
        luku   = (rand() % 6) + 1;  // modulo 6 → 0..5, +1 → 1..6
        PORTB  = luku;
        _delay_ms(500);
    }
}
