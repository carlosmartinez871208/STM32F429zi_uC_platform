/*********************************************************************************************************************/
/*                                                  SOURCE GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $File: os_kernel.c
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2025-03-23 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/* os_kernel.c:
               provides thr logic for task switching.
               All Round Robin tasks has the same execution time.
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
#include "os_kernel.h"
/*                                                        Types                                                      */
/*********************************************************************************************************************/

/*                                                      Constants                                                    */
/*********************************************************************************************************************/
tcb_type kernel_os_threads [NUM_OF_THREADS];

tcb_type* current_thread_ptr;

uint32_t tcb_stack[NUM_OF_THREADS][STACK_SIZE];

/*                                             Local functions prototypes                                            */
/*********************************************************************************************************************/
static void rtos_kernel_stack_init (uint32_t task_index);
static void rtos_scheduler_launch  (void);
static void rtos_kernel_launch     (uint32_t quanta);
static void rtos_kernel_add_threads_2 (task_f_ptr task0,task_f_ptr task1);
static void rtos_kernel_add_threads_3 (task_f_ptr task0,task_f_ptr task1,task_f_ptr task2);
static void rtos_kernel_add_threads_4 (task_f_ptr task0,task_f_ptr task1,task_f_ptr task2,task_f_ptr task3);
static void rtos_kernel_add_threads_5 (task_f_ptr task0,task_f_ptr task1,task_f_ptr task2,task_f_ptr task3,task_f_ptr task4);

/*                                           Local functions implementation                                          */
/*********************************************************************************************************************/
void rtos_kernel_launch (uint32_t quanta)
{
    uint32_t os_tick = 0ul;
    /* Reset systick: */
    systick_reset_control_register();
    /* Clear systick current value register: */
    systick_config_reset_value ();
    /* Load quanta*/
    os_tick = (quanta * RTOS_TICK_TIMER)-1ul;
    systick_config_clock_cycles (os_tick);
    /* Set systick priority: */
    sbc_shpr_config_handler_priority (SysTick_IRQn,SBC_SHPR_SYSTICK_PRI_14);
    /* PendSV priority shall be a bit lower than SysTick: */
    sbc_shpr_config_handler_priority (PendSV_IRQn,SBC_SHPR_PENDSV_PRI_15);
    /* Enable systick, select internal clock (PLL in our case 96 MHz): */
    systick_config_select_clk_src (int_clock);
    /* Enable systick interrupt: */
    systick_config_enable_interrupt (true);
    /* Enable SysTick: */
    systick_config_enable (true);
    /* RTOS call scheduler launch */
    rtos_scheduler_launch();
}

static void rtos_kernel_stack_init (uint32_t task_index)
{
    kernel_os_threads[task_index].stack_pointer = &tcb_stack[task_index][STACK_SIZE-16];
    tcb_stack[task_index][STACK_SIZE-1] = THUMB_MODE;
}

void rtos_init (uint32_t threads)
{
    if (5ul==threads)
    {
        rtos_kernel_add_threads_5 (&os_task_0,&os_task_1,&os_task_2,&os_task_3,&os_task_4);
    } 
    else if (4ul==threads)
    {
        rtos_kernel_add_threads_4 (&os_task_0,&os_task_1,&os_task_2,&os_task_3);
    } 
    else if (3ul==threads)
    {
        rtos_kernel_add_threads_3 (&os_task_0,&os_task_1,&os_task_2);
    }
    else
    {
        rtos_kernel_add_threads_2 (&os_task_0,&os_task_1);
    }
    rtos_kernel_launch (OS_PERIOD_16_MS); /* Every task is executed every 16 mS aprox. 60 Hz. */
}

void rtos_kernel_add_threads_2 (task_f_ptr task0,task_f_ptr task1)
{
    __disable_irq();
    kernel_os_threads[0].next_thread_pointer = &kernel_os_threads[1];
    kernel_os_threads[1].next_thread_pointer = &kernel_os_threads[0];
    rtos_kernel_stack_init(0);
    tcb_stack[0][STACK_SIZE-2] = (uint32_t)(task0);
    rtos_kernel_stack_init(1);
    tcb_stack[1][STACK_SIZE-2] = (uint32_t)(task1);
    current_thread_ptr = &kernel_os_threads[0];
    __enable_irq();
}

void rtos_kernel_add_threads_3 (task_f_ptr task0,task_f_ptr task1,task_f_ptr task2)
{
    __disable_irq();
    kernel_os_threads[0].next_thread_pointer = &kernel_os_threads[1];
    kernel_os_threads[1].next_thread_pointer = &kernel_os_threads[2];
    kernel_os_threads[2].next_thread_pointer = &kernel_os_threads[0];
    rtos_kernel_stack_init(0);
    tcb_stack[0][STACK_SIZE-2] = (uint32_t)(task0);
    rtos_kernel_stack_init(1);
    tcb_stack[1][STACK_SIZE-2] = (uint32_t)(task1);
    rtos_kernel_stack_init(2);
    tcb_stack[2][STACK_SIZE-2] = (uint32_t)(task2);
    current_thread_ptr = &kernel_os_threads[0];
    __enable_irq();
}

