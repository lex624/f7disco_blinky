################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Device_Drivers/GPIO.cpp 

OBJS += \
./Device_Drivers/GPIO.o 

CPP_DEPS += \
./Device_Drivers/GPIO.d 


# Each subdirectory must supply rules for building sources it contributes
Device_Drivers/%.o Device_Drivers/%.su Device_Drivers/%.cyclo: ../Device_Drivers/%.cpp Device_Drivers/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F769xx -c -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Core -I../Device_Drivers -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Device_Drivers

clean-Device_Drivers:
	-$(RM) ./Device_Drivers/GPIO.cyclo ./Device_Drivers/GPIO.d ./Device_Drivers/GPIO.o ./Device_Drivers/GPIO.su

.PHONY: clean-Device_Drivers

