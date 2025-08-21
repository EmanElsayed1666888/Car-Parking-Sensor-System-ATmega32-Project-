/*
 * Module: buzzer Driver
 *
 * File Name: Buzzer.c
 *
 *
 * Author:Eman Sayed Hamdy
 */
#include"Buzzer.h"
#include"gpio.h"
void Buzzer_init(void){
//Initializes the buzzer pin direction and turn off the buzzer.
	GPIO_setupPinDirection(PORTC_ID , PIN5_ID , PIN_OUTPUT);
}
void Buzzer_on(void){
//Activates the buzzer.
	GPIO_writePin(PORTC_ID,PIN5_ID,LOGIC_HIGH);
}
void Buzzer_off(void){
	//Deactivates the buzzer.
	GPIO_writePin(PORTC_ID,PIN5_ID,LOGIC_LOW);
}

