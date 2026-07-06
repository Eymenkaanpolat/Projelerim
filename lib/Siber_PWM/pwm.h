#ifndef PWM_H_
#define PWM_H_

#include <avr/io.h>

// Arduino Uno üzerindeki tüm 6 PWM pininin siber lakapları kanka
#define PWM_D6 0  // Timer0 - OC0A -> Dijital 6
#define PWM_D5 1  // Timer0 - OC0B -> Dijital 5
#define PWM_B1 2  // Timer1 - OC1A -> Dijital 9  (16-bit Timer kanka!)
#define PWM_B2 3  // Timer1 - OC1B -> Dijital 10 (16-bit Timer kanka!)
#define PWM_B3 4  // Timer2 - OC2A -> Dijital 11
#define PWM_D3 5  // Timer2 - OC2B -> Dijital 3

// İstediğin PWM pinini arka planda hazırlar
void pwm_basla(uint8_t kanal);

// Seçtiğin pine 0-255 arası güç verir kanka
void pinPWM(uint8_t kanal, uint8_t duty);

#endif /* PWM_H_ */