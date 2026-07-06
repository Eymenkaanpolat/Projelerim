#include "analogR.h"

uint16_t analogR(uint8_t kanal) {
    // 1. Kanalı sınırla kanka (Sadece A0-A5 arası pini seçebilelim diye maskeleme)
    kanal &= 0x07; 
    
    // 2. Voltaj referansını AVCC (5V) yap ve kanalı ADMUX'a yaz
    ADMUX = (1 << REFS0) | kanal;
    
    // 3. ADC donanımını aktif et ve frekans bölücüyü 128 yap (Hassas okuma için)
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
    
    // 4. Okumayı başlat kanka! (Start Conversion)
    ADCSRA |= (1 << ADSC);
    
    // 5. Okuma bitene kadar (ADSC biti tekrar 0 olana kadar) işlemciyi burada beklet
    while (ADCSRA & (1 << ADSC));
    
    // 6. İçerideki 10-bitlik dijital sonucu (0-1023 arası) geri döndür
    return ADC;
}