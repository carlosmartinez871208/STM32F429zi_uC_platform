MACH = cortex-m4

SRC_DIR = src
OBJ_DIR = ../../../../build/obj

SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

INCLUDES =\
-Iinc/\
-I../../../../inc/generic/\
-I../../../../inc/stm32f429zi/\
-I../../mcal/flash/inc/\
-I../../mcal/port/inc/\
-I../../mcal/dio/inc\
-I../../mcal/gpio/

# Flags:
CC = arm-none-eabi-gcc
WARNS = -Wall -Werror -Wpedantic -Wno-unused-variable -Wno-unused-function -Werror-implicit-function-declaration
CFLAGS = -c -mcpu=$(MACH) -mthumb -std=gnu11 -g

all:
	@echo "Building module: Input/Output hardware abstraction."
	$(CC) $(CFLAGS) $(WARNS) $(INCLUDES) $(SOURCES) -o $(OBJECTS)

.PHONY: all