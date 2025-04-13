# STM32F429ZI platform development.

## Architecture

### build: this folder contains:

1. **obj**: all relocatable object files from project are stored here.

2. **bin**: elf, bin and hex files are stored here.

3. **makefile**: this is used to build entire project. makefile will create obj and bin folders during build process.

4. **report**: this folder contains Map files and compilation logs.

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
    │   │   └── Std_types.h
    │   └── stm32f429zi
    ├── readme.md
    ├── settings
    │   ├── linker_files
    │   │   └── stm32f429zi_ls.ld
    │   ├── startup_code_files
    │   │   └── stm32f429zi_startup.c
    │   └── sys
    │       └── syscalls.c
    └── src
    ├── asw
        │   └── module
        │       ├── inc
        │       │   └── aswmod.h
        │       ├── makefile
        │       └── src
        │           └── awsmod.c
        ├── bsw
        │   ├── complex_drivers
        │   │   └── module
        │   │       ├── inc
        │   │       │   └── cdrmod.h
        │   │       ├── makefile
        │   │       └── src
        │   │           └── cdrmod.c
        │   ├── hal
        │   │   └── module
        │   │       ├── inc
        │   │       │   └── halmod.h
        │   │       ├── makefile
        │   │       └── src
        │   │           └── halmod.c
        │   ├── makefile
        │   ├── mcal
        │   │   └── module
        │   │       ├── inc
        │   │       │   └── mcalmod.h
        │   │       ├── makefile
        │   │       └── src
        │   │           └── mcalmod.c
        │   └── services
        │       └── module
        │           ├── inc
        │           │   └── servmod.h
        │           ├── makefile
        │           └── src
        │               └── servmod.c
        ├── main.c
        └── rte

As you can see, there are some folders called 'module':

    module
        ├── inc
        │   └── mcalmod.h
        ├── makefile
        └── src
            └── mcalmod.c

Copy every module according your needs, just rename it automatically it all will be builded.

### Project building

Go to build folder and run following command (to run project without standard libraries):

    make all

Go to build folder and run following command (to run project with standard libraries):

    make all STDLIB=Y

To clean project just run

    make clean

### RTOS notes:

What is an Operating System?

It is a resource manager, it allocates resources to every part of the system.

What is a Real Time Operating System?

It performs the functions of an operating system, but in this case is very important the term of dealine.

RTOS Performance Metrics.

Dealines: deriving the right results with in a set time constraint.

Reliability: Running in a predictable way with a guaranteed response.

Thread:
Timed threads.

> 1. sporadic.
> 2. periodic.
> 3. aperiodic.

Event triggered threads.

> 1. flag.
> 2. input.
> 3. output.

Main threads.

Non real-time: No guarantee of task execution.

Real-time: bounded latency, guarantees execution.

Soft real-time: executes on priority bases.

Latency: execution delay.

Periodic thread: runs at a fixed time interval.

Aperiodic thread: run frequently, runtime cannot anticipated.

Sporadic thread: runs infrequently or never.

Blocked state: waiting state.

Run state: execution state.

Process: execution of program instance.

Thread: execution of task, this is part of a process. Also a thread it is an execution of a task.

Classification:

static

dynamic

preemptive 

non preemtive




