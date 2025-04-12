/*********************************************************************************************************************/
/*                                                INCLUDES GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $File: IoHwAb.h
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2025-03-23 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/* IoHwAb.h:
             The Input Output Hardware Abstraction, contains driver from ports, adc, port, Dio, PWM.
 */
/*********************************************************************************************************************/
/* ALL RIGHTS RESERVED                                                                                               */
/*                                                                                                                   */
/* The reproduction, transmission, or use of this document or its content is                                         */
/* not permitted without express written authority. Offenders will be liable                                         */
/* for damages.                                                                                                      */
/*********************************************************************************************************************/
#ifndef IO_HARDWARE_ABSTRACTION_H_
#define IO_HARDWARE_ABSTRACTION_H_
/*                                                       Includes                                                    */
/*********************************************************************************************************************/
#include "Std_types.h"
#include "dio.h"
#include "port.h"

/*                                                        Types                                                      */
/*********************************************************************************************************************/

/*                                                      Constants                                                    */
/*********************************************************************************************************************/

/*                                                 Exported Variables                                                */
/*********************************************************************************************************************/

/*                                            Exported functions prototypes                                          */
/*********************************************************************************************************************/
#define IoHwAb_port_pin_mode_input(gpio_type,uint32_t)                     port_gpio_pin_mode_input(gpio_type,uint32_t)
#define IoHwAb_port_pin_mode_output(gpio_type,uint32_t)                    port_gpio_pin_mode_output(gpio_type,uint32_t)
#define IoHwAb_port_pin_mode_alternate(gpio_type,uint32_t)                 port_gpio_pin_mode_alternate(gpio_type,uint32_t)
#define IoHwAb_port_pin_mode_analog(gpio_type,uint32_t)                    port_gpio_pin_mode_analog(gpio_type,uint32_t)
#define IoHwAb_port_pin_reset(gpio_type,uint32_t)                          port_gpio_pin_reset(gpio_type,uint32_t)
#define IoHwAb_port_pin_config_alt_mode(gpio_type,uint32_t,gpio_afr)       port_gpio_pin_config_alternate_mode(gpio_type,uint32_t,gpio_afr)
#define IoHwAb_port_pin_config_alt_rst(gpio_type,uint32_t,gpio_afr)        port_gpio_pin_config_alternate_reset(gpio_type,uint32_t,gpio_afr)
#define IoHwAb_port_pin_config_pull_up_down(gpio_type,uint32_t,gpio_pupdr) port_gpio_pin_config_pull_up_down(gpio_type,uint32_t,gpio_pupdr)
#define IoHwAb_set_pin_high(gpio_type,uint32_t)                            dio_gpio_pin_high(gpio_type,uint32_t)
#define IoHwAb_set_pin_low(gpio_type,uint32_t)                             dio_gpio_pin_low(gpio_type,uint32_t)
#define IoHwAb_get_pin_state(gpio_type,uint32_t)                           gio_gpio_pin_state(gpio_type,uint32_t)
/*********************************************************************************************************************/
#endif
/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/ 