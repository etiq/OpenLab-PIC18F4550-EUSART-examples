
/*
 * File name            : delay.h
 * Compiler             : MPLAB XC8/ MPLAB C18 compiler
 * IDE                  : Microchip  MPLAB X IDE v1.90/ MPLAB IDE v8
 * Author               : Etiq Technologies
 * Description          : Example 3.4 USART_4
 *                      : Created on November 29, 2013, 3:24 PM
 *                      : Delay functions header
 */

#ifndef DELAY__H
#define	DELAY__H
/*____________________Milli seconds delay function header_________________________________*/
void delay_ms(unsigned char t);
/*
 * Include          :       delay.h
 * Description      :       generates milli seconds delay
 * Arguments        :       Decimal
 * Returns          :       None
 */


/* ___________________________Seconds delay function header______________________________ */
void Delay_s(unsigned char t);
/*
 * Include          :       delay.h
 * Description      :       generates seconds delay  
 * Arguments        :       Decimal
 * Returns          :       None
 */


#endif	/* DELAY__H */

