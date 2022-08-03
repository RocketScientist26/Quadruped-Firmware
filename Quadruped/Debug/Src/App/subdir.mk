################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/App/anim_data.c \
../Src/App/animation.c \
../Src/App/app.c \
../Src/App/parser.c \
../Src/App/settings.c 

OBJS += \
./Src/App/anim_data.o \
./Src/App/animation.o \
./Src/App/app.o \
./Src/App/parser.o \
./Src/App/settings.o 

C_DEPS += \
./Src/App/anim_data.d \
./Src/App/animation.d \
./Src/App/app.d \
./Src/App/parser.d \
./Src/App/settings.d 


# Each subdirectory must supply rules for building sources it contributes
Src/App/%.o Src/App/%.su: ../Src/App/%.c Src/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-App

clean-Src-2f-App:
	-$(RM) ./Src/App/anim_data.d ./Src/App/anim_data.o ./Src/App/anim_data.su ./Src/App/animation.d ./Src/App/animation.o ./Src/App/animation.su ./Src/App/app.d ./Src/App/app.o ./Src/App/app.su ./Src/App/parser.d ./Src/App/parser.o ./Src/App/parser.su ./Src/App/settings.d ./Src/App/settings.o ./Src/App/settings.su

.PHONY: clean-Src-2f-App

