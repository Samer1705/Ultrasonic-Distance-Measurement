 /******************************************************************************
 *
 * Module: ULTRASONIC SENSOR
 *
 * File Name: ultrasonic_sensor.h
 *
 * Description: Header file for the ultrasonic sensor driver
 *
 * Author: Samer Sameh Lawindy
 *
 *******************************************************************************/


#ifndef ULTRASONIC_SENSOR_H_
#define ULTRASONIC_SENSOR_H_

#include "std_types.h"
#include "atmega32_gpio.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define TRIGGER_PIN_PORT_ID PORTD_ID
#define TRIGGER_PIN_PIN_ID PIN7_ID
#define ECHO_PIN_PORT_ID PORTD_ID
#define ECHO_PIN_PIN_ID PIN6_ID



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void Ultrasonic_init(void);
void Ultrasonic_Trigger(void);
uint16 Ultrasonic_readDistance(void);
void Ultrasonic_edgeProcessing(void);

#endif /* ULTRASONIC_SENSOR_H_ */
