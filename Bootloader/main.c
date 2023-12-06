

/**
 * main.c
 */

#include "DSP28x_Project.h"

// Flash API .h
#include "Flash2833x_API_Library.h"
#include "Example_Flash2833x_API.h"
//////////////////////
/*---- Standard headers -------------------------------------------------------*/
#include <stdio.h>

#include "Bootloader_APP.h"


Uint64 PC=0;




////MATLAB Vars
extern DW_Bootloader_APP_T Bootloader_APP_DW;
extern ExtU_Bootloader_APP_T Bootloader_APP_U;
extern ExtY_Bootloader_APP_T Bootloader_APP_Y;
extern SharedDSM_Bootloader_APP_T Bootloader_APP_SharedDSM;
////////////////////////////////




__interrupt void cpu_timer0_isr(void);

void CAN_Receiving_mailbox_Process(void);

extern void INIT_CAN_B_Config(void);



/////////Flash API
void MyCallbackFunction(void);

Uint32 MyCallbackCounter; // Just increment a counter in the callback function

/*--- Global variables used to interface to the flash routines */
FLASH_ST FlashStatus;
/*---------------------------------------------------------------------------
  Data/Program Buffer used for testing the flash API functions
---------------------------------------------------------------------------*/
#define  WORDS_IN_FLASH_BUFFER 0x100               // Programming data buffer, Words
Uint16  Buffer[WORDS_IN_FLASH_BUFFER];
/*---------------------------------------------------------------------------
  Sector address info
---------------------------------------------------------------------------*/
typedef struct {
     Uint16 *StartAddr;
     Uint16 *EndAddr;
} SECTOR;

#define OTP_START_ADDR  0x380400
#define OTP_END_ADDR    0x3807FF


#if FLASH_F28335
#define FLASH_START_ADDR  0x300000
#define FLASH_END_ADDR    0x33FFFF

SECTOR Sector[8] = {
         (Uint16 *)0x338000,(Uint16 *)0x33FFFF,
         (Uint16 *)0x330000,(Uint16 *)0x337FFF,
         (Uint16 *)0x328000,(Uint16 *)0x32FFFF,
         (Uint16 *)0x320000,(Uint16 *)0x327FFF,
         (Uint16 *)0x318000,(Uint16 *)0x31FFFF,
         (Uint16 *)0x33000,(Uint16 *)0x317FFF,
         (Uint16 *)0x308000,(Uint16 *)0x30FFFF,
         (Uint16 *)0x300000,(Uint16 *)0x307FFF

};

#endif


#if FLASH_F28334
#define FLASH_START_ADDR  0x320000
#define FLASH_END_ADDR    0x33FFFF

SECTOR Sector[8] = {
         (Uint16 *)0x33C000,(Uint16 *)0x33FFFF,
         (Uint16 *)0x338000,(Uint16 *)0x33BFFF,
         (Uint16 *)0x334000,(Uint16 *)0x337FFF,
         (Uint16 *)0x330000,(Uint16 *)0x333FFF,
         (Uint16 *)0x32C000,(Uint16 *)0x32FFFF,
         (Uint16 *)0x328000,(Uint16 *)0x32BFFF,
         (Uint16 *)0x324000,(Uint16 *)0x327FFF,
         (Uint16 *)0x320000,(Uint16 *)0x323FFF

};

#endif


#if FLASH_F28332
#define FLASH_START_ADDR  0x330000
#define FLASH_END_ADDR    0x33FFFF

SECTOR Sector[4] = {
         (Uint16 *)0x33C000,(Uint16 *)0x33FFFF,
         (Uint16 *)0x338000,(Uint16 *)0x33BFFF,
         (Uint16 *)0x334000,(Uint16 *)0x337FFF,
         (Uint16 *)0x330000,(Uint16 *)0x333FFF

};

#endif


extern Uint32 Flash_CPUScaleFactor;

Uint16 EraseFlash(void);
Uint16 WriteFlash(Uint16  *Flash_ptr,Uint16  *DATA,Uint32  Length);


