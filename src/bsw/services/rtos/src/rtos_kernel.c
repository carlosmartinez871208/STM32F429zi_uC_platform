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
#include "rtos_kernel.h"
/*                                                       Defines                                                     */
/*********************************************************************************************************************/

/*                                                        Types                                                      */
/*********************************************************************************************************************/

/*                                                      Constants                                                    */
/*********************************************************************************************************************/

/*                                                      Variables                                                    */
/*********************************************************************************************************************/
tcb_type task_configuration [MAX_NUMBER_OF_TASKS]; /* Este arreglo contiene la configuracion de nuestro thread. */

/* Este es un arreglo de callouts. */
task_callback task_callouts  [MAX_NUMBER_OF_TASKS] = {\
    &os_task_0,&os_task_1,&os_task_2,&os_task_3,&os_task_4
    //&os_task_5,&os_task_6,&os_task_7,&os_task_8,&os_task_9
};

uint32_t tcb_stack [MAX_NUMBER_OF_TASKS][STACK_SIZE];

tcb_type* current_thread_pointer;
volatile uint32_t systick_counter;
uint8_t task_counter;
uint8_t number_of_tasks;
scheduling_type scheduler_type;

uint32_t put_index;
uint32_t get_index;
uint32_t os_fifo[FIFO_SIZE];
sint32_t current_fifo_size;
uint32_t lost_data;

/*                                             Local functions prototypes                                            */
/*********************************************************************************************************************/
static void     rtos_launch_task                (task_callback task);
static void     rtos_configure_systick          (uint32_t time_base);
static void     rtos_scheduler_launch           (void);
static void     rtos_kernel_scheduler_control   (void);

/*                                          External functions implementation                                        */
/*********************************************************************************************************************/
void rtos_init (uint8_t task_number,scheduling_type scheduler,task_offset* offset)
{
    uint32_t task_period=(*offset);
    number_of_tasks = task_number;
    scheduler_type = scheduler;
    if (NO_TASK==task_number || ONE_TASK==task_number)
    {
        rtos_launch_task (&os_task_main);
    }
    else if(MAX_NUMBER_OF_TASKS>=task_number)
    {
        if(round_robin==scheduler)
        {
            task_period = (task_period*OS_TICK_BASE*OS_TIME_MULT)-1ul;
            for(uint8_t index=0u;index<task_number;index++)
            {
                task_configuration[index].stack_pointer = &tcb_stack[index][STACK_SIZE-16];
                tcb_stack[index][STACK_SIZE-1] = THUMB_MODE;
                tcb_stack[index][STACK_SIZE-2] = (uint32_t)task_callouts[index];
            }
        }
        else
        {
            task_period=(task_period*OS_TICK_BASE*OS_TIME_MULT/task_number)-1ul; 
            for(uint8_t index=0u;index<task_number;index++)
            {
                task_configuration[index].stack_pointer = &tcb_stack[index][STACK_SIZE-16];
                tcb_stack[index][STACK_SIZE-1] = THUMB_MODE;
                tcb_stack[index][STACK_SIZE-2] = (uint32_t)task_callouts[index];
                task_configuration[index].priority      = index;
                task_configuration[index].status        = ready;
                task_configuration[index].offset        = *(offset+index);
            }
            task_configuration[task_number].stack_pointer = &tcb_stack[task_number][STACK_SIZE-16];
            tcb_stack[task_number][STACK_SIZE-1] = THUMB_MODE;
            tcb_stack[task_number][STACK_SIZE-2] = (uint32_t)(&os_task_background);
            task_configuration[task_number].priority      = background;
            task_configuration[task_number].status        = ready;
            task_configuration[task_number].offset        = 0;
        }
        task_configuration[0].status = executing;
        current_thread_pointer = &task_configuration[0];
        rtos_configure_systick (task_period);
        rtos_scheduler_launch ();
    }
    else
    {/*Do nothing.*/}
}

