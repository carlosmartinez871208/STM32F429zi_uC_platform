/*********************************************************************************************************************/
/*                                                INCLUDES GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $File: systick.h
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2025-03-23 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/* systick.h:
              configures systick timer.
 */
/*********************************************************************************************************************/
/* ALL RIGHTS RESERVED                                                                                               */
/*                                                                                                                   */
/* The reproduction, transmission, or use of this document or its content is                                         */
/* not permitted without express written authority. Offenders will be liable                                         */
/* for damages.                                                                                                      */
/*********************************************************************************************************************/
#ifndef SYSTICK_H_
#define SYSTICK_H_
/*                                                       Includes                                                    */
/*********************************************************************************************************************/
#include "Std_types.h"
#include "peripherals.h"
/*                                                        Types                                                      */
/*********************************************************************************************************************/
/* Systick control and status register. */
#ifndef SYST_CSR_OFFSET
#define SYST_CSR_OFFSET (0x0ul)
 #define SYST_CSR (*(__IO uint32_t*)(SYSTICK_BASE_ADDRESS + SYST_CSR_OFFSET))
#endif

/* Systick reload value register */
#ifndef SYST_RVR_OFFSET
 #define SYST_RVR_OFFSET (0x4ul)
 #define SYST_RVR (*(__IO uint32_t*)(SYSTICK_BASE_ADDRESS + SYST_RVR_OFFSET))
#endif

/* Systick current value register */
#ifndef SYST_CVR_OFFSET
 #define SYST_CVR_OFFSET (0x8ul)
 #define SYST_CVR (*(__IO uint32_t*)(SYSTICK_BASE_ADDRESS + SYST_CVR_OFFSET))
#endif

typedef enum {int_clock=0,ext_clock}clock_source;

/*                                                      Constants                                                    */
/*********************************************************************************************************************/

/* Enable Systick counter */
#define SYST_CSR_ENABLE       (1ul << 0)
/* Enable Systick exception request */
#define SYST_CSR_TICKINT      (1ul << 1)
/* Indicates Systick source clock */
#define SYST_CSR_CLK_SOURCE   (1ul << 2)
/* SysTick count flag, returns 1 if timer counted to 0 since last time this was read. */
#define SYST_CSR_COUNTFLAG    (1ul << 16)
/* SysTick down counter */
#define DELAY_MS              (0x176FFul & 0xFFFFFFul) /* 95,999 pulses = 1 mS */
/* OS tick timer. */
#define OS_TICK_TIMER         (0x1193Ful & 0xFFFFFFul) /* 750us OS tick */
/* Clear Systick value register */
#define SYST_CVR_CURRENT_CLR  (0x000000ul)
/* Determine how many ticks are need */
#define TICK_FREQUENCY        (1ul)
/* Maximun delay allowed */
#define MAX_DELAY             (0xFFFFFFFFul)

/*                                                 Exported Variables                                                */
/*********************************************************************************************************************/

/*                                            Exported functions prototypes                                          */
/*********************************************************************************************************************/
extern void systick_config_clock_cycles     (uint32_t clk_cycles);
extern void systick_config_reset_value      (void);
extern void systick_config_select_clk_src   (clock_source clk_src);
extern void systick_config_enable_interrupt (bool en_int);
extern void systick_config_enable           (bool en_systick);


/*********************************************************************************************************************/
#endif
/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/ 