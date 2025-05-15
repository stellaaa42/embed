#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#define S1 bit_is_clear(PIND, 2) // pull-up
#define MIN 100


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
	
	DDRB  = 0x7F; // output 
	PORTB = 0x7F; // high
	// _delay_ms(500);
	
	noppa = 0;
	run   = 0;
	i     = sizeof(dly)/sizeof(dly[0]); // 12*2/2 2/4 bytes per int
	
	rnd = 0;


	while (1)
	{
		// if (!S1)
		// if (PIND & (1<<PD2))
		if (!PIND.2) // high -> low btn
		{
			run = MIN + rnd % 7; // 0-6 run 100-106
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

		// _delay_ms(200);
		PORTB = taulukko[noppa]; // when run == 0
		_delay_loop_1(200); // 3x ck cycle x200
		rnd++;
		
		if (run > 0 && run < i + 1) // 1-12
		{
			_delay_loop_1(dly[run - 1]); // run-- longer delay
		}

	}

	return 0;
}