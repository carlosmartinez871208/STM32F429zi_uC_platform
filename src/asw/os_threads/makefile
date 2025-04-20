MACH = cortex-m4

SRC_DIR := src
OBJ_DIR  = ../../../build/obj

SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

INCLUDES =\
-I../../../inc/generic/\
-I../../../inc/stm32f429zi/\
-I../../bsw/mcal/debug/inc/\
-I../../bsw/mcal/dio/inc/\
-I../../bsw/mcal/flash/inc/\
-I../../bsw/mcal/gpio/\
-I../../bsw/mcal/mcu_driver/\
-I../../bsw/mcal/port/inc/\
-I../../bsw/mcal/pwr/inc/\
-I../../bsw/mcal/rcc/inc/\
-I../../bsw/mcal/sbc/inc/\
-I../../bsw/mcal/systick/inc/\
-I../../bsw/hal/device_abstraction/inc/\
-I../../bsw/hal/memory_abstraction/inc/\
-I../../bsw/hal/IoHwAb/inc/\
-I../../bsw/complex_drivers/usart/inc/\
-I../../bsw/services/rtos/inc/

# Flags:
CC = arm-none-eabi-gcc
WARNS = -Wall -Werror -Wpedantic -Wno-unused-variable -Wno-unused-function -Werror-implicit-function-declaration
CFLAGS = -c -mcpu=$(MACH) -mthumb -std=gnu11 -g

all: intro $(OBJECTS)

intro:
	@echo "Building module: OS threads."

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(WARNS) $(INCLUDES) $< -o $@

.PHONY: all intro