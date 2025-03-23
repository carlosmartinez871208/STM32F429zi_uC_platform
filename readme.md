# STM32F429ZI platform development.

## Architecture

### build: this folder contains:

1. **obj**: all relocatable object files from project are stored here.

2. **bin**: elf, bin and hex files are stored here.

3. **makefile**: this is used to build entire project. makefile will create obj and bin folders during build process.

### doc: contains microcontroller documentation and templates for src files and header files.

1. stm32f429zi: datasheet, reference manual.

2. templates: templates for source code and header files.

> 2.1 template.c: use this template for all your source code (just change the name).

> 2.2 template.h: use this template for all your header files (just change the name).

### inc: include .h files required by the project. 

1. **stm32f429zi**: contains all libraries from microcontroller used by the project.

2. **generic**: contains generic .h files used by the project.

### settings: contains startup file and linker script.

1. linker_files

2. startup_code_files

### src: contains all source code.

1. **bsw**: contains basic software.

> 1.1 **mcal**: microcontroller abstraction layer.

>> 1.1.1 **lld**: low level drivers.

> 1.2 **hal**: hardware abstraction layer.

> 1.3 **services**: contains all services.

> 1.4 **complex_drivers**: contanis different drivers used by the application.

2. **rte**: this is a wrapper between bsw and asw. 

3. **asw**: contains application software.

**Project structure** looks as follows:

    .
    ├── build
    │   └── makefile
    ├── doc
    │   ├── stm32f429zi
    │   │   ├── 32f429idiscovery.pdf
    │   │   ├── STM32F427XX.PDF
    │   │   ├── dm00031020-stm32f405-415-stm32f407-417-stm32f427-437-and-stm32f429-439-advanced-arm-based-32-bit-mcus-stmicroelectronics.pdf
    │   │   └── um1670-discovery-kit-with-stm32f429zi-mcu-stmicroelectronics.pdf
    │   └── templates
    │       ├── template.c
    │       └── template.h
    ├── inc
    │   ├── generic
    │   └── stm32f429zi
    ├── readme.md
    ├── settings
    │   ├── linker_files
    │   └── startup_code_files
    └── src
        ├── asw
        ├── bsw
        │   ├── complex_drivers
        │   ├── hal
        │   ├── mcal
        │   │   └── lld
        │   └── services
        ├── main.c
        └── rte