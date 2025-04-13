/*********************************************************************************************************************/
/*                                                INCLUDES GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $File: usart.h
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2025-03-23 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/* usart.h:
            usart serial communication.
 */
/*********************************************************************************************************************/
/* ALL RIGHTS RESERVED                                                                                               */
/*                                                                                                                   */
/* The reproduction, transmission, or use of this document or its content is                                         */
/* not permitted without express written authority. Offenders will be liable                                         */
/* for damages.                                                                                                      */
/*********************************************************************************************************************/
#ifndef USART_H_
#define USART_H_
/*                                                       Includes                                                    */
/*********************************************************************************************************************/
#include "Std_types.h"
#include "peripherals.h"

/*                                                        Types                                                      */
/*********************************************************************************************************************/
#ifndef gpio_type
typedef struct
{
    __IO uint32_t sr;
    __IO uint32_t dr;
    __IO uint32_t brr;
    __IO uint32_t cr1;
    __IO uint32_t cr2;
    __IO uint32_t cr3;
    __IO uint32_t gtpr;
}usart_type;
#endif

#ifndef USART1
 #define USART1 ((usart_type*)USART1_BASE_ADDRESS)
#endif

#ifndef USART2
 #define USART2 ((usart_type*)USART2_BASE_ADDRESS)
#endif

#ifndef USART3
 #define USART3 ((usart_type*)USART3_BASE_ADDRESS)
#endif

#ifndef UART4
 #define UART4  ((usart_type*)UART4_BASE_ADDRESS)
#endif

#ifndef UART5
 #define UART5  ((usart_type*)UART5_BASE_ADDRESS)
#endif

#ifndef USART6
 #define USART6 ((usart_type*)USART6_BASE_ADDRESS)
#endif

#ifndef UART7
 #define UART7  ((usart_type*)UART7_BASE_ADDRESS)
#endif

#ifndef UART8
 #define UART8  ((usart_type*)UART8_BASE_ADDRESS)
#endif

typedef enum{eight_bits=0,nine_bits}word_length;
typedef enum{one_stop_bit=0,dot_five_stop_bits,two_stop_bits,one_dot_five_stop_its}stop_bits;
typedef enum{even=0,odd}parity;

/*                                                      Constants                                                    */
/*********************************************************************************************************************/
#define USART_OVERSAMPLING_RST  (0x1ul<<15)
#define USART_OVERSAMPLING_16   (0x0ul) 
#define USART_OVERSAMPLING_8    USART_OVERSAMPLING_RST

//#define USART_BAUDRATE_115200   (52ul<<4 | 1ul<<0) /* Fck must be peripheral clock setup at startup configuration. */
#define USART_BAUDRATE_115200   (13ul<<4)

#define USART_TRANSMITER_ENABLE (0x1ul<<3)
#define USART_RECEIVER_ENABLE   (0x1ul<<2)

#define USART_WORD_LENGTH       (0x1ul<<12)

#define USART_PARITY_CONTROL    (0x01ul<<10)

#define USART_STOP_BIT_0        (0x1ul<<12)
#define USART_STOP_BIT_1        (0x1ul<<13)

#define USART_CTS_ENABLE        (0x1ul<<9)
#define USART_RTS_ENABLE        (0x1ul<<8)

#define USART_PARITY_SELECTION  (0x1ul<<9)

#define USART_TX_INTERRUPT_EN   (0x1ul<<7)
#define USART_RX_INTERRUPT_EN   (0x1ul<<5)

#define USART_ENABLE            (0x1ul<<13)

#define USART_SR_TXE            (0x1ul<<7)
#define USART_SR_TC             (0x1ul<<6)
#define USART_TXE_MASK          (0xFF<<0)

/*                                                 Exported Variables                                                */
/*********************************************************************************************************************/

/*                                            Exported functions prototypes                                          */
/*********************************************************************************************************************/
extern void cmplx_dr_usart_config_oversamplig       (usart_type* usart_port,uint32_t oversampling);
extern void cmplx_dr_usart_config_baudrate          (usart_type* usart_port,uint32_t baudrate);
extern void cmplx_dr_usart_config_transmitter       (usart_type* usart_port,bool state);
extern void cmplx_dr_usart_config_receiver          (usart_type* usart_port,bool state);
extern void cmplx_dr_usart_config_word_length       (usart_type* usart_port,word_length w_len);
extern void cmplx_dr_usart_config_parity_control    (usart_type* usart_port,bool pce); 
extern void cmplx_dr_usart_config_stop_bits         (usart_type* usart_port,stop_bits num_stop_bits);
extern void cmplx_dr_usart_config_cts               (usart_type* usart_port,bool state);
extern void cmplx_dr_usart_config_rts               (usart_type* usart_port,bool state);
extern void cmplx_dr_usart_config_tx_interrupt      (usart_type* usart_port,bool state);
extern void cmplx_dr_usart_config_rx_interrupt      (usart_type* usart_port,bool state);
extern void cmplx_dr_usart_config_parity_selection  (usart_type* usart_port,parity par_type);
extern void cmplx_dr_usart_config_enable            (usart_type* usart_port,bool state);
extern void cmplx_dr_usart_putchar                  (usart_type* usart_port,uint32_t data);

/*********************************************************************************************************************/
#endif
/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/ 