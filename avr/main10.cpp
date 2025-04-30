#define F_CPU 1000000UL //  1 MHz
#include <avr/io.h> // AVR I/O 
#include <util/delay.h> //(_delay_ms)

#define S1 bit_is_set(PIND,2) 
#define S2 bit_is_set(PIND,3) 

int main(void)
{
    unsigned char luku; 

    DDRD = 0x00; // input
	PORTD |= (1<<PD2)|(1<<PD3); // pullup

    DDRB = 0xFF; // output
    PORTB = 0x00;

    luku = 0x80;

    while (1)
    {
        PORTB = luku;
        if (S1) 
        {
            luku <<= 1;
            _delay_ms(500); //wait out the bounces
            if(luku==0) 
                luku = 0x01;
        }
        if (S2) 
        {
            luku >>= 1;
            _delay_ms(500);
            if(luku==0)
                luku = 0x80;
        }
    }
}