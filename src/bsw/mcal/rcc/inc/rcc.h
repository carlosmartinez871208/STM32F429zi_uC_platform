/*********************************************************************************************************************/
/*                                                INCLUDES GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $File: template.h
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2025-03-23 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/* rcc.h:
         Reset and clock control peripheral.
 */
/*********************************************************************************************************************/
/* ALL RIGHTS RESERVED                                                                                               */
/*                                                                                                                   */
/* The reproduction, transmission, or use of this document or its content is                                         */
/* not permitted without express written authority. Offenders will be liable                                         */
/* for damages.                                                                                                      */
/*********************************************************************************************************************/
#ifndef RCC_H_
#define RCC_H_
/*                                                       Includes                                                    */
/*********************************************************************************************************************/
#include "Std_types.h"
#include "peripherals.h"

/*                                                        Types                                                      */
/*********************************************************************************************************************/
/* RCC Clock Control Register (RCC_CR): */
#ifndef RCC_CR
 #define RCC_CR_OFFSET         (0x0ul)
 #define RCC_CR                (*(__IO uint32_t*)(RCC_BASE_ADDRESS + RCC_CR_OFFSET))
#endif

/* RCC PLL Configuration Register (RCC_PLLCFGR): */
#ifndef RCC_PLLCFGR
 #define RCC_PLLCFGR_OFFSET    (0x04ul)
 #define RCC_PLLCFGR           (*(__IO uint32_t*)(RCC_BASE_ADDRESS + RCC_PLLCFGR_OFFSET))
#endif

/* RCC Clock configuration Register: */
#ifndef RCC_CFGR
 #define RCC_CFGR_OFFSET       (0x08ul)
 #define RCC_CFGR              (*(__IO uint32_t*)(RCC_BASE_ADDRESS + RCC_CFGR_OFFSET))
#endif

/* RCC AHB1 peripheral clock register (RCC_AHB1ENR): */
#ifndef RCC_AHB1ENR
 #define RCC_AHB1ENR_OFFSET    (0x30ul)
 #define RCC_AHB1ENR (*(__IO uint32_t*)(RCC_BASE_ADDRESS + RCC_AHB1ENR_OFFSET))
#endif

/* RCC AHB1 peripheral clock register (RCC_AHB1ENR): */
#ifndef RCC_APB1ENR
 #define RCC_APB1ENR_OFFSET    (0x40ul)
 #define RCC_APB1ENR (*(__IO uint32_t*)(RCC_BASE_ADDRESS + RCC_APB1ENR_OFFSET))
#endif

/* RCC APB1 peripheral clock enable in low power mode register:*/
#ifndef RCC_APB1LPENR
 #define RCC_APB1LPENR_OFFSETT (0x60ul)
 #define RCC_APB1LPENR         (*(__IO uint32_t*)(RCC_BASE_ADDRESS + RCC_APB1LPENR_OFFSETT))
#endif

/*                                                      Constants                                                    */
/*********************************************************************************************************************/
/* Not ready status macro: */
#define NOT_READY     (0ul)
/* RCC Clock Control Register (RCC_CR): */
/* HSI internal high speed clock enable: */
#define RCC_CR_HSION  (1ul << 0)
/* HSI ready flag: */
#define RCC_CR_HSIRDY (1ul << 1)
/* HSE clock enable: */
#define RCC_CR_HSEON  (1ul << 16)
/* HSE clock ready flag: */
#define RCC_CR_HSERDY (1ul << 17)
/* PLL clock enable: */
#define RCC_CR_PLLON  (1ul << 24)
/* PLL clock ready flag: */
#define RCC_CR_PLLRDY (1ul << 25)

