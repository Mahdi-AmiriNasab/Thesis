/*!
  ltc681x hardware library
@verbatim
  This library contains all of the hardware dependant functions used by the bms
  code
@endverbatim

Copyright 2018(c) Analog Devices, Inc.

All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
 - Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
 - Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in
   the documentation and/or other materials provided with the
   distribution.
 - Neither the name of Analog Devices, Inc. nor the names of its
   contributors may be used to endorse or promote products derived
   from this software without specific prior written permission.
 - The use of this software may or may not infringe the patent rights
   of one or more patent holders.  This license does not release you
   from the requirement that you obtain separate licenses from these
   patent holders to use this software.
 - Use of the software either in source or binary form, must be run
   on or directly connected to an Analog Devices Inc. component.

THIS SOFTWARE IS PROVIDED BY ANALOG DEVICES "AS IS" AND ANY EXPRESS OR
IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, NON-INFRINGEMENT,
MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL ANALOG DEVICES BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, INTELLECTUAL PROPERTY RIGHTS, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

Copyright 2017 Linear Technology Corp. (LTC)
*/
#include "bms_hardware.h"
#include "defines.h"
#include <xc.h>
#include <stdint.h>
#include "mcc_generated_files/pin_manager.h"
#include "CAN/rtwtypes.h"

void cs_low()
{
    SPI_Chip_Select_SetLow();
}

void cs_high()
{
    SPI_Chip_Select_SetHigh();
}

/*
Writes an array of bytes out of the SPI port
*/
uint8_t spi_write_array(unsigned char len, // Option: Number of bytes to be written on the SPI port
                     unsigned char data[] //Array of bytes to be written on the SPI port
                    )
{
    
    unsigned char Temp;
    cs_low();
    for (unsigned char i = 0; i < len; i++)
    {
        Temp = SSPBUF;
        PIR1bits.SSPIF = 0;
        SSPCON1bits.WCOL = 0;
        SSPBUF = data[i];
        uint16_t counter=0;
        while(!PIR1bits.SSPIF){
      counter++;
      if(counter>500){
        LTCerrorCounter++;
        break;
      }
  }  // wait until bus cycle complete
        PIR1bits.SSPIF = 0;         // Clear interrupt flag
        
    }
    cs_high();
}

/*
 Writes and read a set number of bytes using the SPI port.

*/

void spi_write_read(unsigned char tx_Data[],//array of data to be written on SPI port
                    unsigned char tx_len, //length of the tx data arry
                    unsigned char *rx_data,//Input: array that will store the data read by the SPI port
                    unsigned char rx_len //Option: number of bytes to be read from the SPI port
                   )
{
    unsigned char Temp;  
    cs_low();
      for (unsigned char i = 0; i < tx_len; i++)
      {
        Temp = SSPBUF;           // Clears BF
        PIR1bits.SSPIF = 0;         // Clear interrupt flag
        SSPCON1bits.WCOL = 0;            //Clear any previous write collision
        SSPBUF = tx_Data[i];           // write byte to SSPBUF register
        uint16_t counter=0;
        while(!PIR1bits.SSPIF){
      counter++;
      if(counter>500){
        LTCerrorCounter++;
        break;
      }
  }  // wait until bus cycle complete
        PIR1bits.SSPIF = 0;
      }

      for (unsigned char i = 0; i < rx_len; i++)
      {

      Temp = SSPBUF;        // Clear BF
      PIR1bits.SSPIF = 0;      // Clear interrupt flag
      SSPBUF = 0x00;           // initiate bus cycle
      uint16_t counter=0;
      while(!PIR1bits.SSPIF){
      counter++;
      if(counter>500){
        LTCerrorCounter++;
        break;
      }
  }  // wait until bus cycle complete
PIR1bits.SSPIF = 0;
        rx_data[i] = (unsigned char)SSPBUF;
      }
        cs_high();
}


unsigned char spi_read_byte(unsigned char tx_dat)
{
  cs_low();
  
  unsigned char data;
  unsigned char Temp;
  uint16_t counter=0;
  Temp = SSPBUF;        // Clear BF
  PIR1bits.SSPIF = 0;      // Clear interrupt flag
  SSPBUF = 0x00;           // initiate bus cycle
  while(!PIR1bits.SSPIF){
      counter++;
      if(counter>500){
        LTCerrorCounter++;
        break;
      }
  }  // wait until bus cycle complete
  PIR1bits.SSPIF = 0;
  data = (unsigned char)SSPBUF;
  cs_high();
  return(data);
}
