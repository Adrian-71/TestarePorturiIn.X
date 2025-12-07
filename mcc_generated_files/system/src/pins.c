/**
 * Generated Driver File
 * 
 * @file pins.c
 * 
 * @ingroup  pinsdriver
 * 
 * @brief This is generated driver implementation for pins. 
 *        This file provides implementations for pin APIs for all pins selected in the GUI.
 *
 * @version Driver Version 3.1.1
*/

/*
© [2025] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#include "../pins.h"


void PIN_MANAGER_Initialize(void)
{
   /**
    LATx registers
    */
    LATA = 0x0;
    LATB = 0x0;
    LATC = 0x40;
    LATD = 0x0;
    LATE = 0x0;
    LATF = 0x0;
    LATG = 0x0;
    LATH = 0x0;
    /**
    ODx registers
    */
    ODCONA = 0x0;
    ODCONB = 0x0;
    ODCONC = 0x0;
    ODCOND = 0x0;
    ODCONE = 0x0;
    ODCONF = 0x0;
    ODCONG = 0x0;
    ODCONH = 0x0;

    /**
    TRISx registers
    */
    TRISA = 0xFF;
    TRISB = 0xFF;
    TRISC = 0xBF;
    TRISD = 0xFF;
    TRISE = 0xFF;
    TRISF = 0xFF;
    TRISG = 0xD7;
    TRISH = 0xF;

    /**
    ANSELx registers
    */
    ANSELA = 0x0;
    ANSELB = 0x0;
    ANSELD = 0x0;
    ANSELE = 0x0;
    ANSELF = 0x0;
    ANSELG = 0x0;

    /**
    WPUx registers
    */
    WPUA = 0xFF;
    WPUB = 0xFF;
    WPUC = 0x3F;
    WPUD = 0xFF;
    WPUE = 0xF7;
    WPUF = 0xFF;
    WPUG = 0xDF;
    WPUH = 0xF;


    /**
    SLRCONx registers
    */
    SLRCONA = 0xFF;
    SLRCONB = 0xFF;
    SLRCONC = 0xFF;
    SLRCOND = 0xFF;
    SLRCONE = 0xFF;
    SLRCONF = 0xFF;
    SLRCONG = 0xDF;
    SLRCONH = 0xF;

    /**
    INLVLx registers
    */
    INLVLA = 0xFF;
    INLVLB = 0xFF;
    INLVLC = 0xFF;
    INLVLD = 0xFF;
    INLVLE = 0xFF;
    INLVLF = 0xFF;
    INLVLG = 0xFF;
    INLVLH = 0xF;

   /**
    RxyI2C | RxyFEAT registers   
    */
    /**
    PPS registers
    */
    RX1PPS = 0x17; //RC7->EUSART1:RX1;
    RC6PPS = 0x0C;  //RC6->EUSART1:TX1;

   /**
    IOCx registers 
    */
    IOCBP = 0x0;
    IOCBN = 0x0;
    IOCBF = 0x0;
    IOCCP = 0x0;
    IOCCN = 0x0;
    IOCCF = 0x0;
    IOCEP = 0x0;
    IOCEN = 0x0;
    IOCEF = 0x0;
    IOCGP = 0x0;
    IOCGN = 0x0;
    IOCGF = 0x0;


    // Enable PIE0bits.IOCIE interrupt 
    PIE0bits.IOCIE = 1; 
}
  
void PIN_MANAGER_IOC(void)
{
}
/**
 End of File
*/