MACH = cortex-m4

SRC_DIR = src
OBJ_DIR = ../../../../build/obj

SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

INCLUDES =\
-Iinc/\
-I../../../../inc/generic/\
-I../../../../inc/stm32f429zi/\
-I../../mcal/mcu_driver/\
-I../../mcal/pwr/inc/\
-I../../mcal/rcc/inc/

# Flags:
CC = arm-none-eabi-gcc
WARNS = -Wall -Werror -Wpedantic -Wno-unused-variable -Wno-unused-function -Werror-implicit-function-declaration
CFLAGS = -c -mcpu=$(MACH) -mthumb -std=gnu11

all:
	@echo "Building module: device abstraction."
	$(CC) $(CFLAGS) $(WARNS) $(INCLUDES) $(SOURCES) -o $(OBJECTS)

.PHONY: all