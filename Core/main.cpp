/*
 * main.cpp
 *
 *  Created on: Nov 11, 2024
 *      Author: mistya
 */



//includes
#include "main.hpp"
#include "boot.hpp"

// GPIO initialization for the LEDs
void LED_Init(void) {
	  __HAL_RCC_GPIOJ_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // Configure Red LED pin
    GPIO_InitStruct.Pin = USERLED_RED_GPIO_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(USERLED_RED_GPIO_PORT, &GPIO_InitStruct);

    // Configure Green LED pin
    GPIO_InitStruct.Pin = USERLED_GREEN_GPIO_PIN;
    HAL_GPIO_Init(USERLED_GREEN_GPIO_PORT, &GPIO_InitStruct);
}


// Toggle Red LED
void Toggle_Red_LED(void) {
    HAL_GPIO_TogglePin( USERLED_RED_GPIO_PORT, USERLED_RED_GPIO_PIN);
}

// Toggle Green LED
void Toggle_Green_LED(void) {
    HAL_GPIO_TogglePin( USERLED_GREEN_GPIO_PORT, USERLED_GREEN_GPIO_PIN);
}

// Turn Red LED On
void Red_LED_On(void) {
    HAL_GPIO_WritePin(USERLED_RED_GPIO_PORT, USERLED_RED_GPIO_PIN, GPIO_PIN_SET);
}

// Turn Red LED Off
void Red_LED_Off(void) {
    HAL_GPIO_WritePin(USERLED_RED_GPIO_PORT, USERLED_RED_GPIO_PIN, GPIO_PIN_RESET);
}

// Turn Green LED On
void Green_LED_On(void) {
    HAL_GPIO_WritePin(USERLED_GREEN_GPIO_PORT, USERLED_GREEN_GPIO_PIN, GPIO_PIN_SET);
}

// Turn Green LED Off
void Green_LED_Off(void) {
    HAL_GPIO_WritePin(USERLED_GREEN_GPIO_PORT, USERLED_GREEN_GPIO_PIN, GPIO_PIN_RESET);
}


//main
//App entry point
int main(void) {

	if (SystemInitialize() == Fail)	{
		while (1)	{}
	}

	LED_Init();

	while(1)	{

		uint32_t timer;

		        Red_LED_On();
		        Green_LED_Off();

		        timer=0;
		        while (	timer < 10000)	{ timer++; }

		        // Turn Red LED Off, Green LED On
		        Red_LED_Off();
		        Green_LED_On();

		        timer=0;
		        while (	timer < 10000)	{ timer++; }
	}

	return 0;
}

