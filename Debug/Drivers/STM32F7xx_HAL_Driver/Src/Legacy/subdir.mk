################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/STM32F7xx_HAL_Driver/Src/Legacy/stm32f7xx_hal_can.c \
../Drivers/STM32F7xx_HAL_Driver/Src/Legacy/stm32f7xx_hal_eth.c 

C_DEPS += \
./Drivers/STM32F7xx_HAL_Driver/Src/Legacy/stm32f7xx_hal_can.d \
./Drivers/STM32F7xx_HAL_Driver/Src/Legacy/stm32f7xx_hal_eth.d 

OBJS += \
./Drivers/STM32F7xx_HAL_Driver/Src/Legacy/stm32f7xx_hal_can.o \
./Drivers/STM32F7xx_HAL_Driver/Src/Legacy/stm32f7xx_hal_eth.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STM32F7xx_HAL_Driver/Src/Legacy/%.o Drivers/STM32F7xx_HAL_Driver/Src/Legacy/%.su Drivers/STM32F7xx_HAL_Driver/Src/Legacy/%.cyclo: ../Drivers/STM32F7xx_HAL_Driver/Src/Legacy/%.c Drivers/STM32F7xx_HAL_Driver/Src/Legacy/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F769xx -c -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Core -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-STM32F7xx_HAL_Driver-2f-Src-2f-Legacy

clean-Drivers-2f-STM32F7xx_HAL_Driver-2f-Src-2f-Legacy:
	-$(RM) ./Drivers/STM32F7xx_HAL_Driver/Src/Legacy/stm32f7xx_hal_can.cyclo ./Drivers/STM32F7xx_HAL_Driver/Src/Legacy/stm32f7xx_hal_can.d ./Drivers/STM32F7xx_HAL_Driver/Src/Legacy/stm32f7xx_hal_can.o ./Drivers/STM32F7xx_HAL_Driver/Src/Legacy/stm32f7xx_hal_can.su ./Drivers/STM32F7xx_HAL_Driver/Src/Legacy/stm32f7xx_hal_eth.cyclo ./Drivers/STM32F7xx_HAL_Driver/Src/Legacy/stm32f7xx_hal_eth.d ./Drivers/STM32F7xx_HAL_Driver/Src/Legacy/stm32f7xx_hal_eth.o ./Drivers/STM32F7xx_HAL_Driver/Src/Legacy/stm32f7xx_hal_eth.su

.PHONY: clean-Drivers-2f-STM32F7xx_HAL_Driver-2f-Src-2f-Legacy

