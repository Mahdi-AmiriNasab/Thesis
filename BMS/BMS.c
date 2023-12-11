// load f28335.cmd from c2000ware path. this includes ramfuncloadsize for flash program

#include "DSP28x_Project.h"     // Device Headerfile and Examples Include File
#include <string.h>
#include <ADCFilter.h>
#include "test3.h"     //Device Headerfile and Examples Include File
#include "VCU_CAN_Function.h"
#include <CAN.h>
#include <Estimations.h>
#include <CANBMB.h>
#include "ChargeAl.h"


#define seriesCells 96
#define parallelCells 28
#define capacityCell 4.77

//black EV currentLowOffset = 1677, currentHighOffset = 2034
#define currentLowOffset 1701 //obtained when no current
#define currentHighOffset 2155 //obtained when no current

#define packVoltageGain 0.10566 //obtained by known ref voltage
#define inputVoltageGain 0.00485 //obtained by known ref voltage

Uint16 counterX=0;
Uint32 aa = 0,bb=0;
double ntcTable[138] = {183,173,163,153,144,135,120,128,113,
 107,   101,   90,    85,    80.6,  76.02,72.01,68.14,64.47,61.03,57.8,
 54.77, 51.82, 49.28, 46,89, 44.62, 42.48, 40.45, 38.53,
 36.70, 34.97, 33.33
,31.77, 30.25, 28.82, 27.45, 26.16, 24.94, 23.77, 22.67,
 21.62, 20.63, 19.68, 18.78, 17.93, 17.12, 16.35, 15.62,
 14.93, 14.26, 13.63, 13.04, 12.47, 11.92, 11.41, 10.91,
 10.45, 10.00, 9.575, 9.170, 8.784, 8.416, 8.064, 7.730,
 7.410, 7.106, 6.815, 6.538, 6.273, 6.020, 5.778, 5.548,
 5.327, 5.117, 4.915, 4.723, 4.539, 4.363, 4.195, 4.034,
 3.880, 3.733, 3.592 ,3.457, 3.328, 3.204, 3.086, 2.972,
 2.863, 2.759, 2.659, 2.564, 2.472, 2.384, 2.292, 2.218,
 2.141, 2.066, 1.994, 1.926, 1.860, 1.796, 1.735, 1.677,
 1.621, 1.567, 1.515, 1.465, 1.417, 1.371, 1.326, 1.284,
 1.243, 1.203, 1.165, 1.128, 1.093, 1.059, 1.027, 0.9955,
 0.9654,0.9363,0.9083,0.8812,0.8550,0.8297,0.8052,0.7816,
 0.7587,0.7366,0.7152,0.6945,0.6744,0.6558,0.6376,0.6199,
 0.6026,0.5858};

double OCV_Curve[101]=
    {4.1629, 4.1223, 4.1043, 4.0910, 4.0804, 4.0724, 4.0659, 4.0597, 4.0539, 4.0482, 4.0432,
     4.0389, 4.0333, 4.0268, 4.0200, 4.0128, 4.0035, 3.9930, 3.9812, 3.9694, 3.9580, 3.9471,
     3.9353, 3.9220, 3.9090, 3.8972, 3.8864, 3.8771, 3.8678, 3.8585, 3.8501, 3.8423, 3.8349,
     3.8268, 3.8188, 3.8110, 3.8033, 3.7955, 3.7875, 3.7788, 3.7698, 3.7611, 3.7524, 3.7431,
     3.7338, 3.7248, 3.7165, 3.7075, 3.6979, 3.6879, 3.6780, 3.6687, 3.6588, 3.6489, 3.6393,
     3.6303, 3.6213, 3.6120, 3.6027, 3.5943, 3.5850, 3.5757, 3.5661, 3.5565, 3.5469, 3.5363,
     3.5252, 3.5131, 3.5016, 3.4911, 3.4824, 3.4743, 3.4666, 3.4588, 3.4505, 3.4412, 3.4306,
     3.4185, 3.4046, 3.3885, 3.3717, 3.3544, 3.3364, 3.3175, 3.2961, 3.2722, 3.2468, 3.2201,
     3.1913, 3.1600, 3.1274, 3.0952, 3.0633, 3.0298, 2.9907, 2.9454, 2.8931, 2.8357, 2.7610,
     2.6534, 2.5000};

double OCV_Curve_new[21]={
4.164, 4.098, 4.077, 4.050, 4.002, 3.951, 3.910, 3.854, 3.808, 3.766, 3.729, 3.686, 3.634, 3.578, 3.524, 3.489, 3.429, 3.341, 3.235, 3.125, 2.877};


double OCV(double v){
    Uint16 i;
    for(i=0;i<101;i++){
        if( v > OCV_Curve[i] ){
            return 100 - (double)i;
        }
    }
}

double new_OCV(double v){
    Uint16 i;
    for(i=0;i<21;i++){
        if( v > OCV_Curve_new[i] ){
            if(i==0)
                return 100;
            return 100 - 5*(double)i + 5.00* (v - OCV_Curve_new[i]) / (OCV_Curve_new[i-1]-OCV_Curve_new[i]);
        }
    }
}

double voltagetest,itest;
float kwh_integral=0,kwh_integral_noFilter=0;
Uint16 counterCHM=0;
void   I2CA_Init(void);
Uint16 I2CA_WriteData(struct I2CMSG *msg);
Uint16 I2CA_ReadData(struct I2CMSG *msg);
__interrupt void i2c_int1a_isr(void);
void pass(void);
void fail(void);
//
// Defines
//
#define I2C_SLAVE_ADDR        0x50
#define I2C_NUMBYTES          4
#define I2C_EEPROM_HIGH_ADDR  0x00
#define I2C_EEPROM_LOW_ADDR   0x30
struct I2CMSG I2cMsgOut1=
{
    I2C_MSGSTAT_SEND_WITHSTOP,
    I2C_SLAVE_ADDR,
    I2C_NUMBYTES,
    I2C_EEPROM_HIGH_ADDR,
    I2C_EEPROM_LOW_ADDR,
    0x12,                   // Msg Byte 1
    0x34,                   // Msg Byte 2
    0x56,                   // Msg Byte 3
    0x78,                   // Msg Byte 4
    0x9A,                   // Msg Byte 5
    0xBC,                   // Msg Byte 6
    0xDE,                   // Msg Byte 7
    0xF0,                   // Msg Byte 8
    0x11,                   // Msg Byte 9
    0x10,                   // Msg Byte 10
    0x11,                   // Msg Byte 11
    0x12,                   // Msg Byte 12
    0x13,                   // Msg Byte 13
    0x12                    // Msg Byte 14
};

struct I2CMSG I2cMsgIn1=
{   I2C_MSGSTAT_SEND_NOSTOP,
    I2C_SLAVE_ADDR,
    I2C_NUMBYTES,
    I2C_EEPROM_HIGH_ADDR,
    I2C_EEPROM_LOW_ADDR
};

//
// Globals
//


Uint16 Flag_Fast_Charge_Counter=0,Flag_Fast_Charge=0;

struct I2CMSG *CurrentMsgPtr;               // Used in interrupts
Uint16 PassCount;
Uint16 FailCount;

extern ExtU_ChargeAl_T ChargeAl_U;
extern ExtY_ChargeAl_T ChargeAl_Y;

extern ExtU_ADCFilter_T ADCFilter_U;
extern ExtY_ADCFilter_T ADCFilter_Y;

extern ExtU_CAN_T CAN_U;
extern ExtY_CAN_T CAN_Y;

extern ExtU_test3_T test3_U;
extern ExtY_test3_T test3_Y;

extern ExtU_CANBMB_T CANBMB_U;
extern ExtY_CANBMB_T CANBMB_Y;

extern Uint16 e2pWriteComplete;
extern Uint16 e2pCompleteReading;
extern Uint16 e2pRecievedData[16];

#define LED1_SET       GpioDataRegs.GPCSET.bit.GPIO77 = 1
#define LED1_RESET       GpioDataRegs.GPCCLEAR.bit.GPIO77 = 1
#define LED1_TOGGLE       GpioDataRegs.GPCTOGGLE.bit.GPIO77 = 1

#define LED2_SET       GpioDataRegs.GPCSET.bit.GPIO78 = 1
#define LED2_RESET       GpioDataRegs.GPCCLEAR.bit.GPIO78 = 1
#define LED2_TOGGLE       GpioDataRegs.GPCTOGGLE.bit.GPIO78 = 1

#define LED3_SET       GpioDataRegs.GPCSET.bit.GPIO79 = 1
#define LED3_RESET       GpioDataRegs.GPCCLEAR.bit.GPIO79 = 1
#define LED3_TOGGLE       GpioDataRegs.GPCTOGGLE.bit.GPIO79 = 1

#define LED4_SET       GpioDataRegs.GPBSET.bit.GPIO38 = 1
#define LED4_RESET       GpioDataRegs.GPBCLEAR.bit.GPIO38 = 1
#define LED4_TOGGLE       GpioDataRegs.GPBTOGGLE.bit.GPIO38 = 1

#define bmb_SET       GpioDataRegs.GPCSET.bit.GPIO75 = 1
#define bmb_RESET       GpioDataRegs.GPCCLEAR.bit.GPIO75 = 1
#define bmb_TOGGLE       GpioDataRegs.GPCTOGGLE.bit.GPIO75 = 1

#define PRECHARGE_SET       GpioDataRegs.GPASET.bit.GPIO4 = 1
#define PRECHARGE_RESET       GpioDataRegs.GPACLEAR.bit.GPIO4 = 1


