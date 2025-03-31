/*********************************************************************************************************************/
/*                                                INCLUDES GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $File: debug.h
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2025-03-23 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/* debug.h:
         debug control peripheral.
 */
/*********************************************************************************************************************/
/* ALL RIGHTS RESERVED                                                                                               */
/*                                                                                                                   */
/* The reproduction, transmission, or use of this document or its content is                                         */
/* not permitted without express written authority. Offenders will be liable                                         */
/* for damages.                                                                                                      */
/*********************************************************************************************************************/
#ifndef DEBUG_H_
#define DEBUG_H_
/*                                                       Includes                                                    */
/*********************************************************************************************************************/
#include "Std_types.h"
#include "peripherals.h"

/*                                                        Types                                                      */
/*********************************************************************************************************************/
/* Microcontroller device ID (DBGMCU_IDCODE): */
#ifndef DBGMCU_IDCODE
 #define DBGMCU_IDCODE_OFFSET (0x0ul)
 #define DBGMCU_IDCODE        (*(__IO uint32_t*)(DBG_MCU_BASE_ADDRESS + DBGMCU_IDCODE_OFFSET))
#endif

/* Debug microcontroller control register (DBGMCU_CR): */
#ifndef DBGMCU_CR
 #define DBGMCU_CR_OFFSET     (0x4ul)
 #define DBGMCU_CR            (*(__IO uint32_t*)(DBG_MCU_BASE_ADDRESS + DBGMCU_CR_OFFSET))
#endif

/*                                                      Constants                                                    */
/*********************************************************************************************************************/
/* Microcontroller device ID (DBGMCU_IDCODE): */
/* Microcontroller revision ID (DBGMCU_IDCODE): */
#define DBGMCU_REV_ID_MASK   (0XFFFF0000ul)
#define DBGMCU_REV_ID_A      (0x10000000ul)
#define DBGMCU_REV_ID_X      (0x10030000ul)
#define DBGMCU_REV_ID_1      (0x10070000ul)
#define DBGMCU_REV_ID_3      (0x20010000ul)
#define DBGMCU_REV_ID_4_5_B  (0x20030000ul)

/* Microcontroller device ID (DBGMCU_IDCODE): */
#define DBGMCU_DEV_ID_MASK   (0xFFFul)
#define DBGMCU_DEV_ID        (0x419ul)

/* Debug microcontroller control register (DBGMCU_CR): */
/* In Sleep mode, the clock controller configuration is not reset and remains in the previously
programmed state. Consequently, when exiting from Sleep mode, the software does not
need to reconfigure the clock controller.*/ 
#define DBGMCU_CR_SLEEP      (0x1ul << 0) /* Debug sleep mode. */
#define DBGMCU_CR_STOP       (0x1ul << 1) /* Debug stop mode. */
#define DBGMCU_CR_STANDBY    (0x1ul << 2) /* Debug standby mode. */

/*                                                 Exported Variables                                                */
/*********************************************************************************************************************/

/*                                            Exported functions prototypes                                          */
/*********************************************************************************************************************/
/* Microcontroller device ID (DBGMCU_IDCODE): */
extern uint32_t debug_dbgmcu_rev_id (void); /* Return: microcontroller revision id. */
extern uint32_t debug_dbgmcu_dev_id (void); /* Return: microcontroller device id. */


/* Debug microcontroller control register (DBGMCU_CR): */
extern void debug_dbgmcu_cr_sleep_on    (void); /* Debug sleep mode: on. */
extern void debug_dbgmcu_cr_sleep_off   (void); /* Debug sleep mode: off. */
extern void debug_dbgmcu_cr_stop_on     (void); /* Debug stop mode: on. */
extern void debug_dbgmcu_cr_stop_off    (void); /* Debug stop mode: off. */
extern void debug_dbgmcu_cr_standby_on  (void); /* Debug standby mode: on. */
extern void debug_dbgmcu_cr_standby_off (void); /* Debug standby mode: off. */
/*********************************************************************************************************************/
#endif
/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/ 