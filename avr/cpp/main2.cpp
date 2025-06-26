#define F_CPU 1000000UL //1 MHz kellotaajuus
#include <avr/io.h> 
#include <util/delay.h>

int main(void)

{

	DDRB =0xFF; // output
    PORTB = 0X00;
    unsigned char luku;
    luku = 0; 

	_delay_ms(500);


	while(1)

	{
		PORTB = luku%8;
		luku++;
		_delay_ms(1000);
	}

    return 0;

}

// 0-7 in binary --> lower 3 bit 
// three rightmost bits/led 1, others 0