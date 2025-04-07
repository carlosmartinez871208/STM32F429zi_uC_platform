/*********************************************************************************************************************/
/*                                                  SOURCE GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $File: rcc.c
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2025-03-23 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/* rcc.c:
          Reset and clock control.
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
#include "rcc.h"

/*                                                        Types                                                      */
/*********************************************************************************************************************/

/*                                                      Constants                                                    */
/*********************************************************************************************************************/

/*                                             Local functions prototypes                                            */
/*********************************************************************************************************************/

/*                                           Local functions implementation                                          */
/*********************************************************************************************************************/
/* RCC Control Register (RCC_CR): */
/* Enable HSI (High Speed Internal Clock). */
void rcc_rc_hsi_enable  (void)
{
    RCC_CR |= RCC_CR_HSION; /* This source clock is enabled by default. */
    while (RCC_CR_HSIRDY != (RCC_CR & RCC_CR_HSIRDY)); /* Waits until HSI is ready. */
}

/* Enable HSE (High Speed External Clock). */
void rcc_rc_hse_enable  (void)
{
    RCC_CR |= RCC_CR_HSEON; /* Enables HSE as source clock. */
    while (RCC_CR_HSERDY != (RCC_CR & RCC_CR_HSERDY)); /* Waits until HSE is ready. */
}

/* Enable main PLL. */
void rcc_rc_pll_enable  (void)
{
    RCC_CR |= RCC_CR_PLLON; /* Enables PLL as source clock. */
    while (RCC_CR_PLLRDY != (RCC_CR & RCC_CR_PLLRDY)); /* Waits until PLL is ready. */
}

/* Disable HSI (High Speed Internal Clock) */
void rcc_rc_hsi_disable (void)
{
    RCC_CR &= (~RCC_CR_HSION); /* Disables HSI as source clock. */
    while (NOT_READY != (RCC_CR & RCC_CR_HSIRDY)); /* Waits until HSI ready is locked. */
}

/* Disable HSE (High Speed External Clock) */
void rcc_rc_hse_disable (void)
{
    RCC_CR &= (~RCC_CR_HSEON); /* Disables HSE as source clock. */
    while (NOT_READY != (RCC_CR & RCC_CR_HSERDY)); /* Waits until HSE ready is locked. */
}

/* Disable main PLL. */
void rcc_rc_pll_disable (void)
{
    RCC_CR &= (~RCC_CR_PLLON); /* Disables PLL as source clock. */
    while (NOT_READY != (RCC_CR & RCC_CR_PLLRDY)); /* Waits until PLL ready is locked. */
}

/* RCC PLL Configuration Register (RCC_PLLCFGR): */
/* Configures system clock: */
void rcc_pllcfgr_sys_clk (uint32_t clock_cfgr)
{
    
    RCC_PLLCFGR = clock_cfgr;
}

/* Choises hsi as PLL source clock: */
void rcc_pllcfgr_pllsrc_hsi (void)
{
    RCC_PLLCFGR &= (~RCC_PLLCFGR_PLLSRC);
}

/* Choises hse as PLL source clock: */
void rcc_pllcfgr_pllsrc_hse (void)
{
    RCC_PLLCFGR |= RCC_PLLCFGR_PLLSRC;
}

