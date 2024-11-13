/*
 * main.cpp
 *
 *  Created on: Nov 11, 2024
 *      Author: mistya
 */



//includes
#include "main.hpp"
#include "boot.hpp"
#include "gpio.hpp"

GPIO_Output* GPIO_UserLED_Red = nullptr;
GPIO_Output* GPIO_UserLED_Green = nullptr;

GPIO_Input* GPIO_UserButton = nullptr;



//main
//App entry point
int main(void) {

	if (SystemInitialize() == Fail)	{
		while (1)	{}
	}

	GPIO_UserButton = new GPIO_Input (USERBUTTON_GPIO_PORT, USERBUTTON_GPIO_PIN);
	GPIO_UserLED_Red = new GPIO_Output(USERLED_RED_GPIO_PORT, USERLED_RED_GPIO_PIN);
	GPIO_UserLED_Green = new GPIO_Output(USERLED_GREEN_GPIO_PORT, USERLED_GREEN_GPIO_PIN);



	while(1)	{

		if (GPIO_UserButton ->readState()) {
				GPIO_UserLED_Red->on();
				GPIO_UserLED_Green->off();
				HAL_Delay(500);
				GPIO_UserLED_Red->off();
				GPIO_UserLED_Green->on();
				HAL_Delay(500);
			}	else {
				GPIO_UserLED_Green->on();
				GPIO_UserLED_Red->on();
			}
		}

	return 0;
}

