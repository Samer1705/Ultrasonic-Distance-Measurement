 /******************************************************************************
 *
 * Module: ATMEGA32 INTERRUPTS
 *
 * File Name: atmega32_interrupt.c
 *
 * Description: ATMEGA32 Interrupt Driver Source File
 *
 * Author: Samer Sameh Lawindy
 *
 *******************************************************************************/

#include "atmega32_interrupt.h"
#include "atmega32_gpio.h"
#include "lcd.h"
#include "common_macros.h"
#include <avr/interrupt.h>
#include <avr/io.h> /* To use the IO Ports Registers */


/*******************************************************************************
 *                          Functions Definitions                              *
 *******************************************************************************/
void INTERRUPT_enable()
{
	SREG |= (1<<7);					/* Enable Global Interrupts */
}
void INTERRUPT_INT0_init()
{
	GPIO_setupPinDirection(PORTD_ID, PIN2_ID, PIN_INPUT);
	GICR |= (1<<INT0);
}
void INTERRUPT_INT1_init()
{
	GPIO_setupPinDirection(PORTD_ID, PIN3_ID, PIN_INPUT);
	GICR |= (1<<INT1);
}
void INTERRUPT_disable()
{
	SREG &= ~(1<<7);					/* Disable Global Interrupts */
}