/* RCC Clock configuration Register: */
/* Sets hsi as system clocK. */
void rcc_cfgr_sys_clk_hsi    (void)
{
    RCC_CFGR &= (~RCC_CFGR_SW_RESET); /* 0000 0000 & FFFF FFFC = 0000 0000 */
    while (RCC_ZERO != (RCC_CFGR & RCC_CFGR_SWS_RESET)); /* Wait until RCC_CFGR switch status is 0 */
    RCC_CFGR &= (~RCC_CFGR_SW_0);     /* 0000 0000 & FFFF FFFE = 0000 0000 */
    RCC_CFGR &= (~RCC_CFGR_SW_1);     /* 0000 0000 & FFFF FFFD = 0000 0000 */
    while (RCC_ZERO != (RCC_CFGR & RCC_CFGR_SWS_HSI)); /* Wait until RCC_CFGR switch status is 0 (0000 0000 & 0000 000C = 0000 0000) */
}
/* Sets hse as system clock. */
void rcc_cfgr_sys_clk_hse    (void)
{
    RCC_CFGR &= (~RCC_CFGR_SW_RESET); /* 0000 0000 & FFFF FFFC = 0000 0000 */
    while (RCC_ZERO != (RCC_CFGR & RCC_CFGR_SWS_RESET)); /* Wait until RCC_CFGR switch status is 0 */
    RCC_CFGR |= RCC_CFGR_SW_0;        /* 0000 0000 | 0000 0001 = 0000 0001 */
    RCC_CFGR &= (~RCC_CFGR_SW_1);     /* 0000 0001 & FFFF FFFD = 0000 0001 */
    while (RCC_CFGR_SWS_HSE != (RCC_CFGR & RCC_CFGR_SWS_HSE)); /* Wait until RCC_CFGR switch status is 1 (0000 0001 & 0000 0004 = 0000 0000) */
}

/* Sets pll as system clock. */
void rcc_cfgr_sys_clk_pll    (void)
{
    RCC_CFGR &= (~RCC_CFGR_SW_RESET); /* 0000 0000 & FFFF FFFC = 0000 0000 */
    while (RCC_ZERO != (RCC_CFGR & RCC_CFGR_SWS_RESET)); /* Wait until RCC_CFGR switch status is 0 */
    RCC_CFGR &= (~RCC_CFGR_SW_0);     /* 0000 0000 & FFFF FFFE = 0000 0000 */
    RCC_CFGR |= RCC_CFGR_SW_1;        /* 0000 0000 | 0000 0002 = 0000 0002*/
    while (RCC_CFGR_SWS_PLL != (RCC_CFGR & RCC_CFGR_SWS_PLL)); /* Wait until RCC_CFGR switch status is 2 (0000 0002 & 0000 0008 = 0000 0000) */
}

/* Set AHB system clock divided factor. Max 180 MHz: */
void rcc_cfgr_ahb_prescaler  (uint32_t ahb_pre)
{
    RCC_CFGR &= (~RCC_CFGR_HPRE_RESET);
    RCC_CFGR |= ahb_pre;
}

/* Set APB1 system clock divided factor. Max 45 MHz: */
void rcc_cfgr_apb1_prescaler (uint32_t apb1_pre)
{
    RCC_CFGR &= (~RCC_CFGR_PPRE1_RESET);
    RCC_CFGR |= apb1_pre;
}

/* Set APB2 system clock divided factor. Max 90 MHz: */
void rcc_cfgr_apb2_prescaler (uint32_t apb2_pre)
{
    RCC_CFGR &= (~RCC_CFGR_PPRE2_RESET);
    RCC_CFGR |= apb2_pre;
}

/* RCC APB1 peripheral clock enable in low power mode register: */
void rcc_apb1lpenr_pwrlp_enable  (void)
{
    RCC_APB1LPENR |= RCC_APB1LPENR_PWRLPEN;
}

/*  Power interface clock disable during Sleep mode: */
void rcc_apb1lpenr_pwrlp_disable (void)
{
    RCC_APB1LPENR &= (~RCC_APB1LPENR_PWRLPEN);
}

/* RCC AHB1ENR functions: */
void rcc_aph1enr_gpio_enable (uint32_t gpio_x_en)
{
    RCC_AHB1ENR |= gpio_x_en;
}

void rcc_aph1enr_gpio_disable (uint32_t gpio_x_dis)
{
    RCC_AHB1ENR &= (~gpio_x_dis);
}

void rcc_aph1enr_crc_enable (void)
{
    RCC_AHB1ENR |= RCC_AHB1ENR_CRCRN;
}

void rcc_aph1enr_crc_disable (void)
{
    RCC_AHB1ENR &= (~RCC_AHB1ENR_CRCRN);
}
/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/
