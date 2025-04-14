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
/* Thread control block struct. */
struct tcb
{
    uint32_t*   stack_ptr;
    struct tcb* next_ptr;
};

typedef struct tcb tcb_type;

/* Defines task function pointer: */
typedef void(*task_f_ptr)(void);

/*                                                      Constants                                                    */
/*********************************************************************************************************************/
#define NUMBER_OF_THREADS   (3ul)
#define STACK_SIZE          (100ul) /* 1 Kb */

#define THUMB_MODE          (1ul<<24) /* PSR*/

#define RTOS_KERNEL_PREES   OS_TICK_TIMER

#define PERIODIC_TASK_100MS (100ul)

/*                                                 Exported Variables                                                */
/*********************************************************************************************************************/

/*                                            Exported functions prototypes                                          */
/*********************************************************************************************************************/
extern void rtos_init              (task_f_ptr task0,task_f_ptr task1,task_f_ptr task2);
extern void rtos_thread_yield      (void); /*Use this function if you need a task to be coperative.*/
extern void rtos_semaphore_init    (sint32_t* semaphore,sint32_t value); /* Use semaphore is you two or more task are using same resource. */
extern void rtos_semaphore_set     (sint32_t* semaphore);
extern void rtos_semaphore_wait    (sint32_t* semaphore);

/*********************************************************************************************************************/
#endif
/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/ 