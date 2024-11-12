/*
 * handler.cpp
 *
 *  Created on: Nov 11, 2024
 *      Author: mistya
 */


//includes
#include "handler.hpp"
#include "stm32f7xx_hal.h"


void  NMI_Handler(void) {
	while(1)	{}
}

void  HardFault_Handler(void) {
	while(1)	{}
}

void  MemManage_Handler(void) {

}

void  BusFault_Handler(void) {
	while(1)	{}
}

void  UsageFault_Handler(void) {
	while(1)	{}
}

void  SVC_Handler(void) {
//	while(1)	{}
}

void  DebugMon_Handler(void) {
//	while(1)	{}
}

void  PendSV_Handler(void) {
//	while(1)	{}
}

void  SysTick_Handler(void) {
	HAL_IncTick();
}