#define EPWM1_TIMER_TBPRD  2000  // Period register
#define EPWM1_MAX_CMPA     1950
#define EPWM1_MIN_CMPA     50
#define EPWM2_TIMER_TBPRD  2000  // Period register
#define EPWM2_MAX_CMPA     1950
#define EPWM2_MIN_CMPA       50
#define EPWM_CMP_UP   1
#define EPWM_CMP_DOWN 0


typedef struct
{
    volatile struct EPWM_REGS *EPwmRegHandle;
    Uint16 stopFlag;
    Uint16 EPwm_CMPA_Direction;
    Uint16 EPwm_CMPB_Direction;
    Uint16 EPwmTimerIntCount;
    Uint16 EPwmMaxCMPA;
    Uint16 EPwmMinCMPA;
    Uint16 EPwmMaxCMPB;
    Uint16 EPwmMinCMPB;
} EPWM_INFO;
EPWM_INFO epwm1_info;
EPWM_INFO epwm2_info;


Uint16 CANBMBCounter[8],bmbReadyCounter[8];
Uint16 BMBFailedCounter=0;
Uint16 flag100ms=0;
Uint16 startAlgorithmFlag = 0;

double test,test1,test2;

Uint16 max=0,max1=0;
Uint16 totalBalancerCount=0,totalBalancerCountTemp=0;
double cellCurrent;

Uint16 ADC[4];
double test4;

Uint16 timerbmb=0,BMBQualityCounter=0;

Uint16 calculationFlag = 0;


float inputVoltage, currentLow, currentHigh, packVoltage,packVoltageX, currentLowFilter, currentHighFilter;


Uint16 CurrentCalFlag=0;

Uint16 BMBCounter1,BMBCounter2,BMBCounter3,BMBCounter4,BMBCounter5,BMBCounter6,BMBCounter7,BMBCounter8;


Uint16 bmbReadyFlag[8];

Uint16 estimationCount=0;

Uint16 CANQualityFlag, lowSpeedFlag=0;

Uint16 Flag_test3;
Uint16 Flag_test3_CAN_Fault;
double packCurrent;
Uint16 flagStartMeasure=0;

double currentIntegral=0, SOC_columb=0;

Uint16 testCounter=0,timer=0;
Uint16 testbmbcounter=0;

Uint16 NegContFlag,PosContFlag,PrechargeContFlag;

Uint16 ShortCircuitFault = 0;

Uint16 estimationFlag = 0;

Uint16 FlagStartEstimation=0;
Uint16 flagEpwm1Stop=0, flagEpwm2Stop=0;

double OCV_table = 0;
Uint16 OCV_GetFlag =0,FlagStartOCV=0;

// Function Prototypes
void balancer();
void CANQualityCal();
void cellDataParser();
void NegContStart();
void NegContStop();
double ntcTemp(double ohm, real32_T *des);
void PosContStart();
void PosContStop();
void prechargContStart();
void prechargContStop();
void validateBMBData();

void config_ADC_A(Uint16 maxConv, Uint16 adcChselSEQ1Reg, Uint16
                  adcChselSEQ2Reg, Uint16 adcChselSEQ3Reg, Uint16
                  adcChselSEQ4Reg);
__interrupt void cpu_timer0_isr(void);
__interrupt void cpu_timer2_isr(void);



void InitEPwm2Example(void);
void InitEPwm1Example(void);

__interrupt void epwm1_isr(void);
__interrupt void epwm2_isr(void);

__interrupt void WAKE_ISR(void);

Uint16 bmbMask[8];

extern Uint16 RamfuncsLoadStart;
extern Uint16 RamfuncsLoadEnd;
extern Uint16 RamfuncsRunStart;
extern Uint16 RamfuncsLoadSize;


void update_compare(EPWM_INFO*);


Uint16 i,j;

void main(void)

