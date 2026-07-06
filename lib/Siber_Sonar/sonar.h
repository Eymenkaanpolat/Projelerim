#ifndef SONAR_H_
#define SONAR_H_

#include <avr/io.h>

// Sonar pinlerini ve kesme (interrupt) mekanizmasını hazırlar kanka
void sonar_basla(void);

// Sensörü tetiklemek için 10us'lik ses bombası fırlatır
void sonar_tetikle(void);

// En son ölçülen mesafeyi santimetre (cm) olarak döner
uint16_t sonar_mesafe_oku(void);

#endif /* SONAR_H_ */