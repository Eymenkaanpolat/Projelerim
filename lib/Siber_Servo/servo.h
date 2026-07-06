#ifndef SERVO_H_
#define SERVO_H_

#include <stdint.h>

// Fonksiyon prototiplerimiz kanka
void servo_basla(char port, uint8_t pin);
void servo_yaz(char port, uint8_t pin, uint8_t aci);

#endif /* SERVO_H_ */