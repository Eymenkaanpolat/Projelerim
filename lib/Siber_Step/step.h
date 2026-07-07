#ifndef STEP_H_
#define STEP_H_

#include <avr/io.h>
#include <util/delay.h>
#include "gpio.h" // Senin o efsane kütüphane burada!

// Harf kalabalığı yok, jilet gibi hız kısayolu!
extern uint16_t step_hiz;

// En sade fonksiyonumuz: Port, 4 pin, Adım sayısı ve Yön
void motor_basla(char port, uint8_t p1, uint8_t p2, uint8_t p3, uint8_t p4, uint16_t adim_sayisi, uint8_t yon);

#endif /* STEP_H_ */