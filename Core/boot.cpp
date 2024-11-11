/*
 * boot.cpp
 *
 *  Created on: Nov 11, 2024
 *      Author: mistya
 */



//includes
#include "boot.hpp"


//system initialization
Result SystemInitialiize(void)	{

	    // Enable CPU Instruction & Data Caches
	    SCB_EnableICache();
	    SCB_EnableDCache();

	    // Enable ART Accelerator - allows cpu to more easily access data in the flash
	    __HAL_FLASH_ART_ENABLE();

	    // Enable Flash Prefetch - allows quick flow of cpu instructions
	    __HAL_FLASH_PREFETCH_BUFFER_ENABLE();

	    // Set NVIC Priority Grouping
	    HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

	    // Init SysTick
	    HAL_InitTick(TICK_INT_PRIORITY);

	    // Configure LSE Drive Capability - used for RTC
	    HAL_PWR_EnableBkUpAccess();
	    __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);

	    // Configure Main Internal Regulator Output Voltage
	    __HAL_RCC_PWR_CLK_ENABLE();
	    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	    // Enable Clock Sources and Setup
	    RCC_OscInitTypeDef RCC_OscInit = {0};
	    RCC_OscInit.OscillatorType = RCC_OSCILLATORTYPE_HSE | RCC_OSCILLATORTYPE_LSE;
	    RCC_OscInit.HSEState = RCC_HSE_ON;
	    RCC_OscInit.LSEState = RCC_LSE_ON;
	    RCC_OscInit.PLL.PLLState = RCC_PLL_ON;
	    RCC_OscInit.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	    RCC_OscInit.PLL.PLLM = 25;
	    RCC_OscInit.PLL.PLLN = 432;
	    RCC_OscInit.PLL.PLLP = RCC_PLLP_DIV2;
	    RCC_OscInit.PLL.PLLQ = 4;
	    if (HAL_RCC_OscConfig(&RCC_OscInit) != HAL_OK) {
	        return Fail;
	    }

	    //Enable system config clock
	    __HAL_RCC_SYSCFG_CLK_ENABLE();

	    //Enable overdrive mode
	    if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
	    	return Fail;
	    }

	    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
	    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
	        return Fail;
	    }

	    //-----------------------------
	    // Initialize Peripheral Clocks
	    RCC_PeriphCLKInitTypeDef RCC_PeriphClkInit = {0};
	    RCC_PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_RTC | RCC_PERIPHCLK_LTDC | RCC_PERIPHCLK_USART1;

	    // NOTE: PLL SAI is also used for LTDC
	    RCC_PeriphClkInit.PLLSAI.PLLSAIN = 384;
	    RCC_PeriphClkInit.PLLSAI.PLLSAIP = RCC_PLLSAIP_DIV8;
	    RCC_PeriphClkInit.PLLSAI.PLLSAIR = 7;
	    RCC_PeriphClkInit.PLLSAI.PLLSAIQ = 8;
	    RCC_PeriphClkInit.PLLSAIDivQ = 1;
	    RCC_PeriphClkInit.PLLSAIDivR = RCC_PLLSAIDIVR_2;

	    RCC_PeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSE;
	    RCC_PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK2;

	    if (HAL_RCCEx_PeriphCLKConfig(&RCC_PeriphClkInit) != HAL_OK) {
	        return Fail;
	    }


	    //-----------------------------
	    // Enable GPIO Clocks
	    __HAL_RCC_GPIOA_CLK_ENABLE();
	    __HAL_RCC_GPIOB_CLK_ENABLE();
	    __HAL_RCC_GPIOC_CLK_ENABLE();
	    __HAL_RCC_GPIOD_CLK_ENABLE();
	    __HAL_RCC_GPIOE_CLK_ENABLE();
	    __HAL_RCC_GPIOF_CLK_ENABLE();
	    __HAL_RCC_GPIOG_CLK_ENABLE();
	    __HAL_RCC_GPIOH_CLK_ENABLE();
	    __HAL_RCC_GPIOI_CLK_ENABLE();
	    __HAL_RCC_GPIOJ_CLK_ENABLE();
	    __HAL_RCC_GPIOK_CLK_ENABLE();

	    //-----------------------------
	    // Enable DMA Clocks
	    __HAL_RCC_DMA1_CLK_ENABLE();
	    __HAL_RCC_DMA2_CLK_ENABLE();

	    return OK;
}


