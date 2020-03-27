#include <avr/io.h>
#include <util/delay.h>
#include "avr/sfr_defs.h"


void Ports_init();

int main(void) {
	Ports_init();
	
	unsigned char input;
	
    while (1) {
		input = PIND & 0x01;
		
		if (!input) {
			PORTC = 0x02;
			_delay_ms(15000);
			PORTA = 0x40; // Gelb Autos
			_delay_ms(1000);
			PORTA = 0x80; // Rot Autos
			_delay_ms(500);
			PORTC = 0;
			PORTB = 0x40; // Grün Fußgänger
			_delay_ms(5000);
			
			// Blinken
			PORTB = 0;
			_delay_ms(2000);
			PORTB = 0x40;
			_delay_ms(2000);
			PORTB = 0;
			_delay_ms(1000);
			
			PORTB = 0x80; // Rot Fußgänger
			_delay_ms(5000);
			PORTA = 0x40; // Gelb Autos
			_delay_ms(1000);
			PORTA = 0x20; // Grün Autos
			
			// Nächste anforderung erst nach 30 sek
			_delay_ms(30000);
		}
    }
}

void Ports_init() {
	DDRA = 0xFF;
	DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = 0;
	PORTD = 0xFF;
	
	PORTA = 0x20; // Grün Autos
	PORTB = 0x80; // Rot Fußgänger
	PORTC = 0;
}