{
    CurrentMsgPtr = &I2cMsgOut1;

    CANBMBCounter[0] = 0;
    CANBMBCounter[1] = 0;
    CANBMBCounter[2] = 0;
    CANBMBCounter[3] = 0;
    CANBMBCounter[4] = 0;
    CANBMBCounter[5] = 0;
    CANBMBCounter[6] = 0;
    CANBMBCounter[7] = 0;

    bmbReadyCounter[0] = 0;
    bmbReadyCounter[1] = 0;
    bmbReadyCounter[2] = 0;
    bmbReadyCounter[3] = 0;
    bmbReadyCounter[4] = 0;
    bmbReadyCounter[5] = 0;
    bmbReadyCounter[6] = 0;
    bmbReadyCounter[7] = 0;

    bmbMask[0] = 1;
    bmbMask[1] = 1;
    bmbMask[2] = 1;
    bmbMask[3] = 1;
    bmbMask[4] = 1;
    bmbMask[5] = 1;
    bmbMask[6] = 1;
    bmbMask[7] = 1;

    bmbReadyFlag[0] = 0;
    bmbReadyFlag[1] = 0;
    bmbReadyFlag[2] = 0;
    bmbReadyFlag[3] = 0;
    bmbReadyFlag[4] = 0;
    bmbReadyFlag[5] = 0;
    bmbReadyFlag[6] = 0;
    bmbReadyFlag[7] = 0;

    CAN_U.In1.Data[0] = 0;
    CAN_U.In1.Data[1] = 0;
    CAN_U.In1.Data[2] = 0;
    CAN_U.In1.Data[3] = 0;
    CAN_U.In1.Data[4] = 0;
    CAN_U.In1.Data[5] = 0;
    CAN_U.In1.Data[6] = 0;
    CAN_U.In1.Data[7] = 0;
    CAN_U.In1.ID = 0x101;
    CAN_U.In1.Length = 8;
    CAN_U.In1.Extended = 0;

    test3_U.Req_Power = 100000;
    test3_U.Req_Current = 150;
    test3_U.BMBFault = 0;
    test3_U.CurrentSensorFault=0;
    test3_U.InputPowerFault=0;
    test3_U.MemoryFault=0;
    test3_U.ShortCircuitFault=0;
    test3_U.Pack_Current=0;
    test3_U.Pack_Voltage=24;
    test3_U.ReqSOC=100;
    test3_U.SOC=80;
    //test3_U.Req_SOC=0;
    test3_U.Vout_Invtr=24;
    test3_U.Vout_Chgr=24;
    test3_U.Req_FastCh=0;
    test3_U.CAN_VCU_cnt_rst=0;
    test3_U.Reset=0;
    test3_U.StateRequest = Standby;




    InitSysCtrl();



    EALLOW;
    GpioCtrlRegs.GPADIR.bit.GPIO4 = 1; //precharg relay
    PRECHARGE_RESET;
    EDIS;

    EALLOW;
    GpioCtrlRegs.GPCDIR.bit.GPIO74 = 1; // test
    GpioDataRegs.GPCSET.bit.GPIO74 = 1;
    EDIS;

    //InitEPwm1Gpio();
    //InitEPwm2Gpio();

    EALLOW;
        GpioCtrlRegs.GPADIR.bit.GPIO0 = 1; // +
        GpioCtrlRegs.GPADIR.bit.GPIO2 = 1; // -
        EDIS;

    EALLOW;
    GpioCtrlRegs.GPBPUD.bit.GPIO35 = 0;  /*Enable pull-up for GPIO35*/
    GpioCtrlRegs.GPBPUD.bit.GPIO36 = 0;  /*Enable pull-up for GPIO35*/
    GpioCtrlRegs.GPBMUX1.bit.GPIO35 = 1; /*Configure GPIO35 as SCITXDA*/
    GpioCtrlRegs.GPBMUX1.bit.GPIO36 = 1; /*Configure GPIO35 as SCITXDA*/
    GpioCtrlRegs.GPAPUD.bit.GPIO18 = 0;  /*Enable pull-up for GPIO35*/
    GpioCtrlRegs.GPAPUD.bit.GPIO19 = 0;  /*Enable pull-up for GPIO35*/
    GpioCtrlRegs.GPAMUX2.bit.GPIO18 = 2; /*Configure GPIO35 as SCITXDB*/
    GpioCtrlRegs.GPAMUX2.bit.GPIO19 = 2; /*Configure GPIO35 as SCITXDB*/
    EDIS;


    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO29 = 0;
    // GPIO31 CANRX set in the ISR to indicate device woken up.
    GpioCtrlRegs.GPADIR.bit.GPIO29 = 1;
    GpioIntRegs.GPIOLPMSEL.bit.GPIO29 = 1;   // Choose GPIO30 pin for wakeup
    EDIS;


    DINT;
    IER = 0x0000;
    IFR = 0x0000;


    IER |= M_INT1;  // group 9 interrupt 1 for SCIRX
    IER |= M_INT14; // CPU timer2 is INT14 not in groups
    IER |= M_INT9;    // Enable CPU INT
    EINT;



    InitPieVectTable();
    EnableInterrupts();
    InitCpuTimers();

#if (CPU_FRQ_150MHZ)
       //
       // Configure CPU-Timer 0, 1, and 2 to interrupt every second:
       // 150MHz CPU Freq, 1 second Period (in uSeconds)
       //
   ConfigCpuTimer(&CpuTimer0, 150, 100);
   ConfigCpuTimer(&CpuTimer2, 150, 1000);
   #endif



    #if (CPU_FRQ_120MHZ)
        //
        // Configure CPU-Timer 0, 1, and 2 to interrupt every second:
        // 150MHz CPU Freq, 1 second Period (in uSeconds)
        //
    ConfigCpuTimer(&CpuTimer0, 120, 100);
    ConfigCpuTimer(&CpuTimer2, 120, 1000);
    #endif


    memcpy(&RamfuncsRunStart, &RamfuncsLoadStart, (Uint32)&RamfuncsLoadSize);
    InitFlash();

    EALLOW;  // This is needed to write to EALLOW protected registers
    PieVectTable.TINT2 = &cpu_timer2_isr;
    PieVectTable.TINT0 = &cpu_timer0_isr;
    EDIS;

    EALLOW;
    PieVectTable.EPWM1_INT = &epwm1_isr;
    PieVectTable.EPWM2_INT = &epwm2_isr;
    EDIS;

    EALLOW;
    SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 0;
    EDIS;

    EALLOW;
    SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;
    EDIS;


    IER |= M_INT3;


    // Enable EPWM INTn in the PIE: Group 3 interrupt 1-3
    PieCtrlRegs.PIEIER3.bit.INTx1 = 1;
    PieCtrlRegs.PIEIER3.bit.INTx2 = 1;

    CpuTimer0Regs.TCR.all = 0x4000;
    CpuTimer2Regs.TCR.all = 0x4000; //write-only instruction to set TSS bit = 0

    EALLOW;  // This is needed to write to EALLOW protected registers
    PieVectTable.WAKEINT = &WAKE_ISR;
    EDIS;
    //IER |= M_INT1;

    PieCtrlRegs.PIEIER1.bit.INTx8 = 1;
    PieCtrlRegs.PIEACK.bit.ACK1 = 1;

    // The wakeup signal should be (2+QUALSTDBY) OSCCLKs wide.
    SysCtrlRegs.LPMCR0.bit.QUALSTDBY = 0;

    //p150 datasheet
    PieCtrlRegs.PIECTRL.bit.ENPIE = 1;     // Enable the PIE block

    PieCtrlRegs.PIEIER1.bit.INTx7 = 1;     // PIE Group 1, int7 for cpu timer0

    PieCtrlRegs.PIEIER1.bit.INTx8 = 1;      // Enable PIE Group 1 INT8

    EALLOW;
    GpioCtrlRegs.GPCDIR.bit.GPIO76 = 1; // TX ENABLE/DISABLE
    GpioCtrlRegs.GPCDIR.bit.GPIO75 = 1; // bmb power
    GpioCtrlRegs.GPCDIR.bit.GPIO77 = 1;
    GpioCtrlRegs.GPCDIR.bit.GPIO78 = 1;
    GpioCtrlRegs.GPCDIR.bit.GPIO79 = 1;
    GpioCtrlRegs.GPBDIR.bit.GPIO38 = 1;
    GpioCtrlRegs.GPBDIR.bit.GPIO49 = 0;//ignit gpio
    GpioCtrlRegs.GPBDIR.bit.GPIO50 = 0;//charg gpio
    GpioCtrlRegs.GPBPUD.bit.GPIO49 = 1;
    GpioCtrlRegs.GPBPUD.bit.GPIO50 = 1;
    EDIS;

    GpioDataRegs.GPCCLEAR.bit.GPIO64 = 1;

    I2CA_Init();

    InitAdc();
    config_ADC_A (3U, 12816U, 0U, 0U, 0U);
    DELAY_US(1000);

    flagStartMeasure = 1; //start ADC measure

    EALLOW;
    // Only enter Standby mode when PLL is not in limp mode.
    if (SysCtrlRegs.PLLSTS.bit.MCLKSTS != 1)
    {
        SysCtrlRegs.LPMCR0.bit.LPM = 0x0001;   // LPM mode = Standby
    }
    EDIS;


    ADCFilter_initialize();
    VCU_CAN_init();
    CAN_initialize();
    test3_initialize();
    Estimations_initialize();
    CANBMB_initialize();
    ChargeAl_initialize();

    // Connect the watchdog to the WAKEINT interrupt of the PIE
    // Write to the whole SCSR register to avoid clearing WDOVERRIDE bit

    EALLOW;
    SysCtrlRegs.SCSR = 0;
    EDIS;

    // Reset the watchdog counter
    ServiceDog();


    // Enable the watchdog
    EALLOW;
    SysCtrlRegs.WDCR = 0x002F;
    EDIS;


    test3_Y.PreChargeRelay = 0;

    Uint16 data[10];





    // start bmb supply
    bmb_SET;
    DELAY_US(200000);
    ServiceDog();
    DELAY_US(200000);
    ServiceDog();
    DELAY_US(200000);
    ServiceDog();
    bmb_RESET;
    DELAY_US(200000);
    ServiceDog();
    DELAY_US(200000);
    ServiceDog();
    DELAY_US(200000);
    ServiceDog();
    bmb_SET;


    for(;;)
    {


        ServiceDog();

        if (ECanbRegs.CANRMP.bit.RMP12){
                    Flag_Fast_Charge_Counter = 0;
                    test3_U.Req_FastCh = 1;
                }

                if(Flag_Fast_Charge_Counter > 1000){
                    test3_U.Req_FastCh = 0;
                }
                test3_U.Req_FastCh = 1;

                if (test3_U.Req_FastCh == 1 && Flag_Fast_Charge){
                    Flag_Fast_Charge = 0;
                    //update can input table flag and data
                    ChargeAl_U.CAN_Input_d.CHM.Flag = 1;

                    //run fast charge algo
                    ChargeAl_step();

                    //ChargeAl_U.CAN_Input_f.SIF.Flag = 0;
                    //ChargeAl_U.CAN_Input_f.CHM.Flag = 0;

                    //ChargeAl_U.CAN_Input_d.CHM.Flag = 0;
                    //ChargeAl_U.CAN_Input_f.CML.Flag = 0;
                    //ChargeAl_U.CAN_Input_f.CTS.Flag = 0;
                    //ChargeAl_U.CAN_Input_f.CRO.Flag = 0;
                    //ChargeAl_U.CAN_Input_f.CCS.Flag = 0;

                    Fast_Charge_CAN_Output();
                }


                Fast_charge_CAN_Function();
        VCU_b_CAN_Function();
        VCU_a_CAN_Function();

        cellDataParser();

        if (CANQualityFlag){
            CANQualityFlag = 0;
            CANQualityCal();
            validateBMBData();
        }

        CANBMB_step();


        if(FlagStartOCV && !OCV_GetFlag){
            if(test3_Y.MinCellVolt > 2.5 && test3_Y.MinCellVolt < 4.2){
                counterX++;
                if(counterX<50){
                    test3_step();
                    OCV_table = (new_OCV((test3_Y.SumOfVoltages)/96)) * 0.01;
                    Estimations_DW.x[0] = OCV_table;
                }
                else{
                    OCV_GetFlag = 1;
                    FlagStartEstimation = 1;
                }
            }
        }

//        if (lowSpeedFlag){
//            lowSpeedFlag=0;
//            //test3_step2();
//        }

        if (estimationFlag && FlagStartEstimation && startAlgorithmFlag){

            EALLOW;

            if (ECanbRegs.CANES.bit.FE || ECanbRegs.CANES.bit.ACKE || ECanbRegs.CANES.bit.SE
            || ECanbRegs.CANES.bit.CRCE
            || ECanbRegs.CANES.bit.SA1
            || ECanbRegs.CANES.bit.BE
            )
            {

                LED1_TOGGLE;

//                //CAN_U.t1 = ECanbRegs.CANES.all & 0xFFFF;
//                aa = ECanbRegs.CANES.all >> 8;
//                bb = ECanbRegs.CANES.all >> 16;
//                CAN_U.t1 = ECanbRegs.CANES.all & 0xFFFF;
//                CAN_U.t2 = bb & 0xFFFF;

            ECanbRegs.CANES.bit.FE = 1;
            ECanbRegs.CANES.bit.ACKE = 1;
            ECanbRegs.CANES.bit.SE = 1;
            ECanbRegs.CANES.bit.CRCE = 1;
            ECanbRegs.CANES.bit.SA1 = 1;
            ECanbRegs.CANES.bit.BE = 1;

            }


            EDIS;

            estimationFlag=0;

            if(test3_Y.MinCellVolt > 2 && test3_Y.MinCellVolt< 5){
                if(cellCurrent < 20 && cellCurrent > -20){
                    if(test3_Y.MinCellTemp < 400){
                       Estimations_U.voltage = (test3_Y.SumOfVoltages)/96;
                       Estimations_U.current = cellCurrent;
                       Estimations_U.temp = test3_Y.MaxCellTemp;
                       Estimations_U.Cq = capacityCell;
                       Estimations_step();
                       estimationCount++;
                    }
                }
            }
        }

//        if(flag100ms ==1){
//            test3_step1();
//            flag100ms=0;
//        }

        //PackVoltage: resistor divider: 450 / 880k , Vhcpl = Vpack* 450/(450+880k), Vadc = Vhcpl * 7.78 * 1.79 , Vadc = ADC / 4095 * 3
        // Input Voltage : 4.3k / 22k
        //cuurent low ADC[0], current high, inputvoltage, packvoltage
        if(Flag_test3 && startAlgorithmFlag){
            LED3_TOGGLE;

            Flag_test3 = 0;

            test3_U.Pack_Voltage = packVoltage;
            test3_U.Pack_Current = packCurrent;
            test3_U.Vout_Invtr = packVoltage;
            test3_U.Vout_Chgr= packVoltage;

            test3_U.ShortCircuitFault = ShortCircuitFault;

            test3_U.SOC = (double)Estimations_Y.SOC  * 100.00;

            test3_step();

            //set balancers

            balancer();

            totalBalancerCount = 0;
                for(i=0;i<96;i++){
                    totalBalancerCount = totalBalancerCount + test3_Y.BalCmd[i];
                }

                totalBalancerCountTemp = totalBalancerCount;



                CAN_U.t3 = test3_U.CellTemperatures[2] * 10;
                CAN_U.t4 = test3_U.CellTemperatures[3] * 10;

                CAN_U.t5 = test3_U.CellTemperatures[4]*10;
                CAN_U.t6 = test3_U.CellTemperatures[5]*10;
                CAN_U.t7 = test3_U.CellTemperatures[6]*10;
                CAN_U.t8 = test3_U.CellTemperatures[7]*10;

                CAN_U.t9 = test3_U.CellTemperatures[8]*10;
                CAN_U.t10 = test3_U.CellTemperatures[9]*10;
                CAN_U.t11 = test3_U.CellTemperatures[10]*10;
                CAN_U.t12 = test3_U.CellTemperatures[11]*10;

                /*

                CAN_U.t1 = test3_U.CellVoltages[84]*1000;
                CAN_U.t2 = test3_U.CellVoltages[85]*1000;
                CAN_U.t3 = test3_U.CellVoltages[86]*1000;
                CAN_U.t4 = test3_U.CellVoltages[87]*1000;

                CAN_U.t5 = test3_U.CellVoltages[88]*1000;
                CAN_U.t6 = test3_U.CellVoltages[89]*1000;
                CAN_U.t7 = test3_U.CellVoltages[90]*1000;
                CAN_U.t8 = test3_U.CellVoltages[91]*1000;

                CAN_U.t9 = test3_U.CellVoltages[92]*1000;
                CAN_U.t10 = test3_U.CellVoltages[93]*1000;
                CAN_U.t11 = test3_U.CellVoltages[94]*1000;
                CAN_U.t12 = test3_U.CellVoltages[95]*1000;
*/

            //measurement1
            CAN_U.Max_Cell_Temp = test3_Y.MaxCellTemp - 273;
            CAN_U.Min_Cell_Temp1 =  test3_Y.MinCellTemp - 273;
            CAN_U.Max_Cell_Volt = test3_Y.MaxCellVolt;
            CAN_U.Min_Cell_Volt1 = test3_Y.MinCellVolt;
            CAN_U.DC_Link_Volt = test3_Y.SumOfVoltages;


            //measurement2
            CAN_U.Pack_Current = packCurrent;
            CAN_U.Input_Voltage = inputVoltage;
            CAN_U.PackVoltageSensor = packVoltage * 10.00;
            CAN_U.PackVoltageSum = test3_Y.SumOfVoltages * 10.00;

            //estimation1
            CAN_U.SOC = (double)Estimations_Y.SOC  * 100.00;

            if(CAN_U.SOC > 100){
               CAN_U.SOC = 100;
            }
            if(CAN_U.SOC < 0){
               CAN_U.SOC = 0;
            }

            CAN_U.SOH = (double)SOC_columb * 100;


            if(CAN_U.SOH > 100){
               CAN_U.SOH = 100;
            }
            if(CAN_U.SOH < 0){
               CAN_U.SOH = 0;
            }

            CAN_U.Discharge_Current_Limit = test3_Y.DischargeCurrentLimit;
            CAN_U.Charge_Current_Limit = test3_Y.ChargeCurrentReq;
            CAN_U.Charge_Voltage_Limit = test3_Y.ChargeVoltReq;

            //estimation2
            CAN_U.Mileage = test3_Y.RD;
            CAN_U.Charge_Remaining_Time = test3_Y.RCT;
            CAN_U.Disharge_Remaining_Time = test3_Y.RDT;
            CAN_U.BMBQualityCounter = BMBQualityCounter;
            CAN_U.balanceCounter = totalBalancerCountTemp;

            //Faults
            CAN_U.BMBFault = test3_Y.Faults_d.BMBFault;
            CAN_U.Bal_En = test3_Y.Faults_d.BalEn;
            CAN_U.Charger = test3_Y.Faults_d.Charger;
            CAN_U.CurrentSensor = test3_Y.Faults_d.CurrentSensor;
            CAN_U.HighTemp = test3_Y.Faults_d.HighTemp;
            CAN_U.InputPowerFault = test3_Y.Faults_d.InputPowerFault;
            CAN_U.Inverter = test3_Y.Faults_d.Inverter;
            CAN_U.LowTemp  = test3_Y.Faults_d.LowTemp;

            CAN_U.MemoryFault   = test3_Y.Faults_d.MemoryFault;
            CAN_U.OverChargeCurrent =test3_Y.Faults_d.OverChargeCurrent;
            CAN_U.OverCurrent = test3_Y.Faults_d.OverCurrent;
            CAN_U.OverDischargeCurrent = test3_Y.Faults_d.OverDischargeCurrent;
            CAN_U.OverVolt = test3_Y.Faults_d.OverVolt;
            CAN_U.PreChargeFault = test3_Y.Faults_d.PreChargeFault;
            CAN_U.ShortCircuitFault = test3_Y.Faults_d.ShortCircuitFault;
            CAN_U.TempSensor = test3_Y.Faults_d.TempSensor;

            CAN_U.UnderVoltage = test3_Y.Faults_d.UnderVolt;
            CAN_U.VoltSensor = test3_Y.Faults_d.VoltSensor;
            CAN_U.Communication_Fault = test3_Y.Faults_d.CAN_VCU_Fault;


            CAN_U.State = test3_Y.BMS_State;
            CAN_U.BMS_DI = 0;
            CAN_U.Contactor_State = test3_Y.Contactor_State;
            CAN_U.Charge_Complete = 0;
            CAN_U.Bal_Complete = 0;


            //diagnosis
            for(i = 0;i<96;i++){

               if(test3_Y.MaxCellCmd[i]){
                   CAN_U.maxVoltageIndex = i;
                   break;
               }

            }
            for(i = 0;i<96;i++){

               if(test3_Y.MinCellCmd[i]){
                   CAN_U.minVoltageIndex = i;
                   break;
               }

            }
            for(i = 0;i<16;i++){

               if(test3_Y.MaxTempCmd[i]){
                   CAN_U.maxTempIndex = i;
                   break;
               }

            }
            for(i = 0;i<16;i++){

               if(test3_Y.MinTempCmd[i]){
                   CAN_U.minTempIndex = i;
                   break;
               }

            }

            CAN_step();


            test3_U.StateRequest = CAN_Y.BMS_State;
            test3_U.Reset = 0;//CAN_Y.Fault_Reset;
            //test3_U.Req_FastCh = CAN_Y.Charge_Mode;
            test3_U.ReqSOC = CAN_Y.SOC_Max;

            if (CAN_Y.Fault_Reset){
               ShortCircuitFault = 0;
            }


        }

        if(Flag_test3_CAN_Fault && startAlgorithmFlag){
            Flag_test3_CAN_Fault = 0;
            test3_U.CAN_VCU_Flag=0;
        }





        if (test3_Y.PreChargeRelay){
            prechargContStart();}
        else{
            prechargContStop();
        }

        if (test3_Y.NegContactor && !NegContFlag)
            {NegContStart(); NegContFlag = 1;}
        else if (test3_Y.NegContactor == 0)
            {
            NegContFlag = 0;
            //NegContStop();
            }


        if (test3_Y.PosContactor && !PosContFlag)
            {PosContStart(); PosContFlag = 1;}
        else if (test3_Y.PosContactor == 0)
            {
            PosContFlag = 0;
            //PosContStop();
            }




        if(CurrentCalFlag == 1){
            CurrentCalFlag=0;
            currentLow = (float)(currentLowOffset - (float)ADC[0])/ 13.15;
            currentHigh = (float)(currentHighOffset - (float)ADC[1])/ 1.822;
            CAN_U.test1 = (Uint16)((double)currentLow*10+5000.0) & 0xFF;
            CAN_U.test2 = ((Uint16)((double)currentLow*10+5000.0) >> 8) & 0xFF;
            CAN_U.test3 = (Uint16)((double)currentHigh*10+5000.0) & 0xFF;
            CAN_U.test4 = ((Uint16)((double)currentHigh*10+5000.0) >> 8) & 0xFF;

            if(currentHigh <= 2 && currentHigh >= -2)
                currentHigh = 0;

            kwh_integral_noFilter = kwh_integral_noFilter + currentHigh * test3_Y.SumOfVoltages * 0.01/3600;
            CAN_U.kwh_noFilter = kwh_integral_noFilter/1000.0;
        }




        if(calculationFlag == 1 && startAlgorithmFlag){
            calculationFlag = 0;
            testbmbcounter++;
            packVoltageX = (float)ADC[3] * packVoltageGain;
            inputVoltage = (float)ADC[2] * inputVoltageGain;
            currentLow = (float)(currentLowOffset - (float)ADC[0])/ 13.15;
            currentHigh = (float)(currentHighOffset - (float)ADC[1])/ 1.822;

            // low channel: +-100A
            //High channel: +500 -1000

            ADCFilter_U.LowCurrent = currentLow;
            ADCFilter_U.HighCurrent = currentHigh;
            ADCFilter_U.PackVoltage = packVoltageX;
            ADCFilter_step();

            currentLowFilter = ADCFilter_Y.lowCurrentFilter;
            currentHighFilter = ADCFilter_Y.highCurrentFilter;
            packCurrent = ADCFilter_Y.Current;
            packVoltage = ADCFilter_Y.Voltage;

            //change for new design
            cellCurrent = packCurrent / (double)parallelCells;

            currentIntegral = currentIntegral + cellCurrent * 0.05/3600;
            SOC_columb = OCV_table - currentIntegral/capacityCell;

            kwh_integral = kwh_integral + packCurrent * test3_Y.SumOfVoltages * 0.05/3600;
            CAN_U.signal = 0;
            CAN_U.kwh = kwh_integral/1000.0;
        }

    }//end while(1)
}//end main


