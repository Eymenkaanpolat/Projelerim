#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#include <stdint.h>

// F_CPU 16MHz ve 9600 Baud için UBRR değeri (16000000 / (16 * 9600)) - 1 = 103
#define BAUD_ORANI 103

void uart_basla(void);
void uart_harfW(char harf);
void uart_yaz(const char *yazi);
void uart_degerW(uint32_t sayi);
char uart_char_oku(void);
uint32_t uart_harfR(char *cihaz);

#endif /* UART_H_ */