#include "analogR.h"
#include "uart.h"
#include <util/delay.h>
#include "gpio.h"
int main(void)
{
    pin_mod('D', 2, 0);
    pinW('D', 2, 1); // D2 pinini giriş olarak ayarla (analog giriş)
    pin_mod('D', 3, 1);
    pin_mod('D', 4, 1);
    pin_mod('D', 5, 1);
    uart_basla();
    while (1)
    {
        if (pinR('D', 2) == 0)
        {
            uint16_t rastgele = analogR(0);
            uart_degerW(rastgele);
            uart_yaz("\r\n");
             // 0. kanaldan analog değeri oku
            if (rastgele <= 300) {
                pinW('D', 3, 1);
                _delay_ms(1000);
                pinW('D', 3, 0);
            }
            else if (rastgele <= 600) {
                pinW('D', 4, 1);
                _delay_ms(1000);
                pinW('D', 4, 0);
            }
            else {
                pinW('D', 5, 1);
                _delay_ms(1000);
                pinW('D', 5, 0);
            }
          
            _delay_ms(1000);
        }
    }

    return 0;
}