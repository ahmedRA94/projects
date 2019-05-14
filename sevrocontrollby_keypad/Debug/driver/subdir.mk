################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../driver/ADC\ LIB.c \
../driver/keypad.c 

OBJS += \
./driver/ADC\ LIB.o \
./driver/keypad.o 

C_DEPS += \
./driver/ADC\ LIB.d \
./driver/keypad.d 


# Each subdirectory must supply rules for building sources it contributes
driver/ADC\ LIB.o: ../driver/ADC\ LIB.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"driver/ADC LIB.d" -MT"driver/ADC\ LIB.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

driver/%.o: ../driver/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


