#include "ir.h"

static volatile uint32_t ir_kod = 0;
static volatile uint8_t veri_hazir = 0;
static volatile uint8_t ir_repeat = 0;
static volatile uint8_t gecerli_kod_var = 0; // Hayalet Repeat'i engelleyen kilit

void ir_basla(void)
{
    pin_mod('D', 3, 0);

    // Timer1 Prescaler 64 (16MHz için her tık 4us)
    TCCR1A = 0x00;
    TCCR1B = (1 << CS11) | (1 << CS10);
    TCNT1 = 0;

    // INT1 Falling Edge (Düşen kenar kesmesi)
    EICRA |= (1 << ISC11);
    EICRA &= ~(1 << ISC10);

    EIFR |= (1 << INTF1);
    EIMSK |= (1 << INT1);

    sei();
}

uint8_t ir_veri_var(void)
{
    return veri_hazir;
}

uint8_t ir_repeat_var(void)
{
    return ir_repeat;
}

uint32_t ir_oku(void)
{
    veri_hazir = 0;
    return ir_kod;
}

void ir_repeat_temizle(void)
{
    ir_repeat = 0;
}

void ir_temizle(void)
{
    ir_kod = 0;
    veri_hazir = 0;
    ir_repeat = 0;
    gecerli_kod_var = 0;
}

ISR(INT1_vect)
{
    static uint16_t son_zaman = 0;
    static uint8_t bit_indeks = 0;
    static uint32_t gecici_kod = 0;

    uint16_t simdiki_zaman = TCNT1;
    uint16_t fark_tik;

    if (simdiki_zaman >= son_zaman)
        fark_tik = simdiki_zaman - son_zaman;
    else
        fark_tik = (65536UL - son_zaman) + simdiki_zaman;

    son_zaman = simdiki_zaman;

    uint32_t fark_us = (uint32_t)fark_tik * 4;

    // 1. NEC Repeat (~11.25ms) -> SADECE önceden geçerli bir tuş okunduysa kabul et
    if (fark_us > 10000 && fark_us < 12000)
    {
        if (gecerli_kod_var) 
        {
            ir_repeat = 1;
        }
        bit_indeks = 0;
        return;
    }

    // 2. NEC Başlangıç (~13.5ms) -> Yeni paket geliyor
    if (fark_us > 12000 && fark_us < 15000)
    {
        bit_indeks = 0;
        gecici_kod = 0;
        gecerli_kod_var = 0; // Yeni pakete başlarken eski kilidi sıfırla
        return;
    }

    // 3. Paketler / Sinyaller Arası Boşluk (> 15ms)
    // NEC protokolünde paketler arası 40ms-110ms yasal boşluk olur. 
    // Kilidi kırma, bitleri sıfırla ve bekle.
    if (fark_us >= 15000)
    {
        bit_indeks = 0;
        gecici_kod = 0;
        return;
    }

    // Yeni veri okunmadıysa yeni bitleri işleme
    if (veri_hazir)
        return;

    // 4. Bit 0 (~1.12ms)
    if (fark_us > 800 && fark_us < 1600)
    {
        bit_indeks++;
    }
    // 5. Bit 1 (~2.25ms)
    else if (fark_us > 1800 && fark_us < 3000)
    {
        gecici_kod |= ((uint32_t)1 << bit_indeks);
        bit_indeks++;
    }
    // 6. Gerçek Gürültü / Bozuk Sinyal
    else
    {
        bit_indeks = 0;
        gecici_kod = 0;
        gecerli_kod_var = 0; // Gerçek bir gürültüde kilit kapanır
        return;
    }

    // 32 bit tamamlandı!
    if (bit_indeks >= 32)
    {
        ir_kod = gecici_kod;
        veri_hazir = 1;
        gecerli_kod_var = 1; // Kilit açıldı! Artık peşinden gelecek Repeat meşrudur.

        bit_indeks = 0;
        gecici_kod = 0;
    }
}