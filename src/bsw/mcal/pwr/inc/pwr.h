/*********************************************************************************************************************/
/*                                                INCLUDES GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $File: pwr.h
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2025-03-23 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/* pwr.h:
         power peripheral control.
 */
/*********************************************************************************************************************/
/* ALL RIGHTS RESERVED                                                                                               */
/*                                                                                                                   */
/* The reproduction, transmission, or use of this document or its content is                                         */
/* not permitted without express written authority. Offenders will be liable                                         */
/* for damages.                                                                                                      */
/*********************************************************************************************************************/
#ifndef PWR_H_
#define PWR_H_
/*                                                       Includes                                                    */
/*********************************************************************************************************************/
#include "Std_types.h"
#include "peripherals.h"

/*                                                        Types                                                      */
/*********************************************************************************************************************/
/* PWR power control register (PWR_CR): */
#ifndef PWR_CR
 #define PWR_CR_OFFSET (0x0ul)
 #define PWR_CR        (*(__IO uint32_t*)(PWR_BASE_ADDRESS + PWR_CR_OFFSET))
#endif

/*                                                      Constants                                                    */
/*********************************************************************************************************************/
/* PWR power control register (PWR_CR): */
/* VOS regulator voltage scaling output selection: */
#define PWR_CR_VOS_RESET (0x3ul << 14)
#define PWR_CR_VOS_SCL_3 (0xFFFF7FFFul)
#define PWR_CR_VOS_SCL_2 (0xFFFFBFFFul)
#define PWR_CR_VOS_SCL_1 (0XFFFFFFFFul)

/* PVD Level selection: */
#define PWR_CR_PVD_RESET (0x7ul << 5)
#define PWR_CR_PVD_2_0V  (0x0)
#define PWR_CR_PVD_2_1V  (0x1ul << 5)
#define PWR_CR_PVD_2_3V  (0x2ul << 5)
#define PWR_CR_PVD_2_5V  (0x3ul << 5)
#define PWR_CR_PVD_2_6V  (0x4ul << 5)
#define PWR_CR_PVD_2_7V  (0x5ul << 5)
#define PWR_CR_PVD_2_8V  (0x6ul << 5)
#define PWR_CR_PVD_2_9V  (0x7ul << 5)

/*                                                 Exported Variables                                                */
/*********************************************************************************************************************/

/*                                            Exported functions prototypes                                          */
/*********************************************************************************************************************/
/* PWR power control register (PWR_CR): */
extern void pwr_cr_vos_mode  (uint32_t vos_mode);  /* Set regulator voltage scaling. */
extern void pwr_cr_pvd_level (uint32_t pvd_level); /* Select PVD level. */


/*********************************************************************************************************************/
#endif
/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/ 