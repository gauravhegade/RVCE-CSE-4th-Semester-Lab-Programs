/**
 * DC Motor Speed Control
 * P0.28 - used for direction control
 * P0.9 - used for speed,generated by PWM6
 * duty cycle - 0 to 100 controlled by PWM, fed from Potentiameter connected to ADC
 */

#include <lpc214x.h>

#define LED_OFF (IO0SET = 1U << 31)
#define LED_ON (IO0CLR = 1U << 31)

void delay_ms(unsigned int ms)
{
	while (ms--)
		for (unsigned int i = 0; i < 10000; i++);
}

void runDCMotor(int direction, int dutycycle)
{
	IO0DIR |= 1U << 28; // set P0.28 as output pin
	PINSEL0 |= 2 << 18; // select P0.9 as PWM6 (option 2)
	
	if (direction == 1)
		IO0SET = 1 << 28; // set to 1, to choose anti-clockwise direction
	else
		IO0CLR = 1 << 28;				// set to 0, to choose clockwise direction
	
	PWMPCR = (1 << 14);					// enable PWM6
	PWMMR0 = 1000;						// set PULSE rate to value suitable for DC Motor operation
	PWMMR6 = (1000U * dutycycle) / 100; // set PULSE period
	PWMTCR = 0x00000009;				// bit D3 = 1 (enable PWM), bit D0=1 (start the timer)
	PWMLER = 0X70;						// load the new values to PWMMR0 and PWMMR6 registers
}

// adc(1,4) for temp sensor LM34, digital value will increase as temp increases
// adc(1,3) for LDR - digital value will reduce as the light increases
// adc(1,2) for trimpot - digital value changes as the potetiometer rotates
unsigned int adc(int no, int ch)
{
	unsigned int val;

	/* Select the P0_13 AD1.4 for ADC function */
	/* Select the P0_12 AD1.3 for ADC function */
	/* Select the P0_10 AD1.2 for ADC function */
	PINSEL0 |= 0x0F300000;

	switch (no) // select adc
	{
	case 0:
		AD0CR = 0x00200600 | (1 << ch); // select channel
		AD0CR |= (1 << 24);		// start conversion
		// while the done bit is 0 wait, when 1 - exit
		while ((AD0GDR & (1U << 31)) == 0);
		val = AD0GDR;
		break;
	case 1:
		AD1CR = 0x00200600 | (1 << ch); // select channel
		AD1CR |= (1 << 24);		// start conversion
		while ((AD1GDR & (1U << 31)) == 0);
		val = AD1GDR;
		break;
	}
	val = (val >> 6) & 0x03FF; // bit 6:15 is 10 bit AD value
	return val;
}

int main()
{
	int dig_val;
	IO0DIR |= 1U << 31 | 0x00FF0000 | 1U << 30; // to set P0.16 to P0.23 as o/ps

	LED_ON;
	delay_ms(500);
	LED_OFF; // make D7 Led on / off for program checking

	do
	{
		dig_val = adc(1, 2) / 10;
		if (dig_val > 100)
			dig_val = 100;
		runDCMotor(2, dig_val); // run at 10% duty cycle
	} while (1);
}
