#include <lpc214x.h>

// SET PINS AS OUTPUT
#define SET_PINS (IO0DIR |= 0X000F0000)

// DEFINE STEPS
#define STEP1 (IOSET0 = 0X00010000)
#define STEP2 (IOSET0 = 0X00020000)
#define STEP3 (IOSET0 = 0X00040000)
#define STEP4 (IOSET0 = 0X00080000)

// STOP CURRENT FLOW AFTER EACH STEP
#define STOP_CURRENT IOCLR0 = 0X000F0000

void delay(unsigned int ms)
{
	while (ms--)
		for (unsigned int i = 0; i < 10000; i++)
			;
}

int main()
{
	unsigned int clock_steps = 100, anti_steps = 100;
	SET_PINS;
	// clockwise rotation
	do
	{
		STOP_CURRENT;
		STEP1;
		delay(10);
		if (--clock_steps == 0)
			break;

		STOP_CURRENT;
		STEP2;
		delay(10);
		if (--clock_steps == 0)
			break;

		STOP_CURRENT;
		STEP3;
		delay(10);
		if (--clock_steps == 0)
			break;

		STOP_CURRENT;
		STEP4;
		delay(10);
		if (--clock_steps == 0)
			break;

	} while (1);
	// anticlockwise rotation
	do
	{
		STOP_CURRENT;
		STEP4;
		delay(10);
		if (--anti_steps == 0)
			break;

		STOP_CURRENT;
		STEP3;
		delay(10);
		if (--anti_steps == 0)
			break;

		STOP_CURRENT;
		STEP2;
		delay(10);
		if (--anti_steps == 0)
			break;

		STOP_CURRENT;
		STEP1;
		delay(10);
		if (--anti_steps == 0)
			break;

	} while (1);
	IO0CLR = 0X000F0000;
}
