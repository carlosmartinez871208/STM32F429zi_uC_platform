/*********************************************************************************************************************/
/*                                                  SOURCE GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $File: kernel.c
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2025-03-23 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/* schduler.c:
               provides thr logic for task switching.
 */
/*********************************************************************************************************************/
/* ALL RIGHTS RESERVED                                                                                               */
/*                                                                                                                   */
/* The reproduction, transmission, or use of this document or its content is                                         */
/* not permitted without express written authority. Offenders will be liable                                         */
/* for damages.                                                                                                      */
/*********************************************************************************************************************/

/*                                                 Standard libraries                                                */
/*********************************************************************************************************************/

/*                                                   User libraries                                                  */
/*********************************************************************************************************************/
#include "Std_types.h"
#include "kernel.h"
/*                                                        Types                                                      */
/*********************************************************************************************************************/

/*                                                      Constants                                                    */
/*********************************************************************************************************************/
tcb_type  thread_cb[NUMBER_OF_THREADS];
tcb_type* current_thread;

/*Each thread will have stacksize of 100: 400 bytes.*/
uint32_t tcb_stack[NUMBER_OF_THREADS][STACK_SIZE];

/*                                             Local functions prototypes                                            */
/*********************************************************************************************************************/
static void rtos_scheduler_launch (void);
static void rtos_kernel_stack_init (uint32_t index);

/*                                           Local functions implementation                                          */
/*********************************************************************************************************************/
static void rtos_kernel_stack_init (uint32_t index)
{
    /* Asigns Stack Pointer to  */
    thread_cb[index].stack_ptr = &tcb_stack[index][STACK_SIZE-16ul];
    /* Set PSR (T-bit) to 1, to operate in thumb mode: */
    tcb_stack[index][STACK_SIZE-1ul] = THUMB_MODE;

    /* For debugging purpose: */
    /* Stack frame: */
    //tcb_stack[index][STACK_SIZE-3ul]  = 0xAAAAAAAAul; /* R14 i.e Link Register (LR). */
    //tcb_stack[index][STACK_SIZE-4ul]  = 0xAAAAAAAAul; /* R12 i.e */
    //tcb_stack[index][STACK_SIZE-5ul]  = 0xAAAAAAAAul; /* R3 i.e */
    //tcb_stack[index][STACK_SIZE-6ul]  = 0xAAAAAAAAul; /* R2 i.e */
    //tcb_stack[index][STACK_SIZE-7ul]  = 0xAAAAAAAAul; /* R1 i.e */
    //tcb_stack[index][STACK_SIZE-8ul]  = 0xAAAAAAAAul; /* R0 i.e */
    /*  */
    //tcb_stack[index][STACK_SIZE-9ul]  = 0xAAAAAAAAul; /* R11 i.e */
    //tcb_stack[index][STACK_SIZE-10ul] = 0xAAAAAAAAul; /* R10 i.e */
    //tcb_stack[index][STACK_SIZE-11ul] = 0xAAAAAAAAul; /* R9 i.e */
    //tcb_stack[index][STACK_SIZE-12ul] = 0xAAAAAAAAul; /* R8 i.e */
    //tcb_stack[index][STACK_SIZE-13ul] = 0xAAAAAAAAul; /* R7 i.e */
    //tcb_stack[index][STACK_SIZE-14ul] = 0xAAAAAAAAul; /* R6 i.e */
    //tcb_stack[index][STACK_SIZE-15ul] = 0xAAAAAAAAul; /* R5 i.e */
    //tcb_stack[index][STACK_SIZE-16ul] = 0xAAAAAAAAul; /* R4 i.e */
}

