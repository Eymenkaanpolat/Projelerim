#ifndef GPIO_H_
#define GPIO_H_

#include <avr/io.h>

// Kolaylık olsun diye port isimlerini lakaplandırıyoruz kanka
#define PORT_B 'B'
#define PORT_D 'D'

/* 
  KANKA AKILDA TUTMA NOTU (Arduino Uno Pin Haritası):
  - Eğer Arduino D0 - D7 arası pinleri kontrol edeceksen: port 'D', pin 0-7 arası seçilmeli.
  - Eğer Arduino D8 - D13 arası pinleri kontrol edeceksen: port 'B', pin 0-5 arası seçilmeli.
*/

// Mod ayarla kanka (port: 'B' veya 'D', pin: 0-7 arası, mod: 1 çıkış / 0 giriş)
void pin_mod(char port, uint8_t pin, uint8_t mod);

// Voltaj ver veya kes (port: 'B' veya 'D', pin: 0-7 arası, deger: 1 HIGH / 0 LOW)
void pinW(char port, uint8_t pin, uint8_t deger);

// Voltaj oku (port: 'B' veya 'D', pin: 0-7 arası)
uint8_t pinR(char port, uint8_t pin);

#endif /* GPIO_H_ */