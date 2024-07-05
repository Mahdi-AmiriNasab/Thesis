/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F45K80
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set IO_RA6 aliases
#define IO_RA6_TRIS                 TRISAbits.TRISA6
#define IO_RA6_LAT                  LATAbits.LATA6
#define IO_RA6_PORT                 PORTAbits.RA6
#define IO_RA6_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define IO_RA6_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define IO_RA6_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define IO_RA6_GetValue()           PORTAbits.RA6
#define IO_RA6_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define IO_RA6_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)

// get/set IO_RA7 aliases
#define IO_RA7_TRIS                 TRISAbits.TRISA7
#define IO_RA7_LAT                  LATAbits.LATA7
#define IO_RA7_PORT                 PORTAbits.RA7
#define IO_RA7_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define IO_RA7_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define IO_RA7_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define IO_RA7_GetValue()           PORTAbits.RA7
#define IO_RA7_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define IO_RA7_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)

// get/set LED aliases
#define LED_TRIS                 TRISBbits.TRISB4
#define LED_LAT                  LATBbits.LATB4
#define LED_PORT                 PORTBbits.RB4
#define LED_WPU                  WPUBbits.WPUB4
#define LED_ANS                  ANCON1bits.ANSEL9
#define LED_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define LED_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define LED_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define LED_GetValue()           PORTBbits.RB4
#define LED_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define LED_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define LED_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define LED_SetAnalogMode()      do { ANCON1bits.ANSEL9 = 1; } while(0)
#define LED_SetDigitalMode()     do { ANCON1bits.ANSEL9 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)

// get/set RC5 procedures
#define RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()              PORTCbits.RC5
#define RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)

// get/set SPI_Chip_Select aliases
#define SPI_Chip_Select_TRIS                 TRISDbits.TRISD0
#define SPI_Chip_Select_LAT                  LATDbits.LATD0
#define SPI_Chip_Select_PORT                 PORTDbits.RD0
#define SPI_Chip_Select_ANS                  ANCON1bits.ANSEL11
#define SPI_Chip_Select_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define SPI_Chip_Select_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define SPI_Chip_Select_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define SPI_Chip_Select_GetValue()           PORTDbits.RD0
#define SPI_Chip_Select_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define SPI_Chip_Select_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define SPI_Chip_Select_SetAnalogMode()      do { ANCON1bits.ANSEL11 = 1; } while(0)
#define SPI_Chip_Select_SetDigitalMode()     do { ANCON1bits.ANSEL11 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/