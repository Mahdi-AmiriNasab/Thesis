/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F45K80
        Driver Version    :  2.00
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
#pragma config WDTEN = ON         /* Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))*/


#include "mcc_generated_files/mcc.h"
#include "LTC681xRev2.h"
#include "CAN/CAN.h"
/*
                         Main application
 */

//173 = -30 (0)
//54.77 = -10
//31.77 = 0 (30)
//19.68 = 10 ()
//10.00 = 25 (55)
//
//float ntcTable[136] = {173,163,153,144,135,120,128,113,
//107,101,90,85,80.6,76.02,72.01,68.14,64.47,61.03,57.8,
//54.77,51.82,49.28,46,89,44.62,42.48,40.45, 38.53, 36.70,34.97,33.33
//,31.77, 30.25, 28.82, 27.45, 26.16, 24.94, 23.77, 22.67,
// 21.62, 20.63, 19.68, 18.78, 17.93, 17.12, 16.35, 15.62,
// 14.93, 14.26, 13.63, 13.04, 12.47, 11.92, 11.41, 10.91,
// 10.45, 10.00, 9.575, 9.170, 8.784, 8.416, 8.064, 7.730,
// 7.410, 7.106, 6.815, 6.538, 6.273, 6.020, 5.778, 5.548,
// 5.327, 5.117, 4.915, 4.723, 4.539, 4.363, 4.195, 4.034,
// 3.880, 3.733, 3.592 ,3.457, 3.328, 3.204, 3.086, 2.972,
// 2.863, 2.759, 2.659, 2.564, 2.472, 2.384, 2.292, 2.218,
// 2.141, 2.066, 1.994, 1.926, 1.860, 1.796, 1.735, 1.677,
// 1.621, 1.567, 1.515, 1.465, 1.417, 1.371, 1.326, 1.284,
// 1.243, 1.203, 1.165, 1.128, 1.093, 1.059, 1.027, 0.9955,
// 0.9654, 0.9363, 0.9083, 0.8812, 0.8550, 0.8297, 0.8052, 0.7816, 
// 0.7587, 0.7366, 0.7152, 0.6945, 0.6744, 0.6558, 0.6376, 0.6199,
// 0.6026, 0.5858};

///////////////////////////
#define MyID 8
///////////////////////////
#define match(x,y) 2*(x+8*y)


///////////////////////////
bool LTCBusyFlag, dataReadyFlag,LTCPermit,CANPermit,SPIError,CANRecError,LTCError;
uint16_t balancerIndex = 0;
uint8_t mainCounter = 0; 
uint16_t testCounter = 0;
uint16_t SPIerrorCounter = 0,CANRecCounter = 0, LTCerrorCounter=0;
uint8_t CANTxCounter = 0;
uint16_t voltageBuffer[24];
uint16_t tempBuffer[4];
uint16_t Tx_counter = 0;
uint16_t counter=0,preCounter=0,deltaCounter=0;
uint8_t CAN_Tx_flag = 0,CAN_Rx_flag = 0;

ExtU_CAN_T CAN_U;
ExtY_CAN_T CAN_Y;

uCAN_MSG CAN_Tx;
uCAN_MSG CAN_Rx,CAN_Rx1,CAN_Rx2;

