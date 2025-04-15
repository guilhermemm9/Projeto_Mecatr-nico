/*******************************************************************************
* arquivo: lcd.cpp - arquivo de definição
* PC1602F - LCD code
* atualização: 2019-05-08
* do livro Fast and Effective Embedded Systems Design 2nd Ed 2016
* In the LCD definition file (LCD.cpp),
* we need to define the mbed objects required to control the LCD.
* Here, we can use one digital output each for RS and E,
* and we can use an mbed BusOut object for the 4-bit data.
*******************************************************************************/
/* Program Example 8.2: Declaration of objects and functions in LCD.cpp file
*/
#include "LCD.h"
DigitalOut RS(D8); // alterado para NUCLEO
DigitalOut E(D9); // alterado para NUCLEO
BusOut data(D4, D5, D6, D7); // alterado para NUCLEO
void toggle_enable(void)
{
E=1;
wait(0.002);
E=0;
wait(0.002);
}
//initialise LCD function
void LCD_init(void)
{
wait(0.02); // pause for 20 ms
RS=0; // set low to write control data
E=0; // set low
//function mode
data=0x2; // 4 bit mode (data packet 1, DB4-DB7)
toggle_enable();
data=0x8; // 2-line, 7 dot char (data packet 2, DB0-DB3)
toggle_enable();
//display mode
data=0x0; // 4 bit mode (data packet 1, DB4-DB7)
toggle_enable();
data=0xF; // display on, cursor on, blink on
toggle_enable();
//clear display
data=0x0; //
toggle_enable();
data=0x1; // clear
toggle_enable();
}
//display function
void display_to_LCD(char value)
{
RS=1; // set high to write character data
data=value>>4; // value shifted right 4 = upper nibble
toggle_enable();
data=value; // value bitmask with 0x0F = lower nibble
toggle_enable();
}