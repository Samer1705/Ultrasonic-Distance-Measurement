/*
 ============================================================================
 Name        : main.c
 Author      : Samer Sameh Lawindy
 ============================================================================
 */

#include "lcd.h"
#include "ultrasonic_sensor.h"
#include "common_macros.h"
#include "std_types.h"

int main(void)
{
	INTERRUPT_enable();
	LCD_init();
	Ultrasonic_init();
	LCD_displayString("Distance= ");
	uint16 distance;
	while(1)
	{
		distance = Ultrasonic_readDistance();
		LCD_moveCursor(0, 10);
		LCD_intgerToString(distance);
		LCD_displayString("cm    ");
	}
}
