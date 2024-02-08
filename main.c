/*
 ============================================================================
 Name        : main.c
 Author      : Samer Sameh Lawindy
 ============================================================================
 */

#include "lcd.h"
#include "common_macros.h"
#include "std_types.h"

int main(void)
{
	LCD_init();
	LCD_displayString("Distance= ");
	while(1)
	{

	}
}
