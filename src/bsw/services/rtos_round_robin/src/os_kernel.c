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
               This rtos has a periodic scheduler.
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

uint32_t put_index;
uint32_t get_index;
uint32_t os_fifo[FIFO_SIZE];
sint32_t current_fifo_size;
uint32_t lost_data;

/*                                             Local functions prototypes                                            */
/*********************************************************************************************************************/
static void rtos_kernel_stack_init    (uint32_t task_index);
static void rtos_scheduler_launch     (void);
static void rtos_kernel_launch        (uint32_t quanta);
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

static void rtos_kernel_stack_init (uint32_t task_index) /* Allocates space in the stack  */
{
    kernel_os_threads[task_index].stack_pointer = &tcb_stack[task_index][STACK_SIZE-16]; /* kernel[0].stack = &tcb_stack[0][336]. */
    tcb_stack[task_index][STACK_SIZE-1] = THUMB_MODE;                                    /* tcb[0][396] = (1ul<<24), enable EPSR T bit.*/
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
    rtos_kernel_launch (OS_PERIOD_5_MS); /* Every task is executed every 10 mS aprox. full RTOS cycle is 50 mS, 20 Hz. */
}

void rtos_kernel_add_threads_2 (task_f_ptr task0,task_f_ptr task1)
{
    __disable_irq();
    kernel_os_threads[0].next_thread_pointer = &kernel_os_threads[1]; /* next element is asigned. Second thread. */
    kernel_os_threads[1].next_thread_pointer = &kernel_os_threads[0]; /* next element is asigned. First thread.*/
    rtos_kernel_stack_init(0);                                        /* kernel_os_threads[0].stack_pointer = &tcb_stack[0][336].  */
                                                                      /* tcb_stack[0][396] = 0x100 0000 (processor will execute thumb mode). */
    tcb_stack[0][STACK_SIZE-2] = (uint32_t)(task0);                   /* tcb_stack[0][392] = &task0. */
    rtos_kernel_stack_init(1);                                        /* kernel_os_threads[1].stack_pointer = &tcb_stack[1][736].  */
                                                                      /* tcb_stack[1][796] = 0x100 0000 (processor will execute thumb mode).*/
    tcb_stack[1][STACK_SIZE-2] = (uint32_t)(task1);                   /* tcb_stack[1][792] = &task1. */
    current_thread_ptr = &kernel_os_threads[0];                       /* current_thread_ptr is initilialized with thread 0. */
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
    __asm("CPSID I");                            /* Suspend current thread: current_thread_ptr = &kernel_os_threads[0]. */
                                                 /* Disable global interrupt:*/

    __asm("PUSH {R4-R11}");                      /* Save r4,r5,r6,r7,r8,r10,r11: this is the current context. */

    __asm("LDR R0,=current_thread_ptr");         /* R0 = current_thread_ptr = &kernel_os_threads[0]. */

    __asm("LDR R1,[R0]");                        /* R1 = R0 = current_thread_ptr = &kernel_os_threads[0]. */

    __asm("STR SP,[R1]");                        /* R1 = SP = R0 = current_thread_ptr = &kernel_os_threads[0]. */

    __asm("PUSH {R0,LR}");                       /* Saves context. */

    __asm("BL rtos_scheduler_round_robin");      /* Calls a function that performs round robin scheduling. */

    __asm("POP {R0,LR}");                        /* Restores context. */

    __asm("LDR R1,[R0]");                        /* R1 = R0 = current_thread_ptr = &kernel_os_threads[1]. */

    __asm("LDR SP,[R1]");                        /* SP = R1 = &kernel_os_threads[1]. */

    __asm("POP {R4-R11}");                       /* Restores r4,r5,r6,r7,r8,r10,r11: */

    __asm("CPSIE I");                            /* Enables interrutps */

    __asm("BX LR");                              /* Return from exception. */
}

void Systick_Handler (void)
{
    sbc_icsr_config_pendsv_pending_bit();
}

void rtos_scheduler_round_robin (void)
{
    current_thread_ptr = current_thread_ptr->next_thread_pointer;
}

/* To make switch context:
1.- Enable processor faults ans interrupts.
2.- Prioritize the interrupts properly.
3.- Create a structure to store the list of tasks. This is called Task  Control Block. Initialize each tasl and store PSP into this table.
4.- Initializae Systick timer.
5.- On each systick interrupt, we would increment tick value and trigger PendSV interrupt.
6.- context switch at PendSV interrup:
    Save context of existing task by saving R4-R11.
    Save PSP to the Task Control Block
    Update the PSP with stack pointer of new task from Task Control Block.
    Recover context of new task by updating R4-R11 from the task's stack.
*/

static void rtos_scheduler_launch (void)
{
    __asm("LDR R0,=current_thread_ptr"); /* First cycle: */
                                         /* R0 = &kernel_os_threads[0]. */

    __asm("LDR R2,[R0]");                /* R2 = R0 = current_thread_ptr = &kernel_os_threads[0]. */

    __asm("LDR SP,[R2]");                /* SP = R2 = current_thread_ptr = R0 = &kernel_os_threads[0]. */

    __asm("POP {R4-R11}");               /* Restores r4,r5,r6,r7,r8,r10,r11: */

    __asm("POP {R0-R3}");                /* Restores r0,r1,r2,r3: */ 

    __asm("POP {R12}");                  /* Restore Link Register (R12): */

    __asm("ADD SP,SP,#4");               /* Skips LR: */

    __asm("POP {LR}");                   /* Create a new start location by popping LR: */

    __asm("ADD SP,SP,#4");               /* Skip PSR by adding 4 to SP: */

    __asm("CPSIE I");                    /* Enable Global interrupts: */

    __asm("BX LR");                      /* Return from exception. */
}

/* Once the thread process has finished this function allows other task access to the RTOS clock. */
void rtos_thread_yield       (void)
{
    /* Clear SysTick current value register: */
    systick_config_reset_value ();
    /* Trigger SysTick: */
    sbc_icsr_config_systick_pending_bit (true);
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

void rtos_fifo_init(void)
{
    put_index = 0ul;
    get_index = 0ul;
    rtos_semaphore_init (&current_fifo_size,0ul);
    lost_data = 0ul;
}

void rtos_fifo_put (uint32_t data)
{
    if(FIFO_SIZE == current_fifo_size)
    {
        lost_data++;
    }
    else
    {
        os_fifo[put_index] = data;
        put_index = (put_index+1ul)%FIFO_SIZE;
        rtos_semaphore_set(&current_fifo_size);
    }
}

uint32_t rtos_fifo_get (void)
{
    uint32_t data;
    rtos_semaphore_wait(&current_fifo_size);
    __disable_irq();
    data = os_fifo[get_index];
    get_index = (get_index+1ul)%FIFO_SIZE;
    __enable_irq();
    return data;
}
/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/
