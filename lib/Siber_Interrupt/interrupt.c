#include "interrupt.h"

// Kesme donanımını ateşleyen o siber fonksiyon kanka
void kesme_basla(uint8_t pin, uint8_t tetik_tipi) 
{
    // Önce eski ayarları temizlemek için geçici bir maske hazırlayalım kanka
    if (pin == KESME_INT0) 
    {
        // INT0 için tetikleme modunu ayarlıyoruz (EICRA register'ındaki ISC00 ve ISC01 bitleri)
        if (tetik_tipi == TETIK_DUSEN) 
        {
            // Düşen kenar için: ISC01 = 1, ISC00 = 0 yap kanka
            EICRA |= (1 << ISC01);
            EICRA &= ~(1 << ISC00);
        } 
        else if (tetik_tipi == TETIK_YUKSELEN) 
        {
            // Yükselen kenar için: ISC01 = 1, ISC00 = 1 yap kanka
            EICRA |= (1 << ISC01) | (1 << ISC00);
        }

        // Ana donanımsal şalteri kaldırıyoruz: INT0 kesmesini aktif et kanka!
        EIMSK |= (1 << INT0);
    } 
    else if (pin == KESME_INT1) 
    {
        // INT1 için tetikleme modunu ayarlıyoruz (EICRA register'ındaki ISC10 ve ISC11 bitleri)
        if (tetik_tipi == TETIK_DUSEN) 
        {
            // Düşen kenar için: ISC11 = 1, ISC10 = 0 yap kanka
            EICRA |= (1 << ISC11);
            EICRA &= ~(1 << ISC10);
        } 
        else if (tetik_tipi == TETIK_YUKSELEN) 
        {
            // Yükselen kenar için: ISC11 = 1, ISC10 = 1 yap kanka
            EICRA |= (1 << ISC11) | (1 << ISC10);
        }

        // Ana donanımsal şalteri kaldırıyoruz: INT1 kesmesini aktif et kanka!
        EIMSK |= (1 << INT1);
    }
}