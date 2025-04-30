#define F_CPU 1000000UL //1 MHz kellotaajuus
#include <avr/io.h> 
#include <util/delay.h>

int main(void)
{
	DDRB =0xFF; //output
	_delay_ms(200); //200ms

	while(1)
	{

		PORTB = 0x55; // 0b01010101
		_delay_ms(2000);

		PORTB = 0xAA; // 0b10101010
		_delay_ms(2000);
	}
}