__interrupt void
cpu_timer2_isr(void)
{
    CpuTimer2.InterruptCount++;

    if(flagStartMeasure)
    {


        AdcRegs.ADCTRL2.bit.RST_SEQ1 = 1;  /* Reset SEQ1 module*/
        AdcRegs.ADCST.bit.INT_SEQ1_CLR = 1;/*clear INT sequencer*/
        AdcRegs.ADCTRL2.bit.SOC_SEQ1 = 1;  /* Software Trigger*/
        while (AdcRegs.ADCST.bit.INT_SEQ1 == 0) {
        }                                  /*Wait for Sequencer INT bit to clear */

        asm(" RPT #11 || NOP");

        ADC[0] = (AdcRegs.ADCRESULT0) >> 4;
        ADC[1] = (AdcRegs.ADCRESULT1) >> 4;
        ADC[2] = (AdcRegs.ADCRESULT2) >> 4;
        ADC[3] = (AdcRegs.ADCRESULT3) >> 4;
    }

    //short circuit protection
    if(ADC[0] < 4090 && ADC[1] < 4090){
        if ((ADC[0] > 3000 && ADC[1] > 3000) || (ADC[0] < 100 && ADC[1] < 100)){
//            ShortCircuitFault = 1;
//            NegContStop();
//            PosContStop();
//            prechargContStop();
        }
    }

    if (CpuTimer2.InterruptCount % 1000 == 0){
        estimationFlag = 1; //every 1s
        CANQualityFlag = 1;
        timer = testCounter;
        testCounter=0;
        timerbmb = testbmbcounter;
        testbmbcounter = 0;

        for(i=0;i<8;i++){
            CANBMBCounter[i] = bmbReadyCounter[i];
            bmbReadyCounter[i] = 0;
        }
    }

    if (CpuTimer2.InterruptCount % 2000 == 0){
        lowSpeedFlag = 1; //every 10s
    }

    if (CpuTimer2.InterruptCount % 10 == 0){
        CurrentCalFlag=1;
    }

    if (CpuTimer2.InterruptCount % 100 == 0){
        //calculation flag started
        flag100ms=1;
        // current integral 100ms , CC = soc - 1/C * zigma(I * dt)
        // current integral =  current integral +
    }
    if (CpuTimer2.InterruptCount % 50 == 0){
        //calculation flag started
        calculationFlag = 1;
        // current integral 100ms , CC = soc - 1/C * zigma(I * dt)
        // current integral =  current integral +
    }

    if(CpuTimer2.InterruptCount % 2000 == 0){
        startAlgorithmFlag = 1;
    }

}

