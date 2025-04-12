/*********************************************************************************************************************/
/*                                                INCLUDES GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $File: port.h
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2025-03-23 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/* port.h:
          Performs MCU pin settings (I/O, shared functions)
 */
/*********************************************************************************************************************/
/* ALL RIGHTS RESERVED                                                                                               */
/*                                                                                                                   */
/* The reproduction, transmission, or use of this document or its content is                                         */
/* not permitted without express written authority. Offenders will be liable                                         */
/* for damages.                                                                                                      */
/*********************************************************************************************************************/
#ifndef GPIO_H_
#define GPIO_H_
/*                                                       Includes                                                    */
/*********************************************************************************************************************/
#include "Std_types.h"
#include "peripherals.h"

/*                                                        Types                                                      */
/*********************************************************************************************************************/
#ifndef gpio_type
typedef struct
{
    __IO uint32_t moder;
    __IO uint32_t otyper;
    __IO uint32_t ospeedr;
    __IO uint32_t pupdr;
    __IO uint32_t idr;
    __IO uint32_t odr;
    __IO uint32_t bsrr;
    __IO uint32_t lckr;
    __IO uint32_t afrl;
    __IO uint32_t afrh;
}gpio_type;
#endif

#ifndef GPIOA
 #define GPIOA ((gpio_type*)GPIOA_BASE_ADDRESS)
#endif

#ifndef GPIOB
 #define GPIOB ((gpio_type*)GPIOB_BASE_ADDRESS)
#endif

#ifndef GPIOC
 #define GPIOC ((gpio_type*)GPIOC_BASE_ADDRESS)
#endif

#ifndef GPIOD
 #define GPIOD ((gpio_type*)GPIOD_BASE_ADDRESS)
#endif

#ifndef GPIOE
 #define GPIOE ((gpio_type*)GPIOE_BASE_ADDRESS)
#endif

#ifndef GPIOF
 #define GPIOF ((gpio_type*)GPIOF_BASE_ADDRESS)
#endif

#ifndef GPIOG
 #define GPIOG ((gpio_type*)GPIOG_BASE_ADDRESS)
#endif

#ifndef GPIOH
 #define GPIOH ((gpio_type*)GPIOH_BASE_ADDRESS)
#endif

#ifndef GPIOI
 #define GPIOI ((gpio_type*)GPIOI_BASE_ADDRESS)
#endif

#ifndef GPIOJ
 #define GPIOJ ((gpio_type*)GPIOJ_BASE_ADDRESS)
#endif

#ifndef GPIOK
 #define GPIOK ((gpio_type*)GPIOK_BASE_ADDRESS)
#endif

