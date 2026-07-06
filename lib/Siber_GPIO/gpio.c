#include "gpio.h"

void pin_mod(char port, uint8_t pin, uint8_t mod) {
    // Arduino D8 - D13 pinleri PORTB'nin 0-5 pinlerine denk gelir kanka
    if (port == 'B' || port == 'b') {
        if (pin <= 7) { // 0-7 arası tüm pin emniyeti
            if (mod == 1) { DDRB |= (1 << pin); } 
            else { DDRB &= ~(1 << pin); }
        }
    } 
    // Arduino D0 - D7 pinleri direkt PORTD'nin 0-7 pinlerine denk gelir kanka
    else if (port == 'D' || port == 'd') {
        if (pin <= 7) {
            if (mod == 1) { DDRD |= (1 << pin); } 
            else { DDRD &= ~(1 << pin); }
        }
    }
}

void pinW(char port, uint8_t pin, uint8_t deger) {
    if (port == 'B' || port == 'b') {
        if (pin <= 7) {
            if (deger == 1) { PORTB |= (1 << pin); } 
            else { PORTB &= ~(1 << pin); }
        }
    } 
    else if (port == 'D' || port == 'd') {
        if (pin <= 7) {
            if (deger == 1) { PORTD |= (1 << pin); } 
            else { PORTD &= ~(1 << pin); }
        }
    }
}

uint8_t pinR(char port, uint8_t pin) {
    if (port == 'B' || port == 'b') {
        if (pin <= 7) {
            if (PINB & (1 << pin)) return 1;
        }
    } 
    else if (port == 'D' || port == 'd') {
        if (pin <= 7) {
            if (PIND & (1 << pin)) return 1;
        }
    }
    return 0;
}