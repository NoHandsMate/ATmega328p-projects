
#include <avr/io.h>				


template<typename T, typename U>
constexpr bool IS_BIT_CLEAR(T reg, U bit) {
	return (reg & (_BV(bit))) ? true : false;
}


