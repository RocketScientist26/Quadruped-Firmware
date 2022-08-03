################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/App/Device/bluetooth.c \
../Src/App/Device/button.c \
../Src/App/Device/flash.c \
../Src/App/Device/general.c \
../Src/App/Device/interrupts.c \
../Src/App/Device/led.c \
../Src/App/Device/servo.c 

OBJS += \
./Src/App/Device/bluetooth.o \
./Src/App/Device/button.o \
./Src/App/Device/flash.o \
./Src/App/Device/general.o \
./Src/App/Device/interrupts.o \
./Src/App/Device/led.o \
./Src/App/Device/servo.o 

C_DEPS += \
./Src/App/Device/bluetooth.d \
./Src/App/Device/button.d \
./Src/App/Device/flash.d \
./Src/App/Device/general.d \
./Src/App/Device/interrupts.d \
./Src/App/Device/led.d \
./Src/App/Device/servo.d 


# Each subdirectory must supply rules for building sources it contributes
Src/App/Device/%.o Src/App/Device/%.su: ../Src/App/Device/%.c Src/App/Device/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-App-2f-Device

clean-Src-2f-App-2f-Device:
	-$(RM) ./Src/App/Device/bluetooth.d ./Src/App/Device/bluetooth.o ./Src/App/Device/bluetooth.su ./Src/App/Device/button.d ./Src/App/Device/button.o ./Src/App/Device/button.su ./Src/App/Device/flash.d ./Src/App/Device/flash.o ./Src/App/Device/flash.su ./Src/App/Device/general.d ./Src/App/Device/general.o ./Src/App/Device/general.su ./Src/App/Device/interrupts.d ./Src/App/Device/interrupts.o ./Src/App/Device/interrupts.su ./Src/App/Device/led.d ./Src/App/Device/led.o ./Src/App/Device/led.su ./Src/App/Device/servo.d ./Src/App/Device/servo.o ./Src/App/Device/servo.su

.PHONY: clean-Src-2f-App-2f-Device

