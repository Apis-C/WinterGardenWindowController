################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/lib/subdir.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(I_DEPS)),)
-include $(I_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(M_DEPS)),)
-include $(M_DEPS)
endif
ifneq ($(strip $(MI_DEPS)),)
-include $(MI_DEPS)
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
WinterGardenWindowController.lss \

FLASH_IMAGE += \
WinterGardenWindowController.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: WinterGardenWindowController.elf secondary-outputs

# Tool invocations
WinterGardenWindowController.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,WinterGardenWindowController.map -mmcu=atmega16 -o "WinterGardenWindowController.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

WinterGardenWindowController.lss: WinterGardenWindowController.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S WinterGardenWindowController.elf  >"WinterGardenWindowController.lss"
	@echo 'Finished building: $@'
	@echo ' '

WinterGardenWindowController.hex: WinterGardenWindowController.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex WinterGardenWindowController.elf  "WinterGardenWindowController.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: WinterGardenWindowController.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 WinterGardenWindowController.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: WinterGardenWindowController.elf
	@echo 'Invoking: AVRDude'
	/usr/bin/avrdude -c atmelice_isp -pm16 -Uflash:w:WinterGardenWindowController.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(M_DEPS)$(MI_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(LSS)$(C_DEPS)$(FLASH_IMAGE)$(ELFS)$(I_DEPS)$(OBJS)$(ASM_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) WinterGardenWindowController.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
