/* 
 * File:   main.c
 * Author: Etiq Technologies
 *
 * Example 3.1
 * Created on October 18, 2013, 10:37 AM
 * Example code to send a Byte(Character)through USART module in Asynchronous mode
 *
 *
*/
#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include "UART.h"
#define _XTAL_FREQ 20000000
int main()
   {
   char data = 'C';                                             /*Assigning variable data with ASCII value for charecter 'Q' */
   TRISAbits.TRISA0 = 1;                                        /*Setting the direction of Pin RA0 as input*/
   ConfigUSART();                                               /*Configure USART module in Asynchronous mode*/
         while(1)                                               /*Infinite loop*/
            {
            while(!PORTAbits.RA0);                              /*Wait until pin RA0 become HIGH before going to the next operation*/
            WriteUSART(data);                                   /*Writing a Byte(character) to serial port*/
            while (BusyUSART());                                /*Check if USART is busy or not*/
            data = data++;                                      /*Incrementing the ASCII value once for the next character*/
            while(PORTAbits.RA0);                               /*Waiting for pin RA0 to become LOW*/
            }
    return (0);
 }