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
ds18B20_1_wire.lss \

FLASH_IMAGE += \
ds18B20_1_wire.hex \

EEPROM_IMAGE += \
ds18B20_1_wire.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: ds18B20_1_wire.elf secondary-outputs

# Tool invocations
ds18B20_1_wire.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ds18B20_1_wire.map -mmcu=atmega32 -o "ds18B20_1_wire.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ds18B20_1_wire.lss: ds18B20_1_wire.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ds18B20_1_wire.elf  >"ds18B20_1_wire.lss"
	@echo 'Finished building: $@'
	@echo ' '

ds18B20_1_wire.hex: ds18B20_1_wire.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex ds18B20_1_wire.elf  "ds18B20_1_wire.hex"
	@echo 'Finished building: $@'
	@echo ' '

ds18B20_1_wire.eep: ds18B20_1_wire.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex ds18B20_1_wire.elf  "ds18B20_1_wire.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ds18B20_1_wire.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 ds18B20_1_wire.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ds18B20_1_wire.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
