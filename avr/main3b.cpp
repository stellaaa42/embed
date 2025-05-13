#define F_CPU 1000000UL // 1 MHz


#include <avr/io.h> 

#include <util/delay.h> 


#define S1 bit_is_set(PIND,2) 
#define S3 bit_is_clear(PIND,4)

int main(void) 
{
    DDRD=0x00; // input
    PORTD |= (1<<PD4); // pull-up

    DDRB=0xFF; // output
    PORTB=0x00; // low

    while(1)
    {
        PORTB = 0x00; 

        if(S1) 
        {
            PORTB = 0x55;
            _delay_ms(200);
            PORTB = 0xAA;
            _delay_ms(200);
        }
        
        if(S3) 
        {
            PORTB = 0xFF;
            _delay_ms(200);
            PORTB = 0x00;
            _delay_ms(200);
        }
    }
}