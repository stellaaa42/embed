#define F_CPU 8000000UL //8Mhz each cycle is 125 nanosec each delay_loop iteration 3xck 3x125xdelay

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#define S1 bit_is_clear(PIND, 2) // pull-up
#define MIN 100


int main(void)
{
	unsigned char nop;
	unsigned char run;
	unsigned char rnd;
	unsigned char i;
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
	
	nop = 0;
	run   = 0;
	i     = sizeof(dly)/2; // 12*2/2 int 2/4 bytes
	
	rnd = 0; // pseudorandom 8-bit linear feedback shift register/XOR change bits
	// 2^8	at most 255 non-zero
	// increment every 75ms


	while (1)
	{
		for (i = 0; i < 6; i++)
		{
			PORTB = taulukko[i];
			_delay_ms(100);
		}
		if (PIND & (1<<PD2))
		// once btn high -> low, asynchronous with the loop, appears random
		{
			run = MIN + rnd % 32; // 'roll' 100+0 100+1..131 7.5ms-8.9ms
			PORTB = taulukko[nop]; // display current, when run-- -> 0 stop at that num
			_delay_ms(500);
		}

		if (run)
		{
			run--; // 100,99,...0 hit 0 before 255, then MCU sleeps until next btn
			nop++; // 1 2...7
			if (nop == 7)
			{
				nop = 0;
			}
		}

		_delay_loop_1(200); // counter++, cpu sits in the loop++, delay++
		// busy_wait for a bit, run>12 200 iterations 125x3x200 -> 75 microsec/us 8-bit counter up to 256
		rnd++; // 1 cycle 0-255 256->0 every 256x75=19.2milliseconds/ms
		
		if (run > 0 && run < i + 1) // 1-12 <=12
		{
			_delay_loop_1(dly[run - 1]); // run-- longer delay
		}

	}

	return 0;
}