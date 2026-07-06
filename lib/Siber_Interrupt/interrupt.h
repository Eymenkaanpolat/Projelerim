#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include <avr/io.h>
#include <avr/interrupt.h> // AVR'nin kendi kesme makroları için şart kanka

#define KESME_INT0 0 // Arduino Pin 2 (PD2)
#define KESME_INT1 1 // Arduino Pin 3 (PD3)

// Kesmenin ne zaman tetikleneceğini seçmek için lakaplar
#define TETIK_DUSEN  0 // Sinyal 5V'tan 0V'a düştüğü an (Butona basınca)
#define TETIK_YUKSELEN 1 // Sinyal 0V'tan 5V'a çıktığı an (Butondan çekince)

// Kesme donanımını ateşler kanka
void kesme_basla(uint8_t pin, uint8_t tetik_tipi);

#endif /* INTERRUPT_H_ */