typedef enum{high=0,low}gpio_afr;
typedef enum{no=0,pup,pdown}gpio_pupdr;
/*                                                      Constants                                                    */
/*********************************************************************************************************************/
/* GPIO Port Mode Register (GPIOx_MODER) */
/* Reset pin: */
#define RESET_PIN_0             (0x3ul<<0)
#define RESET_PIN_1             (0x3ul<<2)
#define RESET_PIN_2             (0x3ul<<4)
#define RESET_PIN_3             (0x3ul<<6)
#define RESET_PIN_4             (0x3ul<<8)
#define RESET_PIN_5             (0x3ul<<10)
#define RESET_PIN_6             (0x3ul<<12)
#define RESET_PIN_7             (0x3ul<<14)
#define RESET_PIN_8             (0x3ul<<16)
#define RESET_PIN_9             (0x3ul<<18)
#define RESET_PIN_10            (0x3ul<<20)
#define RESET_PIN_11            (0x3ul<<22)
#define RESET_PIN_12            (0x3ul<<24)
#define RESET_PIN_13            (0x3ul<<26)
#define RESET_PIN_14            (0x3ul<<28)
#define RESET_PIN_15            (0x3ul<<30)
/* GPIOx_MODER Generic macros: */
/* Input mode: */
#define GPIO_MODER_INPUT_0        (0x3ul<<0)
#define GPIO_MODER_INPUT_1        (0x3ul<<2)
#define GPIO_MODER_INPUT_2        (0x3ul<<4)
#define GPIO_MODER_INPUT_3        (0x3ul<<6)
#define GPIO_MODER_INPUT_4        (0x3ul<<8)
#define GPIO_MODER_INPUT_5        (0x3ul<<10)
#define GPIO_MODER_INPUT_6        (0x3ul<<12)
#define GPIO_MODER_INPUT_7        (0x3ul<<14)
#define GPIO_MODER_INPUT_8        (0x3ul<<16)
#define GPIO_MODER_INPUT_9        (0x3ul<<18)
#define GPIO_MODER_INPUT_10       (0x3ul<<20)
#define GPIO_MODER_INPUT_11       (0x3ul<<22)
#define GPIO_MODER_INPUT_12       (0x3ul<<24)
#define GPIO_MODER_INPUT_13       (0x3ul<<26)
#define GPIO_MODER_INPUT_14       (0x3ul<<28)
#define GPIO_MODER_INPUT_15       (0x3ul<<30)
/* Output mode: */
#define GPIO_MODER_OUTPUT_0       (0x1ul<<0)
#define GPIO_MODER_OUTPUT_1       (0x1ul<<2)
#define GPIO_MODER_OUTPUT_2       (0x1ul<<4)
#define GPIO_MODER_OUTPUT_3       (0x1ul<<6)
#define GPIO_MODER_OUTPUT_4       (0x1ul<<8)
#define GPIO_MODER_OUTPUT_5       (0x1ul<<10)
#define GPIO_MODER_OUTPUT_6       (0x1ul<<12)
#define GPIO_MODER_OUTPUT_7       (0x1ul<<14)
#define GPIO_MODER_OUTPUT_8       (0x1ul<<16)
#define GPIO_MODER_OUTPUT_9       (0x1ul<<18)
#define GPIO_MODER_OUTPUT_10      (0x1ul<<20)
#define GPIO_MODER_OUTPUT_11      (0x1ul<<22)
#define GPIO_MODER_OUTPUT_12      (0x1ul<<24)
#define GPIO_MODER_OUTPUT_13      (0x1ul<<26)
#define GPIO_MODER_OUTPUT_14      (0x1ul<<28)
#define GPIO_MODER_OUTPUT_15      (0x1ul<<30)
/* Alternate mode:*/
#define GPIO_MODER_ALTERNATE_0    (0x2ul<<0)
#define GPIO_MODER_ALTERNATE_1    (0x2ul<<2)
#define GPIO_MODER_ALTERNATE_2    (0x2ul<<4)
#define GPIO_MODER_ALTERNATE_3    (0x2ul<<6)
#define GPIO_MODER_ALTERNATE_4    (0x2ul<<8)
#define GPIO_MODER_ALTERNATE_5    (0x2ul<<10)
#define GPIO_MODER_ALTERNATE_6    (0x2ul<<12)
#define GPIO_MODER_ALTERNATE_7    (0x2ul<<14)
#define GPIO_MODER_ALTERNATE_8    (0x2ul<<16)
#define GPIO_MODER_ALTERNATE_9    (0x2ul<<18)
#define GPIO_MODER_ALTERNATE_10   (0x2ul<<20)
#define GPIO_MODER_ALTERNATE_11   (0x2ul<<22)
#define GPIO_MODER_ALTERNATE_12   (0x2ul<<24)
#define GPIO_MODER_ALTERNATE_13   (0x2ul<<26)
#define GPIO_MODER_ALTERNATE_14   (0x2ul<<28)
#define GPIO_MODER_ALTERNATE_15   (0x2ul<<30)
/* Analog mode: */
#define GPIO_MODER_ANALOG_0       (0x3ul<<0)
#define GPIO_MODER_ANALOG_1       (0x3ul<<2)
#define GPIO_MODER_ANALOG_2       (0x3ul<<4)
#define GPIO_MODER_ANALOG_3       (0x3ul<<6)
#define GPIO_MODER_ANALOG_4       (0x3ul<<8)
#define GPIO_MODER_ANALOG_5       (0x3ul<<10)
#define GPIO_MODER_ANALOG_6       (0x3ul<<12)
#define GPIO_MODER_ANALOG_7       (0x3ul<<14)
#define GPIO_MODER_ANALOG_8       (0x3ul<<16)
#define GPIO_MODER_ANALOG_9       (0x3ul<<18)
#define GPIO_MODER_ANALOG_10      (0x3ul<<20)
#define GPIO_MODER_ANALOG_11      (0x3ul<<22)
#define GPIO_MODER_ANALOG_12      (0x3ul<<24)
#define GPIO_MODER_ANALOG_13      (0x3ul<<26)
#define GPIO_MODER_ANALOG_14      (0x3ul<<28)
#define GPIO_MODER_ANALOG_15      (0x3ul<<30)