/* RCC PLL Configuration Register (RCC_PLLCFGR): */
/*
    ** Configures Main PLL: see formulas from Reference Manual, page: 228.
    ** HSI as clock input
    ** fvco = 384 MHz
    ** fpllout = 96 MHz
    ** fusb = 48 MHz
    ** PLLM = 8
    ** PLLN = 384
    ** PLLP = 4
    ** PLLQ = 8
*/
#define RCC_PLLCFGR_PLLM   (16ul << 0)  /*0x010<<00= 0000 0010*/
#define RCC_PLLCFGR_PLLN   (384ul << 6) /*0x180<<06= 0000 6000*/
#define RCC_PLLCFGR_PLLP   (1ul << 16)  /*0x001<<16= 0001 0000*/
#define RCC_PLLCFGR_PLLQ   (8ul << 24)  /*0x008<<24= 0800 0000*/
/* Configures System Clock: */
#define RCC_PLLCFGR_SYSCLK (RCC_PLLCFGR_PLLQ|RCC_PLLCFGR_PLLP|RCC_PLLCFGR_PLLN|RCC_PLLCFGR_PLLM)
/* PLL source clock: */
#define RCC_PLLCFGR_PLLSRC (0x1ul << 22)

/* RCC Clock configuration Register: */
#define RCC_ZERO               (0x0ul)
/* Select main system clock: */
#define RCC_CFGR_SW_RESET      (0x3ul << 0) /* Reset value. */
#define RCC_CFGR_SW_0          (0x1ul << 0) /* SW0. */
#define RCC_CFGR_SW_1          (0x1ul << 1) /* SW1. */
/* System Clock switch status: */
#define RCC_CFGR_SWS_RESET     (3ul << 2) /* Reset value. */
#define RCC_CFGR_SWS_HSI       (3ul << 2) /* HSI as system clock. */
#define RCC_CFGR_SWS_HSE       (1ul << 2) /* HSE as system clock. */
#define RCC_CFGR_SWS_PLL       (2ul << 2) /* PLL as system clock. */
/* HPRE: AHB prescaler: */
#define RCC_CFGR_HPRE_RESET    (0xFul << 4) /* Reset value */
#define RCC_CFGR_HPRE_DIV_0    (0x1ul << 4)
#define RCC_CFGR_HPRE_DIV_2    (0x8ul << 4)
#define RCC_CFGR_HPRE_DIV_4    (0x9ul << 4)
#define RCC_CFGR_HPRE_DIV_8    (0xAul << 4)
#define RCC_CFGR_HPRE_DIV_16   (0xBul << 4)
#define RCC_CFGR_HPRE_DIV_64   (0xCul << 4)
#define RCC_CFGR_HPRE_DIV_128  (0xDul << 4)
#define RCC_CFGR_HPRE_DIV_256  (0xEul << 4)
#define RCC_CFGR_HPRE_DIV_512  (0xFul << 4)
/* PPRE1: APB1 prescaler: */
#define RCC_CFGR_PPRE1_RESET   (0x7ul << 10) /* Reset value */
#define RCC_CFGR_PPRE1_DIV_0   (0x1ul << 10)
#define RCC_CFGR_PPRE1_DIV_2   (0x4ul << 10)
#define RCC_CFGR_PPRE1_DIV_4   (0x5ul << 10)
#define RCC_CFGR_PPRE1_DIV_8   (0x6ul << 10)
#define RCC_CFGR_PPRE1_DIV_16  (0x7ul << 10)
/* PPRE2: APB2 prescaler: */
#define RCC_CFGR_PPRE2_RESET   (0x7ul << 13) /* Reset value */
#define RCC_CFGR_PPRE2_DIV_0   (0x1ul << 13)
#define RCC_CFGR_PPRE2_DIV_2   (0x4ul << 13)
#define RCC_CFGR_PPRE2_DIV_4   (0x5ul << 13)
#define RCC_CFGR_PPRE2_DIV_8   (0x6ul << 13)
#define RCC_CFGR_PPRE2_DIV_16  (0x7ul << 13)

/* RCC APB1 peripheral clock enable in low power mode register:*/
#define RCC_APB1LPENR_PWRLPEN  (0x1ul << 28)

