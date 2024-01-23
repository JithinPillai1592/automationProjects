#include <avr/io.h>

#pragma config OCDEN = SET

volatile uint8_t m = 10;

volatile uint8_t add(volatile uint8_t n, volatile uint8_t o, volatile uint8_t p) {
    return (n + o + p);
}

int main() {
    while (1) {
        volatile uint8_t a = 0x05;
        SPCR1 = a;
        m = SPCR1;
        volatile uint8_t c = 0x1F;
        DDRD = c;
        volatile uint8_t b = 0x08;
        DDRC = b;
        volatile uint8_t t = add(a, b, c);
        DDRB = t;
        t = (a + b + c);
    }

    m = 0;

    return 0;
}