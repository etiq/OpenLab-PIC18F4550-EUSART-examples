
/*
 * File name            : main.c
 * Compiler             : MPLAB XC8/ MPLAB C18 compiler
 * IDE                  : Microchip  MPLAB X IDE v1.90/ MPLAB IDE v8
 * Author               : Etiq Technologies
 * Description          : Example 3.1 USART_1
 *                      : Created on October 18, 2013, 10:37 AM
 *                      : Example code to send a Byte(Character)through USART module in Asynchronous mode
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
#include "config.h"
#include "uart.h"
#include "delay.h"
#endif

#define _XTAL_FREQ 20000000
#define Fosc 20000000
#define baud 9600
#define spbrg ((Fosc/baud/64)-1)

unsigned char config_1 = USART_TX_INT_OFF & USART_RX_INT_OFF & USART_ASYNCH_MODE & USART_EIGHT_BIT & USART_CONT_RX & USART_BRGH_LOW;
unsigned char config_2 = spbrg;

int main(void)
   {
   char data = 'A';                             /*Assigning variable data with ASCII value for charecter 'Q'                */
   TRISAbits.TRISA0 = 1;                        /*Setting the direction of Pin RA0 as input                                 */
   ConfigUSART(config_1, config_2);             /*Configure USART module in Asynchronous mode                               */
         while(1)                               /*Infinite loop                                                             */
            {
             Write('\n');                       /* New line                                                                 */
             Write('\r');                       /* Return                                                                   */
             do
             {
             Write(data++);                     /*Writing a Byte(a character) to serial port and incrementing the ASCII value
                                                  once, for the next character                                              */
             delay_ms(200);
             } while(data != 'Z'+1);

             Write(' ');
             data = 'a';
             do
             {
             Write(data++);                     /*Writing a Byte(a character) to serial port and decrementing the ASCII value
                                                  once, for the next character                                              */
             delay_ms(200);
             }while(data != 'z'+1);
             data = 'A'; 
         }
    return (0);
    }