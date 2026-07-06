#ifndef UART_H_
#define UART_H_

#include <avr/io.h>

// Haberleşmeyi 9600 hızında başlatır kanka
void uart_basla(void);

// Bilgisayara tek bir harf/karakter fırlatır
void uart_harfW(char harf);

// Bilgisayara upuzun bir yazı (string) gönderir
void uart_yaz(char* yazi);

// Bilgisayardan gelen 5 karakterlik paketi yakalar ve 1023'luk degeri doner kanka (YENİ MOD!)
uint16_t uart_harfR(char hedef_cihaz);

#endif /* UART_H_ */