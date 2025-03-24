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

# Linker script file.
LINKER_SCRIP = ../settings/linker_files/stm32f429zi_ls.ld

# Target name:
TARGET = $(BIN_PATH)/$(PROJECT)

# Microcontroller Processor Architecture:
MACH = cortex-m4

# Header files paths:
INC_PATH =\
-I../inc/generic/\
-I../stm32f429zi/

# Source directory:
SRC_PATH = ../src

# Log file:
LOG_FILE = $(LOG_PATH)/report.log
LOG_CMD  = 2>&1 | tee -a $(LOG_FILE)

# Call source files within folders:
define makeallmodules
    for dir in $(SRC_PATH)/*;\
        do\
        make -C $$dir $(1);\
        done
endef

# Flags:
CC = arm-none-eabi-gcc
WARNS = -Wall -Werror -Wpedantic -Wno-unused-variable -Wno-unused-function -Werror-implicit-function-declaration
CFLAGS = -c -mcpu=$(MACH) -mthumb -std=gnu11

# Check if user has selected standard library integration.
STDLIB =
ifeq ($(STDLIB),Y)
    LFLAGS = -mcpu=$(MACH) -mthumb $(INC_PATH) --specs=nano.specs -T $(LINKER_SCRIP)
	SYSCALLS = $(CC) $(CFLAGS) $(WARNS) $(INC_PATH) ../settings/sys/syscalls.c -o $(OBJ_PATH)/syscalls.o
else
    LFLAGS = -mcpu=$(MACH) -mthumb $(INC_PATH) -nostdlib -T $(LINKER_SCRIP)
	SYSCALLS = 
endif

.PHONY: all build clean link_build post_build start_build

all:
	@mkdir -p $(BIN_PATH)
	@mkdir -p $(LOG_PATH)
	@mkdir -p $(OBJ_PATH)
	@d=$$(date +%s); $(MAKE) "build" $(LOG_CMD) && echo "Building time: $$(date --utc --date=@$$(($$(date +%s)-d)) '+%H:%M:%S')" $(LOG_CMD)
	
build: start_build link_build post_build

start_build:
	@echo $(PROJECT) "project build date: "$(shell date '+%Y-%m-%d %H:%M:%S')
	@echo ''
	@echo $(PROJECT) "project: building started..."
	$(CC) $(CFLAGS) $(WARNS) $(INC_PATH) ../src/main.c -o $(OBJ_PATH)/main.o
	$(CC) $(CFLAGS) $(WARNS) $(INC_PATH) ../settings/startup_code_files/stm32f429zi_startup.c -o $(OBJ_PATH)/stm32f429zi_startup.o
	$(SYSCALLS) 
	@echo''
	@$(call makeallmodules,all)
	@echo "Building done!!!"
	@echo''

link_build:


post_build:


clean:
	@echo $(PROJECT) "project: cleaning started!"
	@rm -rf $(BIN_PATH) $(OBJ_PATH) $(LOG_PATH)
	@echo $(PROJECT) "project: succesfully cleaned!!!"
	@echo''

