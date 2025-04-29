#define F_CPU 1000000UL // 1 MHz clock speed


#include <avr/io.h> // Liitetään kirjasto ohjelmaan

#include <util/delay.h> // Liitetään kirjasto ohjelmaan


#define S1 bit_is_set(PIND,2) /* Määritetään ensimmäinen kytkin S1, attiny2313 pinni6=PD02 Ei PullUp tilaan */
#define S3 bit_is_clear(PIND,4)

int main(void) // Aloitetaan pääohjelma

{
    DDRD=0x00; // Alustetaan portin D liitännät tuloksi input
    PORTD |= (1<<PD4); // Otetaan PD4:lle sisäinen ylösvetovastus käyttöön

    DDRB=0xFF; // Alustetaan portin B liitännät lähdöiksi output
    PORTB=0x00; // Alustetaan portin B liitännät alatilaan



    while(1)


    {

        PORTB = 0x00; // kaikki ledit nollatilaan


        if(S1) // jos nappia 1 painetaan
        {
            PORTB = 0x55;//ledit vilkkuvat vuorotellen parilliset ja parittomat
            _delay_ms(200);
            PORTB = 0xAA;
            _delay_ms(200);
        }
        
        if(S3) // jos nappia 3 painetaan (PD4 pullupilla)
        {
            PORTB = 0xFF;
            _delay_ms(200);
            PORTB = 0x00;
            _delay_ms(200);
        }

    }
}