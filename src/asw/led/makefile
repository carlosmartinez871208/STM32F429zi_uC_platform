MACH = cortex-m4

SRC_DIR = src
OBJ_DIR = ../../../build/obj

SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

INCLUDES =\
-Iinc/\
-I../../../inc/generic/\
-I../../../inc/stm32f429zi\
-I../../rte/\
-I../../bsw/hal/device_abstraction/inc/\
-I../../bsw/hal/IoHwAb/inc/\
-I../../bsw/mcal/mcu_driver/\
-I../../bsw/mcal/pwr/inc/\
-I../../bsw/mcal/rcc/inc/\
-I../../bsw/mcal/port/inc/\
-I../../bsw/mcal/dio/inc/\
-I../../bsw/mcal/gpio

# Flags:
CC = arm-none-eabi-gcc
WARNS = -Wall -Werror -Wpedantic -Wno-unused-variable -Wno-unused-function -Werror-implicit-function-declaration
CFLAGS = -c -mcpu=$(MACH) -mthumb -std=gnu11 -g

all:
	@echo "Building module: LED."
	$(CC) $(CFLAGS) $(WARNS) $(INCLUDES) $(SOURCES) -o $(OBJECTS)

.PHONY: all