/*********************************************************************************************************************/
/*                                                  SOURCE GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $File: usart.c
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2025-03-23 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/* usart.c:
            usart serial communication.
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
#include "usart.h"
/*                                                        Types                                                      */
/*********************************************************************************************************************/

/*                                                      Constants                                                    */
/*********************************************************************************************************************/
 
/*                                             Local functions prototypes                                            */
/*********************************************************************************************************************/

/*                                           Local functions implementation                                          */
/*********************************************************************************************************************/
void cmplx_dr_usart_config_oversamplig (usart_type* usart_port,uint32_t oversampling)
{
    usart_port->cr1 &= (~USART_OVERSAMPLING_RST);
    usart_port->cr1 |= oversampling;
}

void cmplx_dr_usart_config_baudrate (usart_type* usart_port,uint32_t baudrate)
{
    usart_port->brr = baudrate;
}

void cmplx_dr_usart_config_transmitter (usart_type* usart_port,bool state)
{
    if(true==state)
    {
        usart_port->cr1 |= USART_TRANSMITER_ENABLE;
    }
    else
    {
        usart_port->cr1 &= (~USART_TRANSMITER_ENABLE);
    }
}

void cmplx_dr_usart_config_receiver (usart_type* usart_port,bool state)
{
    if(true==state)
    {
        usart_port->cr1 |= USART_RECEIVER_ENABLE;
    }
    else
    {
        usart_port->cr1 &= (~USART_RECEIVER_ENABLE);
    }
}

void cmplx_dr_usart_config_word_length (usart_type* usart_port,word_length w_len)
{
    if(eight_bits==w_len)
    {
        usart_port->cr1 &= (~USART_WORD_LENGTH);
    }
    else
    {
        usart_port->cr1 |= USART_WORD_LENGTH;
    }
}

void cmplx_dr_usart_config_parity_control  (usart_type* usart_port,bool pce)
{
    if(true==pce)
    {
        usart_port->cr1 |= USART_PARITY_CONTROL;
    }
    else
    {
        usart_port->cr1 &= (~USART_PARITY_CONTROL);
    }
}

void cmplx_dr_usart_config_stop_bits       (usart_type* usart_port,stop_bits num_stop_bits)
{
    if (one_stop_bit==num_stop_bits)
    {
        usart_port->cr2 &= (~USART_STOP_BIT_0);
        usart_port->cr2 &= (~USART_STOP_BIT_1);
    }
    else if (dot_five_stop_bits==num_stop_bits)
    {
        usart_port->cr2 |= USART_STOP_BIT_0;
        usart_port->cr2 &= (~USART_STOP_BIT_1);
    }
    else if (two_stop_bits==num_stop_bits)
    {
        usart_port->cr2 &= (~USART_STOP_BIT_0);
        usart_port->cr2 |= USART_STOP_BIT_1;
    }
    else
    {
        usart_port->cr2 |= USART_STOP_BIT_0;
        usart_port->cr2 |= USART_STOP_BIT_1;
    }
}

void cmplx_dr_usart_config_cts             (usart_type* usart_port,bool state)
{
    if(true==state)
    {
        usart_port->cr3 |= USART_CTS_ENABLE;
    }
    else
    {
        usart_port->cr3 &= (~USART_CTS_ENABLE);
    }
}

void cmplx_dr_usart_config_rts             (usart_type* usart_port,bool state)
{
    if(true==state)
    {
        usart_port->cr3 |= USART_RTS_ENABLE;
    }
    else
    {
        usart_port->cr3 &= (~USART_RTS_ENABLE);
    }
}

extern void cmplx_dr_usart_config_tx_interrupt    (usart_type* usart_port,bool state)
{
    if(true==state)
    {
        usart_port->cr1 |= USART_TX_INTERRUPT_EN;
    }
    else
    {
        usart_port->cr1 &= (~USART_TX_INTERRUPT_EN);
    }
}

extern void cmplx_dr_usart_config_rx_interrupt    (usart_type* usart_port,bool state)
{
    if(true==state)
    {
        usart_port->cr1 |= USART_RX_INTERRUPT_EN;
    }
    else
    {
        usart_port->cr1 &= (~USART_RX_INTERRUPT_EN);
    }
}

extern void cmplx_dr_usart_config_parity_selection     (usart_type* usart_port,parity par_type)
{
    if(even==par_type)
    {
        usart_port->cr1 &= (~USART_PARITY_SELECTION);
    }
    else
    {
        usart_port->cr1 |= USART_PARITY_SELECTION;
    }
}

void cmplx_dr_usart_config_enable            (usart_type* usart_port,bool state)
{
    {
        if(true==state)
        {
            usart_port->cr1 |= USART_ENABLE;
        }
        else
        {
            usart_port->cr1 &= (~USART_ENABLE);
        }
    }
}

void cmplx_dr_usart_putchar                  (usart_type* usart_port,uint32_t data)
{
    while (USART_SR_TXE!=(usart_port->sr & USART_SR_TXE));
    usart_port->dr = (data & USART_TXE_MASK);
    while (USART_SR_TC!=(usart_port->sr & USART_SR_TC));
}

/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/