Uint16 Write_Flash=0;
Uint16 Erase_Flag=0;

Uint16 DATA[3000];


Uint16 *start_Address;
Uint32 Strt_Address;
///CAN Flag
uint16_T Flag_CAN_REC=0;
extern struct ECAN_REGS ECanbShadow_CANB;



uint32_T debug_counter=0;


uint16_T i=0;
uint16_T DATA_REC[100][8];
int main(void)
{
	Uint16 *signature_Address= (Uint16 *) 0x337f80;
	Uint16 signature = 0x1234;
        InitSysCtrl();
        DINT;
        InitPieCtrl();
        IER = 0x0000;
        IFR = 0x0000;

        /// Flash API
        Uint16 Status;
    /*------------------------------------------------------------------
     Unlock the CSM.
        If the API functions are going to run in unsecured RAM
        then the CSM must be unlocked in order for the flash
        API functions to access the flash.

        If the flash API functions are executed from secure memory
        (L0-L3) then this step is not required.
    ------------------------------------------------------------------*/

       Status = Example_CsmUnlock();
       if(Status != STATUS_SUCCESS)
       {
           Example_Error(Status);
       }






//        Copy the Flash API functions to SARAM
       Example_MemCopy(&Flash28_API_LoadStart, &Flash28_API_LoadEnd, &Flash28_API_RunStart);

       // We must also copy required user interface functions to RAM.
       Example_MemCopy(&RamfuncsLoadStart, &RamfuncsLoadEnd, &RamfuncsRunStart);



       /*------------------------------------------------------------------
         Initalize Flash_CPUScaleFactor.

          Flash_CPUScaleFactor is a 32-bit global variable that the flash
          API functions use to scale software delays. This scale factor
          must be initalized to SCALE_FACTOR by the user's code prior
          to calling any of the Flash API functions. This initalization
          is VITAL to the proper operation of the flash API functions.

          SCALE_FACTOR is defined in Example_Flash2833x_API.h as
            #define SCALE_FACTOR  1048576.0L*( (200L/CPU_RATE) )

          This value is calculated during the compile based on the CPU
          rate, in nanoseconds, at which the algorithums will be run.
       ------------------------------------------------------------------*/

          Flash_CPUScaleFactor = SCALE_FACTOR;

          /*------------------------------------------------------------------
            Initalize Flash_CallbackPtr.

             Flash_CallbackPtr is a pointer to a function.  The API uses
             this pointer to invoke a callback function during the API operations.
             If this function is not going to be used, set the pointer to NULL
             NULL is defined in <stdio.h>.
          ------------------------------------------------------------------*/

             Flash_CallbackPtr = &MyCallbackFunction;

             MyCallbackCounter = 0; // Increment this counter in the callback function



            InitPieVectTable();


            INIT_CAN_B_Config();

			///LED Configuration
			GpioCtrlRegs.GPBDIR.bit.GPIO49 = 1;

            EALLOW;  // This is needed to write to EALLOW protected registers
            PieVectTable.TINT0 = &cpu_timer0_isr;
            EDIS;
            InitCpuTimers();   // For this example, only initialize the Cpu Timers

            ConfigCpuTimer(&CpuTimer0, 120, 200);
            CpuTimer0Regs.TCR.all = 0x4000; //write-only instruction to set TSS bit = 0

            IER |= M_INT1;
            PieCtrlRegs.PIEIER1.bit.INTx7 = 1;



            Bootloader_APP_initialize();


            EINT;
            ERTM;




            Uint32 i;
            for(i=0;i<3000;i++){
                DATA[i]=0xAA+i;
            }

    while(1){

		if(*signature_Address == signature)
		{
			Bootloader_APP_SharedDSM.flag_signature_found = 1;
		}
		
        if(Bootloader_APP_SharedDSM.flag_jump==1){

            // IER = 0x0000;
            // IFR = 0x0000;
            // DINT;
            // asm(" LB 0x300000");

			asm(" SETC INTM");  // Disable all interrupts
			asm(" ZAPA");       // Zero accumulator pointer address
			asm(" MOV @SP,#0"); // Set Stack Pointer to 0
			asm(" PUSH ACC");   // Save ACC register to STACK
			asm(" PUSH AL");    // Save AL register to STACK
			asm(" MOV AL, #0x0a08");  // Load AL register with 0x0a08
			asm(" PUSH AL");    // Save AL register to STACK
			asm(" MOVL XAR7, #0x300000");  // Load XAR7 register with 0x300000 (your app start address)
			asm(" PUSH XAR7");  // Save XAR7 register to STACK
			asm(" POP RPC");    // Restore RPC register from STACK (jump to the address stored in RPC)
			asm(" POP ST1");    // Restore ST1 register from STACK
			asm(" POP ST0");    // Restore ST0 register from STACK
			asm(" POP IER");    // Restore IER register from STACK
			asm(" POP DBGIER"); // Restore DBGIER register from STACK

			// disable peripherals
            InitCpuTimers();   // For this example, only initialize the Cpu Timers

			// clear interrupt
            PieCtrlRegs.PIEIER1.bit.INTx7 = 0;


			asm(" LRETR");      // Long Return (restores multiple registers from the stac


            // Bootloader_APP_SharedDSM.flag_jump=0;
        }


        if(Bootloader_APP_SharedDSM.flag_Erase_flash==1){
            DINT;

            EraseFlash();
            EINT;
            ERTM;

            Bootloader_APP_SharedDSM.flag_Erase_flash=0;
        }

        if(Bootloader_APP_SharedDSM.flag_Write_flash==1){
            DINT;
            start_Address=(Uint16 *) Bootloader_APP_Y.FLASH_WR_ADDRESS;

            WriteFlash(start_Address, &Bootloader_APP_Y.FLASH_WR_DATA, Bootloader_APP_Y.FLASH_WR_SIZE);
            EINT;
            ERTM;

            Bootloader_APP_SharedDSM.flag_Write_flash=0;
        }

		// sign the programming termination
		if(Bootloader_APP_Y.BOOT_status == SND_RST_REQ)
		{
			DINT;
            WriteFlash(signature_Address, &signature, 1);
			Bootloader_APP_SharedDSM.flag_signature_found = 1;
            EINT;
            ERTM;

		}


        if((Flag_CAN_REC==1)&&(Bootloader_APP_SharedDSM.flag_MCU_CAN_rec==0)){

           CAN_Receiving_mailbox_Process();


            ECanbRegs.CANRMP.all=0xFFFFFFFF;
            Flag_CAN_REC=0;
        }


        if(Bootloader_APP_SharedDSM.flag_MCU_CAN_trs==1){

          ECanbMboxes.MBOX1.MDL.byte.BYTE0=Bootloader_APP_Y.CAN_To_client_DATA[0];
          ECanbMboxes.MBOX1.MDL.byte.BYTE1=Bootloader_APP_Y.CAN_To_client_DATA[1];
          ECanbMboxes.MBOX1.MDL.byte.BYTE2=Bootloader_APP_Y.CAN_To_client_DATA[2];
          ECanbMboxes.MBOX1.MDL.byte.BYTE3=Bootloader_APP_Y.CAN_To_client_DATA[3];
          ECanbMboxes.MBOX1.MDH.byte.BYTE4=Bootloader_APP_Y.CAN_To_client_DATA[4];
          ECanbMboxes.MBOX1.MDH.byte.BYTE5=Bootloader_APP_Y.CAN_To_client_DATA[5];
          ECanbMboxes.MBOX1.MDH.byte.BYTE6=Bootloader_APP_Y.CAN_To_client_DATA[6];
          ECanbMboxes.MBOX1.MDH.byte.BYTE7=Bootloader_APP_Y.CAN_To_client_DATA[7];
          //// Mbox 1 sending DATA
          ECanbShadow_CANB.CANTRS.all=ECanbRegs.CANTRS.all;
          ECanbShadow_CANB.CANTRS.bit.TRS1=1;
          ECanbRegs.CANTRS.all=ECanbShadow_CANB.CANTRS.all;

            Bootloader_APP_SharedDSM.flag_MCU_CAN_trs=0;
        }


    }





}




