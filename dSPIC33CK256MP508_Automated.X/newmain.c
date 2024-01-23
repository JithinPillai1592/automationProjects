#include <xc.h>

#pragma config ICS = PGD3              // ICD Communication Channel Select bits (Communicate on PGC3 and PGD3)

volatile uint8_t m = 10;

uint8_t add(uint8_t n, uint8_t o, uint8_t p) {
    return (n + o + p);
}

int main() {
    while (1) {
        volatile uint8_t a = 0x05;
        TMR1 = a;
        m = TMR1;
        volatile uint8_t c = 0x1F;
        POS1CNTL = c;
        volatile uint8_t b = 0x08;
        PR1 = b;
        volatile uint8_t t = add(a, b, c);
        POS1CNTH = t;
    }

    m = 0;

    return 0;
}