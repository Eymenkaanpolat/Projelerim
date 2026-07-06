#include "pwm.h"

void pwm_basla(uint8_t kanal) {
    switch(kanal) {
        case PWM_D6: // Timer0 - OC0A (Dijital 6)
            DDRD |= (1 << DDD6);
            TCCR0A |= (1 << COM0A1) | (1 << WGM01) | (1 << WGM00);
            TCCR0B |= (1 << CS01) | (1 << CS00); // Prescaler 64
            OCR0A = 0;
            break;
            
        case PWM_D5: // Timer0 - OC0B (Dijital 5)
            DDRD |= (1 << DDD5);
            TCCR0A |= (1 << COM0B1) | (1 << WGM01) | (1 << WGM00);
            TCCR0B |= (1 << CS01) | (1 << CS00); // Prescaler 64
            OCR0B = 0;
            break;
            
        case PWM_B1: // Timer1 - OC1A (Dijital 9) - 8 bit Fast PWM modu yapıyoruz kanka
            DDRB |= (1 << DDB1);
            TCCR1A |= (1 << COM1A1) | (1 << WGM10);
            TCCR1B |= (1 << WGM12) | (1 << CS11) | (1 << CS10); // Prescaler 64
            OCR1AL = 0;
            break;
            
        case PWM_B2: // Timer1 - OC1B (Dijital 10)
            DDRB |= (1 << DDB2);
            TCCR1A |= (1 << COM1B1) | (1 << WGM10);
            TCCR1B |= (1 << WGM12) | (1 << CS11) | (1 << CS10); // Prescaler 64
            OCR1BL = 0;
            break;
            
        case PWM_B3: // Timer2 - OC2A (Dijital 11)
            DDRB |= (1 << DDB3);
            TCCR2A |= (1 << COM2A1) | (1 << WGM21) | (1 << WGM20);
            TCCR2B |= (1 << CS22); // Timer2 için Prescaler 64 şalteri kanka
            OCR2A = 0;
            break;
            
        case PWM_D3: // Timer2 - OC2B (Dijital 3)
            DDRD |= (1 << DDD3);
            TCCR2A |= (1 << COM2B1) | (1 << WGM21) | (1 << WGM20);
            TCCR2B |= (1 << CS22); // Prescaler 64
            OCR2B = 0;
            break;
    }
}

void pinPWM(uint8_t kanal, uint8_t duty) {
    switch(kanal) {
        case PWM_D6: OCR0A = duty; break;
        case PWM_D5: OCR0B = duty; break;
        case PWM_B1: OCR1AL = duty; break; // 8-bit modda olduğumuz için Low register'ı yeterli kanka
        case PWM_B2: OCR1BL = duty; break;
        case PWM_B3: OCR2A = duty; break;
        case PWM_D3: OCR2B = duty; break;
    }
}