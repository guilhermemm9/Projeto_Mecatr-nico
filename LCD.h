/*******************************************************************************
 * arquivo: lcd.h
 * PC1602F - LCD code
 * atualização: 2019-05-08
 * do livro Fast and Effective Embedded Systems Design 2nd Ed 2016
 * declaradas as functions no header file do LCD:
 * - toggle_enable(): a function to toggle/pulse the enable bit,
 * - LCD_init(): a function to initialize the LCD,
 * - display_to_LCD(): a function to display characters on the LCD.
 *******************************************************************************/
 
 /* Program Example 8.1: LCD.h header file
*/
#ifndef LCD_H
#define LCD_H
#include "mbed.h"
void toggle_enable(void); //function to toggle/pulse the enable bit
void LCD_init(void); //function to initialise the LCD
void display_to_LCD(char value); //function to display characters
#endif