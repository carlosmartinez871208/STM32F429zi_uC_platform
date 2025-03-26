/*********************************************************************************************************************/
/*                                                INCLUDES GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $File: Std_types.h
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2025-03-23 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/* Std_types.h:
               Use this template for your header files.
 */
/*********************************************************************************************************************/
/* ALL RIGHTS RESERVED                                                                                               */
/*                                                                                                                   */
/* The reproduction, transmission, or use of this document or its content is                                         */
/* not permitted without express written authority. Offenders will be liable                                         */
/* for damages.                                                                                                      */
/*********************************************************************************************************************/
#ifndef STD_TYPES_H_
#define STD_TYPES_H_
/*                                                       Includes                                                    */
/*********************************************************************************************************************/

/*                                                        Types                                                      */
/*********************************************************************************************************************/
/* Unsigned types: */
/* 32 bits data type. */
#ifndef uint32_t
 typedef unsigned long  uint32_t;
#endif
/* 16 bits data type. */
#ifndef uint16_t
 typedef unsigned short uint16_t;
#endif
/* 8 bits data type. */
#ifndef uint8_t
 typedef unsigned char  uint8_t;
#endif

/* Signed types: */
/* 32 bits data type. */
#ifndef sint32_t
 typedef signed long  sint32_t;
#endif
/* 16 bits data type. */
#ifndef sint16_t
 typedef signed short sint16_t;
#endif
/* 8 bits data type. */
#ifndef sint8_t
 typedef signed char  sint8_t;
#endif

/* Bool (boolean) type: */
#ifndef bool
 typedef enum{false=0u,true} bool;
#endif

/* Function pointer type definition, points a void function type. */
#ifndef func_ptr
 typedef void(*func_ptr)(void);
#endif

/* IO definitions */
/* Defines read only permissions. */
#define __I volatile const
/* Defines write only permissions. */
#define __O volatile
/* Defines read / write permissions. */
#define __IO volatile

 /*                                                      Constants                                                   */
/*********************************************************************************************************************/
/* NULL pointer type definition. */
#ifndef NULL
 #define NULL (void*)(0u)
#endif 

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS true;
#endif

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