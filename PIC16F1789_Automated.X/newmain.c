#pragma config WDTE = OFF        // WDT operating mode (WDT enabled regardless of sleep; SWDTEN is ignored)

#include <xc.h>

uint8_t m = 10;

uint8_t add(uint8_t n, uint8_t o, uint8_t p) {
    return (n + o + p);
}

int main() {
    m = 0;
	++m;
	++m;
	--m;
	
    while (1) {
        uint8_t a = 0x05;
        TMR1H = a;
        m = TMR1H;
        uint8_t c = 0x1F;
        TMR1L = c;
        uint8_t b = 0x08;
        T1CON = b;
        uint8_t t = add(a, b, c);
        T2CON = t;
	    ++m;
	    --m;
	    ++m;
	    ++m;
	    --m;
    }

    return 0;
}