const uint8_t TOTAL_IC = 1;
cell_asic bmb_ic[1];
uint8_t gpio[5] = {1,1,1,1,1}; //should be 1 to disable pulldown to read voltage 
uint8_t dcc[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
uint8_t dcto[4] = {0,0,0,0};
void checkPEC();
void LTC_Init();
uint8_t getGpioVoltage();
uint8_t getCellVoltage();
void updateCellVoltage();
//float ntcTemp(float ohm);
void CANTransmit();
void updateCANData();
void CANParser();
void BalancerCommand();


void timer0_ISR(){
    //2ms
    
    mainCounter++;
    CAN_Rx_flag = CAN_receive(&CAN_Rx1, &CAN_Rx2);
    if(CAN_Rx_flag == 2){
    CANParser(MyID);
        CANRecCounter++;
        mainCounter=0;TMR0_Reload();
    }
    
    /*
    mainCounter++;
    CAN_Rx_flag = CAN_receive(&CAN_Rx);
    if(CAN_Rx_flag == 1){
        
        CAN_Rx1 = CAN_Rx;
    }
    if(CAN_Rx_flag == 2){
      
        CAN_Rx2 = CAN_Rx;
        CANParser(MyID);
        CANRecCounter++;
        mainCounter=0;TMR0_Reload();LED_Toggle();
    }
    
*/

    
//    if(mainCounter % 500 == 0){ // check every 1 sec
//        if(LTCerrorCounter > 20){
//            LTCerrorCounter = 0;
//            LTCError = 1;
//        }
//        else{
//            LTCError = 0;
//            LTCerrorCounter = 0;
//        }        
//        
//        if(CANRecCounter < 5){
//            CANRecCounter = 0;
//            CANRecError = 1;
//        }
//        else{
//            CANRecError = 0;
//            CANRecCounter = 0;
//        }
//    }

//    if(!LTCError && !SPIError && CANRecError){ 
//        if(mainCounter % 250 == 0)
//        LED_Toggle(); // error indicator CAN recieve under 50% every 500ms blink
//    }    
//    
//    if(LTCError){ 
//        if(mainCounter % 10 == 0)
//        LED_Toggle(); // error indicator LTC error every 20ms blink
//    }
}

void timer1_ISR(){
    //5ms
//    if(dataReadyFlag == 1){
//        CANPermit = 0;
//        CANTxCounter++;
//        
//        if(CANTxCounter == 1){
//            CAN_Tx.frame.idType = dSTANDARD_CAN_MSG_ID_2_0B;
//            CAN_Tx.frame.id = MyID*3;
//            CAN_Tx.frame.dlc = 8;
//            CAN_Tx.frame.data0 = CAN_Y.Voltage1.Data[0];CAN_Tx.frame.data1 = CAN_Y.Voltage1.Data[1];
//            CAN_Tx.frame.data2 = CAN_Y.Voltage1.Data[2];CAN_Tx.frame.data3 = CAN_Y.Voltage1.Data[3];
//            CAN_Tx.frame.data4 = CAN_Y.Voltage1.Data[4];CAN_Tx.frame.data5 = CAN_Y.Voltage1.Data[5];
//            CAN_Tx.frame.data6 = CAN_Y.Voltage1.Data[6];CAN_Tx.frame.data7 = CAN_Y.Voltage1.Data[7];
//            CAN_Tx_flag = CAN_transmit(&CAN_Tx);
//        }
//        else if(CANTxCounter == 2){
//            CAN_Tx.frame.idType = dSTANDARD_CAN_MSG_ID_2_0B;
//            CAN_Tx.frame.id = MyID*3+1;
//            CAN_Tx.frame.dlc = 8;
//            CAN_Tx.frame.data0 = CAN_Y.Voltage2.Data[0];CAN_Tx.frame.data1 = CAN_Y.Voltage2.Data[1];
//            CAN_Tx.frame.data2 = CAN_Y.Voltage2.Data[2];CAN_Tx.frame.data3 = CAN_Y.Voltage2.Data[3];
//            CAN_Tx.frame.data4 = CAN_Y.Voltage2.Data[4];CAN_Tx.frame.data5 = CAN_Y.Voltage2.Data[5];
//            CAN_Tx.frame.data6 = CAN_Y.Voltage2.Data[6];CAN_Tx.frame.data7 = CAN_Y.Voltage2.Data[7];
//            CAN_Tx_flag = CAN_transmit(&CAN_Tx);
//        }
//        else if(CANTxCounter == 3){
//            CAN_Tx.frame.idType = dSTANDARD_CAN_MSG_ID_2_0B;
//            CAN_Tx.frame.id = MyID*3+2;
//            CAN_Tx.frame.dlc = 8;
//            CAN_Tx.frame.data0 = CAN_Y.Voltage3.Data[0];CAN_Tx.frame.data1 = CAN_Y.Voltage3.Data[1];
//            CAN_Tx.frame.data2 = CAN_Y.Voltage3.Data[2];CAN_Tx.frame.data3 = CAN_Y.Voltage3.Data[3];
//            CAN_Tx.frame.data4 = CAN_Y.Voltage3.Data[4];CAN_Tx.frame.data5 = CAN_Y.Voltage3.Data[5];
//            CAN_Tx.frame.data6 = CAN_Y.Voltage3.Data[6];CAN_Tx.frame.data7 = CAN_Y.Voltage3.Data[7];
//            CAN_Tx_flag = CAN_transmit(&CAN_Tx);
//            CANTxCounter = 0;
//            dataReadyFlag = 0;
//            CANPermit = 1;
//        }
//    }else{
//        CANTxCounter = 0;
//    }
    
    counter++;  
    
if (counter % 200 == 0){
    
    if(CANRecCounter < 5){
            CANRecCounter = 0;
            CANRecError = 1;
        }
    else{
        CANRecError = 0;
        CANRecCounter = 0;
    }
}
    
//    
//    
//    
//    if (Tx_counter % 200 == 0){
//        //check LTC errors
//    if(SPIerrorCounter > 10){
//        SPIError = 1;SPIerrorCounter=0;
//    }else{
//        SPIError = 0;SPIerrorCounter=0;
//    }
//
//    }

    
    
    
    if(CANRecError && counter%100==1){
        LED_Toggle(); //indicator per 100ms if LTC timeout for 50 times 
    }
    if(!CANRecError && counter%200==0){
        LED_Toggle(); //indicator per 100ms if LTC timeout for 50 times 
    }
    
    
    
    
//    //!CANRecError && !SPIError &&
//    if(!LTCError && !CANRecError && !SPIError && Tx_counter % 200 == 0){
//        LED_Toggle(); //OK indicator per 1s
//        
//    }
    
    
    
}
spi_modes_t mySPI;

void main(void)
{

    // Initialize the device
    SYSTEM_Initialize();
    TMR0_SetInterruptHandler(timer0_ISR);
    TMR1_SetInterruptHandler(timer1_ISR);
    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    
    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    SPI_Open();
    for(int i=0;i<10;i++){
        LED_Toggle();
    __delay_ms(25);
    }
    LED_SetLow();
 
    LTC_Init();
    WDTCONbits.SWDTEN = 1;
    LTCPermit = 1;
    CANPermit = 1;
    while (1)
    {
    CLRWDT();
    //Add your application code
    
    preCounter = counter;
    if(LTCPermit == 1){
        LTCBusyFlag = 1;
    wakeup_sleep(TOTAL_IC);//1ms    
    LTC681x_wrcfg(TOTAL_IC, bmb_ic); //1.8ms
    LTC681x_rdcfg(TOTAL_IC, bmb_ic); //2.6ms
    getCellVoltage(); //8.6ms
    checkPEC();
    LTC681x_rdcfg(TOTAL_IC, bmb_ic); //2.6ms
    getGpioVoltage(); //4.8ms
    LTC681x_set_balance(balancerIndex, bmb_ic);
    LTC681x_wrsctrl(TOTAL_IC,0,bmb_ic);
    LTC681x_stsctrl();
    LTC681x_rdsctrl(TOTAL_IC, 0, bmb_ic);
    //LED_SetHigh();
    updateCellVoltage();  //0.6ms
    //LED_SetLow();
        LTCBusyFlag = 0;
    }   
    
        updateCANData(); //0.2ms
        CAN_step(); //4ms
    
    if(PIR5bits.IRXIF){ 
        PIR5bits.IRXIF = 0;
    }
    
    BalancerCommand();
    
    deltaCounter = counter - preCounter;
    
    
    while(!(mainCounter == match(MyID,0)||
            mainCounter == match(MyID,1)||
            mainCounter == match(MyID,2)||
            mainCounter == match(MyID,3)||
            mainCounter == match(MyID,4)||
            mainCounter == match(MyID,5)
            )
            ){
        __delay_us(10);
    }
        CANTransmit();
    }
}
void LTC_Init(){
//LTC init
LTC681x_init_cfg(TOTAL_IC, bmb_ic);
LTC681x_reset_crc_count(TOTAL_IC,bmb_ic);

bmb_ic[0].ic_reg.aux_channels = 6;
bmb_ic[0].ic_reg.cell_channels = 12;
bmb_ic[0].ic_reg.num_cv_reg = 4;
bmb_ic[0].ic_reg.num_gpio_reg = 2;
bmb_ic[0].ic_reg.num_stat_reg = 3;
bmb_ic[0].ic_reg.stat_channels = 4;

for(uint8_t current_ic = 0 ; current_ic<TOTAL_IC ; current_ic++)
{
    LTC681x_set_cfgr(current_ic, bmb_ic, 1, 0, gpio, dcc, dcto, 0, 50000);
}
wakeup_sleep(TOTAL_IC);
LTC681x_wrcfg(TOTAL_IC, bmb_ic);
    
}

uint8_t getGpioVoltage(){
    
//    LTC681x_adax(MD_7KHZ_3KHZ, AUX_CH_GPIO1);
//    __delay_ms(1); //wait to stable vref
//    LTC681x_rdaux(REG_ALL, TOTAL_IC, bmb_ic);  
//    LTC681x_adax(MD_7KHZ_3KHZ, AUX_CH_GPIO2);  
//    LTC681x_rdaux(REG_ALL, TOTAL_IC, bmb_ic);
    
    
    LTC681x_adax(MD_7KHZ_3KHZ, AUX_CH_ALL);
    __delay_ms(1); //wait to stable vref
    LTC681x_rdaux(REG_ALL, TOTAL_IC, bmb_ic);
   
    
    
    
}

uint8_t getCellVoltage(){

    LTC681x_adcv(MD_7KHZ_3KHZ,DCP_DISABLED,CELL_CH_ALL);// ADC initialize command
    __delay_ms(1); //wait to stable vref
    LTC681x_rdcv(REG_ALL, TOTAL_IC, bmb_ic); //read voltages
    
}
void checkPEC(){
    if(bmb_ic[0].cells.pec_match[0] == 1 && bmb_ic[0].cells.pec_match[1] == 1 && bmb_ic[0].cells.pec_match[2] == 1){
        SPIerrorCounter++;
    }
}


void updateCellVoltage(){
    
for(int i=0; i<12; i++){
                
                voltageBuffer[2*i+1] = bmb_ic[0].cells.c_codes[i] & 0xFF;
                voltageBuffer[2*i] = (uint8_t)(bmb_ic[0].cells.c_codes[i] >> 8) & 0xFF;
            
            }

            tempBuffer[1] = bmb_ic[0].aux.a_codes[0] & 0xFF;
            tempBuffer[0] = (uint8_t)(bmb_ic[0].aux.a_codes[0] >> 8) & 0xFF;
            tempBuffer[3] = bmb_ic[0].aux.a_codes[1] & 0xFF;
            tempBuffer[2] = (uint8_t)(bmb_ic[0].aux.a_codes[1] >> 8) & 0xFF;    
}

//
//float ntcTemp(float ohm){
//	float slop;
//	for(int i=0; i<136; i++){
//		
//		if(ohm > ntcTable[i]){		
//			slop = (ohm - ntcTable[i-1])/(ntcTable[i] - ntcTable[i-1]) + (double)i -1;
//			return slop;
//		}
//	}
//}


void updateCANData(){
    //CAN INIT
    //if(voltageBuffer[1] | (voltageBuffer[0] << 8) != 0)
    CAN_U.v1 = voltageBuffer[1] | (voltageBuffer[0] << 8);   
    
    //if(voltageBuffer[3] | (voltageBuffer[2] << 8) != 0)
    CAN_U.v2 = voltageBuffer[3] | (voltageBuffer[2] << 8);
    
    //if(voltageBuffer[5] | (voltageBuffer[4] << 8) != 0)
    CAN_U.v3 = voltageBuffer[5] | (voltageBuffer[4] << 8);
    
    //if(voltageBuffer[7] | (voltageBuffer[6] << 8) != 0)
    CAN_U.v4 = voltageBuffer[7] | (voltageBuffer[6] << 8);
    
    //if(voltageBuffer[9] | (voltageBuffer[8] << 8) != 0)
    CAN_U.v5 = voltageBuffer[9] | (voltageBuffer[8] << 8);
    
    //if(voltageBuffer[11] | (voltageBuffer[10] << 8) != 0)
    CAN_U.v6 = voltageBuffer[11] | (voltageBuffer[10] << 8);
    
    //if(voltageBuffer[13] | (voltageBuffer[12] << 8) != 0)
    CAN_U.v7 = voltageBuffer[13] | (voltageBuffer[12] << 8);
    
    //if(voltageBuffer[15] | (voltageBuffer[14] << 8) != 0)
    CAN_U.v8 = voltageBuffer[15] | (voltageBuffer[14] << 8);
    
    //if(voltageBuffer[17] | (voltageBuffer[16] << 8) != 0)
    CAN_U.v9 = voltageBuffer[17] | (voltageBuffer[16] << 8);
    
    //if(voltageBuffer[19] | (voltageBuffer[18] << 8) != 0)
    CAN_U.v10 = voltageBuffer[19] | (voltageBuffer[18] << 8);
    
    //if(voltageBuffer[21] | (voltageBuffer[20] << 8) != 0)
    CAN_U.v11 = voltageBuffer[21] | (voltageBuffer[20] << 8);
    
    //if(voltageBuffer[23] | (voltageBuffer[22] << 8) != 0)
    CAN_U.v12 = voltageBuffer[23] | (voltageBuffer[22] << 8);
    
    //if(tempBuffer[1] | (tempBuffer[0] << 8) != 0)
    CAN_U.t1 = tempBuffer[1] | (tempBuffer[0] << 8);
    
    //if(tempBuffer[3] | (tempBuffer[2] << 8) != 0)
    CAN_U.t2 = tempBuffer[3] | (tempBuffer[2] << 8);
    
    CAN_U.counter = deltaCounter;
    
}

void CANParser(){
    CAN_U.balance1.Data[0] = CAN_Rx1.frame.data0;
    CAN_U.balance1.Data[1] = CAN_Rx1.frame.data1;
    CAN_U.balance1.Data[2] = CAN_Rx1.frame.data2;
    CAN_U.balance1.Data[3] = CAN_Rx1.frame.data3;
    CAN_U.balance1.Data[4] = CAN_Rx1.frame.data4;
    CAN_U.balance1.Data[5] = CAN_Rx1.frame.data5;
    CAN_U.balance1.Data[6] = CAN_Rx1.frame.data6;
    CAN_U.balance1.Data[7] = CAN_Rx1.frame.data7;
    CAN_U.balance1.ID = 1;
    CAN_U.balance1.Length = 8;
    CAN_U.balance1.Extended = 0;
    
    CAN_U.balance2.Data[0] = CAN_Rx2.frame.data0;
    CAN_U.balance2.Data[1] = CAN_Rx2.frame.data1;
    CAN_U.balance2.Data[2] = CAN_Rx2.frame.data2;
    CAN_U.balance2.Data[3] = CAN_Rx2.frame.data3;
    CAN_U.balance2.Data[4] = CAN_Rx2.frame.data4;
    CAN_U.balance2.Data[5] = CAN_Rx2.frame.data5;
    CAN_U.balance2.Data[6] = CAN_Rx2.frame.data6;
    CAN_U.balance2.Data[7] = CAN_Rx2.frame.data7;
    CAN_U.balance2.ID = 2;
    CAN_U.balance2.Length = 8;
    CAN_U.balance2.Extended = 0;
}
void BalancerCommand(){
    switch(MyID){
        
        case 1:
            balancerIndex = CAN_Y.b1;
            break;
        case 2:
            balancerIndex = CAN_Y.b2; 
            break;
        case 3:
            balancerIndex = CAN_Y.b3;
            break;
        case 4:    
            balancerIndex = CAN_Y.b4;
            break;
        case 5:
            balancerIndex = CAN_Y.b5;
            break;
        case 6:
            balancerIndex = CAN_Y.b6;
            break;
        case 7:
            balancerIndex = CAN_Y.b7;
            break;
        case 8:
            balancerIndex = CAN_Y.b8; 
            break;
    }

}

void CANTransmit(){

            CAN_Tx.frame.idType = dSTANDARD_CAN_MSG_ID_2_0B;
            CAN_Tx.frame.id = MyID*3;
            CAN_Tx.frame.dlc = 8;
            CAN_Tx.frame.data0 = CAN_Y.Voltage1.Data[0];CAN_Tx.frame.data1 = CAN_Y.Voltage1.Data[1];
            CAN_Tx.frame.data2 = CAN_Y.Voltage1.Data[2];CAN_Tx.frame.data3 = CAN_Y.Voltage1.Data[3];
            CAN_Tx.frame.data4 = CAN_Y.Voltage1.Data[4];CAN_Tx.frame.data5 = CAN_Y.Voltage1.Data[5];
            CAN_Tx.frame.data6 = CAN_Y.Voltage1.Data[6];CAN_Tx.frame.data7 = CAN_Y.Voltage1.Data[7];
            CAN_Tx_flag = CAN_transmit(&CAN_Tx); //every packet last for 200us
            __delay_us(200);
            //time between packet without delay is 20us
            CAN_Tx.frame.idType = dSTANDARD_CAN_MSG_ID_2_0B;
            CAN_Tx.frame.id = MyID*3+1;
            CAN_Tx.frame.dlc = 8;
            CAN_Tx.frame.data0 = CAN_Y.Voltage2.Data[0];CAN_Tx.frame.data1 = CAN_Y.Voltage2.Data[1];
            CAN_Tx.frame.data2 = CAN_Y.Voltage2.Data[2];CAN_Tx.frame.data3 = CAN_Y.Voltage2.Data[3];
            CAN_Tx.frame.data4 = CAN_Y.Voltage2.Data[4];CAN_Tx.frame.data5 = CAN_Y.Voltage2.Data[5];
            CAN_Tx.frame.data6 = CAN_Y.Voltage2.Data[6];CAN_Tx.frame.data7 = CAN_Y.Voltage2.Data[7];
            CAN_Tx_flag = CAN_transmit(&CAN_Tx);
            __delay_us(200);
            CAN_Tx.frame.idType = dSTANDARD_CAN_MSG_ID_2_0B;
            CAN_Tx.frame.id = MyID*3+2;
            CAN_Tx.frame.dlc = 8;
            CAN_Tx.frame.data0 = CAN_Y.Voltage3.Data[0];CAN_Tx.frame.data1 = CAN_Y.Voltage3.Data[1];
            CAN_Tx.frame.data2 = CAN_Y.Voltage3.Data[2];CAN_Tx.frame.data3 = CAN_Y.Voltage3.Data[3];
            CAN_Tx.frame.data4 = CAN_Y.Voltage3.Data[4];CAN_Tx.frame.data5 = CAN_Y.Voltage3.Data[5];
            CAN_Tx.frame.data6 = CAN_Y.Voltage3.Data[6];CAN_Tx.frame.data7 = CAN_Y.Voltage3.Data[7];
            CAN_Tx_flag = CAN_transmit(&CAN_Tx);
            
    
}

/**
 End of File
*/