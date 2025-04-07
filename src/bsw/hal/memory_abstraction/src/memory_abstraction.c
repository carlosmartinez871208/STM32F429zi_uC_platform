/*********************************************************************************************************************/
/*                                                  SOURCE GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $File: device_abstraction.c
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2025-03-23 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/* device_abstraction.c:
                         This module abstracts from ECU-specific onboard devices. This module contains drivers for 
                         onboard devices that are not sensors, actuators, or timers, such as internal or external 
                         watchdog timers.
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
#include "memory_abstraction.h"
/*                                                        Types                                                      */
/*********************************************************************************************************************/

/*                                                      Constants                                                    */
/*********************************************************************************************************************/

/*                                             Local functions prototypes                                            */
/*********************************************************************************************************************/

/*                                           Local functions implementation                                          */
/*********************************************************************************************************************/
void mem_abs_set_memory_latency  (uint32_t wait_states)
{
    flash_acr_latency(wait_states);
}

void mem_abs_set_memory_prefetch (bool set_pref)
{
    if(true==set_pref)
    {
        flash_acr_prf_enable();
    }
    else
    {
        flash_acr_prf_disable();
    }
}

void mem_abs_set_memory_cache    (bool set_cache)
{
    if(true==set_cache)
    {
        flash_acr_icen_enable();
    }
    else
    {
        flash_acr_icen_disable();
    }
}

/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/
