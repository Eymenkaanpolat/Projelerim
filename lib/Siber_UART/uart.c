#include "uart.h"

#define BAUD_ORANI 103

void uart_basla(void)
{
    UBRR0H = (BAUD_ORANI >> 8);
    UBRR0L = BAUD_ORANI;

    UCSR0B = (1 << TXEN0) | (1 << RXEN0);
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void uart_harfW(char harf)
{
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = harf;
}

void uart_yaz(char *yazi)
{
    while (*yazi)
    {
        uart_harfW(*yazi++);
    }
}

void uart_degerW(uint32_t sayi)
{
    char tampon[10];
    uint8_t i = 0;

    if (sayi == 0)
    {
        uart_harfW('0');
        return;
    }

    while (sayi)
    {
        tampon[i++] = (sayi % 10) + '0';
        sayi /= 10;
    }

    while (i)
    {
        uart_harfW(tampon[--i]);
    }
}

uint32_t uart_harfR(char *cihaz)
{
    char c;
    uint32_t sonuc;
    uint8_t rakam_sayisi;

yeni_paket:

    sonuc = 0;
    rakam_sayisi = 0;

    while (!(UCSR0A & (1 << RXC0)));
    c = UDR0;

    if (c == '\r' || c == '\n' || c == ' ')
        goto yeni_paket;

    if (c >= 'a' && c <= 'z')
        c -= 32;

    if (!(c >= 'A' && c <= 'Z'))
        goto yeni_paket;

    *cihaz = c;

    uart_harfW(c);

    while (1)
    {
        while (!(UCSR0A & (1 << RXC0)));
        c = UDR0;

       if (c == '\r' || c == '\n')
{
    if (rakam_sayisi == 0)
    {
        uart_yaz("\r\nHata: Sayi girilmedi!\r\n");
        goto yeni_paket;
    }

    uart_yaz("\r\n");
    return sonuc;
}

        uart_harfW(c);
                if (c >= '0' && c <= '9')
        {
            if (rakam_sayisi < 6)
            {
                sonuc = (sonuc * 10) + (c - '0');
                rakam_sayisi++;
            }
            else
            {
                uart_yaz("\r\nHata: En fazla 6 rakam!\r\n");

                // Satır sonuna kadar tamponu temizle
                while (1)
                {
                    while (!(UCSR0A & (1 << RXC0)));
                    c = UDR0;

                    if (c == '\r' || c == '\n')
                        break;
                }

                goto yeni_paket;
            }
        }
        else
        {
            uart_yaz("\r\nHata: Gecersiz karakter!\r\n");

            // Satır sonuna kadar tamponu temizle
            while (1)
            {
                while (!(UCSR0A & (1 << RXC0)));
                c = UDR0;

                if (c == '\r' || c == '\n')
                    break;
            }

            goto yeni_paket;
        }
    }
}