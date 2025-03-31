/*********************************************************************************************************************/
/*                                                INCLUDES GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $File: flash.h
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2025-03-23 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/* flash.h:
         Flash memory peripheral control.
 */
/*********************************************************************************************************************/
/* ALL RIGHTS RESERVED                                                                                               */
/*                                                                                                                   */
/* The reproduction, transmission, or use of this document or its content is                                         */
/* not permitted without express written authority. Offenders will be liable                                         */
/* for damages.                                                                                                      */
/*********************************************************************************************************************/
#ifndef FLASH_H_
#define FLASH_H_
/*                                                       Includes                                                    */
/*********************************************************************************************************************/
#include "Std_types.h"
#include "peripherals.h"

/*                                                        Types                                                      */
/*********************************************************************************************************************/
/* Flash Access Control Register (FLASH_ACR): */
#ifndef FLASH_ACR
 #define FLASH_ACR_OFFSET (0x0ul)
 #define FLASH_ACR        (*(__IO uint32_t*)(FLASH_IR_BASE_ADDRESS + FLASH_ACR_OFFSET))
#endif

/*                                                      Constants                                                    */
/*********************************************************************************************************************/
/* FLASH ACR latency: */
#define FLASH_ACR_LAT_RESET (0x7ul << 0)
#define FLASH_ACR_LAT_0_WS  (0x0ul)
#define FLASH_ACR_LAT_1_WS  (0x1ul << 0)
#define FLASH_ACR_LAT_2_WS  (0x2ul << 0)
#define FLASH_ACR_LAT_3_WS  (0x3ul << 0)
#define FLASH_ACR_LAT_4_WS  (0x4ul << 0)
#define FLASH_ACR_LAT_5_WS  (0x5ul << 0)
#define FLASH_ACR_LAT_6_WS  (0x6ul << 0)
#define FLASH_ACR_LAT_7_WS  (0x7ul << 0)

/* FLASH ACR prefetch enable: */
#define FLASH_ACR_PRFTEN    (1ul << 8)

/* FLASH ACR Instruction cache enable: */
#define FLASH_ACR_ICEN      (1ul << 9)

/*                                                 Exported Variables                                                */
/*********************************************************************************************************************/

/*                                            Exported functions prototypes                                          */
/*********************************************************************************************************************/
/* Flash Access Control Register (FLASH_ACR): */
//* FLASH ACR latency: */
extern void flash_acr_latency      (uint32_t wait_states); /* Set latency wait states. */

/* FLASH ACR prefetch enable: */
extern void flash_acr_prf_enable   (void); /* Enable prefetch. */
extern void flash_acr_prf_disable  (void); /* Disable prefetch. */

/* FLASH ACR Instruction cache enable: */
extern void flash_acr_icen_enable  (void); /* Enable instruction cache. */
extern void flash_acr_icen_disable (void); /* Disable instruction cache. */

/*********************************************************************************************************************/
#endif
/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/ 