/*                                           Local functions implementation                                          */
/*********************************************************************************************************************/
void rtos_launch_task (task_callback task)
{
    (*task)();
}

void rtos_configure_systick (uint32_t time_base)
{
    /* Reset systick: */
    systick_reset_control_register();
    /* Clear systick current value register: */
    systick_config_reset_value ();
    /* Load SysTick time base. */
    systick_config_clock_cycles (time_base);
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
}

void rtos_scheduler_launch (void)
{
    __asm("LDR R0,=current_thread_pointer"); /* First cycle: */
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

void rtos_kernel_scheduler_control (void)
{
    if(periodic==scheduler_type)
    {
        if (systick_counter<number_of_tasks)
        {
            if(task_configuration[systick_counter].status==ready &&\
                current_thread_pointer->status==executing)
            {
                current_thread_pointer->status = waiting;
                current_thread_pointer = &task_configuration[systick_counter];
                current_thread_pointer->status = executing;
            }
            else{}
        }
        else
        { 
            if (task_configuration[task_counter].status==waiting &&\
                (systick_counter-task_counter)%task_configuration[task_counter].offset == 0u &&\
                task_configuration[task_counter].priority<current_thread_pointer->priority)
            {
                current_thread_pointer->status = waiting;
                current_thread_pointer = &task_configuration[task_counter];
                current_thread_pointer->status = executing;
                task_counter++;
            }
            else if (task_configuration[task_counter].status==waiting &&\
                    (systick_counter-task_counter)%task_configuration[task_counter].offset == 0u &&\
                    task_configuration[task_counter].priority>current_thread_pointer->priority)
            {
                current_thread_pointer->status = waiting;
                current_thread_pointer = &task_configuration[task_counter];
                current_thread_pointer->status = executing;
                task_counter++;
                if(task_counter==number_of_tasks){
                    task_counter=0u;
                }else{}
            }
            else
            {
                current_thread_pointer->status = waiting;
                current_thread_pointer = &task_configuration[number_of_tasks];
                current_thread_pointer->status = executing;
                task_counter=0u;
            }
        }
    }
    else
    {
        task_counter++;
        current_thread_pointer = &task_configuration[task_counter];
        if(number_of_tasks==task_counter)
        {
            task_counter=0;
            current_thread_pointer = &task_configuration[task_counter];
        }else{}
    }
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

/* Interrupt Handlers */
/* SysTick */
void Systick_Handler (void)
{
    systick_counter++;
    sbc_icsr_config_pendsv_pending_bit();
}

/* PendSV */
__attribute__((naked)) void PendSV_Handler (void)
{
    __asm("CPSID I");                            /* Suspend current thread: current_thread_ptr = &kernel_os_threads[0]. */
                                                 /* Disable global interrupt:*/

    __asm("PUSH {R4-R11}");                      /* Save r4,r5,r6,r7,r8,r10,r11: this is the current context. */

    __asm("LDR R0,=current_thread_pointer");         /* R0 = current_thread_ptr = &kernel_os_threads[0]. */

    __asm("LDR R1,[R0]");                        /* R1 = R0 = current_thread_ptr = &kernel_os_threads[0]. */

    __asm("STR SP,[R1]");                        /* R1 = SP = R0 = current_thread_ptr = &kernel_os_threads[0]. */

    __asm("PUSH {R0,LR}");                       /* Saves context. */

    __asm("BL rtos_kernel_scheduler_control");   /* Calls a function that performs round robin scheduling. */

    __asm("POP {R0,LR}");                        /* Restores context. */

    __asm("LDR R1,[R0]");                        /* R1 = R0 = current_thread_ptr = &kernel_os_threads[1]. */

    __asm("LDR SP,[R1]");                        /* SP = R1 = &kernel_os_threads[1]. */

    __asm("POP {R4-R11}");                       /* Restores r4,r5,r6,r7,r8,r10,r11: */

    __asm("CPSIE I");                            /* Enables interrutps */

    __asm("BX LR");                              /* Return from exception. */
}
/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/
