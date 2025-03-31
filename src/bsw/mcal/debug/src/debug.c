/*********************************************************************************************************************/
/*                                                  SOURCE GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $File: debug.c
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2025-03-23 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/* debug.c:
          debug control peripherals.
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
#include "debug.h"

/*                                                        Types                                                      */
/*********************************************************************************************************************/

/*                                                      Constants                                                    */
/*********************************************************************************************************************/

/*                                             Local functions prototypes                                            */
/*********************************************************************************************************************/

/*                                           Local functions implementation                                          */
/*********************************************************************************************************************/
/* Microcontroller device ID (DBGMCU_IDCODE): */
/* Return: microcontroller revision id: */
uint32_t debug_dbgmcu_rev_id (void)
{
    return (uint32_t)(DBGMCU_IDCODE & DBGMCU_REV_ID_MASK);
}

/* Return: microcontroller device id. */
uint32_t debug_dbgmcu_dev_id (void)
{
    return (uint32_t)(DBGMCU_IDCODE & DBGMCU_DEV_ID_MASK);
}


/* Debug microcontroller control register (DBGMCU_CR): */
/* Debug sleep mode: on. */
void debug_dbgmcu_cr_sleep_on    (void)
{
    DBGMCU_CR |= DBGMCU_CR_SLEEP;
}

/* Debug sleep mode: off. */
void debug_dbgmcu_cr_sleep_off   (void)
{
    DBGMCU_CR &= (~DBGMCU_CR_SLEEP);
}

/* Debug stop mode: on. */
void debug_dbgmcu_cr_stop_on     (void)
{
    DBGMCU_CR |= DBGMCU_CR_STOP;
}

/* Debug stop mode: off. */
void debug_dbgmcu_cr_stop_off    (void)
{
    DBGMCU_CR &= (~DBGMCU_CR_STOP);
}

/* Debug standby mode: on. */
void debug_dbgmcu_cr_standby_on  (void)
{
    DBGMCU_CR |= DBGMCU_CR_STANDBY;
}

/* Debug standby mode: off. */
void debug_dbgmcu_cr_standby_off (void)
{
    DBGMCU_CR &= (~DBGMCU_CR_STANDBY);
}

/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/
