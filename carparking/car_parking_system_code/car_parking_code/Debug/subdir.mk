################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Buzzer.c \
../LCD_driver.c \
../LED.c \
../UltraSonic.c \
../application.c \
../gpio.c \
../icu.c 

OBJS += \
./Buzzer.o \
./LCD_driver.o \
./LED.o \
./UltraSonic.o \
./application.o \
./gpio.o \
./icu.o 

C_DEPS += \
./Buzzer.d \
./LCD_driver.d \
./LED.d \
./UltraSonic.d \
./application.d \
./gpio.d \
./icu.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


