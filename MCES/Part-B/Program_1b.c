#include <lpc214x.h>

#define SW2 (IO0PIN & (1 << 14)) // sw2 connected to P0.14
#define SW3 (IO0PIN & (1 << 15)) // P0.15
#define SW4 (IO1PIN & (1 << 18)) // P1.18
#define SW5 (IO1PIN & (1 << 19)) // P1.19
#define SW6 (IO1PIN & (1 << 20)) // P1.20

int contUP = 0;
int contDN = 99;
unsigned int rightSFT = 1U << 7;
unsigned int leftSFT = 1;

void reset_values(int y)
{
    switch (y)
    {
    case 0:
        contDN = 99;
        rightSFT = 1U << 7;
        leftSFT = 1;
        break;
    case 1:
        contUP = 0;
        rightSFT = 1U << 7;
        leftSFT = 1;
        break;
    case 2:
        contUP = 0;
        contDN = 99;
        rightSFT = 1U << 7;
        break;
    case 3:
        contUP = 0;
        contDN = 99;
        leftSFT = 1;
        break;
    }
}

void delay_ms(unsigned int ms)
{
    while (ms--)
        for (int x = 0; x < 10000; x++)
            ;
}

int main()
{
    IO0DIR |= 0XFF << 16;
    // LED20-27 are connected to P0.16-P0.23
    IO0SET = 0xFF << 16; // switch off the LEDs
    while (1)
    {
        // BCD Up Counter
        if (!SW2)
        {
            reset_values(0);
            IO0SET = 0xFF << 16;
            IO0CLR = ((contUP / 10) << 4 | (contUP % 10)) << 16;
            contUP++;
            if (contUP > 99)
                contUP = 0;
        }

        // BCD Down Counter
        else if (!SW3)
        {
            reset_values(1);
            IO0SET = 0xFF << 16;
            IO0CLR = ((contDN / 10) << 4 | (contDN % 10)) << 16;
            contDN--;
            if (contDN < 0)
                contDN = 99;
        }

        // Ring counter left shifting
        else if (!SW4)
        {
            reset_values(2);
            IO0SET = 0xFF << 16;
            IO0CLR = leftSFT << 16;
            leftSFT <<= 1;
            if (leftSFT > 1U << 7)
                leftSFT = 1;
        }

        // Ring counter right shifting
        else if (!SW5)
        {
            reset_values(3);
            IO0SET = 0xFF << 16;
            IO0CLR = rightSFT << 16;
            rightSFT >>= 1;
            if (rightSFT < 1)
                rightSFT = 1U << 7;
        }
        delay_ms(300);
    }
}
