/**
 * 4x4 Matrix Keyboard Interface
 * OUTPUT PINS (SENDING 0):
 * ROW PINS - P0.16 (ROW0) P0.17(ROW1) P0.18(ROW2) P0.19(ROW3)
 *
 * INPUT PINS (READING KEY PRESS)
 * COL PINS - P1.19 (COL0) P1.18 (COL1) P1.17 (COL2) P1.16 (COL3)
 *
 */

#include <lpc214x.h>

#define COL0 (IOPIN1 & 1 << 19)
#define COL1 (IOPIN1 & 1 << 18)
#define COL2 (IOPIN1 & 1 << 17)
#define COL3 (IOPIN1 & 1 << 16)

#define SET_OUTPUT_PINS (IO0DIR |= 0X000F0000)

// supporting functions
void uartinit();
void delay(unsigned int ms);

// required variables
// 4x4 lookup table for 4x4 matrix keyboard
unsigned char lookup_table[4][4] = {
	{'0', '1', '2', '3'},
	{'4', '5', '6', '7'},
	{'8', '9', 'A', 'B'},
	{'C', 'D', 'E', 'F'},
};
unsigned char rowsel, colsel;

int main()
{
	uartinit();
	SET_OUTPUT_PINS;
	while (1)
	{
		do
		{
			// set row0 to 0 and check for keypress
			rowsel = 0;
			IOSET0 = 0X000F0000;
			IOCLR0 = 1 << 16;
			if (!COL0)
			{
				colsel = 0;
				break;
			}
			if (!COL1)
			{
				colsel = 1;
				break;
			}
			if (!COL2)
			{
				colsel = 2;
				break;
			}
			if (!COL3)
			{
				colsel = 3;
				break;
			}

			// set row1 to 0 and check for keypress
			rowsel = 1;
			IOSET0 = 0X000F0000;
			IOCLR0 = 1 << 17;
			if (!COL0)
			{
				colsel = 0;
				break;
			}
			if (!COL1)
			{
				colsel = 1;
				break;
			}
			if (!COL2)
			{
				colsel = 2;
				break;
			}
			if (!COL3)
			{
				colsel = 3;
				break;
			}

			// set row2 to 0 and check for keypress
			rowsel = 2;
			IOSET0 = 0X000F0000;
			IOCLR0 = 1 << 18;
			if (!COL0)
			{
				colsel = 0;
				break;
			}
			if (!COL1)
			{
				colsel = 1;
				break;
			}
			if (!COL2)
			{
				colsel = 2;
				break;
			}
			if (!COL3)
			{
				colsel = 3;
				break;
			}

			// set row3 to 0 and check for keypress
			rowsel = 3;
			IOSET0 = 0X000F0000;
			IOCLR0 = 1 << 19;
			if (!COL0)
			{
				colsel = 0;
				break;
			}
			if (!COL1)
			{
				colsel = 1;
				break;
			}
			if (!COL2)
			{
				colsel = 2;
				break;
			}
			if (!COL3)
			{
				colsel = 3;
				break;
			}

		} while (1);

		// for key debouncing
		delay(20);

		// wait till key released
		while (!COL0 || !COL1 || !COL2 || !COL3)
			;
		// key debouncing again
		delay(20);

		// send pressed key to serial port (uart)
		U0THR = lookup_table[rowsel][colsel];
	}
}

void uartinit()
{
	PINSEL0 |= 0X05;
	U0LCR = 0X83;
	U0DLM = 0;
	U0DLL = 8;
	U0LCR = 0X03;
	U0FCR = 0X07;
}

void delay(unsigned int ms)
{
	while (ms--)
		for (unsigned int i = 0; i < 10000; i++)
			;
}