__interrupt void
cpu_timer0_isr(void)
{
    CpuTimer0.InterruptCount++;



    VCU_CAN_TaskManager(CpuTimer0.InterruptCount);

     if(CpuTimer0.InterruptCount % 100 == 0){
         Flag_test3 = 1;

     }

     if(CpuTimer0.InterruptCount % 100 == 0){
         Flag_test3_CAN_Fault = 1;
     }
     if(CpuTimer0.InterruptCount % 5000 == 0){
         LED2_TOGGLE;
          }
     if(CpuTimer0.InterruptCount % 50 == 0){
              Flag_Fast_Charge = 1;
              Flag_Fast_Charge_Counter++;
              //LED2_TOGGLE;
               }
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}

__interrupt void
epwm1_isr(void)
{
    //
    // Update the CMPA and CMPB values
    //
    if(epwm1_info.stopFlag == 0)
        update_compare(&epwm1_info);

    //
    // Clear INT flag for this timer
    //
    EPwm1Regs.ETCLR.bit.INT = 1;

    //
    // Acknowledge this interrupt to receive more interrupts from group 3
    //
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}

__interrupt void
epwm2_isr(void)
{
    //
    // Update the CMPA and CMPB values
    //
    if(epwm2_info.stopFlag == 0)
        update_compare(&epwm2_info);

    //
    // Clear INT flag for this timer
    //
    EPwm2Regs.ETCLR.bit.INT = 1;

    //
    // Acknowledge this interrupt to receive more interrupts from group 3
    //
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}
void
InitEPwm1Example()
{
    //
    // Setup TBCLK
    //
    EPwm1Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP; // Count up
    EPwm1Regs.TBPRD = EPWM1_TIMER_TBPRD;       // Set timer period
    EPwm1Regs.TBCTL.bit.PHSEN = TB_DISABLE;    // Disable phase loading
    EPwm1Regs.TBPHS.half.TBPHS = 0x0000;       // Phase is 0
    EPwm1Regs.TBCTR = 0x0000;                  // Clear counter
    EPwm1Regs.TBCTL.bit.HSPCLKDIV = TB_DIV2;   // Clock ratio to SYSCLKOUT
    EPwm1Regs.TBCTL.bit.CLKDIV = TB_DIV2;

    //
    // Setup shadow register load on ZERO
    //
    EPwm1Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
    EPwm1Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;

    //
    // Set Compare values
    //
    EPwm1Regs.CMPA.half.CMPA = EPWM1_MIN_CMPA;    // Set compare A value

    // Set actions
    //
    EPwm1Regs.AQCTLA.bit.ZRO = AQ_CLEAR;      // Set PWM1A on Zero
    EPwm1Regs.AQCTLA.bit.CAU = AQ_SET;    // Clear PWM1A on event A, up count

    //
    // Interrupt where we will change the Compare Values
    //
    EPwm1Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;     // Select INT on Zero event
    EPwm1Regs.ETSEL.bit.INTEN = 1;                // Enable INT
    EPwm1Regs.ETPS.bit.INTPRD = ET_3RD;           // Generate INT on 3rd event

    //
    // Information this example uses to keep track of the direction the
    // CMPA/CMPB values are moving, the min and max allowed values and
    // a pointer to the correct ePWM registers
    //

    //
    // Start by increasing CMPA & CMPB
    //
    epwm1_info.EPwm_CMPA_Direction = EPWM_CMP_UP;

    epwm1_info.EPwmTimerIntCount = 0;      // Zero the interrupt counter
    epwm1_info.EPwmRegHandle = &EPwm1Regs; //Set the pointer to the ePWM module
    epwm1_info.EPwmMaxCMPA = EPWM1_MAX_CMPA;  // Setup min/max CMPA/CMPB values
    epwm1_info.EPwmMinCMPA = EPWM1_MIN_CMPA;
    epwm1_info.EPwmRegHandle->CMPA.half.CMPA = 1;

}
void
InitEPwm2Example()
{
    //
    // Setup TBCLK
    //
    EPwm2Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP; // Count up
    EPwm2Regs.TBPRD = EPWM2_TIMER_TBPRD;       // Set timer period
    EPwm2Regs.TBCTL.bit.PHSEN = TB_DISABLE;    // Disable phase loading
    EPwm2Regs.TBPHS.half.TBPHS = 0x0000;       // Phase is 0
    EPwm2Regs.TBCTR = 0x0000;                  // Clear counter
    EPwm2Regs.TBCTL.bit.HSPCLKDIV = TB_DIV2;   // Clock ratio to SYSCLKOUT
    EPwm2Regs.TBCTL.bit.CLKDIV = TB_DIV2;

    //
    // Setup shadow register load on ZERO
    //
    EPwm2Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
    EPwm2Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;

    //
    // Set Compare values
    //
    EPwm2Regs.CMPA.half.CMPA = EPWM2_MIN_CMPA;   // Set compare A value

    //
    // Set actions
    //
    EPwm2Regs.AQCTLA.bit.ZRO = AQ_CLEAR;      // Clear PWM2A on Period
    EPwm2Regs.AQCTLA.bit.CAU = AQ_SET;        // Set PWM2A on event A, up count


    //
    // Interrupt where we will change the Compare Values
    //
    EPwm2Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO; // Select INT on Zero event
    EPwm2Regs.ETSEL.bit.INTEN = 1;            // Enable INT
    EPwm2Regs.ETPS.bit.INTPRD = ET_3RD;       // Generate INT on 3rd event

    //
    // Information this example uses to keep track of the direction the
    // CMPA/CMPB values are moving, the min and max allowed values and
    // a pointer to the correct ePWM registers
    //
    epwm2_info.EPwm_CMPA_Direction = EPWM_CMP_UP;   // Start by increasing CMPA
    epwm2_info.EPwmTimerIntCount = 0;         // Zero the interrupt counter
    epwm2_info.EPwmRegHandle = &EPwm2Regs; //Set the pointer to the ePWM module
    epwm2_info.EPwmMaxCMPA = EPWM2_MAX_CMPA;  // Setup min/max CMPA/CMPB values
    epwm2_info.EPwmMinCMPA = EPWM2_MIN_CMPA;
    epwm2_info.EPwmRegHandle->CMPA.half.CMPA = 1;
}

void
update_compare(EPWM_INFO *epwm_info)
{
    //
    // Every 4'th interrupt, change the CMPA/CMPB values
    //
    if(epwm_info->EPwmTimerIntCount == 2)
    {
        epwm_info->EPwmTimerIntCount = 0;
        epwm_info->EPwmRegHandle->CMPA.half.CMPA++;
        if (epwm_info->EPwmRegHandle->CMPA.half.CMPA > 1600 && epwm_info->stopFlag == 0){
            epwm_info->stopFlag = 1;
        }
    }
    else
    {
        epwm_info->EPwmTimerIntCount++;
    }
}

