/*********************************************************************************************************************/
/*                                                  SOURCE GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $File: log.c
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2025-03-23 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/* log.c:
          it is used to send log files throught usart.
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
#include "log.h"
/*                                                        Types                                                      */
/*********************************************************************************************************************/

/*                                                      Constants                                                    */
/*********************************************************************************************************************/
#define PORTD              GPIOD
#define PORTD_CLOCK_EN     RCC_AHB1ENR_GPIODEN
#define USART3_CLOCK_EN    RCC_APB1ENR_USART3EN
#define RESET_PD8          RESET_PIN_8
#define RESET_PD9          RESET_PIN_9
#define ALTERN_PD8         GPIO_MODER_ALTERNATE_8
#define ALTERN_PD9         GPIO_MODER_ALTERNATE_9
#define RESET_ALTERN_PD8   GPIO_AFRH_RESET_PIN_8
#define RESET_ALTERN_PD9   GPIO_AFRH_RESET_PIN_9
#define USART3_RX          GPIO_AFRH_PIN_USART3_RX
#define USART3_TX          GPIO_AFRH_PIN_USART3_TX

/*                                             Local functions prototypes                                            */
/*********************************************************************************************************************/

/*                                           Local functions implementation                                          */
/*********************************************************************************************************************/
void log_init ()
{
    dev_abs_set_gpio_clock (PORTD_CLOCK_EN,true);
    IoHwAb_port_pin_reset (PORTD,RESET_PD8);
    IoHwAb_port_pin_reset (PORTD,RESET_PD9);
    IoHwAb_port_pin_mode_alternate (PORTD,ALTERN_PD8);
    IoHwAb_port_pin_mode_alternate (PORTD,ALTERN_PD9);
    IoHwAb_port_pin_config_alt_rst (PORTD,RESET_ALTERN_PD8,high);
    IoHwAb_port_pin_config_alt_rst (PORTD,RESET_ALTERN_PD9,high);
    IoHwAb_port_pin_config_alt_mode (PORTD,USART3_RX,high);
    IoHwAb_port_pin_config_alt_mode (PORTD,USART3_TX,high);
    dev_abs_set_usart_clock (USART3_CLOCK_EN,true);
    cmplx_dr_usart_config_oversamplig (USART3,USART_OVERSAMPLING_16);
    cmplx_dr_usart_config_baudrate (USART3,USART_BAUDRATE_115200);
    cmplx_dr_usart_config_transmitter (USART3,true);
    cmplx_dr_usart_config_receiver (USART3,true);
    cmplx_dr_usart_config_word_length (USART3,eight_bits);
    cmplx_dr_usart_config_parity_control (USART3,false);
    cmplx_dr_usart_config_stop_bits (USART3,one_stop_bit);
    cmplx_dr_usart_config_cts (USART3,false);
    cmplx_dr_usart_config_rts (USART3,false);
    cmplx_dr_usart_config_enable (USART3,true);
}

int __io_putchar (int ch)
{
    cmplx_dr_usart_putchar(USART3,ch);
    return ch;
}

/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/
