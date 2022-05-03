################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/App/app.c \
../Src/App/bluetooth.c \
../Src/App/flash.c \
../Src/App/general.c \
../Src/App/led.c \
../Src/App/movements.c \
../Src/App/servo.c \
../Src/App/settings.c 

OBJS += \
./Src/App/app.o \
./Src/App/bluetooth.o \
./Src/App/flash.o \
./Src/App/general.o \
./Src/App/led.o \
./Src/App/movements.o \
./Src/App/servo.o \
./Src/App/settings.o 

C_DEPS += \
./Src/App/app.d \
./Src/App/bluetooth.d \
./Src/App/flash.d \
./Src/App/general.d \
./Src/App/led.d \
./Src/App/movements.d \
./Src/App/servo.d \
./Src/App/settings.d 


# Each subdirectory must supply rules for building sources it contributes
Src/App/%.o Src/App/%.su: ../Src/App/%.c Src/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-App

clean-Src-2f-App:
	-$(RM) ./Src/App/app.d ./Src/App/app.o ./Src/App/app.su ./Src/App/bluetooth.d ./Src/App/bluetooth.o ./Src/App/bluetooth.su ./Src/App/flash.d ./Src/App/flash.o ./Src/App/flash.su ./Src/App/general.d ./Src/App/general.o ./Src/App/general.su ./Src/App/led.d ./Src/App/led.o ./Src/App/led.su ./Src/App/movements.d ./Src/App/movements.o ./Src/App/movements.su ./Src/App/servo.d ./Src/App/servo.o ./Src/App/servo.su ./Src/App/settings.d ./Src/App/settings.o ./Src/App/settings.su

.PHONY: clean-Src-2f-App