void config_ADC_A(Uint16 maxConv, Uint16 adcChselSEQ1Reg, Uint16
                  adcChselSEQ2Reg, Uint16 adcChselSEQ3Reg, Uint16
                  adcChselSEQ4Reg)
{
    AdcRegs.ADCTRL1.bit.SUSMOD = 0x0;    /* Emulation suspend ignored*/
    AdcRegs.ADCTRL1.bit.ACQ_PS = 4;      /* Acquisition window size*/
    AdcRegs.ADCTRL1.bit.CPS = 1;         /* Core clock pre-scaler*/
    AdcRegs.ADCTRL3.bit.ADCCLKPS = 3;    /* Core clock divider*/
    AdcRegs.ADCREFSEL.bit.REF_SEL = 0 ;  /* Set Reference Voltage*/
    AdcRegs.ADCOFFTRIM.bit.OFFSET_TRIM = AdcRegs.ADCOFFTRIM.bit.OFFSET_TRIM;/* Set Offset Error Correctino Value*/
    AdcRegs.ADCTRL1.bit.CONT_RUN = 0;
                              /* 0:Start-Stop or continuous sequencer mode*/
    AdcRegs.ADCTRL3.bit.ADCBGRFDN = 0x3; /* Bandgap and reference powered up*/
    AdcRegs.ADCTRL3.bit.SMODE_SEL = 0 ; /* 1:Simultaneous, 0:Sequential sampling*/
    AdcRegs.ADCMAXCONV.bit.MAX_CONV1 = maxConv;
                     /* Number of conversions in CONV2 when using B module*/
    AdcRegs.ADCTRL1.bit.SEQ_CASC = 0;    /* 1:Cascaded, 0:Dual sequencer mode*/
    AdcRegs.ADCCHSELSEQ1.all = adcChselSEQ1Reg;/* Channels for conversion*/
    AdcRegs.ADCCHSELSEQ2.all = adcChselSEQ2Reg;/* Channels for conversion*/
    AdcRegs.ADCTRL2.bit.RST_SEQ1 = 0x1;  /* Reset SEQ1*/
}

void prechargContStart(){
    PRECHARGE_SET;
}
void prechargContStop(){
    PRECHARGE_RESET;
}

void NegContStart(){
    GpioDataRegs.GPASET.bit.GPIO2 = 1;

}

void NegContStop(){

    GpioDataRegs.GPACLEAR.bit.GPIO2 = 1;
}

void PosContStart(){

    GpioDataRegs.GPASET.bit.GPIO0 = 1;
}

void PosContStop(){

    GpioDataRegs.GPACLEAR.bit.GPIO0 = 1;
}

__interrupt void
WAKE_ISR(void)
{
    PieCtrlRegs.PIEACK.bit.ACK1 = 1;
}

void cellDataParser(){

    //0-11
    if(bmbReadyFlag[0] == 1){
        test3_U.CellVoltages[0] = (float)CANBMB_Y.v1_1 * 0.001;
        test3_U.CellVoltages[1] = (float)CANBMB_Y.v1_2 * 0.001;
        test3_U.CellVoltages[2] = (float)CANBMB_Y.v1_3 * 0.001;
        test3_U.CellVoltages[3] = (float)CANBMB_Y.v1_4 * 0.001;
        test3_U.CellVoltages[4] = (float)CANBMB_Y.v1_5 * 0.001;
        test3_U.CellVoltages[5] = (float)CANBMB_Y.v1_6 * 0.001;
        test3_U.CellVoltages[6] = (float)CANBMB_Y.v1_7 * 0.001;
        test3_U.CellVoltages[7] = (float)CANBMB_Y.v1_8 * 0.001;
        test3_U.CellVoltages[8] = (float)CANBMB_Y.v1_9 * 0.001;
        test3_U.CellVoltages[9] = (float)CANBMB_Y.v1_10 * 0.001;
        test3_U.CellVoltages[10] = (float)CANBMB_Y.v1_11 * 0.001;
        test3_U.CellVoltages[11] = (float)CANBMB_Y.v1_12 * 0.001;

        ntcTemp((double)CANBMB_Y.t1_1 * 200 /(30000 - 20*(double)CANBMB_Y.t1_1), &test3_U.CellTemperatures[0]);
        ntcTemp((double)CANBMB_Y.t1_2 * 200 /(30000 - 20*(double)CANBMB_Y.t1_2), &test3_U.CellTemperatures[1]);
    }
    //12-23
    if(bmbReadyFlag[1] == 1){
        test3_U.CellVoltages[12] = (float)CANBMB_Y.v2_1 * 0.001;
        test3_U.CellVoltages[13] = (float)CANBMB_Y.v2_2 * 0.001;
        test3_U.CellVoltages[14] = (float)CANBMB_Y.v2_3 * 0.001;
        test3_U.CellVoltages[15] = (float)CANBMB_Y.v2_4 * 0.001;
        test3_U.CellVoltages[16] = (float)CANBMB_Y.v2_5 * 0.001;
        test3_U.CellVoltages[17] = (float)CANBMB_Y.v2_6 * 0.001;
        test3_U.CellVoltages[18] = (float)CANBMB_Y.v2_7 * 0.001;
        test3_U.CellVoltages[19] = (float)CANBMB_Y.v2_8 * 0.001;
        test3_U.CellVoltages[20] = (float)CANBMB_Y.v2_9 * 0.001;
        test3_U.CellVoltages[21] = (float)CANBMB_Y.v2_10 * 0.001;
        test3_U.CellVoltages[22] = (float)CANBMB_Y.v2_11 * 0.001;
        test3_U.CellVoltages[23] = (float)CANBMB_Y.v2_12 * 0.001;

        ntcTemp((double)CANBMB_Y.t2_1 * 200 /(30000 - 20*(double)CANBMB_Y.t2_1), &test3_U.CellTemperatures[2]);
        ntcTemp((double)CANBMB_Y.t2_2 * 200 /(30000 - 20*(double)CANBMB_Y.t2_2), &test3_U.CellTemperatures[3]);
    }
    //24-35
    if(bmbReadyFlag[2] == 1){
        test3_U.CellVoltages[24] = (float)CANBMB_Y.v3_1 * 0.001;
        test3_U.CellVoltages[25] = (float)CANBMB_Y.v3_2 * 0.001;
        test3_U.CellVoltages[26] = (float)CANBMB_Y.v3_3 * 0.001;
        test3_U.CellVoltages[27] = (float)CANBMB_Y.v3_4 * 0.001;
        test3_U.CellVoltages[28] = (float)CANBMB_Y.v3_5 * 0.001;
        test3_U.CellVoltages[29] = (float)CANBMB_Y.v3_6 * 0.001;
        test3_U.CellVoltages[30] = (float)CANBMB_Y.v3_7 * 0.001;
        test3_U.CellVoltages[31] = (float)CANBMB_Y.v3_8 * 0.001;
        test3_U.CellVoltages[32] = (float)CANBMB_Y.v3_9 * 0.001;
        test3_U.CellVoltages[33] = (float)CANBMB_Y.v3_10 * 0.001;
        test3_U.CellVoltages[34] = (float)CANBMB_Y.v3_11 * 0.001;
        test3_U.CellVoltages[35] = (float)CANBMB_Y.v3_12 * 0.001;

        ntcTemp((double)CANBMB_Y.t3_1 * 200 /(30000 - 20*(double)CANBMB_Y.t3_1), &test3_U.CellTemperatures[4]);
        ntcTemp((double)CANBMB_Y.t3_2 * 200 /(30000 - 20*(double)CANBMB_Y.t3_2), &test3_U.CellTemperatures[5]);
    }
    //36-47
    if(bmbReadyFlag[3] == 1){
        test3_U.CellVoltages[36] = (float)CANBMB_Y.v4_1 * 0.001;
        test3_U.CellVoltages[37] = (float)CANBMB_Y.v4_2 * 0.001;
        test3_U.CellVoltages[38] = (float)CANBMB_Y.v4_3 * 0.001;
        test3_U.CellVoltages[39] = (float)CANBMB_Y.v4_4 * 0.001;
        test3_U.CellVoltages[40] = (float)CANBMB_Y.v4_5 * 0.001;
        test3_U.CellVoltages[41] = (float)CANBMB_Y.v4_6 * 0.001;
        test3_U.CellVoltages[42] = (float)CANBMB_Y.v4_7 * 0.001;
        test3_U.CellVoltages[43] = (float)CANBMB_Y.v4_8 * 0.001;
        test3_U.CellVoltages[44] = (float)CANBMB_Y.v4_9 * 0.001;
        test3_U.CellVoltages[45] = (float)CANBMB_Y.v4_10 * 0.001;
        test3_U.CellVoltages[46] = (float)CANBMB_Y.v4_11 * 0.001;
        test3_U.CellVoltages[47] = (float)CANBMB_Y.v4_12 * 0.001;

        ntcTemp((double)CANBMB_Y.t4_1 * 200 /(30000 - 20*(double)CANBMB_Y.t4_1), &test3_U.CellTemperatures[6]);
        ntcTemp((double)CANBMB_Y.t4_2 * 200 /(30000 - 20*(double)CANBMB_Y.t4_2), &test3_U.CellTemperatures[7]);
    }
    //48-59
    if(bmbReadyFlag[4] == 1){
        test3_U.CellVoltages[48] = (float)CANBMB_Y.v5_1 * 0.001;
        test3_U.CellVoltages[49] = (float)CANBMB_Y.v5_2 * 0.001;
        test3_U.CellVoltages[50] = (float)CANBMB_Y.v5_3 * 0.001;
        test3_U.CellVoltages[51] = (float)CANBMB_Y.v5_4 * 0.001;
        test3_U.CellVoltages[52] = (float)CANBMB_Y.v5_5 * 0.001;
        test3_U.CellVoltages[53] = (float)CANBMB_Y.v5_6 * 0.001;
        test3_U.CellVoltages[54] = (float)CANBMB_Y.v5_7 * 0.001;
        test3_U.CellVoltages[55] = (float)CANBMB_Y.v5_8 * 0.001;
        test3_U.CellVoltages[56] = (float)CANBMB_Y.v5_9 * 0.001;
        test3_U.CellVoltages[57] = (float)CANBMB_Y.v5_10 * 0.001;
        test3_U.CellVoltages[58] = (float)CANBMB_Y.v5_11 * 0.001;
        test3_U.CellVoltages[59] = (float)CANBMB_Y.v5_12 * 0.001;

        ntcTemp((double)CANBMB_Y.t5_1 * 200 /(30000 - 20*(double)CANBMB_Y.t5_1), &test3_U.CellTemperatures[8]);
        ntcTemp((double)CANBMB_Y.t5_2 * 200 /(30000 - 20*(double)CANBMB_Y.t5_2), &test3_U.CellTemperatures[9]);
    }
    //60-71
    if(bmbReadyFlag[5] == 1){
        test3_U.CellVoltages[60] = (float)CANBMB_Y.v6_1 * 0.001;
        test3_U.CellVoltages[61] = (float)CANBMB_Y.v6_2 * 0.001;
        test3_U.CellVoltages[62] = (float)CANBMB_Y.v6_3 * 0.001;
        test3_U.CellVoltages[63] = (float)CANBMB_Y.v6_4 * 0.001;
        test3_U.CellVoltages[64] = (float)CANBMB_Y.v6_5 * 0.001;
        test3_U.CellVoltages[65] = (float)CANBMB_Y.v6_6 * 0.001;
        test3_U.CellVoltages[66] = (float)CANBMB_Y.v6_7 * 0.001;
        test3_U.CellVoltages[67] = (float)CANBMB_Y.v6_8 * 0.001;
        test3_U.CellVoltages[68] = (float)CANBMB_Y.v6_9 * 0.001;
        test3_U.CellVoltages[69] = (float)CANBMB_Y.v6_10 * 0.001;
        test3_U.CellVoltages[70] = (float)CANBMB_Y.v6_11 * 0.001;
        test3_U.CellVoltages[71] = (float)CANBMB_Y.v6_12 * 0.001;

        ntcTemp((double)CANBMB_Y.t6_1 * 200 /(30000 - 20*(double)CANBMB_Y.t6_1), &test3_U.CellTemperatures[10]);
        ntcTemp((double)CANBMB_Y.t6_2 * 200 /(30000 - 20*(double)CANBMB_Y.t6_2), &test3_U.CellTemperatures[11]);
    }
    //72-83
    if(bmbReadyFlag[6] == 1){
        test3_U.CellVoltages[72] = (float)CANBMB_Y.v7_1 * 0.001;
        test3_U.CellVoltages[73] = (float)CANBMB_Y.v7_2 * 0.001;
        test3_U.CellVoltages[74] = (float)CANBMB_Y.v7_3 * 0.001;
        test3_U.CellVoltages[75] = (float)CANBMB_Y.v7_4 * 0.001;
        test3_U.CellVoltages[76] = (float)CANBMB_Y.v7_5 * 0.001;
        test3_U.CellVoltages[77] = (float)CANBMB_Y.v7_6 * 0.001;
        test3_U.CellVoltages[78] = (float)CANBMB_Y.v7_7 * 0.001;
        test3_U.CellVoltages[79] = (float)CANBMB_Y.v7_8 * 0.001;
        test3_U.CellVoltages[80] = (float)CANBMB_Y.v7_9 * 0.001;
        test3_U.CellVoltages[81] = (float)CANBMB_Y.v7_10 * 0.001;
        test3_U.CellVoltages[82] = (float)CANBMB_Y.v7_11 * 0.001;
        test3_U.CellVoltages[83] = (float)CANBMB_Y.v7_12 * 0.001;

        ntcTemp((double)CANBMB_Y.t7_1 * 200 /(30000 - 20*(double)CANBMB_Y.t7_1), &test3_U.CellTemperatures[12]);
        ntcTemp((double)CANBMB_Y.t7_2 * 200 /(30000 - 20*(double)CANBMB_Y.t7_2), &test3_U.CellTemperatures[13]);
    }
    //84-95
    if(bmbReadyFlag[7] == 1){
        test3_U.CellVoltages[84] = (float)CANBMB_Y.v8_1 * 0.001;
        test3_U.CellVoltages[85] = (float)CANBMB_Y.v8_2 * 0.001;
        test3_U.CellVoltages[86] = (float)CANBMB_Y.v8_3 * 0.001;
        test3_U.CellVoltages[87] = (float)CANBMB_Y.v8_4 * 0.001;
        test3_U.CellVoltages[88] = (float)CANBMB_Y.v8_5 * 0.001;
        test3_U.CellVoltages[89] = (float)CANBMB_Y.v8_6 * 0.001;
        test3_U.CellVoltages[90] = (float)CANBMB_Y.v8_7 * 0.001;
        test3_U.CellVoltages[91] = (float)CANBMB_Y.v8_8 * 0.001;
        test3_U.CellVoltages[92] = (float)CANBMB_Y.v8_9 * 0.001;
        test3_U.CellVoltages[93] = (float)CANBMB_Y.v8_10 * 0.001;
        test3_U.CellVoltages[94] = (float)CANBMB_Y.v8_11 * 0.001;
        test3_U.CellVoltages[95] = (float)CANBMB_Y.v8_12 * 0.001;

        ntcTemp((double)CANBMB_Y.t8_1 * 200 /(30000 - 20*(double)CANBMB_Y.t8_1), &test3_U.CellTemperatures[14]);
        ntcTemp((double)CANBMB_Y.t8_2 * 200 /(30000 - 20*(double)CANBMB_Y.t8_2), &test3_U.CellTemperatures[15]);

    }

    bmbReadyFlag[0] = 0;
    bmbReadyFlag[1] = 0;
    bmbReadyFlag[2] = 0;
    bmbReadyFlag[3] = 0;
    bmbReadyFlag[4] = 0;
    bmbReadyFlag[5] = 0;
    bmbReadyFlag[6] = 0;
    bmbReadyFlag[7] = 0;
}

