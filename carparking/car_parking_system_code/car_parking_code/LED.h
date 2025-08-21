/*
 * Module: LED Driver
 *
 * File Name: LED.h
 *
 *
 * Author: Eman Sayed Hamdy
 */

#ifndef LED_H_
#define LED_H_
#include "std_types.h"
#define  LED_STATE LOGIC_HIGH


#define LED_POSITIVE_LOGIC LOGIC_HIGH
#define LED_NEGITIVE_LOGIC LOGIC_LOW

void LEDS_init(void) ;
void LED_on(uint8 LED_ID_id) ;
void LED_off(uint8 LED_ID_id) ;
#endif /* LED_H_ */
