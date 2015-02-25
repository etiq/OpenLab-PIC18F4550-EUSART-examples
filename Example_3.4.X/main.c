/*
 * File name            : main.c
 * Compiler             : MPLAB XC8/ MPLAB C18 compiler
 * IDE                  : Microchip  MPLAB X IDE v1.90/ MPLAB IDE v8
 * Author               : Etiq Technologies
 * Description          : Example 3.4 USART_4
 *                      : Created on November 29, 2013, 3:24 PM
 *                      : Example for sending a string through USART module in asynchronous mode.
 */

#if defined(__XC)
    #include <xc.h>        /* XC8 General Include File 		*/
    #include <plib\usart.h>
#elif defined(HI_TECH_C)
    #include <htc.h>       /* HiTech General Include File 	*/
#elif defined(__18CXX)
    #include <p18cxxx.h>   /* C18 General Include File 		*/
    #include <usart.h>
#endif

#if defined(__XC) || defined(HI_TECH_C)
#include <stdint.h>        /* For uint8_t definition 		*/
#include <stdbool.h>       /* For true/false definition 	*/
#endif

#if defined(__XC) || defined(__18CXX)
#include "uart.h"
#include "config.h"
#include "delay.h"
#endif

#define Fosc 20000000
#define baud 9600
#define spbrg ((Fosc/baud/64)-1)

unsigned char config_1 = USART_TX_INT_OFF & USART_RX_INT_OFF & USART_ASYNCH_MODE & USART_EIGHT_BIT & USART_CONT_RX & USART_BRGH_LOW;
unsigned char config_2 = spbrg;
unsigned char str[10] = "MICROCHIP";

void main(void)
{
    ConfigUSART(config_1, config_2);                             /* Configure USART module in Asynchronous mode                      */
    while(1)
        {
        Write_str(str);                                          /* Passing the address of the String to the USART write function    */
        delay_ms(200);                                           /* Delay of 200 ms                                                  */
        Write(' ');
        }
}