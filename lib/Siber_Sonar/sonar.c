#include "sonar.h"
#include <avr/interrupt.h>
#include <util/delay.h>

volatile uint16_t yukselme_zamani = 0;
volatile uint16_t dusme_zamani = 0;
volatile uint16_t havada_gecen_sure = 0;
volatile uint8_t olcum_bitti_mi = 0;

void sonar_basla(void) {
    // PD4 pinini (Trig) ÇIKIŞ yapıyoruz kanka
    DDRD |= (1 << PD4);
    // PD2 pinini (Echo / INT0) GİRİŞ yapıyoruz
    DDRD &= ~(1 << PD2);
    
    // Timer1 Ayarı: Normal mod, saat hızını 8'e bölüyoruz (Prescaler = 8)
    // 16MHz / 8 = 2MHz -> Yani Timer1 her 0.5 mikrosaniyede bir 1 artacak kanka.
    TCCR1B |= (1 << CS11);
    
    // Dış Kesme Ayarı (INT0): Herhangi bir mantıksal değişimde tetiklensin (Any logic change)
    // Yani Echo pini 1 olunca da kesmeye girecek, 0 olunca da!
    EICRA |= (1 << ISC00);
    EICRA &= ~(1 << ISC01);
    
    // INT0 kesme şalterini aktif et kanka
    EIMSK |= (1 << INT0);
    
    // Global kesmeleri aç (Siber kapıları açtık)
    sei();
}

void sonar_tetikle(void) {
    olcum_bitti_mi = 0;
    
    // Trig pinine 10 mikrosaniyelik tetikleme darbesi gönderiyoruz kanka
    PORTD |= (1 << PD4);
    _delay_us(10);
    PORTD &= ~(1 << PD4);
}

// Donanımsal Kesme Alt Programı (Echo pini değiştiği an buraya fırlar)
ISR(INT0_vect) {
    if (PIND & (1 << PD2)) {
        // Echo pini HIGH (1) oldu kanka -> Ses dalgası havaya fırladı, süreyi başlat!
        yukselme_zamani = TCNT1;
    } else {
        // Echo pini LOW (0) oldu kanka -> Ses dalgası çarptı geri geldi, süreyi durdur!
        dusme_zamani = TCNT1;
        havada_gecen_sure = dusme_zamani - yukselme_zamani;
        olcum_bitti_mi = 1;
    }
}

uint16_t sonar_mesafe_oku(void) {
    // Timer 2MHz'de çalıştığı için geçen süreyi 2'ye bölerek mikrosaniyeye çeviriyoruz
    uint32_t mikrosaniye = havada_gecen_sure / 2;
    
    // Bizim o virgülsüz siber doğru orantı formülü kanka: (Süre * 0.0343) / 2
    // İşlemciyi yormamak için: (Süre / 58) bize doğrudan CM verir kanka!
    uint16_t cm = mikrosaniye / 58;
    
    return cm;
}