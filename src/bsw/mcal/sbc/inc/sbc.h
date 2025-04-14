/*********************************************************************************************************************/
/*                                                INCLUDES GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $File: sbc.h
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2025-03-23 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/* sbc.h:
         provides system implementation information ans system control.
 */
/*********************************************************************************************************************/
/* ALL RIGHTS RESERVED                                                                                               */
/*                                                                                                                   */
/* The reproduction, transmission, or use of this document or its content is                                         */
/* not permitted without express written authority. Offenders will be liable                                         */
/* for damages.                                                                                                      */
/*********************************************************************************************************************/
#ifndef SBC_H_
#define SBC_H_
/*                                                       Includes                                                    */
/*********************************************************************************************************************/
#include "Std_types.h"
#include "peripherals.h"

/*                                                        Types                                                      */
/*********************************************************************************************************************/
typedef struct
{
    __IO uint8_t  mmsr;
    __IO uint8_t  bfsr;
    __IO uint16_t ufsr;
}cfsr_type;

/* SBC Control Block Register (SBC_ACTLR): */
#ifndef SBC_ACTLR
 #define SBC_ACTLR_OFFSET         (0x0ul)
 #define SBC_ACTLR                (*(__IO uint32_t*)(SCB_BASE_ADDRESS + SBC_ACTLR_OFFSET))
#endif

#ifndef SBC_CPUID
 #define SBC_CPUID_OFFSET         (0xCF8ul)
 #define SBC_CPUID                (*(__IO uint32_t*)(SCB_BASE_ADDRESS + SBC_CPUID_OFFSET))
#endif

#ifndef SBC_ICSR
 #define SBC_ICSR_OFFSET          (0xCFCul)
 #define SBC_ICSR                 (*(__IO uint32_t*)(SCB_BASE_ADDRESS + SBC_ICSR_OFFSET))
#endif

#ifndef SBC_VTOR
 #define SBC_VTOR_OFFSET          (0xD00ul)
 #define SBC_VTOR                 (*(__IO uint32_t*)(SCB_BASE_ADDRESS + SBC_VTOR_OFFSET))
#endif

#ifndef SBC_AIRCR
 #define SBC_AIRCR_OFFSET         (0xD04l)
 #define SBC_AIRCR                (*(__IO uint32_t*)(SCB_BASE_ADDRESS + SBC_AIRCR_OFFSET))
#endif

#ifndef SBC_SCR
 #define SBC_SCR_OFFSET           (0xD08ul)
 #define SBC_SCR                  (*(__IO uint32_t*)(SCB_BASE_ADDRESS + SBC_SCR_OFFSET))
#endif

#ifndef SBC_CCR
 #define SBC_CCR_OFFSET           (0xD0Cul)
 #define SBC_CCR                  (*(__IO uint32_t*)(SCB_BASE_ADDRESS + SBC_CCR_OFFSET))
#endif

#ifndef SBC_SPHR1
 #define SBC_SPHR1_OFFSET         (0xD10ul)
 #define SBC_SPHR1                (*(__IO uint32_t*)(SCB_BASE_ADDRESS + SBC_SPHR1_OFFSET))
#endif

#ifndef SBC_SPHR2
 #define SBC_SPHR2_OFFSET         (0xD14ul)
 #define SBC_SPHR2                (*(__IO uint32_t*)(SCB_BASE_ADDRESS + SBC_SPHR2_OFFSET))
#endif

#ifndef SBC_SPHR3
 #define SBC_SPHR3_OFFSET         (0xD18ul)
 #define SBC_SPHR3                (*(__IO uint32_t*)(SCB_BASE_ADDRESS + SBC_SPHR3_OFFSET))
#endif

#ifndef SBC_SPHCRS
 #define SBC_SPHCRS_OFFSET        (0xD1Cul)
 #define SBC_SPHCRS               (*(__IO uint32_t*)(SCB_BASE_ADDRESS + SBC_SPHCRS_OFFSET))
#endif

#ifndef SBC_CFSR
 #define SBC_CFSR_OFFSET          (0xD20ul)
 #define SBC_CFSR                 ((cfsr_type*)(SCB_BASE_ADDRESS + SBC_CFSR_OFFSET))
#endif

#ifndef SBC_HFSR
 #define SBC_HFSR_OFFSET          (0xD24ul)
 #define SBC_HFSR                 (*(__IO uint32_t*)(SCB_BASE_ADDRESS + SBC_HFSR_OFFSET))
#endif

#ifndef SBC_MMAR
 #define SBC_MMAR_OFFSET          (0xD2Cul)
 #define SBC_MMAR                 (*(__IO uint32_t*)(SCB_BASE_ADDRESS + SBC_MMAR_OFFSET))
#endif

#ifndef SBC_BFAR
 #define SBC_BFAR_OFFSET          (0xD30ul)
 #define SBC_BFAR                 (*(__IO uint32_t*)(SCB_BASE_ADDRESS + SBC_BFAR_OFFSET))
#endif

#ifndef SBC_AFSR
 #define SBC_AFSR_OFFSET          (0xD34ul)
 #define SBC_AFSR                 (*(__IO uint32_t*)(SCB_BASE_ADDRESS + SBC_AFSR_OFFSET))
#endif

/*                                                      Constants                                                    */
/*********************************************************************************************************************/
#define SBC_ISCR_SET_PEN_BIT      (0x1ul<<26)

/*                                                 Exported Variables                                                */
/*********************************************************************************************************************/
extern void sbc_vtor_config_offset              (uint32_t mem_base,uint32_t tab_offset);
extern void sbc_icsr_config_systick_pending_bit (bool config_bit);

/*                                            Exported functions prototypes                                          */
/*********************************************************************************************************************/


/*********************************************************************************************************************/
#endif
/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/ 