/*********************************************************************************************************************/
/*                                                INCLUDES GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $File: os_rr_kernel.h
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2025-03-23 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/* os_rr_kernel.h:
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

#define THUMB_MODE          (1ul<<24) /* PSR*/

#define RTOS_TICK_TIMER     OS_TICK_TIMER

#define OS_PERIOD_50_MS     (50ul)
#define OS_PERIOD_20_MS     (20ul)
#define OS_PERIOD_30_MS     (30ul)
#define OS_PERIOD_16_MS     (16ul)

/*                                                 Exported Variables                                                */
/*********************************************************************************************************************/
struct thread_ctrl_block
{
    uint32_t*                 stack_pointer;
    struct thread_ctrl_block* next_thread_pointer;
};

typedef struct thread_ctrl_block tcb_type;

/* Defines task function pointer: */
typedef void(*task_f_ptr)(void);

/*                                            Exported functions prototypes                                          */
/*********************************************************************************************************************/
extern void rtos_init              (uint32_t task_index);
extern void rtos_thread_yield      (void);
extern void rtos_semaphore_init    (sint32_t* semaphore,sint32_t value);
extern void rtos_semaphore_set     (sint32_t* semaphore);
extern void rtos_semaphore_wait    (sint32_t* semaphore);

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