/*********************************************************************************************************************/
/*                                                INCLUDES GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $File: mcu_driver.h
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2025-03-23 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/* mcu_driver.h:
               MCU (Micro Controller Unit) Driver
               Device driver that performs MCU settings
               Initializes clock, performs power mode settings
 */
/*********************************************************************************************************************/
/* ALL RIGHTS RESERVED                                                                                               */
/*                                                                                                                   */
/* The reproduction, transmission, or use of this document or its content is                                         */
/* not permitted without express written authority. Offenders will be liable                                         */
/* for damages.                                                                                                      */
/*********************************************************************************************************************/
#ifndef MCU_DRIVER_H_
#define MCU_DRIVER_H_
/*                                                       Includes                                                    */
/*********************************************************************************************************************/
#include "Std_types.h"
#include "pwr.h"
#include "rcc.h"

/*                                                        Types                                                      */
/*********************************************************************************************************************/

/*                                                      Constants                                                    */
/*********************************************************************************************************************/

/*                                                 Exported Variables                                                */
/*********************************************************************************************************************/

/*                                            Exported functions prototypes                                          */
/*********************************************************************************************************************/
/* RCC */
/* RCC Control Register (RCC_CR): */
#define mcu_driver_rcc_rc_hsi_enable(void)              rcc_rc_hsi_enable(void)
#define mcu_driver_rcc_rc_hse_enable(void)              rcc_rc_hse_enable(void)
#define mcu_driver_rcc_rc_pll_enable(void)              rcc_rc_pll_enable(void)
#define mcu_driver_rcc_rc_hsi_disable(void)             rcc_rc_hsi_disable(void)
#define mcu_driver_rcc_rc_hse_disable(void)             rcc_rc_hse_disable(void)
#define mcu_driver_rcc_rc_pll_disable(void)             rcc_rc_pll_disable(void)
/* RCC PLL Configuration Register (RCC_PLLCFGR): */
#define mcu_driver_rcc_pllcfgr_sys_clk(uint32_t)        rcc_pllcfgr_sys_clk(uint32_t)
#define mcu_driver_rcc_pllcfgr_pllsrc_hsi(void)         rcc_pllcfgr_pllsrc_hsi(void)
#define mcu_driver_rcc_pllcfgr_pllsrc_hse(void)         rcc_pllcfgr_pllsrc_hse(void)
/* RCC Clock configuration Register: */
#define mcu_driver_rcc_cfgr_sys_clk_hsi(void)           rcc_cfgr_sys_clk_hsi(void)
#define mcu_driver_rcc_cfgr_sys_clk_hse(void)           rcc_cfgr_sys_clk_hse(void)
#define mcu_driver_rcc_cfgr_sys_clk_pll(void)           rcc_cfgr_sys_clk_pll(void)
#define mcu_driver_rcc_cfgr_ahb_prescaler(uint32_t)     rcc_cfgr_ahb_prescaler(uint32_t)
#define mcu_driver_rcc_cfgr_apb1_prescaler(uint32_t)    rcc_cfgr_apb1_prescaler(uint32_t)
#define mcu_driver_rcc_cfgr_apb2_prescaler(uint32_t)    rcc_cfgr_apb2_prescaler(uint32_t)
/* RCC APB1 peripheral clock enable in low power mode register:*/
#define mcu_driver_rcc_apb1lpenr_pwrlp_enable(void)     rcc_apb1lpenr_pwrlp_enable(void)
#define mcu_driver_rcc_apb1lpenr_pwrlp_disable(void)    rcc_apb1lpenr_pwrlp_enable(void)
/* PWR */
/* PWR power control register (PWR_CR): */
#define mcu_driver_pwr_cr_vos_mode(uint32_t)            pwr_cr_vos_mode(uint32_t)
#define mcu_driver_pwr_cr_pvd_level(uint32_t)           pwr_cr_pvd_level(uint32_t)
/*********************************************************************************************************************/
#endif
/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/ 