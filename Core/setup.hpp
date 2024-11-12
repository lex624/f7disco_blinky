/*
 * setup.hpp
 *
 *  Created on: Nov 11, 2024
 *      Author: mistya
 */

#ifndef STARTUP_SETUP_HPP_
#define STARTUP_SETUP_HPP_


//Includes
#include "stm32f7xx.h"
#include "stm32f7xx_hal.h"


//
//enum Result : uint8_t {
//	OK = 0,
//	Fail = 1
//};

enum Result : uint8_t {
	OK = 0,                   //Function has succeeded
	Fail,                     //Function has failed, with a non-specific error
	Error_PeriphBusy,         //Function has not been able to initialize a particular peripheral as the peripheral is busy
	Error_PeriphNotSupported  //Function has not been able to initialize a particular peripheral as the peripheral doesn't support the required functionality
};

//-----------------------------
//GPIO Definitions

#define USERLED_RED_GPIO_PORT       GPIOJ
#define USERLED_RED_GPIO_PIN        GPIO_PIN_13  // J13

#define USERLED_GREEN_GPIO_PORT     GPIOJ
#define USERLED_GREEN_GPIO_PIN      GPIO_PIN_5   // J5

#define USERBUTTON_GPIO_PORT        GPIOA
#define USERBUTTON_GPIO_PIN         GPIO_PIN_0   // A0






#endif /* STARTUP_SETUP_HPP_ */
