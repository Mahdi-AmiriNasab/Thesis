

/**
 * main.c
 */

#include "DSP28x_Project.h"

//////////////////////
/*---- Standard headers -------------------------------------------------------*/
#include <stdio.h>
/* Include Files */
#include "rtwtypes.h"
#include "pso.h"
#include "pso_internal_types.h"
#include "pso_terminate.h"
#include "pso_types.h"
#include "rt_nonfinite.h"

#ifndef typedef_emxArray_struct1_T_1x100
#define typedef_emxArray_struct1_T_1x100
typedef struct {
  struct1_T data[100];
  int size[2];
} emxArray_struct1_T_1x100;
#endif /* typedef_emxArray_struct1_T_1x100 */



  emxArray_struct1_T_1x100 eq_step;
  struct0_T global_best;
  struct2_T stio;





__interrupt void cpu_timer0_isr(void);

void CAN_Receiving_mailbox_Process(void);

extern void INIT_CAN_B_Config(void);




Uint32 MyCallbackCounter; // Just increment a counter in the callback function

/*--- Global variables used to interface to the flash routines */

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


// #if FLASH_F28335
// #define FLASH_START_ADDR  0x300000
// #define FLASH_END_ADDR    0x33FFFF

// SECTOR Sector[8] = {
//          (Uint16 *)0x338000,(Uint16 *)0x33FFFF,
//          (Uint16 *)0x330000,(Uint16 *)0x337FFF,
//          (Uint16 *)0x328000,(Uint16 *)0x32FFFF,
//          (Uint16 *)0x320000,(Uint16 *)0x327FFF,
//          (Uint16 *)0x318000,(Uint16 *)0x31FFFF,
//          (Uint16 *)0x33000,(Uint16 *)0x317FFF,
//          (Uint16 *)0x308000,(Uint16 *)0x30FFFF,
//          (Uint16 *)0x300000,(Uint16 *)0x307FFF

// };

// #endif


// #if FLASH_F28334
// #define FLASH_START_ADDR  0x320000
// #define FLASH_END_ADDR    0x33FFFF

// SECTOR Sector[8] = {
//          (Uint16 *)0x33C000,(Uint16 *)0x33FFFF,
//          (Uint16 *)0x338000,(Uint16 *)0x33BFFF,
//          (Uint16 *)0x334000,(Uint16 *)0x337FFF,
//          (Uint16 *)0x330000,(Uint16 *)0x333FFF,
//          (Uint16 *)0x32C000,(Uint16 *)0x32FFFF,
//          (Uint16 *)0x328000,(Uint16 *)0x32BFFF,
//          (Uint16 *)0x324000,(Uint16 *)0x327FFF,
//          (Uint16 *)0x320000,(Uint16 *)0x323FFF

// };

// #endif


// #if FLASH_F28332
// #define FLASH_START_ADDR  0x330000
// #define FLASH_END_ADDR    0x33FFFF

// SECTOR Sector[4] = {
//          (Uint16 *)0x33C000,(Uint16 *)0x33FFFF,
//          (Uint16 *)0x338000,(Uint16 *)0x33BFFF,
//          (Uint16 *)0x334000,(Uint16 *)0x337FFF,
//          (Uint16 *)0x330000,(Uint16 *)0x333FFF

// };

// #endif


extern Uint32 Flash_CPUScaleFactor;


Uint16 Write_Flash=0;
Uint16 Erase_Flag=0;

Uint16 *start_Address;
Uint32 Strt_Address;
///CAN Flag
Uint16 Flag_CAN_REC=0;
extern struct ECAN_REGS ECanbShadow_CANB;



Uint32 debug_counter=0;


Uint16 i=0;
Uint16 DATA_REC[100][8];

/* Function Declarations */
static void argInit_1x9_real_T(double result[9]);

static double argInit_real_T(void);

static void main_pso(void);

/* Function Definitions */
/*
 * Arguments    : double result[9]
 * Return Type  : void
 */
static void argInit_1x9_real_T(double result[9])
{
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 9; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

Uint64 PC=0;



int main(void)
{
	Uint16 *signature_Address= (Uint16 *) 0x337f80;
	Uint16 signature = 0x1234;
        InitSysCtrl();
        DINT;
        InitPieCtrl();
        IER = 0x0000;
        IFR = 0x0000;

	        Uint16 Status;

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



            EINT;
            ERTM;




   


	/* Initialize function 'pso' input arguments. */
	/* Initialize function input argument 'soc_in'. */

	/* Call the entry-point 'pso'. */
    int64 w_time = 0.5;
	int64 w_inc = 0.5;
	int64 soc[9] = {7, 88, 10, 95, 52, 50, 48, 42, 76};

	while(1)
	{

		pso(soc, 2, w_time, w_inc, 0, &global_best, eq_step.data, eq_step.size, &stio);

	}

	
		
			
			


    


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
    //
    // Acknowledge this interrupt to receive more interrupts from group 1
    //
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}

void CAN_Receiving_mailbox_Process(void){



        ECanbShadow_CANB.CANRMP.all=ECanbRegs.CANRMP.all;
        if(ECanbShadow_CANB.CANRMP.bit.RMP2==1){
            ///    Data excahange Start



        DATA_REC[i][0]=ECanbMboxes.MBOX2.MDL.byte.BYTE0;
        DATA_REC[i][1]=ECanbMboxes.MBOX2.MDL.byte.BYTE1;
        DATA_REC[i][2]=ECanbMboxes.MBOX2.MDL.byte.BYTE2;
        DATA_REC[i][3]=ECanbMboxes.MBOX2.MDL.byte.BYTE3;
        DATA_REC[i][4]=ECanbMboxes.MBOX2.MDH.byte.BYTE4;
        DATA_REC[i][5]=ECanbMboxes.MBOX2.MDH.byte.BYTE5;
        DATA_REC[i][6]=ECanbMboxes.MBOX2.MDH.byte.BYTE6;
        DATA_REC[i][7]=ECanbMboxes.MBOX2.MDH.byte.BYTE7;


        i++;




        ///    Data excahange Stop
        }

}
