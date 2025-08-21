/*
 * Module: LED Driver
 *
 * File Name: LED.c
 *

 *
 * Author: Eman Sayed Hamdy
 */
#include"LED.h"
#include"gpio.h"
/********************* FUNCTION DEFINITION*********************/
void LEDS_init(void){
/*
 * Initializes all Leds (red, green, blue) pins direction.
   Turn off all the Leds
 * */
	GPIO_setupPinDirection(PORTC_ID,PIN0_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTC_ID,PIN1_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTC_ID,PIN2_ID,PIN_OUTPUT);
#if(LED_STATE == LED_POSITIVE_LOGIC)
	GPIO_writePin(PORTC_ID,PIN0_ID,LOGIC_LOW);
	GPIO_writePin(PORTC_ID,PIN1_ID,LOGIC_LOW);
	GPIO_writePin(PORTC_ID,PIN2_ID,LOGIC_LOW);
#else
	// IF LEDSTATE == LED_NEGITIVE_LOGIC
	GPIO_writePin(PORTC_ID,PIN0_ID,LOGIC_HIGH);
	GPIO_writePin(PORTC_ID,PIN1_ID,LOGIC_HIGH);
	GPIO_writePin(PORTC_ID,PIN2_ID,LOGIC_HIGH);
#endif
}
void LED_on(uint8 LED_ID_id) {
	//Turns on the specified LED.
#if(LED_STATE == LED_NEGITIVE_LOGIC)
	//LED connect NEGITIVE logic
	GPIO_writePin(PORTC_ID,LED_ID_id,LOGIC_LOW);
#elif(LED_STATE == LED_POSITIVE_LOGIC)
	//LED is connect Positive Logic
	GPIO_writePin(PORTC_ID,LED_ID_id,LOGIC_HIGH);
#endif

}
void LED_off(uint8 LED_ID_id) {
//Turns off the specified LED.
#if(LED_STATE == LED_NEGITIVE_LOGIC)
	//LED connect NEGITIVE logic
	GPIO_writePin(PORTC_ID,LED_ID_id,LOGIC_HIGH);
#elif(LED_STATE == LED_POSITIVE_LOGIC)
	//LED is connect Positive Logic
	GPIO_writePin(PORTC_ID,LED_ID_id,LOGIC_LOW);
#endif
}
