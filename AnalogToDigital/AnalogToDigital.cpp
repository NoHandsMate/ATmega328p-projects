
#include "../Utils/Utils.hpp"


int main() {
	
	DDRD = 0xFF; // Set all PORTD pins as output

	ADMUX  = 0b01100101; // The last 4 bits define what port are we using. In this case, the ADC5, or PC5
	ADCSRA = 0b10000011; // Check the datasheet to understand what is going on here. We're just enabling the ADC 
	ADCSRB = 0b00000000;


	while(true) {
		ADCSRA = ADCSRA | _BV(ADSC);
		 while(IS_BIT_CLEAR(ADCSRA, ADSC)); // Wait for the conversion to end, and then set all the PORTD bits with the result 
			PORTD = ADCH;
		
	}

	return 0;
}
