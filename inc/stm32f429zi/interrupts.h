/*********************************************************************************************************************/
/*                                                INCLUDES GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $File: interrupts.h
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2025-03-23 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/* interrupts.h:
               contains system definitions like, enable/disable interrupts.
 */
/*********************************************************************************************************************/
/* ALL RIGHTS RESERVED                                                                                               */
/*                                                                                                                   */
/* The reproduction, transmission, or use of this document or its content is                                         */
/* not permitted without express written authority. Offenders will be liable                                         */
/* for damages.                                                                                                      */
/*********************************************************************************************************************/
#ifndef INTERRUPTS_H_
 #define INTERRUPTS_H_
/*                                                       Includes                                                    */
/*********************************************************************************************************************/
/*                                                        Types                                                      */
/*********************************************************************************************************************/

/*                                                      Constants                                                    */
/*********************************************************************************************************************/
/*                         Special functions                         */
/* The compiler attempts to inline the function, regardless of the characteristics of the function. 
** However, the compiler does not inline a function if doing so causes problems. For example, a 
** recursive function is inlined into itself only once. 
** The inline keyword suggests to the compiler that the function be inlined. Normally, when a 
** function is called, the current contents of the registers are pushed (copied) to memory. 
** Once the function returns, they are popped (copied back).
** Inline functions are not always important, but it is good to understand them. The basic idea is 
** to save time at a cost in space. Inline functions are a lot like a placeholder. Once you define 
** an inline function, using the 'inline' keyword, whenever you call that function the compiler will 
** replace the function call with the actual code from the function. 
*/
/* Enable IRQ interrupts: by clearing the I-bit in the CPSR. */
__attribute__((__always_inline__)) static inline void __enable_irq (void)
{
    asm volatile ("cpsie i" : : : "memory");
}

/* Enable IRQ interrupts: by setting the I-bit in the CPSR. */
__attribute__((__always_inline__)) static inline void __disable_irq (void)
{
    asm volatile ("cpsid i" : : : "memory");
}

/* Set Main Stack pointer */
__attribute__((__always_inline__)) static inline void __set_MSP (unsigned int MainStackTop)
{
    asm volatile ("MSR msp, %0\n" : : "r" (MainStackTop) : "sp");
}

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