// P0.19 Data pin of 1st shift register
// P0.20 Clock pin of shift registers, make 1 to 0
// P0.30 Strobe pin of shift registers: 1 to 0
#include <lpc214x.h>

#define LED_OFF (IO0SET = 1U << 31)
#define LED_ON (IO0CLR = 1U << 31)

void delay_ms(unsigned int j)
{
    unsigned int x, i;
    for (i = 0; i < j; i++)
    {
        for (x = 0; x < 10000; x++)
            ;
    }
}

unsigned char getAlphaCode(unsigned char alphachar)
{
    switch (alphachar)
    {
    // dp g f e d c b a - common anode: 0 segment on, 1 segment off
    case 'f':
        return 0x8e;
    case 'i':
        return 0xf9;
    case 'r':
        return 0xce;
    case 'e':
        return 0x86;
    case 'h':
        return 0x89;
    case 'l':
        return 0xc7;
    case 'p':
        return 0x8c;
    case ' ':
        return 0xff;
    default:
        break;
    }
    return 0xff;
}

void alphadisp7SEG(char *buf)
{
    unsigned char i, j;
    unsigned char seg7_data, temp = 0;
    for (i = 0; i < 5; i++) // because only 5 seven segment digits are present
    {
        seg7_data = getAlphaCode(*(buf + i));
        // to shift the segment data(8bits)to the hardware (shift registers) using Data,Clock,Strobe
        for (j = 0; j < 8; j++)
        {
            // get one bit of data for serial sending by using concept of masking
            temp = seg7_data & 0x80; // shift data from Most significant bit (D7)

            if (temp == 0x80)
                IOSET0 |= 1 << 19;
            else
                IOCLR0 |= 1 << 19;

            // send one clock pulse
            IOSET0 |= 1 << 20;
            delay_ms(1);
            IOCLR0 |= 1 << 20;
            seg7_data = seg7_data << 1; // get next bit into D7 position
        }
    }

    // send the strobe signal
    IOSET0 |= 1 << 30;
    delay_ms(1);
    IOCLR0 |= 1 << 30;
    return;
}

int main()
{
    // to set as o/ps
    IO0DIR |= 1U << 31 | 1U << 19 | 1U << 20 | 1U << 30;
    LED_ON; // make D7 Led on, just to indicate the program is running
    SystemInit();
    while (1)
    {
        alphadisp7SEG("fire ");
        delay_ms(500);
        alphadisp7SEG("help ");
        delay_ms(500);
    }
}
