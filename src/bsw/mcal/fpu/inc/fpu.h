/*********************************************************************************************************************/
/*                                                INCLUDES GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $File: fpu.h
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2025-03-23 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/* fpu.h:
          provides control for FPU.
 */
/*********************************************************************************************************************/
/* ALL RIGHTS RESERVED                                                                                               */
/*                                                                                                                   */
/* The reproduction, transmission, or use of this document or its content is                                         */
/* not permitted without express written authority. Offenders will be liable                                         */
/* for damages.                                                                                                      */
/*********************************************************************************************************************/
#ifndef FPU_H_
#define FPU_H_
/*                                                       Includes                                                    */
/*********************************************************************************************************************/
#include "Std_types.h"
#include "peripherals.h"

/*                                                        Types                                                      */
/*********************************************************************************************************************/
/* FPU: coprocessor access control register. */
#ifndef FPU_CPACR
 #define FPU_CPACR_OFFSET         (0x0ul)
 #define FPU_CPACR                (*(__IO uint32_t*)(FPU_BASE_ADDRESS + FPU_CPACR_OFFSET))
#endif

#ifndef FPU_FPCCR
 #define FPU_FPCCR_OFFSET         (0x1ACul)
 #define FPU_FPCCR                (*(__IO uint32_t*)(FPU_BASE_ADDRESS + FPU_FPCCR_OFFSET))
#endif

#ifndef FPU_FPCAR
 #define FPU_FPCAR_OFFSET         (0x1B0ul)
 #define FPU_FPCAR                (*(__IO uint32_t*)(FPU_BASE_ADDRESS + FPU_FPCAR_OFFSET))
#endif

#ifndef FPU_FPDSCR
 #define FPU_FPDSCR_OFFSET         (0x1B4ul)
 #define FPU_FPDSCR                (*(__IO uint32_t*)(FPU_BASE_ADDRESS + FPU_FPDSCR_OFFSET))
#endif

typedef enum{denied=0,privileged,reserved,full}access_control;
/*                                                      Constants                                                    */
/*********************************************************************************************************************/
#define FPU_CPACR_CP10_0             (0x1ul<<20)
#define FPU_CPACR_CP10_1             (0x1ul<<21)
#define FPU_CPACR_CP11_0             (0x1ul<<22)
#define FPU_CPACR_CP11_1             (0x1ul<<23)

/*                                                 Exported Variables                                                */
/*********************************************************************************************************************/
extern void fpu_config_coprocessor_privileges_access (access_control privileges);

/*                                            Exported functions prototypes                                          */
/*********************************************************************************************************************/


/*********************************************************************************************************************/
#endif
/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/ 