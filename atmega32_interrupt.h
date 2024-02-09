 /******************************************************************************
 *
 * Module: ATMEGA32 INTERRUPTS
 *
 * File Name: atmega32_interrupt.h
 *
 * Description: ATMEGA32 Interrupt Driver Header File
 *
 * Author: Samer Sameh Lawindy
 *
 *******************************************************************************/

#ifndef ATMEGA32_INTERRUPT_H_
#define ATMEGA32_INTERRUPT_H_


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void INTERRUPT_enable();
void INTERRUPT_INT0_init();
void INTERRUPT_INT1_init();
void INTERRUPT_disable();


#endif /* ATMEGA32_INTERRUPT_H_ */
