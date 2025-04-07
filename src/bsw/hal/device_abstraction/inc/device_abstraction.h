/*********************************************************************************************************************/
/*                                                INCLUDES GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $File: device_abstraction.h
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2025-03-23 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/* device_abstraction.h:
                         This module abstracts from ECU-specific onboard devices. This module contains drivers for 
                         onboard devices that are not sensors, actuators, or timers, such as internal or external 
                         watchdog timers.
 */
/*********************************************************************************************************************/
/* ALL RIGHTS RESERVED                                                                                               */
/*                                                                                                                   */
/* The reproduction, transmission, or use of this document or its content is                                         */
/* not permitted without express written authority. Offenders will be liable                                         */
/* for damages.                                                                                                      */
/*********************************************************************************************************************/
#ifndef DEVICE_ABSTRACTION_H_
#define DEVICE_ABSTRACTION_H_
/*                                                       Includes                                                    */
/*********************************************************************************************************************/
#include "Std_types.h"
#include "mcu_driver.h"

/*                                                        Types                                                      */
/*********************************************************************************************************************/
#ifndef SourceClock
 typedef enum{internal=0u,external,pll} SourceClock;
#endif

/*                                                      Constants                                                    */
/*********************************************************************************************************************/

/*                                                 Exported Variables                                                */
/*********************************************************************************************************************/

/*                                            Exported functions prototypes                                          */
/*********************************************************************************************************************/
extern void dev_abs_power_clock_interface_sleep_mode              (bool set_pwr);
extern void dev_abs_voltage_scaling_output_selector               (uint32_t scale_mode);
extern void dev_abs_programmable_voltage_detector_level_selection (uint32_t pvd_level);
extern void dev_abs_select_source_clock                           (SourceClock src_clk);
extern void dev_abs_disable_source_clock                          (SourceClock src_clk);
extern void dev_abs_select_pll_source_clock                       (SourceClock pll_src_clk);
extern void dev_abs_configure_pll_clock_frequency                 (uint32_t pll_clk_freq);
extern void dev_abs_select_system_clock                           (SourceClock sys_clk);
extern void dev_abs_set_low_speed_prescaler                       (uint32_t prescaler);
extern void dev_abs_set_high_speed_prescaler                      (uint32_t prescaler);
extern void dev_abs_set_abh_speed_prescaler                       (uint32_t prescaler);
extern void dev_abs_set_gpio_clock                                (uint32_t gpio_x,bool set_gpio);
extern void dev_abs_set_crc_clock                                 (bool set_crc);
/*********************************************************************************************************************/
#endif
/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/ 