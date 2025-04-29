#define F_CPU 1000000UL // 1 MHz clock speed

#include <avr/io.h> // Liitetään kirjasto ohjelmaan

#include <util/delay.h> // Liitetään kirjasto ohjelmaan

#define S1 bit_is_set(PIND,2) /* Määritetään ensimmäinn kytkein S1, attiny2313 pinni6=PD02 Ei PullUp tilaan */
#define S2 bit_is_set(PIND,3) // kytkin S2 = PD3


int main(void) // Aloitetaan pääohjelma

{
    DDRD=0x00; // Alustetaan portin D liitännät tuloksi input
    PORTD=0x00; // Alustetaan portin D liitännät suurimpedenssitilaan

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

        if(S2) // jos nappia 2 painetaan
        {
            PORTB = 0xFF; // kaikki ledit päälle
            _delay_ms(200);

            PORTB = 0x00; // kaikki ledit pois
            _delay_ms(200);
        }

    }
}