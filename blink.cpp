#ifndef F_CPU
#define F_CPU 1000000UL			// define it now as 1 MHz unsigned long
#endif

#include <avr/io.h>				// this is always included in AVR programs


template<typename T, typename U>
constexpr bool IS_BIT_CLEAR(T reg, U bit) {
	return (reg & (_BV(bit))) ? true : false;
}

int main(void) {
	

	DDRD  = (DDRD & (~(_BV(PD7)))); // Clear Port D pin PD7 and set it as input 
	DDRB  = _BV(PB0);				// set Port B pin PB0 for output 
	
	while (1) {			
		
		if(IS_BIT_CLEAR(PIND, PD7)) {
			PORTB = PORTB | _BV(PB0);
		} else if (!IS_BIT_CLEAR(PIND, PD7)) {
			PORTB = PORTB & (~(_BV(PB0)));	
		} else {
			//Never here
		}
	}
	
	return 0;		
}

