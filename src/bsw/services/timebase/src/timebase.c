/*********************************************************************************************************************/
/*                                                  SOURCE GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $File: template.c
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2025-03-23 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/* template.c:
               Use this template for your source code files.
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
#include "timebase.h"
#include "interrupts.h"
/*                                                        Types                                                      */
/*********************************************************************************************************************/
volatile uint32_t current_tick;
volatile uint32_t post_tick;

/*                                                      Constants                                                    */
/*********************************************************************************************************************/

/*                                             Local functions prototypes                                            */
/*********************************************************************************************************************/

/*                                           Local functions implementation                                          */
/*********************************************************************************************************************/
void timebase_init (void)
{
    __disable_irq ();
    systick_config_clock_cycles (DELAY_MS);
    systick_config_reset_value ();
    systick_config_select_clk_src (int_clock);
    systick_config_enable_interrupt (true);
    systick_config_enable (true);
    __enable_irq();
}

void tick_increment (void)
{
    current_tick += TICK_FREQUENCY;
}

/* Interrupt handler */
void Systick_Handler (void)
{
    tick_increment();
}

uint32_t get_tick (void)
{
    __disable_irq();
    post_tick = current_tick;
    __enable_irq();
    return post_tick;
}

void delay_ms (uint32_t delay)
{
    unsigned int tickstart = get_tick();
    unsigned int wait = delay;
    if(wait < MAX_DELAY)
    {
        wait += TICK_FREQUENCY;
    }
    else
    {/* Do nothing */}
    while ((get_tick() - tickstart) < wait){}
}

/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/
