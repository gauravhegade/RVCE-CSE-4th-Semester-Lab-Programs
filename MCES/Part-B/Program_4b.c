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
        for (unsigned int i = 0; i < 10000; i++)
            ;
}

short int sine_table[] = {
    // upper half cycle
    512 + 0, 512 + 52, 512 + 106, 512 + 158, 512 + 208, 512 + 255, 512 + 300, 512 + 342, 512 + 380,
    512 + 413, 512 + 442, 512 + 467, 512 + 486, 512 + 500, 512 + 508, 512 + 511, 512 + 508, 512 + 500,
    512 + 486, 512 + 467, 512 + 442, 512 + 413, 512 + 380, 512 + 342, 512 + 300, 512 + 255, 512 + 208,
    512 + 158, 512 + 106, 512 + 52, 512 + 0,
    // lower half cycle
    512 - 0, 512 - 52, 512 - 106, 512 - 158, 512 - 208, 512 - 255, 512 - 300, 512 - 342, 512 - 380,
    512 - 413, 512 - 442, 512 - 467, 512 - 486, 512 - 500, 512 - 508, 512 - 511, 512 - 508, 512 - 500,
    512 - 486, 512 - 467, 512 - 442, 512 - 413, 512 - 380, 512 - 342, 512 - 300, 512 - 255, 512 - 208,
    512 - 158, 512 - 106, 512 - 52, 512 - 0};

int main()
{
    PINSEL1 = 1 << 19; // P0.25 AS DAC
    IODIR0 = 1 << 31;  // FOR LED
    LED_ON;
    short int i = 0, value = 0;

    while (1)
    {
        // sine waveform
        if (SW2)
        {
            while (i != 60)
            {
                // enable bias bit (16) and push data to 6th bit (D15:6)
                value = sine_table[i++];
                DACR = (1 << 16 | value << 6);
                delay_ms(1);
            }
            i = 0;
        }

        // rectified sine waveform
        else if (SW3)
        {
            while (i != 30)
            {
                value = sine_table[i++];
                DACR = (1 << 16 | value << 6);
                delay_ms(1);
            }
            i = 0;
        }

        // triangular waveform
        else if (SW4)
        {
            i = 0;
            while (i != 1023)
            {
                DACR = (1 << 16 | i++ << 6);
                delay_ms(1);
            }

            while (i != 0)
            {
                DACR = (1 << 16 | i-- << 6);
                delay_ms(1);
            }
            i = 0;
        }

        // sawtooth waveform /|/|
        else if (SW5)
        {
            i = 0;
            while (i != 1023)
            {
                DACR = (1 << 16 | i++ << 6);
                delay_ms(1);
            }
        }

        // square waveform
        else if (SW6)
        {
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
