################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../atmega32_gpio.c \
../atmega32_icu.c \
../atmega32_interrupt.c \
../lcd.c \
../main.c \
../ultrasonic_sensor.c 

OBJS += \
./atmega32_gpio.o \
./atmega32_icu.o \
./atmega32_interrupt.o \
./lcd.o \
./main.o \
./ultrasonic_sensor.o 

C_DEPS += \
./atmega32_gpio.d \
./atmega32_icu.d \
./atmega32_interrupt.d \
./lcd.d \
./main.d \
./ultrasonic_sensor.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


