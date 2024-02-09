/******************************************************************************
 *
 * Module: ULTRASONIC SENSOR
 *
 * File Name: ultrasonic_sensor.c
 *
 * Description: Source file for the ultrasonic sensor driver
 *
 * Author: Samer Sameh Lawindy
 *
 *******************************************************************************/

#include "ultrasonic_sensor.h"
#include "atmega32_gpio.h"
#include "atmega32_icu.h"
#include <avr/delay.h>
#include <math.h>

/**************************************************************************************
 *                               Global Variables                                     *
 **************************************************************************************/
static uint8 g_edges = 0; 			/* ICU Edges */
static uint16 g_captureValue = 0; 	/* ICU Captured Value */

/**************************************************************************************
 *                               Function Definition                                  *
 **************************************************************************************/

void Ultrasonic_init(void)
{
	/* Configure and Initialize ICU Module */
	ICU_ConfigType icu_config = {F_CPU_8, RAISING};
	ICU_init(&icu_config);

	ICU_setCallBack(Ultrasonic_edgeProcessing);

	/* Set Trigger and Echo Pins Directions */
	GPIO_setupPinDirection(TRIGGER_PIN_PORT_ID, TRIGGER_PIN_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(ECHO_PIN_PORT_ID, ECHO_PIN_PIN_ID, PIN_INPUT);
}

void Ultrasonic_Trigger(void)
{
	GPIO_writePin(TRIGGER_PIN_PORT_ID,TRIGGER_PIN_PIN_ID,LOGIC_HIGH); 	/* Set Trigger to Logic High*/
	_delay_us(10); 														/* Wait for 10 us */
	GPIO_writePin(TRIGGER_PIN_PORT_ID,TRIGGER_PIN_PIN_ID,LOGIC_LOW); 	/* Set Trigger to Logic Low */
}

uint16 Ultrasonic_readDistance(void)
{
	Ultrasonic_Trigger(); 											/* Send Trigger*/
	_delay_ms(1); 													/* Wait for Signal to be Sent */
	uint16 distance = 0;
	uint32 tick_time = F_CPU/8; 									/* Calculate Tick Time */
	distance = round((double)(34000*(g_captureValue/2))/tick_time);	/* Calculate Distance */
	return distance;
}

void Ultrasonic_edgeProcessing(void)
{
	g_edges++; 			/* Increment Edge Every Function Call */

	/* ICU Starts Counting After the Raising Edge and Waits for the Falling Edge */
	if(g_edges == 1)
	{
		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(FALLING);
	}

	/* Stops Counting After the Falling Edge, Captures the ICU Value and Waits for Another Raising Edge */
	else if(g_edges == 2)
	{
		g_captureValue = ICU_getInputCaptureValue();
		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(RAISING);
		g_edges = 0;
	}
}
