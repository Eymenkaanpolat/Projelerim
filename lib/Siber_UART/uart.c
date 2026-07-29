#include "uart.h"

void uart_basla(void)
{
    UBRR0H = (uint8_t)(BAUD_ORANI >> 8);
    UBRR0L = (uint8_t)BAUD_ORANI;

    // TX ve RX Aktif
    UCSR0B = (1 << TXEN0) | (1 << RXEN0);
    // 8-bit veri, 1 stop biti, parity yok
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

// Tek bir karakter gönderir
void uart_harfW(char harf)
{
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = harf;
}

// Metin (string) gönderir
void uart_yaz(const char *yazi)
{
    while (*yazi)
    {
        uart_harfW(*yazi++);
    }
}

// 32-bit sayıyı desimal (10'luk taban) olarak ekrana basar
void uart_degerW(uint32_t sayi)
{
    char tampon[11];
    uint8_t i = 0;

    if (sayi == 0)
    {
        uart_harfW('0');
        return;
    }

    while (sayi > 0)
    {
        tampon[i++] = (sayi % 10) + '0';
        sayi /= 10;
    }

    while (i > 0)
    {
        uart_harfW(tampon[--i]);
    }
}

// Seri porttan TEK karakter bekler ve döner (Bloklayan okuma)
char uart_char_oku(void)
{
    while (!(UCSR0A & (1 << RXC0)));
    return UDR0;
}

// Hatalı veya uzun girdi durumunda satır sonuna (\r veya \n) kadar olan tamponu temizler
static void tamponu_temizle(void)
{
    char c;
    do {
        c = uart_char_oku();
    } while (c != '\r' && c != '\n');
}

// Cihaz harfi (A-Z) ve peşinden gelen maks 6 haneli sayıyı okur
uint32_t uart_harfR(char *cihaz)
{
    char c;
    uint32_t sonuc;
    uint8_t rakam_sayisi;

    while (1)
    {
        sonuc = 0;
        rakam_sayisi = 0;

        // --- 1. AŞAMA: Cihaz Harfini Okuma ---
        c = uart_char_oku();

        // Satır başı, satır sonu veya boşluk karakterlerini yut
        if (c == '\r' || c == '\n' || c == ' ')
            continue;

        // Küçük harfi büyük harfe çevir
        if (c >= 'a' && c <= 'z')
            c -= 32;

        // Eğer harf değilse hata ver ve satırı temizle
        if (!(c >= 'A' && c <= 'Z'))
        {
            uart_yaz("\r\nHata: Ilk karakter harf olmali!\r\n");
            tamponu_temizle();
            continue;
        }

        *cihaz = c;
        uart_harfW(c); // Okunan harfi ekrana geri bas (Echo)

        // --- 2. AŞAMA: Rakamları Okuma ---
        while (1)
        {
            c = uart_char_oku();

            // Enter (Satır Sonu) algılandı
            if (c == '\r' || c == '\n')
            {
                if (rakam_sayisi == 0)
                {
                    uart_yaz("\r\nHata: Sayi girilmedi!\r\n");
                    break; // Ana döngüye dön, yeniden harf bekle
                }

                // Temiz bir yeni satıra geç ve değeri tamamla
                uart_yaz("\r\n");
                return sonuc;
            }

            // Sayı kontrolü
            if (c >= '0' && c <= '9')
            {
                if (rakam_sayisi < 6)
                {
                    uart_harfW(c); // Rakamı ekrana geri bas (Echo)
                    sonuc = (sonuc * 10) + (c - '0');
                    rakam_sayisi++;
                }
                else
                {
                    uart_yaz("\r\nHata: En fazla 6 rakam girilebilir!\r\n");
                    tamponu_temizle();
                    break; // Ana döngüye dön
                }
            }
            else
            {
                uart_yaz("\r\nHata: Gecersiz karakter!\r\n");
                tamponu_temizle();
                break; // Ana döngüye dön
            }
        }
    }
}