/*
 * File name            : uart.c
 * Compiler             : MPLAB XC8/ MPLAB C18 compiler
 * IDE                  : Microchip  MPLAB X IDE v1.90/ MPLAB IDE v8
 * Author               : Etiq Technologies
 * Description          : Example 3.2 USART_2
 *                      : Created on November 29, 2013, 2:49 PM
 *                      : uart functions source file
 */
#if defined(__XC)
    #include <plib\usart.h>

#elif defined(__18CXX)
    #include <usart.h>
#endif

/*_____________________________________________ USART module configuration function___________________________________ ________*/

void ConfigUSART(unsigned char config_1, unsigned char config_2)
{
OpenUSART(config_1, config_2);
}

unsigned char ReadUART(void)
{
while(!(DataRdyUSART()));                                        /* Reading a data byte                                        */
     return(ReadUSART());
}

void Write_str(unsigned char* str)
{
putsUSART((char *)str);                                         /*Passing the address of the String to the USART write function */
    while(BusyUSART());                                         /*Wait until USART goes to idle state                           */

}
void Read_str(unsigned char* str, unsigned char n)
{
while(!(DataRdyUSART()));                                       /* configure external LCD                                       */
getsUSART((char*)str, n);                                       /* Reading a string from UART                                   */
}

void Write(char data)
{
    WriteUSART(data);                                           /* Write a byte through USART module                            */
    while(BusyUSART());                                         /* Wait until the write complete                                */
}
void Read_string(unsigned char *buffer, unsigned char len)            /* Reads a string data from UART of having specific length*/
  {
  char i;
  unsigned char data;
      Write(0x0D);
      Write('\n');
  for(i=0;i<len;i++)
    {
    while(!DataRdyUSART());                                           /* Wait for data to be received                           */
    data = getcUSART();                                               /* Get a character from the USART                         */
    *buffer = data;                                                   /* save data in a string                                  */
    WriteUSART(data);
    while(BusyUSART());
    buffer++;                                                         /* Increment the string pointer                           */
    }
  }