void validateBMBData(){
    Uint16 a;
    BMBQualityCounter = 0;
    for(a=0;a<8;a++){

        BMBQualityCounter = BMBQualityCounter + CANBMBCounter[a];
    }

    if(  ((CANBMBCounter[0]>0) || !bmbMask[0]) &&
         ((CANBMBCounter[1]>0) || !bmbMask[1]) &&
         ((CANBMBCounter[2]>0) || !bmbMask[2]) &&
         ((CANBMBCounter[3]>0) || !bmbMask[3]) &&
         ((CANBMBCounter[4]>0) || !bmbMask[4]) &&
         ((CANBMBCounter[5]>0) || !bmbMask[5]) &&
         ((CANBMBCounter[6]>0) || !bmbMask[6]) &&
         ((CANBMBCounter[7]>0) || !bmbMask[7]))
    {
        test3_U.BMBFault = 0;
        FlagStartOCV = 1;
        BMBFailedCounter=0;
    }else{
        BMBFailedCounter++;
        if(BMBFailedCounter > 5){
            BMBFailedCounter = 0;
            test3_U.BMBFault = 1;
        }
    }
}

void CANQualityCal(){
    BMBCounter1 = CANBMB_Y.counter1;
    BMBCounter2 = CANBMB_Y.counter2;
    BMBCounter3 = CANBMB_Y.counter3;
    BMBCounter4 = CANBMB_Y.counter4;
    BMBCounter5 = CANBMB_Y.counter5;
    BMBCounter6 = CANBMB_Y.counter6;
    BMBCounter7 = CANBMB_Y.counter7;
    BMBCounter8 = CANBMB_Y.counter8;
}

void balancer(){
    CANBMB_U.b1 = 0;
    CANBMB_U.b2 = 0;
    CANBMB_U.b3 = 0;
    CANBMB_U.b4 = 0;
    CANBMB_U.b5 = 0;
    CANBMB_U.b6 = 0;
    CANBMB_U.b7 = 0;
    CANBMB_U.b8 = 0;

    for(i=0;i<12;i++){
        CANBMB_U.b1 |= test3_Y.BalCmd[i] << i;
    }
    for(i=12;i<24;i++){
        CANBMB_U.b2 |= test3_Y.BalCmd[i] << (i-12);
    }
    for(i=24;i<36;i++){
        CANBMB_U.b3 |= test3_Y.BalCmd[i] << (i-24);
    }
    for(i=36;i<48;i++){
        CANBMB_U.b4 |= test3_Y.BalCmd[i] << (i-36);
    }
    for(i=48;i<60;i++){
        CANBMB_U.b5 |= test3_Y.BalCmd[i] << (i-48);
    }
    for(i=60;i<72;i++){
        CANBMB_U.b6 |= test3_Y.BalCmd[i] << (i-60);
    }
    for(i=72;i<84;i++){
        CANBMB_U.b7 |= test3_Y.BalCmd[i] << (i-72);
    }
    for(i=84;i<96;i++){
        CANBMB_U.b8 |= test3_Y.BalCmd[i] << (i-84);
    }
}
double ntcTemp(double ohm, real32_T *des){
  double slop;
  Uint16 q;
  if(ohm<200){
  for(q=1; q<137; q++){

      if(ohm > ntcTable[q]){
          *des = (ohm - ntcTable[q-1])/(ntcTable[q] - ntcTable[q-1]) + (double)q -2 - 30 + 273;
          return slop;
      }
  }
  }
  else
      *des = 0;

}

