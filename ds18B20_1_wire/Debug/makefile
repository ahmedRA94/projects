################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include driver/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
ds18B20\ 1\ wire.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: ds18B20\ 1\ wire.elf secondary-outputs

# Tool invocations
ds18B20\ 1\ wire.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ds18B20 1 wire.map -mmcu=atmega32 -o "ds18B20 1 wire.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ds18B20\ 1\ wire.lss: ds18B20\ 1\ wire.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ds18B20 1 wire.elf  >"ds18B20 1 wire.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ds18B20\ 1\ wire.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 ds18B20 1 wire.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) "ds18B20 1 wire.elf"
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
