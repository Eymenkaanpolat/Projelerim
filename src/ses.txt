#include <util/delay.h>
#include <stdlib.h>
#include "uart.h"
#include "sonar.h" // Güncellediğimiz sonar kütüphanesi

int main(void)
{
    // Donanım kütüphanelerini ayağa kaldırıyoruz kanka
    uart_basla();         
    sonar_basla(); // 64 prescaler ile 4 metre menzilli yeni siber başlangıç       

    while (1)
    {
        // 1. Sonar sensörüne 10us'lik siber tetiği gönder
        sonar_tetikle();
        
        // 2. Ses dalgasının 4 metreye gidip, yankının geri dönmesi için 
        // işlemciye yeterli zamanı tanıyan siber emniyet beklemesi (100ms)
        _delay_ms(100); 
        
        // 3. Arka planda taşma olmadan hesaplanan net mesafeyi çek kanka
        uint16_t mesafe = sonar_mesafe_oku();

        // 4. SADECE SAF VERİ: Yazı kalabalığı yok, sadece mesafe ve alt satır
        char mesafe_str[6];
        itoa(mesafe, mesafe_str, 10); // Sayıyı ekranda okunacak karakterlere çevir
        
        uart_yaz(mesafe_str);
        uart_yaz("\r\n"); 
    }
    return 0;
}