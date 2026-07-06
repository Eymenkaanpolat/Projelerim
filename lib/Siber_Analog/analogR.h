#ifndef ANALOGR_H_
#define ANALOGR_H_

#include <avr/io.h>

// Belirtilen analog pindeki (0-5 arası) voltajı okur ve 0-1023 arası sayı döner kanka.
uint16_t analogR(uint8_t kanal);

#endif /* ANALOGR_H_ */