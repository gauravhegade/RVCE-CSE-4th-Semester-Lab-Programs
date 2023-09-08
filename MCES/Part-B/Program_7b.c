/**
 * Alpha-numeric LCD Interface (4 Lines, 20 characters)
 * Connected in 4bit nibble mode
 * LCD handshaking: RS->P0.20, EN->P0.25, R/W->Gnd
 * LCD data: D4, D5, D6, D7 -> P0.16, P0.17, P0.18, P0.19
 */

#include <lpc214x.h>

#define LED_OFF (IO0SET = 1U << 31)
#define LED_ON (IO0CLR = 1U << 31)

#define RS_CMD (IO0CLR = 1U << 20)  // RS = 0 then command mode
#define RS_DATA (IO0SET = 1U << 20) // RS = 1 then data mode
#define EN_ON (IO1SET = 1U << 25)
#define EN_OFF (IO1CLR = 1U << 25)

void delay_ms(unsigned int ms)
{
    while (ms--)
        for (unsigned int i = 0; i < 10000; i++)
            ;
}

static void delay_us(unsigned int count)
{
    unsigned int j = 0, i = 0;
    for (j = 0; j < count; j++)
    {
        for (i = 0; i < 10; i++)
            ;
    }
}
static void LCD_SendCmdSignals(void)
{
    RS_CMD;
    EN_ON;
    delay_us(100);
    EN_OFF; // EN - 1 then 0
}

static void LCD_SendDataSignals(void)
{
    RS_DATA;
    EN_ON;
    delay_us(100);
    EN_OFF; // EN - 1 then 0
}

static void LCD_SendHigherNibble(unsigned char dataByte)
{
    // send the D7,6,5,D4(uppernibble) to P0.16 to P0.19
    IO0CLR = 0X000F0000;
    IO0SET = ((dataByte >> 4) & 0x0f) << 16;
}

static void LCD_CmdWrite(unsigned char cmdByte)
{
    LCD_SendHigherNibble(cmdByte);
    LCD_SendCmdSignals();
    cmdByte <<= 4;
    LCD_SendHigherNibble(cmdByte);
    LCD_SendCmdSignals();
}

static void LCD_DataWrite(unsigned char dataByte)
{
    LCD_SendHigherNibble(dataByte);
    LCD_SendDataSignals();
    dataByte <<= 4;
    LCD_SendHigherNibble(dataByte);
    LCD_SendDataSignals();
}

static void LCD_Reset(void)
{
    /* LCD reset sequence for 4-bit mode*/
    LCD_SendHigherNibble(0x30);
    LCD_SendCmdSignals();
    delay_ms(100);

    LCD_SendHigherNibble(0x30);
    LCD_SendCmdSignals();
    delay_us(200);

    LCD_SendHigherNibble(0x30);
    LCD_SendCmdSignals();
    delay_us(200);

    LCD_SendHigherNibble(0x20);
    LCD_SendCmdSignals();
    delay_us(200);
}

static void LCD_Init(void)
{
    delay_ms(100);
    LCD_Reset();
    LCD_CmdWrite(0x28u); // Initialize the LCD for 4-bit 5x7 matrix type
    LCD_CmdWrite(0x0Eu); // Display ON cursor ON
    LCD_CmdWrite(0x01u); // Clear the LCD
    LCD_CmdWrite(0x80u); // go to First line First Position
}

void LCD_DisplayString(const char *ptr_string)
{
    // Loop through the string and display char by char
    while ((*ptr_string) != 0)
        LCD_DataWrite(*ptr_string++);
}

int main()
{
    IO0DIR |= 1U << 31 | 0x00FF0000; // to set P0.16 to P0.23 as o/ps
    IO1DIR |= 1U << 25;              // to set P1.25 as o/p used for EN

    // make D7 Led on off for testing
    LED_ON;
    delay_ms(500);
    LED_OFF;
    delay_ms(500);

    LCD_Init();
    delay_ms(100);

    LCD_CmdWrite(0x80);
    LCD_DisplayString("RV College Of Engineering");

    LCD_CmdWrite(0xc0);
    LCD_DisplayString(" Computer Science");

    LCD_CmdWrite(0x94);
    LCD_DisplayString(" 4th Semester");

    LCD_CmdWrite(0xD4);
    LCD_DisplayString(" A Section");

    while (1)
        ;
}
