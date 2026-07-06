#include "i2c.h"

void i2c_basla(void) {
    // 16 MHz işlemci hızı için I2C hattını 100 kHz (Standart Mod) hızına ayarlıyoruz kanka
    TWBR = 72; 
    TWSR = 0;  // Frekans bölücü (Prescaler) = 1
}

void i2c_start(void) {
    // START sinyali şalterini indir ve donanımın işi bitirmesini bekle kanka
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
}

void i2c_stop(void) {
    // STOP sinyali fırlat kanka (Bunun için beklemeye gerek yoktur)
    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}

void i2c_yaz(uint8_t veri) {
    // Veriyi I2C donanımının gönderme odasına (Data Register) bırakıyoruz
    TWDR = veri;
    // Gönderme şalterini indir ve veri hattan gidene kadar bekle kanka
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
}

uint8_t i2c_oku(void) {
    // Hattan veri okuma şalterini indir ve veri gelene kadar bekle kanka
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    // Gelen veriyi odadan alıp döndür kanka
    return TWDR;
}