#ifndef IR_H_
#define IR_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "gpio.h"

void ir_basla(void);
uint8_t ir_veri_var(void);
uint32_t ir_oku(void);
void ir_temizle(void);
uint8_t ir_repeat_var(void);
void ir_repeat_temizle(void);
void irW(uint32_t kod);

#endif /* IR_H_ */