void rtos_kernel_add_threads_4 (task_f_ptr task0,task_f_ptr task1,task_f_ptr task2,task_f_ptr task3)
{
    __disable_irq();
    kernel_os_threads[0].next_thread_pointer = &kernel_os_threads[1];
    kernel_os_threads[1].next_thread_pointer = &kernel_os_threads[2];
    kernel_os_threads[2].next_thread_pointer = &kernel_os_threads[3];
    kernel_os_threads[3].next_thread_pointer = &kernel_os_threads[0];
    rtos_kernel_stack_init(0);
    tcb_stack[0][STACK_SIZE-2] = (uint32_t)(task0);
    rtos_kernel_stack_init(1);
    tcb_stack[1][STACK_SIZE-2] = (uint32_t)(task1);
    rtos_kernel_stack_init(2);
    tcb_stack[2][STACK_SIZE-2] = (uint32_t)(task2);
    rtos_kernel_stack_init(3);
    tcb_stack[3][STACK_SIZE-2] = (uint32_t)(task3);
    current_thread_ptr = &kernel_os_threads[0];
    __enable_irq();
}

void rtos_kernel_add_threads_5 (task_f_ptr task0,task_f_ptr task1,task_f_ptr task2,task_f_ptr task3,task_f_ptr task4)
{
    __disable_irq();
    kernel_os_threads[0].next_thread_pointer = &kernel_os_threads[1];
    kernel_os_threads[1].next_thread_pointer = &kernel_os_threads[2];
    kernel_os_threads[2].next_thread_pointer = &kernel_os_threads[3];
    kernel_os_threads[3].next_thread_pointer = &kernel_os_threads[4];
    kernel_os_threads[4].next_thread_pointer = &kernel_os_threads[0];
    rtos_kernel_stack_init(0);
    tcb_stack[0][STACK_SIZE-2] = (uint32_t)(task0);
    rtos_kernel_stack_init(1);
    tcb_stack[1][STACK_SIZE-2] = (uint32_t)(task1);
    rtos_kernel_stack_init(2);
    tcb_stack[2][STACK_SIZE-2] = (uint32_t)(task2);
    rtos_kernel_stack_init(3);
    tcb_stack[3][STACK_SIZE-2] = (uint32_t)(task3);
    rtos_kernel_stack_init(4);
    tcb_stack[4][STACK_SIZE-2] = (uint32_t)(task4);
    current_thread_ptr = &kernel_os_threads[0];
    __enable_irq();
}

/* Interrupt handler */
__attribute__((naked)) void PendSV_Handler (void)
{
    /* Suspend current thread: */
    /* Disable global interrupt:*/
    __asm("CPSID I");
    /* Save r4,r5,r6,r7,r8,r10,r11: */
    __asm("PUSH {R4-R11}");
    /* Load address of current pointer into r0 */
    __asm("LDR R0,=current_thread_ptr");
    /* Load r1 from address equals r0: i.e. r1=current_thread: */
    __asm("LDR R1,[R0]");
    /* Store Cortex-M4 SP at address equals r1, i.e. SP into tcb: */
    __asm("STR SP,[R1]");
    /* Choose next thread:*/
    /* Load r1 from a location 4 bytes above address r1, i.e. r1 = current_thread->next_ptr: */
    __asm("LDR R1,[R1,#4]");
    /* Store R1 at address equal R0, i.e. current_thread = r1*/
    __asm("STR R1,[R0]");
    /* SP = current_thread->stack_ptr*/
    __asm("LDR SP,[R1]");
    /* Restore r4,r5,r6,r7,r8,r10,r11: */
    __asm("POP {R4-R11}");
    /* Enable global interrupt:*/
    __asm("CPSIE I");
    /* Return from exception and restore r0,r1,r3,r12,LR,PCR: */
    __asm("BX LR");
}

void Systick_Handler (void)
{
    sbc_icsr_config_pendsv_pending_bit();
}

static void rtos_scheduler_launch (void)
{
    /* Load address of current_thread into R0: */
    __asm("LDR R0,=current_thread_ptr");
    /* Load R2 from address equals r0, r2=current_thread: */
    __asm("LDR R2,[R0]");
    /* Load Cortex-M4 SP from address equals R2, i.e. SP = current_thread->stack_ptr: */
    __asm("LDR SP,[R2]");
    /* Restore r4,r5,r6,r7,r8,r10,r11: */
    __asm("POP {R4-R11}");
    /* Restore r0,r1,r2,r3: */
    __asm("POP {R0-R3}");
    /* Restore Link Register (R12): */
    __asm("POP {R12}");
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

/* Once the thread process has finished this function allows other task access to the RTOS clock. */
void rtos_thread_yield       (void)
{
    /* Clear SysTick current value register: */
    systick_config_reset_value ();
    /* Trigger SysTick: */
    sbc_icsr_config_systick_pending_bit(true);
}

void rtos_semaphore_init (sint32_t* semaphore,sint32_t value)
{
    *semaphore = value;
}

void rtos_semaphore_set (sint32_t* semaphore)
{
    __disable_irq();
    *semaphore +=1;
    __enable_irq();
}

void rtos_semaphore_wait (sint32_t* semaphore)
{
    __disable_irq();
    while(*semaphore <= 0)
    {
        __disable_irq();
        __enable_irq();
    }
    *semaphore -=1;
    __enable_irq();
}

/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/
