/*********************************************************************************************************************/
/*                                                INCLUDES GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $File: rtos_kernel.h
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2025-03-23 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/* rtos_kernel.h:
                provides the system task and resources management.
 */
/*********************************************************************************************************************/
/* ALL RIGHTS RESERVED                                                                                               */
/*                                                                                                                   */
/* The reproduction, transmission, or use of this document or its content is                                         */
/* not permitted without express written authority. Offenders will be liable                                         */
/* for damages.                                                                                                      */
/*********************************************************************************************************************/
#ifndef RTOS_KERNEL_H_
#define RTOS_KERNEL_H_
/*                                                       Includes                                                    */
/*********************************************************************************************************************/
#include "Std_types.h"
#include "interrupts.h"
#include "sbc.h"
#include "systick.h"

/*                                                       Defines                                                     */
/*********************************************************************************************************************/
/* Un sistema operativo debe tener la capacidad de proveer cierto tiempo de procesamiento a cada tarea especifica 
   en el caso de los sistemas operativos de tiempo real lo que los caracteriza es el concepto de "deadline", esto
   significa que cada hilo de ejecucion (thread) debe cumplir ese deadline, cabe mencionar que una tarea (task)
   es la ejecución de un hilo. */

#define MAX_NUMBER_OF_TASKS (11ul) /* Al estar usando sistemas embebidos es recomendable no usar memoria dinamica
                                      debido a los recursos de los microcontroladores que son limitados:
                                      Memoria limitada, capacidad de procesamiento limitado. */

#define STACK_SIZE          (100) /* Reserves 400 bytes for task configuration and task context. */

#define THUMB_MODE          (1ul<<24) /* PSR: this enables THUMB mode. */

#define NO_TASK      (0u)
#define ONE_TASK     (1u)
#define TWO_TASKS    (2u)
#define THREE_TASKS  (3u)
#define FOUR_TASKS   (4u)
#define FIVE_TASKS   (5u)
#define SIX_TASKS    (6u)
#define SEVEN_TASKS  (7u)
#define EIGHT_TASKS  (8u)
#define NINE_TASKS   (9u)
#define TEN_TASKS    (10u)

#define OS_TICK_BASE (9600ul)
#define OS_TIME_MULT (10ul)

#define FIFO_SIZE           (15ul)

/*                                                        Types                                                      */
/*********************************************************************************************************************/
typedef enum
{
    max=0,second,third,fourth,fifth,sixth,seventh,eigth,nineth,tenth,background
}task_priority; /* Esta enumeracion nos permite definir la prioridad de cada tarea. */

typedef enum
{
    ready=0,waiting,executing
}task_status;   /* Esta enumeracion nos permite ver el estado actual de las tareas. */

typedef void (*task_callback) (void); /* Se declara un apuntador a funcion:
                                         Este nos ayudara a hacer los llamados de nuestras tareas. */

typedef struct
{
    uint32_t*      stack_pointer; /* Apunta hasta el inicio del stack (hay que recordar que se incrementa hacia abajo):
                                     Esto tiene como objetivo guardar el contexto de cada tarea. */
    task_priority  priority;      /* Nos brinda la prioridad de la tarea. */
    task_status    status;        /* Nos da informacion del estatus de la tarea. */
    uint32_t       offset;        /* Este es el offset de ejecución. */
}tcb_type; /* Esta estructura nos ayuda a manipular cada uno de nuestros hilos de ejecución. */

typedef enum
{
    periodic=0,round_robin
}scheduling_type;

typedef uint32_t task_offset; 

/*                                                      Constants                                                    */
/*********************************************************************************************************************/

/*                                                 Exported Variables                                                */
/*********************************************************************************************************************/


/*                                            Exported functions prototypes                                          */
/*********************************************************************************************************************/
/* Task function: si el rtos se configuro para una sola tarea. */
extern void os_task_main         (void);
/* Tasks functions: rtos configurado para mas de una tarea. */
extern void os_task_background   (void); /* Realiza actividades mientras las tareas periodicas no estan activas. */
extern void os_task_0            (void);
extern void os_task_1            (void);
extern void os_task_2            (void);
extern void os_task_3            (void);
extern void os_task_4            (void);
extern void os_task_5            (void);
extern void os_task_6            (void);
extern void os_task_7            (void);
extern void os_task_8            (void);
extern void os_task_9            (void);

/* RTOS initialization: configura el rtos. */
/* If NO_TASK or TASK_ONE is passed as argument, no rtos will be configured */
/* task_number     = 0-10
** scheduling_type = periodic or round robin
** offset          = array with offsets in miliseconds, this value is not relevant in case o chosing round robin scheduling.
*/
extern void     rtos_init              (uint8_t task_number,scheduling_type scheduler,task_offset* offset);
extern void     rtos_thread_yield      (void);
extern void     rtos_semaphore_init    (sint32_t* semaphore,sint32_t value);
extern void     rtos_semaphore_set     (sint32_t* semaphore);
extern void     rtos_semaphore_wait    (sint32_t* semaphore);
extern void     rtos_fifo_init         (void);
extern void     rtos_fifo_put          (uint32_t);
extern uint32_t rtos_fifo_get          (void);
/*********************************************************************************************************************/
#endif
/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/ 