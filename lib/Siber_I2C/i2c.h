#ifndef I2C_H_
#define I2C_H_

#include <avr/io.h>

// I2C hattını 100 kHz standart hızda başlatır kanka
void i2c_basla(void);

// Hatta "Ben konuşmaya başlıyorum, herkes sussun!" sinyali (START) fırlatır
void i2c_start(void);

// Hatta "Konuşmam bitti, hat serbest" sinyali (STOP) fırlatır
void i2c_stop(void);

// Hatta bağlı olan spesifik bir cihaza 1 bayt veri/adres gönderir kanka
void i2c_yaz(uint8_t veri);

// Hatta bağlı olan cihazdan 1 bayt veri okur kanka
uint8_t i2c_oku(void);

#endif /* I2C_H_ */