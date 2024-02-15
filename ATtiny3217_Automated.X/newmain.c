#include <avr/io.h>
#include <avr/cpufunc.h>

volatile uint8_t m = 10;

volatile uint8_t add(volatile uint8_t n, volatile uint8_t o, volatile uint8_t p) {
    //_NOP();
    return (n + o + p);
}

int main() {
    m = 0;
	++m;
	++m;
	--m;
	
    while (1) {
        volatile uint8_t a = 0x05;
        PORTA.DIR = a;
        m = PORTA.DIR;
        volatile uint8_t c = 0x1F;
        PORTB.DIR = c;
        volatile uint8_t b = 0x08;
        PORTC.DIR = b;
        volatile uint8_t t = add(a, b, c);
        PORTA.DIR = t;
	    ++m;
	    --m;
	    ++m;
	    ++m;
	    --m;
    }

    return 0;
}