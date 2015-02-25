/*
 * File name            : main.c
 * Compiler             : MPLAB XC8/ MPLAB C18 compiler
 * IDE                  : Microchip  MPLAB X IDE v1.90/ MPLAB IDE v8
 * Author               : Etiq Technologies
 * Description          : Example 3.2 USART_2
 *                      : Created on November 29, 2013, 2:49 PM
 *                      : Example code to receive a Byte(a character) through USART module in Asynchronous mode and transmiting back to serial port.
 */

#if defined(__XC)
    #include <xc.h>        /* XC8 General Include File      */
    #include <plib\usart.h>
#elif defined(HI_TECH_C)
    #include <htc.h>       /* HiTech General Include File   */
#elif defined(__18CXX)
    #include <p18cxxx.h>   /* C18 General Include File      */
    #include <usart.h>
#endif

#if defined(__XC) || defined(HI_TECH_C)
#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */
#endif

#if defined(__XC) || defined(__18CXX)
#include "config.h"
#include "uart.h"
#endif

#define Fosc 20000000
#define baud 9600
#define spbrg ((Fosc/baud/64)-1)

unsigned char config_1 = USART_TX_INT_OFF & USART_RX_INT_OFF & USART_ASYNCH_MODE & USART_EIGHT_BIT & USART_CONT_RX & USART_BRGH_LOW;
unsigned char config_2 = spbrg;

void main(void)
{
   char data;                                            /*Assigning variable data with ASCII value for charecter 'Q'         */
   ConfigUSART(config_1, config_2);                      /*Configure USART module in Asynchronous mode                        */
   while(1)                                              /*Infinite loop                                                      */
        {
        data = ReadUART();                               /* Assigning the received Byte to variable 'data'                    */
        if(data == '\r')
			{
			Write('\n');
			Write('\r');
			}
			Write(data);                                     /* Writing a Byte(character) to serial port                          */
        }
}