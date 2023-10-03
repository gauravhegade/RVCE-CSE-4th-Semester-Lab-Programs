#include <lpc214x.h>

#define LED_ON (IOCLR0 = 1 << 31)

#define SW2 !(IOPIN0 & (1 << 14))
#define SW3 !(IOPIN0 & (1 << 15))
#define SW4 !(IOPIN1 & (1 << 18))
#define SW5 !(IOPIN1 & (1 << 19))
#define SW6 !(IOPIN1 & (1 << 20))

void delay_ms(unsigned int j)
{
    while (j--)
        for (unsigned int i = 0; i < 10000; i++);
}

short int sine_table[] = {
    0, 52, 106, 158, 208, 255, 300, 342, 380,
    413, 442, 467, 486, 500, 508, 511, 508, 500,
    486, 467, 442, 413, 380, 342, 300, 255, 208,
    158, 106, 52, 0,
};

int main() {
    PINSEL1 = 1 << 19; // P0.25 AS DAC
    IODIR0 = 1 << 31;  // FOR LED
    LED_ON;
    short int i = 0, value = 0;

    while (1) {
        // sine waveform
        if (SW2) {
            // upper half cycle
            while (i != 30) {
                // enable bias bit (16) and push data to 6th bit (D15:6)
                value = 512 + sine_table[i++];
                DACR = (1 << 16 | value << 6);
                delay_ms(1);
            }
			i = 0;
            // lower half cycle
			while(i != 30) {
				// enable bias bit (16) and push data to 6th bit (D15:6)
                value = 512 - sine_table[i++];
                DACR = (1 << 16 | value << 6);
                delay_ms(1);	
			}
            i = 0;
        }

        // rectified sine waveform
        else if (SW3) {
            while (i != 30) {
                value = 512 + sine_table[i++];
                DACR = (1 << 16 | value << 6);
                delay_ms(1);
            }
            i = 0;
        }

        // triangular waveform
        else if (SW4) {
            i = 0;
            while (i != 1023) {
                DACR = (1 << 16 | i++ << 6);
                delay_ms(1);
            }

            while (i != 0) {
                DACR = (1 << 16 | i-- << 6);
                delay_ms(1);
            }
            i = 0;
        }

        // sawtooth waveform /|/|
        else if (SW5) {
            i = 0;
            while (i != 1023) {
                DACR = (1 << 16 | i++ << 6);
                delay_ms(1);
            }
        }

        // square waveform
        else if (SW6) {
            DACR = (1 << 16 | 1023 << 6);
            delay_ms(1);
            DACR = (1 << 16 | 0 << 6);
            delay_ms(1);
        }

        // if no switch pressed send 3.3V
        else
            DACR = (1 << 16 | 1023 << 6);
    }
}
