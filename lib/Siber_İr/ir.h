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

#endif /* IR_H_ */