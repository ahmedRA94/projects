################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../driver/I2C\ MASTER.c \
../driver/lcd_4bit.c 

OBJS += \
./driver/I2C\ MASTER.o \
./driver/lcd_4bit.o 

C_DEPS += \
./driver/I2C\ MASTER.d \
./driver/lcd_4bit.d 


# Each subdirectory must supply rules for building sources it contributes
driver/I2C\ MASTER.o: ../driver/I2C\ MASTER.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"driver/I2C MASTER.d" -MT"driver/I2C\ MASTER.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

driver/%.o: ../driver/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