/* RCC AHB1ENR macros: */
/* GPIOs enable A to K */
#define RCC_AHB1ENR_GPIOAEN    (0x1ul << 0)
#define RCC_AHB1ENR_GPIOBEN    (0x1ul << 1)
#define RCC_AHB1ENR_GPIOCEN    (0x1ul << 2)
#define RCC_AHB1ENR_GPIODEN    (0x1ul << 3)
#define RCC_AHB1ENR_GPIOEEN    (0x1ul << 4)
#define RCC_AHB1ENR_GPIOFEN    (0x1ul << 5)
#define RCC_AHB1ENR_GPIOGEN    (0x1ul << 6)
#define RCC_AHB1ENR_GPIOHEN    (0x1ul << 7)
#define RCC_AHB1ENR_GPIOIEN    (0x1ul << 8)
#define RCC_AHB1ENR_GPIOJEN    (0x1ul << 9)
#define RCC_AHB1ENR_GPIOKEN    (0x1ul << 10)
/* CRC enable */
#define RCC_AHB1ENR_CRCRN      (0x1ul << 12)
/* USART */
#define RCC_APB1ENR_USART2EN   (0x1ul<<17)
#define RCC_APB1ENR_USART3EN   (0x1ul<<18)

/*                                                 Exported Variables                                                */
/*********************************************************************************************************************/

/*                                            Exported functions prototypes                                          */
/*********************************************************************************************************************/
/* RCC Control Register (RCC_CR): */
extern void rcc_rc_hsi_enable   (void); /* Enable HSI (High Speed Internal Clock). */
extern void rcc_rc_hse_enable   (void); /* Enable HSE (High Speed External Clock). */
extern void rcc_rc_pll_enable   (void); /* Enable main PLL. */
extern void rcc_rc_hsi_disable  (void); /* Disable HSI (High Speed Internal Clock). */
extern void rcc_rc_hse_disable  (void); /* Disable HSE (High Speed External Clock). */
extern void rcc_rc_pll_disable  (void); /* Disable main PLL. */

/* RCC PLL Configuration Register (RCC_PLLCFGR): */
extern void rcc_pllcfgr_sys_clk    (uint32_t clock_cfgr); /* Configures system clock frequency. */
extern void rcc_pllcfgr_pllsrc_hsi (void); /* Choises hsi as PLL source clock */
extern void rcc_pllcfgr_pllsrc_hse (void); /* Choises hse as PLL source clock */

/* RCC Clock configuration Register: */
extern void rcc_cfgr_sys_clk_hsi    (void); /* Sets hsi as system clocl. */
extern void rcc_cfgr_sys_clk_hse    (void); /* Sets hse as system clock. */
extern void rcc_cfgr_sys_clk_pll    (void); /* Sets pll as system clock. */
extern void rcc_cfgr_ahb_prescaler  (uint32_t ahb_pre);  /* Set AHB system clock divided factor. */
extern void rcc_cfgr_apb1_prescaler (uint32_t apb1_pre); /* Set APB1 system clock divided factor. */
extern void rcc_cfgr_apb2_prescaler (uint32_t apb2_pre); /* Set APB2 system clock divided factor. */

/* RCC APB1 peripheral clock enable in low power mode register:*/
extern void rcc_apb1lpenr_pwrlp_enable  (void); /*  Power interface clock enable during Sleep mode. */
extern void rcc_apb1lpenr_pwrlp_disable (void); /*  Power interface clock disable during Sleep mode. */

/* RCC AHB1ENR functions: */
/* GPIOs */
extern void rcc_aph1enr_gpio_enable  (uint32_t gpio_x_en);  /* Enable clock to gpio x. */
extern void rcc_aph1enr_gpio_disable (uint32_t gpio_x_dis); /* Disable clock to gpio x. */
/* CRC */
extern void rcc_aph1enr_crc_enable (void);  /* Enable clock to CRC. */
extern void rcc_aph1enr_crc_disable (void); /* Disable clock to CRC. */

/* RCC APB2ENR functions: */
/* USART */
extern void rcc_apb1enr_usart_enable (uint32_t usart_en);
extern void rcc_apb1enr_usart_disable (uint32_t usart_en);
/*********************************************************************************************************************/
#endif
/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/ 