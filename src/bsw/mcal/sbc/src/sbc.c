/*********************************************************************************************************************/
/*                                                  SOURCE GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $File: sbc.c
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2025-03-23 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/* sbc.c:
          provides system implementation information ans system control.
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
#include "sbc.h"

/*                                                        Types                                                      */
/*********************************************************************************************************************/

/*                                                      Constants                                                    */
/*********************************************************************************************************************/

/*                                             Local functions prototypes                                            */
/*********************************************************************************************************************/

/*                                           Local functions implementation                                          */
/*********************************************************************************************************************/
void sbc_vtor_config_offset (uint32_t mem_base,uint32_t tab_offset)
{
    SBC_VTOR = (mem_base|tab_offset);
}

void sbc_icsr_config_systick_pending_bit (bool config_bit)
{
    if(true==config_bit)
    {
        SBC_ICSR |= SBC_ISCR_SET_PEN_BIT;
    }
    else
    {
        SBC_ICSR &= (~SBC_ISCR_SET_PEN_BIT);
    }
}

void sbc_icsr_config_pendsv_pending_bit (void)
{
    SBC_ICSR = SBC_ISCR_SET_SET_PENSV_BIT;
}

void sbc_shpr_config_handler_priority (IRQn_type irqn,uint32_t priority)
{
    if(SysTick_IRQn==irqn)
    {
        SBC_SPHR3 &= SBC_SHPR_SYSTICK_RST;
        SBC_SPHR3 |= priority;
    }
    if(PendSV_IRQn==irqn)
    {
        SBC_SPHR3 &= SBC_SHPR_PENDSV_RST;
        SBC_SPHR3 |= priority;
    }
    else{/* Do nothing */}
}
/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/
