#########################################################################################################
# $File: makefile
# $Revision: Version 1.0 $
# $Author: Carlos Martinez $
# $Date: 2025-03-23 $
#
# Descritpion:
#              This file is used to build the entire project
#########################################################################################################
# Project name:
# if no NAME argument, it will take the main project folder name as project name.
NAME =
ifeq ($(NAME),)
 PROJECT = $(notdir $(abspath ..))
else
 PROJECT = $(NAME)
endif

# Folders generated at build time.
BIN_PATH = bin
OBJ_PATH = obj
LOG_PATH = report

# Microcontroller name
DEVICE = STM32F429ZI

# Linker script file.
LINKER_SCRIP = ../settings/linker_files/stm32f429zi_ls.ld

# Target name:
TARGET = $(BIN_PATH)/$(PROJECT)

# Microcontroller Processor Architecture:
MACH = cortex-m4

# Header files paths:
INC_PATH =\
-I../inc/generic/\
-I../inc/stm32f429zi/\
-I../src/bsw/mcal/debug/inc/\
-I../src/bsw/mcal/dio/inc/\
-I../src/bsw/mcal/flash/inc/\
-I../src/bsw/mcal/gpio/\
-I../src/bsw/mcal/mcu_driver/\
-I../src/bsw/mcal/port/inc/\
-I../src/bsw/mcal/pwr/inc/\
-I../src/bsw/mcal/rcc/inc/\
-I../src/bsw/mcal/sbc/inc/\
-I../src/bsw/mcal/systick/inc/\
-I../src/bsw/hal/device_abstraction/inc/\
-I../src/bsw/hal/memory_abstraction/inc/\
-I../src/bsw/hal/IoHwAb/inc/\
-I../src/bsw/complex_drivers/usart/inc/\
-I../src/bsw/services/rtos/inc/\
-I../src/asw/led/inc/\
-I../src/asw/button/inc/\
-I../src/asw/log/inc/\
-I../src/asw/os_threads

# Source directory:
SRC_PATH = ../src
ASW_PATH = $(SRC_PATH)/asw
BSW_PATH = $(SRC_PATH)/bsw

# Log file:
LOG_FILE = $(LOG_PATH)/report.log
LOG_CMD  = 2>&1 | tee -a $(LOG_FILE)

# Compiler variables:
CC = arm-none-eabi-gcc
OC = arm-none-eabi-objcopy
OD = arm-none-eabi-objdump
SIZE = arm-none-eabi-size

#Flags
WARNS = -Wall -Werror -Wpedantic -Wno-unused-variable -Wno-unused-function -Werror-implicit-function-declaration
CFLAGS = -c -mcpu=$(MACH) -mthumb -std=gnu11

# Check if user has selected standard library integration.
STDLIB =
ifeq ($(STDLIB),Y)
    LFLAGS = -mcpu=$(MACH) -mthumb $(INC_PATH) --specs=nano.specs -T $(LINKER_SCRIP) -Wl,-Map=$(BIN_PATH)/$(PROJECT).map
	SYSCALLS = $(CC) $(CFLAGS) $(WARNS) $(INC_PATH) ../settings/sys/syscalls.c -o $(OBJ_PATH)/syscalls.o
else
    LFLAGS = -mcpu=$(MACH) -mthumb $(INC_PATH) -nostdlib -T $(LINKER_SCRIP) -Wl,-Map=$(BIN_PATH)/$(PROJECT).map
	SYSCALLS = 
endif

# Call makefiles within src/
define makeaswmodules
    for dir in $(ASW_PATH)/*;\
        do\
        make -C $$dir $(1);\
        done
endef

.PHONY: all asw bsw clean config flash init link post_build stats

all:
	@mkdir -p $(BIN_PATH)
	@mkdir -p $(LOG_PATH)
	@mkdir -p $(OBJ_PATH)
	@d=$$(gdate +%s); $(MAKE) "build" $(LOG_CMD) && echo "Building time: $$(gdate --utc --date=@$$(($$(gdate +%s)-d)) '+%H:%M:%S')" $(LOG_CMD)
	
build: init bsw asw config link post_build stats

init:
	@echo $(PROJECT) "project build date: "$(shell gdate '+%Y-%m-%d %H:%M:%S')
	@echo ''
	@echo "Building started...!"

asw:
	@echo ''
	@echo "Building ASW ...!"
	@$(call makeaswmodules,all)

bsw:
	@$(MAKE) -C $(BSW_PATH)

config:
	@echo ''
	@echo "Building configuration files ...!"
	$(CC) $(CFLAGS) $(WARNS) $(INC_PATH) ../src/main.c -o $(OBJ_PATH)/main.o
	$(CC) $(CFLAGS) $(WARNS) $(INC_PATH) ../settings/interrupts/interrupts.c -o $(OBJ_PATH)/interrupts.o
	$(CC) $(CFLAGS) $(WARNS) $(INC_PATH) ../settings/startup_code_files/stm32f429zi_startup.c -o $(OBJ_PATH)/stm32f429zi_startup.o
	$(SYSCALLS) 
	@echo ''

link:
	@echo ''
	@echo "Linking ...!"
	$(CC) $(LFLAGS) $(OBJ_PATH)/*.o -o $(TARGET)
	@echo "Linking done!!!"

post_build:
	@echo ''
	@echo "Generating binary ...! "
	$(OC) -O binary $(TARGET) $(TARGET).bin
	@echo "Binary generated!!!"

stats:
	@echo ''
	@echo "Analyzing .elf ...!"
	$(OD) -h $(TARGET)
	@echo "Analysis done!!!"
	@echo ''
	$(SIZE) $(TARGET)
	@echo ''

clean:
	@echo $(PROJECT) "project: cleaning started!"
	@rm -rf $(BIN_PATH) $(OBJ_PATH) $(LOG_PATH)
	@echo $(PROJECT) "project: succesfully cleaned!!!"
	@echo''

$(BIN_PATH)/jflash: $(TARGET).bin
	@touch $@
	@echo Device $(DEVICE) > $@
	@echo si 1'\n'Speed 4000 >> $@
	@echo loadbin $< 0x08000000 >> $@
	@echo r'\n'g'\n'qc >> $@

flash: $(BIN_PATH)/jflash
	@echo "Flashing started ...!"
	JLinkExe -commanderscript $<