uint8_t rtos_kernel_add_thread (task_f_ptr task0,task_f_ptr task1,task_f_ptr task2)
{
    /* Disable global interrups: */
    __disable_irq();
    /* Taks initialization: */
    thread_cb[0].next_ptr = &thread_cb[1];
    thread_cb[1].next_ptr = &thread_cb[2];
    thread_cb[2].next_ptr = &thread_cb[0];
    /* Initial stack for thread 0:*/
    rtos_kernel_stack_init (0ul);
    /* Initialize Program Counter (PC) : */
    tcb_stack[0][STACK_SIZE-2] = (uint32_t)(task0);
    /* Initial stack for thread 1:*/
    rtos_kernel_stack_init (1ul);
    /* Initialize Program Counter (PC) : */
    tcb_stack[1][STACK_SIZE-2] = (uint32_t)(task1);
    /* Initial stack for thread 2:*/
    rtos_kernel_stack_init (2ul);
    /* Initialize Program Counter (PC) : */
    tcb_stack[2][STACK_SIZE-2] = (uint32_t)(task2);
    /* Start from thread 0: */
    current_thread = &thread_cb[0];
    /* Enable global interrupts: */
    __enable_irq();
    return 0u;
}

void rtos_kernel_launch (uint32_t quanta)
{
    uint32_t os_tick = 0ul;
    /* Reset systick: */
    systick_reset_control_register();
    /* Clear systick current value register: */
    systick_config_reset_value ();
    /* Load quanta*/
    os_tick = (quanta * OS_TICK_TIMER)-1ul;
    systick_config_clock_cycles (os_tick);
    /* Set systick to low priority: */
    NVIC_SetPriority (SysTick_IRQn,15ul);
    /* Enable systick, select internal clock (PLL in our case 96 MHz): */
    systick_config_select_clk_src (int_clock);
    /* Enable systick interrupt: */
    systick_config_enable_interrupt (true);
    /* Enable SysTick: */
    systick_config_enable (true);
    /* Launch scheduler: */
    rtos_scheduler_launch ();
}

/* Interrupt handler */
__attribute__((naked)) void Systick_Handler (void)
{
    /* Suspend current thread: */
    /* Disable global interrupt:*/
    __asm("CPSID I");
    /* Save r4,r5,r6,r7,r8,r10,r11: */
    __asm("PUSH {R4-R11}");
    /* Load address of current pointer into r0 */
    __asm("LDR R0,=current_thread");
    /* Load r1 from address equals r0: i.e. r1=current_thread: */
    __asm("LDR R1,[R0]");
    /* Store Cortex-M4 SP at address equals r1, i.e. SP into tcb: */
    __asm("STR SP,[R1]");
    /* Choose next thread:*/
    /* Load r1 from a location 4 bytes above address r1, i.e. r1 = current_thread->next_ptr: */
    __asm("LDR R1,[R1,#4]");
    /* Store R1 at address equal R0, i.e. current_thread = r1*/
    __asm("STR R1,[R0]");
    /* Load Cortex-<4 SP from address equals r1, i.e. SP = current_thread->stack_ptr: */
    __asm("LDR SP,[R1]");
    /* Restore r4,r5,r6,r7,r8,r10,r11: */
    __asm("POP {R4-R11}");
    /* Enable global interrupt:*/
    __asm("CPSIE I");
    /* Return from exception and restore r0,r1,r3,r12,LR,PCR: */
    __asm("BX LR");
}

static void rtos_scheduler_launch (void)
{
    /* Load address of current_thread into R0: */
    __asm("LDR R0,=current_thread");
    /* Load R2 from address equals r0, r2=current_thread: */
    __asm("LDR R2,[R0]");
    /* Load Cortex-M4 SP from address equals R2, i.e. SP = current_thread->stack_ptr: */
    __asm("LDR SP,[R2]");
    /* Restore r4,r5,r6,r7,r8,r10,r11: */
    __asm("POP {R4-R11}");
    /* Restore Link Register (R12): */
    __asm("POP {R12}");
    /* Restore r0,r1,r2,r3: */
    __asm("POP {R0-R3}");
    /* Skip LR: */
    __asm("ADD SP,SP,#4");
    /* Create a new start location by popping LR: */
    __asm("POP {LR}");
    /* Skip PSR by adding 4 to SP: */
    __asm("ADD SP,SP,#4");
    /* Enable Global interrupts: */
    __asm("CPSIE I");
    /* Return from exception */
    __asm("BX LR");
}
/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/
