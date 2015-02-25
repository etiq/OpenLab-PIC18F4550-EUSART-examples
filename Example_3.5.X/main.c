/*
 * File name            : main.c
 * Compiler             : MPLAB XC8/ MPLAB C18 compiler
 * IDE                  : Microchip  MPLAB X IDE v1.90/ MPLAB IDE v8
 * Author               : Etiq Technologies
 * Description          : Example 3.3 USART_3
 *                      : Created on October 18, 2013, 10:37 AM
 *                        Example code to receive a string data from serial port, and sending back through USART module in asynchronous mode
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
#define _XTAL_FREQ 20000000

unsigned char str_1[41] = "\rEnter a string followed by return key\0";
unsigned char str[] = "\0";
unsigned char config_1 = USART_TX_INT_OFF & USART_RX_INT_OFF & USART_ASYNCH_MODE & USART_EIGHT_BIT & USART_CONT_RX & USART_BRGH_LOW;
unsigned char config_2 = spbrg;


Clear_string(unsigned char *buffer)
        {
        while(*buffer)
        {
        *buffer = ' ';                                      /* Clearing buffer (Clearing string)             */
        buffer++;
        }
        }

int main()
   {
   ConfigUSART(config_1, config_2);                         /* Configure USART module in Asynchronous mode   */
         while(1)                                           /* Infinite loop                                 */
            {
            Write_str(str_1);                               /* Writing a string to the serial port           */
            Clear_string(str);                              /* Clearing string                               */
            Read_str(str);                                  /* Reading a string data through serial port     */
            Write_str(str);                                 /* Writing the string back to serial port        */
			Clear_string(str);            
			}
    return (0);
 }