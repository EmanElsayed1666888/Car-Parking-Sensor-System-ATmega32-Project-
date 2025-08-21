/*
 * Module: Application
 *
 * File Name: application.c
 *
 *
 * Author: Eman Sayed Hamdy
 */
/********************* INCLUDES LIBRARY*********************/
#include"LCD_driver.h"
#include"LED.h"
#include"icu.h"
#include"UltraSonic.h"
#include"Buzzer.h"
#include<util/delay.h>
#include <avr/io.h>


int main(){
	SREG |= (1<<7);
	LCD_init();
	Buzzer_init();
	LEDS_init();
	Ultrasonic_init();
	uint16 distance_of_Object_cm =0 ;
	LCD_displayString("Distance=   CM");

	while(1){
		/** Read the distance from the ultrasonic sensor **/
		distance_of_Object_cm = Ultrasonic_readDistance();
		if (distance_of_Object_cm > 100)
		{
			/** If the distance is more than 100 cm, display it directly**/
			LCD_MOVE_Cursor(0,9);
			LCD_Intger_TO_String(distance_of_Object_cm);
		}
		else
		{
			LCD_MOVE_Cursor(0,9);
			LCD_Intger_TO_String(distance_of_Object_cm);
			// Clear the next character on the LCD if present
			LCD_displayCharacter(' ');
		}
		//Check for dangerous proximity (distance <= 5 cm)
		if(distance_of_Object_cm <= 5 ){
			Buzzer_on();
			LCD_Display_String_ROW_COL(1, 6 , "Stop");
			//Keep blinking the LEDs and refreshing the distance until the obstacle is removed
			while(distance_of_Object_cm <= 5){
				distance_of_Object_cm = Ultrasonic_readDistance();
				LCD_MOVE_Cursor(0,9);
				LCD_Intger_TO_String(distance_of_Object_cm);
				LED_on(PIN0_ID);//LED RED
				LED_on(PIN1_ID);//LED GREEN
				LED_on(PIN2_ID);//LED BLUE
				_delay_ms(200);
				LED_off(PIN0_ID);
				LED_off(PIN1_ID);
				LED_off(PIN2_ID);
				_delay_ms(200);
			}
			/* Once the distance is safe, turn off the buzzer and LEDs */
			Buzzer_off();
			LED_off(PIN0_ID);
			LED_off(PIN1_ID);
			LED_off(PIN2_ID);
			/* Clear the STOP message on the LCD */
			LCD_Display_String_ROW_COL(1, 0 , "                ");

		}
		//IF Distance between 6 and 10 cm
		else if((distance_of_Object_cm <= 6)||(distance_of_Object_cm <= 10) ){
			LED_on(PIN0_ID);
			LED_on(PIN1_ID);
			LED_on(PIN2_ID);
		}
		//IF Distance between 11 and 15 cm
		else if((distance_of_Object_cm <= 11)||(distance_of_Object_cm <= 15)){

			LED_on(PIN0_ID);
			LED_on(PIN1_ID);
			LED_off(PIN2_ID);
		}
		//IF Distance between 16 and 20 cm
		else if((distance_of_Object_cm <= 16)||(distance_of_Object_cm <= 20)){

			LED_on(PIN0_ID);
			LED_off(PIN1_ID);
			LED_off(PIN2_ID);
		}
		// Distance more than 20 cm
		else{
			LED_off(PIN0_ID);
			LED_off(PIN1_ID);
			LED_off(PIN2_ID);
		}
		/* Add a small delay for stability */
		_delay_ms(100);
	}
}

