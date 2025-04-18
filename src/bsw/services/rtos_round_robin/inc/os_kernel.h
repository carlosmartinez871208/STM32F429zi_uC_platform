/*********************************************************************************************************************/
/*                                                INCLUDES GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $File: os_kernel.h
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2025-03-23 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/* os_kernel.h:
                provides the system task and resources management.
 */
/*********************************************************************************************************************/
/* ALL RIGHTS RESERVED                                                                                               */
/*                                                                                                                   */
/* The reproduction, transmission, or use of this document or its content is                                         */
/* not permitted without express written authority. Offenders will be liable                                         */
/* for damages.                                                                                                      */
/*********************************************************************************************************************/
#ifndef OS_KERNEL_H_
#define OS_KERNEL_H_
/*                                                       Includes                                                    */
/*********************************************************************************************************************/
#include "Std_types.h"
#include "interrupts.h"
#include "sbc.h"
#include "systick.h"

/*                                                        Types                                                      */
/*********************************************************************************************************************/


/*                                                      Constants                                                    */
/*********************************************************************************************************************/
#define NUM_OF_THREADS      (5)
#define STACK_SIZE          (100)

/*
Thumb mode in ARM processors is a feature that uses a 16-bit instruction set (Thumb) instead of the standard 
32-bit ARM instruction set. This allows for smaller and more densely packed code, which is advantageous for 
memory-constrained systems. Thumb mode effectively compresses the code, reducing the amount of memory required 
to store instructions

The EPSR contains the T bit, that is set to 1 to indicate that the processor executes Thumb instructions, and an
overlaid ICI or IT field that supports interrupt-continue load/store instructions and the IT instruction.
*/
#define THUMB_MODE          (1ul<<24) /* PSR*/

#define RTOS_TICK_TIMER     OS_TICK_TIMER_1MS

#define OS_PERIOD_50_MS     (50ul)
#define OS_PERIOD_20_MS     (20ul)
#define OS_PERIOD_30_MS     (30ul)
#define OS_PERIOD_16_MS     (16ul)
#define OS_PERIOD_10_MS     (10ul)
#define OS_PERIOD_5_MS      (5ul)

#define FIFO_SIZE           (15ul)

/*                                                 Exported Variables                                                */
/*********************************************************************************************************************/
struct thread_ctrl_block
{
    uint32_t*                 stack_pointer;       /* Stack pointer:  */
    struct thread_ctrl_block* next_thread_pointer; /* Points to next stack pointer */
};

typedef struct thread_ctrl_block tcb_type;

/* Defines task function pointer: */
typedef void(*task_f_ptr)(void);

/*                                            Exported functions prototypes                                          */
/*********************************************************************************************************************/
extern void     rtos_init              (uint32_t task_index);
extern void     rtos_thread_yield      (void);
extern void     rtos_semaphore_init    (sint32_t* semaphore,sint32_t value);
extern void     rtos_semaphore_set     (sint32_t* semaphore);
extern void     rtos_semaphore_wait    (sint32_t* semaphore);
extern void     rtos_fifo_init         (void);
extern void     rtos_fifo_put          (uint32_t);
extern uint32_t rtos_fifo_get          (void);

/* Call this function from main if not using RTOS. */
extern void os_task_main (void);

/* Task prototypes: */
extern void os_task_0 (void);
extern void os_task_1 (void);
extern void os_task_2 (void);
extern void os_task_3 (void);
extern void os_task_4 (void);
/*********************************************************************************************************************/
#endif
/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/ 