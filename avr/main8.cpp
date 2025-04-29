
#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    unsigned char luku, suunta; //alustetaan muuttujat luku ja suunta

    DDRB=0xff; //portin B suunta ulos
    PORTB=0xff; //portin kaikki bitit ykkösiä
    _delay_ms(1000); //tässä viive ennen ohjelman aloittamista

    luku=0x01; //annetaan muuttujalle luku alkuarvo 0x01
    suunta=0; //annetaan muuttujalle suunta arvo 0, oikealta vasemmalle

    while(1)
    {
        PORTB = luku;//portille B annetaan arvoksi muuttuja luku
        if(suunta==1)

            luku<<=1; /*jos muuttujan suunta arvo on 1, liikutetaan bittiä vasemmalle yhden bitin verran*/
        else
            luku>>=1; /*jos muuttujan suunta arvo on 0, liikutetaan bittiä oikealle yhden bitin verran*/

        if(luku==0) //suoritetaan if-lause, kun muuttuja luku saa arvon 0
        {
            if(suunta==1)/*kun muuttujan suunta arvo on 1 (silloin kun
            muuttujan luku arvo on 0)*/
            {
                suunta=0;//muuttujalle suunta annetaan arvo 0
                luku=0x80;//muuttujalle luku annetaan arvo 0x80
            }

            else /*kun muuttujan suunta arvo on 1 (silloin kun muuttujan luku arvo on 0)*/
            {
                suunta=1; //muuttujalle suunta annetaan arvo 1
                luku=0x01;//muuttujalle luku annetaan arvo 0x01
            }

        }
        _delay_ms(200);
    }

}

// luku=0x80 -> luku=0x40 liike rajoittuu sisempiin ledeihin
// luku=0x01 -> luku=0x02 välttää reunat
