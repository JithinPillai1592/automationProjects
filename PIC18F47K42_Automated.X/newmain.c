#include <xc.h>

#pragma config WDTE = OFF        // WDT operating mode (WDT enabled regardless of sleep; SWDTEN is ignored)

volatile uint8_t m = 10;

volatile uint8_t add(volatile uint8_t n, volatile uint8_t o, volatile uint8_t p) {
    return (n + o + p);
}

int main() {
    while (1) {
        volatile uint8_t a = 0x05;
        LATA = a;
        m = LATA;
        volatile uint8_t c = 0x1F;
        TRISA = c;
        volatile uint8_t b = 0x08;
        LATB = b;
        volatile uint8_t t = add(a, b, c);
    }

    m = 0;

    return 0;
}