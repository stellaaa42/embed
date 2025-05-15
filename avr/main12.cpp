#define F_CPU 8000000UL //8Mhz each cycle is 125 nanosec each delay_loop iteration 3xck 3x125xdelay

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
	i     = sizeof(dly)/sizeof(dly[0]); // 12*2/2 int 2/4 bytes 
	
	rnd = 0; // increment every 75ms


	while (1)
	{
		// if (!S1)
		// if (PIND & (1<<PD2))
		if (!PIND.2) // btn high -> low asynchronous with the loop, appears random
		{
			run = MIN + rnd % 32; // 'roll' 100+0 100+1..131 7.5ms-8.9ms
			PORTB = taulukko[noppa]; // if btn each cycle run-- -> 0 stop at current
			// _delay_ms(200);
		}

		if (run)
		{
			run--; // hit 0 before 255
			noppa++; // 1 2...7
			if (noppa == 7)
			{
				noppa = 0;
			}
		}

		// _delay_ms(200);
		_delay_loop_1(200); // run>12 200 iterations 125x3x200 -> 75 microsec/us 8-bit counter up to 256
		rnd++; // 1 cycle 0-255 256->0 every 256x75=19.2milliseconds/ms 
		
		if (run > 0 && run < i + 1) // 1-12 <=12
		{
			_delay_loop_1(dly[run - 1]); // run-- longer delay
		}

	}

	return 0;
}