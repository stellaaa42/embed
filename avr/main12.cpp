#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#define S1 bit_is_clear(PIND, 2) // pull-up
#define MIN 8


int main(void)
{
	unsigned char noppa;
	unsigned char run;
	unsigned char rnd;
	unsigned char i;
	unsigned char num;
	unsigned char taulukko[] = {
		0x06, // 1
		0x5B, // 2
		0x4F, // 3
		0x66, // 4
		0x6D, // 5
		0x7D  // 6
	};
	unsigned int  dly []  = {680, 550, 450, 350, 280, 175, 100, 90, 86, 70, 40, 20};


	DDRD = 0x00; // input
	PORTD |= (1<<PD2); // pull-up
	
	DDRB  = 0xFF; // output
	PORTB = 0x00; // 0
	_delay_ms(500);
	
	noppa = 0;
	run   = 0;
	i     = sizeof(dly)/2;
	
	rnd = 0;
	num = rand() % 6;


	while (1)
	{
		// if (!S1)
		if (PIND & (1<<PD2))
		{
			run = MIN + rnd % 32;
			_delay_ms(200);
		}

		if (run)
		{
			run--;
			noppa++;
			if (noppa == 6)
			{
				noppa = 0;
			}
		}

		_delay_ms(200);
		PORTB = taulukko[noppa];
		_delay_loop_1(200);
		rnd++;
		
		if (run > 0 && run < i + 1)
		{
			_delay_loop_1(dly[run - 1]);
		}

	}

	return 0;
}

/*
      attiny23
s1-> pd2 -> pin6
a -> 7 → PB0 -> pin12
b → 6 -> PB1 -> pin13
c → 4 -> PB2 -> pin14
d → 2 -> PB3 -> pin15
e → 1 -> PB4 -> pin16
f → 9 -> PB5 -> pin17
g → 10 -> PB6 -> pin18
*/