#define GPIO_ODR_PIN_0            (0x1ul<<0)
#define GPIO_ODR_PIN_1            (0x1ul<<1)
#define GPIO_ODR_PIN_2            (0x1ul<<2)
#define GPIO_ODR_PIN_3            (0x1ul<<3)
#define GPIO_ODR_PIN_4            (0x1ul<<4)
#define GPIO_ODR_PIN_5            (0x1ul<<5)
#define GPIO_ODR_PIN_6            (0x1ul<<6)
#define GPIO_ODR_PIN_7            (0x1ul<<7)
#define GPIO_ODR_PIN_8            (0x1ul<<8)
#define GPIO_ODR_PIN_9            (0x1ul<<9)
#define GPIO_ODR_PIN_10           (0x1ul<<10)
#define GPIO_ODR_PIN_11           (0x1ul<<11)
#define GPIO_ODR_PIN_12           (0x1ul<<12)
#define GPIO_ODR_PIN_13           (0x1ul<<13)
#define GPIO_ODR_PIN_14           (0x1ul<<14)
#define GPIO_ODR_PIN_15           (0x1ul<<15)

#define GPIO_IDR_PIN_0            (0x1ul<<0)
#define GPIO_IDR_PIN_1            (0x1ul<<1)
#define GPIO_IDR_PIN_2            (0x1ul<<2)
#define GPIO_IDR_PIN_3            (0x1ul<<3)
#define GPIO_IDR_PIN_4            (0x1ul<<4)
#define GPIO_IDR_PIN_5            (0x1ul<<5)
#define GPIO_IDR_PIN_6            (0x1ul<<6)
#define GPIO_IDR_PIN_7            (0x1ul<<7)
#define GPIO_IDR_PIN_8            (0x1ul<<8)
#define GPIO_IDR_PIN_9            (0x1ul<<9)
#define GPIO_IDR_PIN_10           (0x1ul<<10)
#define GPIO_IDR_PIN_11           (0x1ul<<11)
#define GPIO_IDR_PIN_12           (0x1ul<<12)
#define GPIO_IDR_PIN_13           (0x1ul<<13)
#define GPIO_IDR_PIN_14           (0x1ul<<14)
#define GPIO_IDR_PIN_15           (0x1ul<<15)

#define GPIO_AFRL_RESET_PIN_0     (0xFFFFFFF0ul)
#define GPIO_AFRL_RESET_PIN_1     (0xFFFFFF0Ful)
#define GPIO_AFRL_RESET_PIN_2     (0xFFFFF0FFul)
#define GPIO_AFRL_RESET_PIN_3     (0xFFFF0FFFul)
#define GPIO_AFRL_RESET_PIN_4     (0xFFF0FFFFul)
#define GPIO_AFRL_RESET_PIN_5     (0xFF0FFFFFul)
#define GPIO_AFRL_RESET_PIN_6     (0xF0FFFFFFul)
#define GPIO_AFRL_RESET_PIN_7     (0x0FFFFFFFul)
#define GPIO_AFRH_RESET_PIN_8     (0xFFFFFFF0ul)
#define GPIO_AFRH_RESET_PIN_9     (0xFFFFFF0Ful)
#define GPIO_AFRH_RESET_PIN_10    (0xFFFFF0FFul)
#define GPIO_AFRH_RESET_PIN_11    (0xFFFF0FFFul)
#define GPIO_AFRH_RESET_PIN_12    (0xFFF0FFFFul)
#define GPIO_AFRH_RESET_PIN_13    (0xFF0FFFFFul)
#define GPIO_AFRH_RESET_PIN_14    (0xF0FFFFFFul)
#define GPIO_AFRH_RESET_PIN_15    (0x0FFFFFFFul)

#define GPIO_AFRL_PIN_USART2_TX   (0x7ul<<8)
#define GPIO_AFRL_PIN_USART2_RX   (0x7ul<<12)

#define GPIO_AFRH_PIN_USART3_TX   (0x7ul<<0)
#define GPIO_AFRH_PIN_USART3_RX   (0x7ul<<4)

/*                                                 Exported Variables                                                */
/*********************************************************************************************************************/

/*                                            Exported functions prototypes                                          */
/*********************************************************************************************************************/


/*********************************************************************************************************************/
#endif
/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/ 