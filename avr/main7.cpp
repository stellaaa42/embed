#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    unsigned char luku;

    DDRB = 0xFF;
    PORTB = 0x00;
    _delay_ms(2000);
    luku = 0x01;
    uint8_t suunta = 1; 

    while(1)
    {
        PORTB = luku; // Asetetaan portin B liittimien arvoiksi bittijono luku, LED syttyy sen mukaisesti
        luku >>=1
        
        if (luku == 0x00)
        luku = 0x08;
        
        _delay_ms(500);
        
    }
}

// 0x01-> 0x00 -> 0x08 0000 1000 -> 4 2 1... 