void
I2CA_Init(void)
{
    //
    // Initialize I2C
    //
    I2caRegs.I2CSAR = 0x0050;   // Slave address - EEPROM control code

#if (CPU_FRQ_150MHZ)            // Default - For 150MHz SYSCLKOUT
    //
    // Prescaler - need 7-12 Mhz on module clk (150/15 = 10MHz)
    //
    I2caRegs.I2CPSC.all = 14;
#endif
#if (CPU_FRQ_100MHZ)            // For 100 MHz SYSCLKOUT
    //
    // Prescaler - need 7-12 Mhz on module clk (100/10 = 10MHz)
    //
    I2caRegs.I2CPSC.all = 9;
#endif

    I2caRegs.I2CCLKL = 10;      // NOTE: must be non zero
    I2caRegs.I2CCLKH = 5;       // NOTE: must be non zero
    I2caRegs.I2CIER.all = 0x24; // Enable SCD & ARDY interrupts

    //
    // Take I2C out of reset
    // Stop I2C when suspended
    //
    I2caRegs.I2CMDR.all = 0x0020;

    I2caRegs.I2CFFTX.all = 0x6000;  // Enable FIFO mode and TXFIFO
    I2caRegs.I2CFFRX.all = 0x2040;  // Enable RXFIFO, clear RXFFINT,

    return;
}

//
// I2CA_WriteData -
//
Uint16
I2CA_WriteData(struct I2CMSG *msg)
{
    Uint16 i;

    //
    // Wait until the STP bit is cleared from any previous master communication
    // Clearing of this bit by the module is delayed until after the SCD bit is
    // set. If this bit is not checked prior to initiating a new message, the
    // I2C could get confused.
    //
    if (I2caRegs.I2CMDR.bit.STP == 1)
    {
        return I2C_STP_NOT_READY_ERROR;
    }

    //
    // Setup slave address
    //
    I2caRegs.I2CSAR = msg->SlaveAddress;

    //
    // Check if bus busy
    //
    if (I2caRegs.I2CSTR.bit.BB == 1)
    {
        return I2C_BUS_BUSY_ERROR;
    }

    //
    // Setup number of bytes to send MsgBuffer + Address
    //
    I2caRegs.I2CCNT = msg->NumOfBytes+2;

    //
    // Setup data to send
    //
    I2caRegs.I2CDXR = msg->MemoryHighAddr;
    I2caRegs.I2CDXR = msg->MemoryLowAddr;

    for (i=0; i<msg->NumOfBytes; i++)
    {
        I2caRegs.I2CDXR = *(msg->MsgBuffer+i);
    }

    //
    // Send start as master transmitter
    //
    I2caRegs.I2CMDR.all = 0x6E20;

    return I2C_SUCCESS;
}

//
// I2CA_ReadData -
//
Uint16
I2CA_ReadData(struct I2CMSG *msg)
{
    //
    // Wait until the STP bit is cleared from any previous master communication.
    // Clearing of this bit by the module is delayed until after the SCD bit is
    // set. If this bit is not checked prior to initiating a new message, the
    // I2C could get confused.
    //
    if (I2caRegs.I2CMDR.bit.STP == 1)
    {
        return I2C_STP_NOT_READY_ERROR;
    }

    I2caRegs.I2CSAR = msg->SlaveAddress;

    if(msg->MsgStatus == I2C_MSGSTAT_SEND_NOSTOP)
    {
        //
        // Check if bus busy
        //
        if (I2caRegs.I2CSTR.bit.BB == 1)
        {
            return I2C_BUS_BUSY_ERROR;
        }
        I2caRegs.I2CCNT = 2;
        I2caRegs.I2CDXR = msg->MemoryHighAddr;
        I2caRegs.I2CDXR = msg->MemoryLowAddr;
        I2caRegs.I2CMDR.all = 0x2620;   // Send data to setup EEPROM address
    }
    else if(msg->MsgStatus == I2C_MSGSTAT_RESTART)
    {
        I2caRegs.I2CCNT = msg->NumOfBytes;  // Setup how many bytes to expect
        I2caRegs.I2CMDR.all = 0x2C20;       // Send restart as master receiver
    }

    return I2C_SUCCESS;
}

//
// i2c_int1a_isr - I2C-A
//
__interrupt void
i2c_int1a_isr(void)
{
    Uint16 IntSource, i;

    //
    // Read interrupt source
    //
    IntSource = I2caRegs.I2CISRC.all;

    //
    // Interrupt source = stop condition detected
    //
    if(IntSource == I2C_SCD_ISRC)
    {
        //
        // If completed message was writing data, reset msg to inactive state
        //
        if (CurrentMsgPtr->MsgStatus == I2C_MSGSTAT_WRITE_BUSY)
        {
            CurrentMsgPtr->MsgStatus = I2C_MSGSTAT_INACTIVE;

        }
        else
        {
            //
            // If a message receives a NACK during the address setup portion
            // of the EEPROM read, the code further below included in the
            // register access ready interrupt source code will generate a stop
            // condition. After the stop condition is received (here), set the
            // message status to try again. User may want to limit the number
            // of retries before generating an error.
            //
            if(CurrentMsgPtr->MsgStatus == I2C_MSGSTAT_SEND_NOSTOP_BUSY)
            {
                CurrentMsgPtr->MsgStatus = I2C_MSGSTAT_SEND_NOSTOP;
            }

            //
            // If completed message was reading EEPROM data, reset msg
            // to inactive state and read data from FIFO.
            //
            else if (CurrentMsgPtr->MsgStatus == I2C_MSGSTAT_READ_BUSY)
            {
                CurrentMsgPtr->MsgStatus = I2C_MSGSTAT_INACTIVE;
                for(i=0; i < I2C_NUMBYTES; i++)
                {
                    CurrentMsgPtr->MsgBuffer[i] = I2caRegs.I2CDRR;
                }
                {
                    //
                    // Check received data
                    //
                    for(i=0; i < I2C_NUMBYTES; i++)
                    {
                        if(I2cMsgIn1.MsgBuffer[i] == I2cMsgOut1.MsgBuffer[i])
                        {
                            PassCount++;
                        }
                        else
                        {
                            FailCount++;
                        }
                    }

                    if(PassCount == I2C_NUMBYTES)
                    {
                        pass();
                    }
                    else
                    {
                        fail();
                    }
                }
            }
        }
    }  // end of stop condition detected

    //
    // Interrupt source = Register Access Ready
    // This interrupt is used to determine when the EEPROM address setup
    // portion of the read data communication is complete. Since no stop bit is
    // commanded, this flag tells us when the message has been sent instead of
    // the SCD flag. If a NACK is received, clear the NACK bit and command a
    // stop. Otherwise, move on to the read data portion of the communication.
    //
    else if(IntSource == I2C_ARDY_ISRC)
    {
        if(I2caRegs.I2CSTR.bit.NACK == 1)
        {
            I2caRegs.I2CMDR.bit.STP = 1;
            I2caRegs.I2CSTR.all = I2C_CLR_NACK_BIT;
        }
        else if(CurrentMsgPtr->MsgStatus == I2C_MSGSTAT_SEND_NOSTOP_BUSY)
        {
            CurrentMsgPtr->MsgStatus = I2C_MSGSTAT_RESTART;
        }
    }

    else
    {
        //
        // Generate some error due to invalid interrupt source
        //

    }

    //
    // Enable future I2C (PIE Group 8) interrupts
    //
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP8;
}

//
// pass -
//
void pass()
{

}

//
// fail -
//
void fail()
{

}

//
// End of File
//
Uint16 writeE2prom(){
    //to write data to e2prom first set I2cMsgOut1.MsgStatus to I2C_MSGSTAT_SEND_WITHSTOP then run this func.
    //below while func will be run until I2cMsgOut1.MsgStatus turns to I2C_MSGSTAT_WRITE_BUSY, and if this dosent occur after timeout you will recive error return
    //after I2cMsgOut1.MsgStatus turns to I2C_MSGSTAT_WRITE_BUSY remaining process run in interrupts if write process is succesful then
    //I2cMsgOut1.MsgStatus changes to I2C_MSGSTAT_INACTIVE
    // so after you start write process check I2cMsgOut1.MsgStatus after x ms if I2cMsgOut1.MsgStatus turns to I2C_MSGSTAT_INACTIVE or not
    // if it dosent occur so this is error.

Uint16 counter=0,Error;

while(I2cMsgOut1.MsgStatus == I2C_MSGSTAT_SEND_WITHSTOP){
    counter++;
    if(counter > 1000)
        return 2;

    if(I2cMsgOut1.MsgStatus == I2C_MSGSTAT_SEND_WITHSTOP)
            {
                Error = I2CA_WriteData(&I2cMsgOut1);

                //
                // If communication is correctly initiated, set msg status to busy
                // and update CurrentMsgPtr for the interrupt service routine.
                // Otherwise, do nothing and try again next loop. Once message is
                // initiated, the I2C interrupts will handle the rest. Search for
                // ICINTR1A_ISR in the i2c_eeprom_isr.c file.
                //
                if (Error == I2C_SUCCESS)
                {
                    CurrentMsgPtr = &I2cMsgOut1;
                    I2cMsgOut1.MsgStatus = I2C_MSGSTAT_WRITE_BUSY;
                    return 1;
                }
            }  // end of write section

}
return 0;
}