Uint16 Example_CsmUnlock()
{
    volatile Uint16 temp;

    // Load the key registers with the current password
    // These are defined in Example_Flash2833x_CsmKeys.asm

    EALLOW;
    CsmRegs.KEY0 = PRG_key0;
    CsmRegs.KEY1 = PRG_key1;
    CsmRegs.KEY2 = PRG_key2;
    CsmRegs.KEY3 = PRG_key3;
    CsmRegs.KEY4 = PRG_key4;
    CsmRegs.KEY5 = PRG_key5;
    CsmRegs.KEY6 = PRG_key6;
    CsmRegs.KEY7 = PRG_key7;
    EDIS;

    // Perform a dummy read of the password locations
    // if they match the key values, the CSM will unlock

    temp = CsmPwl.PSWD0;
    temp = CsmPwl.PSWD1;
    temp = CsmPwl.PSWD2;
    temp = CsmPwl.PSWD3;
    temp = CsmPwl.PSWD4;
    temp = CsmPwl.PSWD5;
    temp = CsmPwl.PSWD6;
    temp = CsmPwl.PSWD7;

    // If the CSM unlocked, return succes, otherwise return
    // failure.
    if ( (CsmRegs.CSMSCR.all & 0x0001) == 0) return STATUS_SUCCESS;
    else return STATUS_FAIL_CSM_LOCKED;

}
/*------------------------------------------------------------------
  Simple memory copy routine to move code out of flash into SARAM
-----------------------------------------------------------------*/

