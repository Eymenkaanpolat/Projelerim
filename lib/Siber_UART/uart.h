#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#include <stdint.h>

void uart_basla(void);
void uart_harfW(char harf);
void uart_yaz(char *yazi);
void uart_degerW(uint32_t sayi);

// Gelen cihaz harfini cihaz değişkenine yazar.
// Sayısal değeri geri döndürür.
uint32_t uart_harfR(char *cihaz);

#endif