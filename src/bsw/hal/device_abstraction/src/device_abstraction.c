/*********************************************************************************************************************/
/*                                                  SOURCE GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $File: device_abstraction.c
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2025-03-23 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/* device_abstraction.c:
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

/*                                                 Standard libraries                                                */
/*********************************************************************************************************************/

/*                                                   User libraries                                                  */
/*********************************************************************************************************************/
#include "Std_types.h"
#include "device_abstraction.h"
/*                                                        Types                                                      */
/*********************************************************************************************************************/

/*                                                      Constants                                                    */
/*********************************************************************************************************************/

/*                                             Local functions prototypes                                            */
/*********************************************************************************************************************/

/*                                           Local functions implementation                                          */
/*********************************************************************************************************************/
void dev_abs_power_clock_interface_sleep_mode (bool set_pwr)
{
    if(true==set_pwr)
    {
        mcu_driver_rcc_apb1lpenr_pwrlp_enable();
    }
    else
    {
        mcu_driver_rcc_apb1lpenr_pwrlp_disable();
    }
}

void dev_abs_voltage_scaling_output_selector (uint32_t scale_mode)
{
    mcu_driver_pwr_cr_vos_mode (scale_mode);
}

void dev_abs_programmable_voltage_detector_level_selection (uint32_t pvd_level)
{
    mcu_driver_pwr_cr_pvd_level (pvd_level);
}

void dev_abs_select_source_clock (SourceClock src_clk )
{
    if(internal==src_clk)
    {
        mcu_driver_rcc_rc_hsi_enable ();
    }
    else if(external==src_clk)
    {
        mcu_driver_rcc_rc_hse_enable ();
    }
    else
    {
        mcu_driver_rcc_rc_pll_enable ();
    }
}

void dev_abs_disable_source_clock (SourceClock src_clk )
{
    if(internal==src_clk)
    {
        mcu_driver_rcc_rc_hsi_disable ();
    }
    else if(external==src_clk)
    {
        mcu_driver_rcc_rc_hse_disable ();
    }
    else
    {
        mcu_driver_rcc_rc_pll_disable ();
    }
}

void dev_abs_select_pll_source_clock (SourceClock pll_src_clk)
{
    if(internal==pll_src_clk)
    {
        mcu_driver_rcc_pllcfgr_pllsrc_hsi ();
    }
    else if (external == pll_src_clk)
    {
        mcu_driver_rcc_pllcfgr_pllsrc_hse ();
    }
    else
    {
        mcu_driver_rcc_pllcfgr_pllsrc_hsi ();
    }
}

void dev_abs_configure_pll_clock_frequency (uint32_t pll_clk_freq)
{
    mcu_driver_rcc_pllcfgr_sys_clk (pll_clk_freq);
}

void dev_abs_select_system_clock (SourceClock sys_clk)
{
    if(internal==sys_clk)
    {
        mcu_driver_rcc_cfgr_sys_clk_hsi ();
    }
    else if(external==sys_clk)
    {
        mcu_driver_rcc_cfgr_sys_clk_hse ();
    }
    else
    {
        mcu_driver_rcc_cfgr_sys_clk_pll ();
    }
}

void dev_abs_set_low_speed_prescaler (uint32_t prescaler)
{
    mcu_driver_rcc_cfgr_apb1_prescaler (prescaler);
}

void dev_abs_set_high_speed_prescaler (uint32_t prescaler)
{
    mcu_driver_rcc_cfgr_apb2_prescaler (prescaler);
}

void dev_abs_set_abh_speed_prescaler (uint32_t prescaler)
{
    mcu_driver_rcc_cfgr_ahb_prescaler (prescaler);
}

void dev_abs_set_gpio_clock (uint32_t gpio_x,bool set_gpio)
{
    if (true == set_gpio)
    {
        mcu_driver_rcc_aph1enr_gpio_enable (gpio_x);
    }
    else
    {
        mcu_driver_rcc_aph1enr_gpio_disable (gpio_x);
    }
}

void dev_abs_set_crc_clock (bool set_crc)
{
    if (true == set_crc)
    {
        mcu_driver_rcc_aph1enr_crc_enable ();
    }
    else
    {
        mcu_driver_rcc_aph1enr_crc_disable ();
    }
}

void dev_abs_set_usart_clock (uint32_t usart,bool set_usart)
{
    if (true == set_usart)
    {
        mcu_driver_rcc_apb1enr_usart_enable (usart);
    }
    else
    {
        mcu_driver_rcc_apb1enr_usart_disable (usart);
    }
}
/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/