void Example_MemCopy(Uint16 *SourceAddr, Uint16* SourceEndAddr, Uint16* DestAddr)
{
    while(SourceAddr < SourceEndAddr)
    {
       *DestAddr++ = *SourceAddr++;
    }
    return;
}

#pragma CODE_SECTION(Example_Error,".TI.ramfunc");
void Example_Error(Uint16 Status)
{

//  Error code will be in the AL register.
    asm("    ESTOP0");
    asm("    SB 0, UNC");
}
/*------------------------------------------------------------------
  Callback function - must be executed from outside flash/OTP
-----------------------------------------------------------------*/
#pragma CODE_SECTION(MyCallbackFunction,".TI.ramfunc");
void MyCallbackFunction(void)
{
    // Toggle pin, service external watchdog etc
    MyCallbackCounter++;
    asm("    NOP");

}
















__interrupt void
cpu_timer0_isr(void)
{
    PC++;
    if(ECanbRegs.CANRMP.all !=0){
        Flag_CAN_REC=1;
        debug_counter++;
    }
	if(PC%20000==0){
		GpioDataRegs.GPBTOGGLE.bit.GPIO49=1;
    }
	Bootloader_APP_step();
    //
    // Acknowledge this interrupt to receive more interrupts from group 1
    //
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}



#pragma CODE_SECTION(EraseFlash,".TI.ramfunc");
Uint16 EraseFlash(void)
{
   Uint16  Status;
   float32 Version;        // Version of the API in floating point
   Uint16  VersionHex;     // Version of the API in decimal encoded hex


/*------------------------------------------------------------------
  Check the version of the API

  Flash_APIVersion() returns the version in floating point.
  FlashAPIVersionHex() returns the version as a decimal encoded hex.

  FlashAPIVersionHex() can be used to avoid processing issues
  associated with floating point values.
------------------------------------------------------------------*/
   VersionHex = Flash_APIVersionHex();
   if(VersionHex != 0x0210)
   {
       // Unexpected API version
       // Make a decision based on this info.
       asm("    ESTOP0");
   }


   Version = Flash_APIVersion();
   if(Version != (float32)2.10)
   {
       // Unexpected API version
       // Make a decision based on this info.
       asm("    ESTOP0");
   }






/*------------------------------------------------------------------
  Before programming make sure the sectors are Erased.

------------------------------------------------------------------*/

   // Example: Erase Sector B,C
   // Sectors A and D have the example code so leave them
   // programmed.

   // SECTORB, SECTORC are defined in Flash2833x_API_Library.h
   Status = Flash_Erase(((SECTORB)),&FlashStatus);
   Status = Flash_Erase(((SECTORC|SECTORD|SECTORE|SECTORF|SECTORG|SECTORH)),&FlashStatus);


   return Status;



}



