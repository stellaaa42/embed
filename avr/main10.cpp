#define F_CPU 1000000UL    // CPU-kellotaajuus 1 MHz
#include <avr/io.h>       // AVR I/O -määrittelyt
#include <util/delay.h>   // Viivefunktiot (_delay_ms)

#define S1 bit_is_set(PIND,2)  // S1 on painettuna, kun PD2 on korkealla
#define S2 bit_is_set(PIND,3)  // S2 on painettuna, kun PD3 on korkealla

int main(void)
{
    unsigned char luku;      // 8-bittinen muutuja LED-kuviolle

    DDRB  = 0xFF;            // Asetetaan kaikki PORTB:n pinnit ulostuloksi
    PORTB = 0x00;            // Sammutetaan kaikki ledit aluksi
    DDRD &= ~((1<<2)|(1<<3)); // Asetetaan PD2 ja PD3 tuloiksi ~ invert 1 -> 0
    PORTD |= (1<<2)|(1<<3);   // Otetaan pull-up-vastukset käyttöön PD2 ja PD3

    luku = 0x80;             // Aloitus: vasemmanpuoleinen LED päällä

    while (1)
    {
        PORTB = luku;        // Näytetään LED-kuvio PORTB:ssä

        if (S1)              // Jos S1 (PD2) painettuna
        {
            luku <<= 1;      // Siirretään LED-kuviota vasemmalle
            if (luku == 0)   // Kun siirto ylittää vasemman reunan
            {
                // Hypätään oikeaan reunaan
                luku = 0x01;
            }
        }

        if (S2)              // Jos S2 (PD3) painettuna
        {
            luku >>= 1;      // Siirretään LED-kuviota oikealle
            if (luku == 0)   // Kun siirto ylittää oikean reunan
            {
                // Hypätään vasempaan reunaan
                luku = 0x80;
            }
        }

        _delay_ms(500);      // Odotetaan 500 ms ennen seuraavaa askelta
    }

    return 0;               // Ohjelma ei tänne koskaan päädy
}
