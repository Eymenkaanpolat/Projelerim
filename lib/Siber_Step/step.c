#include "step.h"

// Varsayılan siber hız ayarımız
uint16_t step_hiz = 2000;

// Asla diş attırmayan o meşhur çift fazlı (Full-Step) tablomuz
static const uint8_t full_step_tablo[4][4] = {
    {1, 1, 0, 0}, // Adım 0
    {0, 1, 1, 0}, // Adım 1
    {0, 0, 1, 1}, // Adım 2
    {1, 0, 0, 1}  // Adım 3
};

void motor_basla(char port, uint8_t p1, uint8_t p2, uint8_t p3, uint8_t p4, uint16_t adim_sayisi, uint8_t yon) {
    uint8_t pinler[4] = {p1, p2, p3, p4};
    static int8_t mevcut_adim = 0;

    for (uint16_t i = 0; i < adim_sayisi; i++) {
        // Yön kontrolü
        if (yon == 1) {
            mevcut_adim++;
            if (mevcut_adim > 3) mevcut_adim = 0;
        } else {
            mevcut_adim--;
            if (mevcut_adim < 0) mevcut_adim = 3;
        }

        // Doğrudan senin pinW fonksiyonunla bitleri çakıyoruz kanka
        for(uint8_t p = 0; p < 4; p++) {
            pinW(port, pinler[p], full_step_tablo[mevcut_adim][p]);
        }

        // Sadeleşen hız kısayolu döngüsü
        for (uint16_t h = 0; h < step_hiz; h++) {
            _delay_us(1);
        }
    }

    // İş bitince pinleri senin fonksiyonla sıfırlıyoruz ki motor ısınmasın
    for(uint8_t p = 0; p < 4; p++) {
        pinW(port, pinler[p], 0);
    }
}