#pragma CODE_SECTION(WriteFlash,".TI.ramfunc");
Uint16 WriteFlash(Uint16  *Flash_ptr,Uint16  *DATA,Uint32  Length)
{
   Uint16  Status;
   float32 Version;        // Version of the API in floating point
   Uint16  VersionHex;     // Version of the API in decimal encoded hex


/*------------------------------------------------------------------
  Check the version of the API

  Flash_APIVersion() returns the version in floating point.
  FlashAPIVersionHex() returns the version as a decimal encoded hex.

  FlashAPIVersionHex() can be used to avoid processing issues
  associated with floating point values.
------------------------------------------------------------------*/
   VersionHex = Flash_APIVersionHex();
   if(VersionHex != 0x0210)
   {
       // Unexpected API version
       // Make a decision based on this info.
       asm("    ESTOP0");
   }


   Version = Flash_APIVersion();
   if(Version != (float32)2.10)
   {
       // Unexpected API version
       // Make a decision based on this info.
       asm("    ESTOP0");
   }






   Status = Flash_Program(Flash_ptr, DATA ,Length ,&FlashStatus);




   return Status;


}


void CAN_Receiving_mailbox_Process(void){



        ECanbShadow_CANB.CANRMP.all=ECanbRegs.CANRMP.all;
        if(ECanbShadow_CANB.CANRMP.bit.RMP2==1){
            ///    Data excahange Start

        Bootloader_APP_U.CAN_from_client_DATA[0]=ECanbMboxes.MBOX2.MDL.byte.BYTE0;
        Bootloader_APP_U.CAN_from_client_DATA[1]=ECanbMboxes.MBOX2.MDL.byte.BYTE1;
        Bootloader_APP_U.CAN_from_client_DATA[2]=ECanbMboxes.MBOX2.MDL.byte.BYTE2;
        Bootloader_APP_U.CAN_from_client_DATA[3]=ECanbMboxes.MBOX2.MDL.byte.BYTE3;
        Bootloader_APP_U.CAN_from_client_DATA[4]=ECanbMboxes.MBOX2.MDH.byte.BYTE4;
        Bootloader_APP_U.CAN_from_client_DATA[5]=ECanbMboxes.MBOX2.MDH.byte.BYTE5;
        Bootloader_APP_U.CAN_from_client_DATA[6]=ECanbMboxes.MBOX2.MDH.byte.BYTE6;
        Bootloader_APP_U.CAN_from_client_DATA[7]=ECanbMboxes.MBOX2.MDH.byte.BYTE7;


        DATA_REC[i][0]=ECanbMboxes.MBOX2.MDL.byte.BYTE0;
        DATA_REC[i][1]=ECanbMboxes.MBOX2.MDL.byte.BYTE1;
        DATA_REC[i][2]=ECanbMboxes.MBOX2.MDL.byte.BYTE2;
        DATA_REC[i][3]=ECanbMboxes.MBOX2.MDL.byte.BYTE3;
        DATA_REC[i][4]=ECanbMboxes.MBOX2.MDH.byte.BYTE4;
        DATA_REC[i][5]=ECanbMboxes.MBOX2.MDH.byte.BYTE5;
        DATA_REC[i][6]=ECanbMboxes.MBOX2.MDH.byte.BYTE6;
        DATA_REC[i][7]=ECanbMboxes.MBOX2.MDH.byte.BYTE7;


        i++;


        ///FLAG

        Bootloader_APP_SharedDSM.flag_MCU_CAN_rec=1;

        ///    Data excahange Stop
        }

}
