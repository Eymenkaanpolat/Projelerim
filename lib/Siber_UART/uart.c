#include "uart.h"

#define BAUD_ORANI 103

void uart_basla(void) {
    UBRR0H = (BAUD_ORANI >> 8);
    UBRR0L = BAUD_ORANI;
    UCSR0B = (1 << TXEN0) | (1 << RXEN0);
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void uart_harfW(char harf) {
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = harf;
}

void uart_yaz(char* yazi) {
    while (*yazi) {
        uart_harfW(*yazi);
        yazi++;
    }
}

// Sayısal değeri UART üzerinden gönderir (0 - 65535)
void uart_degerW(uint16_t deger) {
    char tampon[6];
    uint8_t i = 0;

    // Eğer değer 0 ise direkt gönder
    if (deger == 0) {
        uart_harfW('0');
        return;
    }

    // Basamakları ters sırayla tampona yaz
    while (deger > 0) {
        tampon[i++] = (deger % 10) + '0';
        deger /= 10;
    }

    // Tampondaki karakterleri doğru sırayla gönder
    while (i > 0) {
        uart_harfW(tampon[--i]);
    }
}

// Birleştirilmiş Siber Fonksiyon: Canlı olarak 1023'lük paketi yakalar
uint16_t uart_harfR(char hedef_cihaz) {
    char tampon[5];
    uint8_t indeks = 0;

    while (1) {
        // Donanımsal buffer'a veri düşene kadar bekle kanka
        while (!(UCSR0A & (1 << RXC0)));
        char c = UDR0;

        // Satır sonu karakterlerini filtrele
        if (c != '\n' && c != '\r') {
            tampon[indeks] = c;
            indeks++;
            uart_harfW(c); // Echo

            // 5 karakter ulaştıysa (Örn: S1023)
            if (indeks == 5) {
                indeks = 0;

                // Harf kontrolü (Büyük-küçük harf duyarsız)
                if (tampon[0] == hedef_cihaz ||
                    tampon[0] == (hedef_cihaz + 32) ||
                    tampon[0] == (hedef_cihaz - 32)) {

                    uint16_t binler = tampon[1] - '0';
                    uint16_t yuzler = tampon[2] - '0';
                    uint16_t onlar  = tampon[3] - '0';
                    uint16_t birler = tampon[4] - '0';

                    uint16_t sonuc = (binler * 1000) +
                                     (yuzler * 100) +
                                     (onlar * 10) +
                                     birler;

                    if (sonuc <= 1023) {
                        return sonuc;
                    } else {
                        uart_yaz(" -> Hata: Deger > 1023!\r\n");
                    }
                } else {
                    uart_yaz(" -> Hata: Gecersiz cihaz kodu!\r\n");
                }

                uart_yaz("\r\nYeni veri gir kanka: ");
            }
        }
    }
}