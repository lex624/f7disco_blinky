/*
 * handler.hpp
 *
 *  Created on: Nov 11, 2024
 *      Author: mistya
 */

#ifndef HANDLER_HPP
#define HANDLER_HPP


//includes
#include "setup.hpp"

//code startes executing from an entry point allowig for system erros and handling system tick. (where the processor can jump to based on hardware trigger)
//linker will be looking for C functions when build is run so use extern to C here
//all the startup is defined in the .s files for when the build process begins (machine code)
extern "C"	{

//trigers when the certain errors like accessing the wrong memory location or when theres a pointer to a class that is currently null
//---------------------------
//Exception Handler Functions

void  NMI_Handler(void);
void  HardFault_Handler(void);
void  MemManage_Handler(void);
void  BusFault_Handler(void);
void  UsageFault_Handler(void);
void  SVC_Handler(void);
void  DebugMon_Handler(void);
void  PendSV_Handler(void);
void  SysTick_Handler(void);


}


#endif /* STARTUP_Handler_HPP_ */
