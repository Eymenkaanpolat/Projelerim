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

// Birleştirilmiş Siber Fonksiyon: Canlı olarak 1023'luk paketi yakalar
uint16_t uart_harfR(char hedef_cihaz) {
    char tampon[5];
    uint8_t indeks = 0;

    while (1) {
        // Donanımsal buffer'a veri düşene kadar bekle kanka
        while (!(UCSR0A & (1 << RXC0)));
        char c = UDR0; // Karakteri donanımdan çek

        // Satır sonu karakterlerini filtrele
        if (c != '\n' && c != '\r') {
            tampon[indeks] = c;
            indeks++;
            uart_harfW(c); // Ekrana yansıt (Echo)

            // 5 karakter ulaştıysa (Örn: S1023) çözmeye başla
            if (indeks == 5) {
                indeks = 0; // Yeni paket için indeks sıfırla

                // Harf kontrolü (Büyük-küçük harf duyarsız kanka)
                if (tampon[0] == hedef_cihaz || tampon[0] == (hedef_cihaz + 32) || tampon[0] == (hedef_cihaz - 32)) {
                    
                    // Basamakları doğrudan tam sayı değerlerine döküyoruz
                    uint16_t binler  = tampon[1] - '0';
                    uint16_t yuzler  = tampon[2] - '0';
                    uint16_t onlar   = tampon[3] - '0';
                    uint16_t birler  = tampon[4] - '0';

                    uint16_t sonuc = (binler * 1000) + (yuzler * 100) + (onlar * 10) + birler;

                    if (sonuc <= 1023) {
                        return sonuc; // 0-1023 arası tertemiz veri döndü!
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