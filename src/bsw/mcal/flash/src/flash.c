/*********************************************************************************************************************/
/*                                                  SOURCE GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $File: flash.c
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2025-03-23 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/* flash.c:
          Flash memory peripheral control.
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
#include "flash.h"

/*                                                        Types                                                      */
/*********************************************************************************************************************/

/*                                                      Constants                                                    */
/*********************************************************************************************************************/

/*                                             Local functions prototypes                                            */
/*********************************************************************************************************************/

/*                                           Local functions implementation                                          */
/*********************************************************************************************************************/
/* Flash Access Control Register (FLASH_ACR): */
/* FLASH ACR latency: */
void flash_acr_latency      (uint32_t wait_states)
{
    FLASH_ACR &= (~FLASH_ACR_LAT_RESET);
    FLASH_ACR |= wait_states;
}

/* FLASH ACR prefetch enable: */
/* Enable prefetch. */
void flash_acr_prf_enable   (void)
{
    FLASH_ACR |= FLASH_ACR_PRFTEN;
}

/* Disable prefetch. */
void flash_acr_prf_disable  (void)
{
    FLASH_ACR &= (~FLASH_ACR_PRFTEN);
}

/* FLASH ACR Instruction cache enable: */
/* Enable instruction cache. */
void flash_acr_icen_enable  (void)
{
    FLASH_ACR |= FLASH_ACR_ICEN;
}

/* Disable instruction cache. */
void flash_acr_icen_disable (void)
{
    FLASH_ACR &= (~FLASH_ACR_ICEN);
}
/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/
