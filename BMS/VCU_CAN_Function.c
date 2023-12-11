/*
 * VCU_CAN_Function.c
 *
 *  Created on: Apr 20, 2022
 *      Author: 10661011
 */

#include  "VCU_CAN_Function.h"
#include "CAN.h"
#include "test3.h"
#include "CANBMB.h"
#include "chargeAl.h"

extern ExtU_CAN_T CAN_U;
extern ExtY_CAN_T CAN_Y;

extern ExtU_ChargeAl_T ChargeAl_U;
extern ExtY_ChargeAl_T ChargeAl_Y;

extern ExtU_test3_T test3_U;
extern ExtY_test3_T test3_Y;
extern ExtU_CANBMB_T CANBMB_U;
extern ExtY_CANBMB_T CANBMB_Y;

extern Uint16 counterCHM;

extern Uint16 bmbReadyFlag[8];
extern Uint16 bmbReadyCounter[8];
#define LED4_SET       GpioDataRegs.GPBSET.bit.GPIO38 = 1
#define LED4_RESET       GpioDataRegs.GPBCLEAR.bit.GPIO38 = 1
#define LED4_TOGGLE       GpioDataRegs.GPBTOGGLE.bit.GPIO38 = 1
extern testbmbcounter;
#define LED1_SET       GpioDataRegs.GPCSET.bit.GPIO77 = 1
#define LED1_RESET       GpioDataRegs.GPCCLEAR.bit.GPIO77 = 1
#define LED1_TOGGLE       GpioDataRegs.GPCTOGGLE.bit.GPIO77 = 1

#define LED2_TOGGLE       GpioDataRegs.GPCTOGGLE.bit.GPIO78 = 1
struct ECAN_REGS ECanbShadow;
struct ECAN_REGS ECanaShadow;
VCU_CAN_Flag a_Flag;
VCU_CAN_Flag b_Flag;
Uint16 DATA[8];
Uint16 t1sFlag = 0;
//extern ExtU_Charger_Functions_T Charger_Functions_U;

//extern ExtY_Charger_Functions_T Charger_Functions_Y;



void b_Mailbox_configuration_Settings(void){

    //**********************************************
    /* Mbox1
      Transmit Mbox
      MsgID:0x1806e5f4  Extended 29 Bit
      sending command for internal  charger
    */
    // Write to the MSGID field
    ECanbMboxes.MBOX1.MSGID.bit.STDMSGID=0x301;
    ECanbMboxes.MBOX1.MSGID.bit.IDE=0;
    ECanbMboxes.MBOX1.MSGID.bit.AAM=0;
    ECanbMboxes.MBOX1.MSGID.bit.AME=0;
    // Configure Mailbox 1 as a Transmit mailbox
     ECanbShadow.CANMD.all = ECanbRegs.CANMD.all;
     ECanbShadow.CANMD.bit.MD1 = 0;
     ECanbRegs.CANMD.all = ECanbShadow.CANMD.all;
     // Enable Mailbox1
     ECanbShadow.CANME.all = ECanbRegs.CANME.all;
     ECanbShadow.CANME.bit.ME1 = 1;
     ECanbRegs.CANME.all = ECanbShadow.CANME.all;
     // Write to DLC field in Master Control reg
     ECanbMboxes.MBOX1.MSGCTRL.bit.DLC = 8;
     //**********************************************
     //**********************************************
         /* Mbox2
           Transmit Mbox
           MsgID:0x1806e5f4  Extended 29 Bit
           sending command for internal  charger
         */
         // Write to the MSGID field
         ECanbMboxes.MBOX2.MSGID.bit.STDMSGID=0x302;
         ECanbMboxes.MBOX2.MSGID.bit.IDE=0;
         ECanbMboxes.MBOX2.MSGID.bit.AAM=0;
         ECanbMboxes.MBOX2.MSGID.bit.AME=0;
         // Configure Mailbox 1 as a Transmit mailbox
          ECanbShadow.CANMD.all = ECanbRegs.CANMD.all;
          ECanbShadow.CANMD.bit.MD2 = 0;
          ECanbRegs.CANMD.all = ECanbShadow.CANMD.all;
          // Enable Mailbox1
          ECanbShadow.CANME.all = ECanbRegs.CANME.all;
          ECanbShadow.CANME.bit.ME2 = 1;
          ECanbRegs.CANME.all = ECanbShadow.CANME.all;
          // Write to DLC field in Master Control reg
          ECanbMboxes.MBOX2.MSGCTRL.bit.DLC = 8;
          //**********************************************

          //**********************************************
              /* Mbox3
                Transmit Mbox3
                MsgID:0x1806e5f4  Extended 29 Bit
                sending command for internal  charger
              */
              // Write to the MSGID field
              ECanbMboxes.MBOX3.MSGID.bit.STDMSGID=0x303;
              ECanbMboxes.MBOX3.MSGID.bit.IDE=0;
              ECanbMboxes.MBOX3.MSGID.bit.AAM=0;
              ECanbMboxes.MBOX3.MSGID.bit.AME=0;
              // Configure Mailbox 1 as a Transmit mailbox
               ECanbShadow.CANMD.all = ECanbRegs.CANMD.all;
               ECanbShadow.CANMD.bit.MD3 = 0;
               ECanbRegs.CANMD.all = ECanbShadow.CANMD.all;
               // Enable Mailbox1
               ECanbShadow.CANME.all = ECanbRegs.CANME.all;
               ECanbShadow.CANME.bit.ME3 = 1;
               ECanbRegs.CANME.all = ECanbShadow.CANME.all;
               // Write to DLC field in Master Control reg
               ECanbMboxes.MBOX3.MSGCTRL.bit.DLC = 8;
               //**********************************************
               //**********************************************
                   /* Mbox4
                     Transmit Mbox
                     MsgID:0x1806e5f4  Extended 29 Bit
                     sending command for internal  charger
                   */
                   // Write to the MSGID field
                   ECanbMboxes.MBOX4.MSGID.bit.STDMSGID=0x304;
                   ECanbMboxes.MBOX4.MSGID.bit.IDE=0;
                   ECanbMboxes.MBOX4.MSGID.bit.AAM=0;
                   ECanbMboxes.MBOX4.MSGID.bit.AME=0;
                   // Configure Mailbox 1 as a Transmit mailbox
                    ECanbShadow.CANMD.all = ECanbRegs.CANMD.all;
                    ECanbShadow.CANMD.bit.MD4 = 0;
                    ECanbRegs.CANMD.all = ECanbShadow.CANMD.all;
                    // Enable Mailbox1
                    ECanbShadow.CANME.all = ECanbRegs.CANME.all;
                    ECanbShadow.CANME.bit.ME4 = 1;
                    ECanbRegs.CANME.all = ECanbShadow.CANME.all;
                    // Write to DLC field in Master Control reg
                    ECanbMboxes.MBOX4.MSGCTRL.bit.DLC = 8;
                    //**********************************************

                    /* Mbox5
                      Transmit Mbox
                      MsgID:0x1806e5f4  Extended 29 Bit
                      sending command for internal  charger
                    */
                    // Write to the MSGID field
                    ECanbMboxes.MBOX5.MSGID.bit.STDMSGID=0x305;
                    ECanbMboxes.MBOX5.MSGID.bit.IDE=0;
                    ECanbMboxes.MBOX5.MSGID.bit.AAM=0;
                    ECanbMboxes.MBOX5.MSGID.bit.AME=0;
                    // Configure Mailbox 1 as a Transmit mailbox
                     ECanbShadow.CANMD.all = ECanbRegs.CANMD.all;
                     ECanbShadow.CANMD.bit.MD5 = 0;
                     ECanbRegs.CANMD.all = ECanbShadow.CANMD.all;
                     // Enable Mailbox1
                     ECanbShadow.CANME.all = ECanbRegs.CANME.all;
                     ECanbShadow.CANME.bit.ME5 = 1;
                     ECanbRegs.CANME.all = ECanbShadow.CANME.all;
                     // Write to DLC field in Master Control reg
                     ECanbMboxes.MBOX5.MSGCTRL.bit.DLC = 8;
                     //**********************************************

                     /* Mbox6
                       Transmit Mbox
                       MsgID:0x1806e5f4  Extended 29 Bit
                       sending command for internal  charger
                     */
                     // Write to the MSGID field
                     ECanbMboxes.MBOX6.MSGID.bit.STDMSGID=0x306;
                     ECanbMboxes.MBOX6.MSGID.bit.IDE=0;
                     ECanbMboxes.MBOX6.MSGID.bit.AAM=0;
                     ECanbMboxes.MBOX6.MSGID.bit.AME=0;
                     // Configure Mailbox 1 as a Transmit mailbox
                      ECanbShadow.CANMD.all = ECanbRegs.CANMD.all;
                      ECanbShadow.CANMD.bit.MD6 = 0;
                      ECanbRegs.CANMD.all = ECanbShadow.CANMD.all;
                      // Enable Mailbox1
                      ECanbShadow.CANME.all = ECanbRegs.CANME.all;
                      ECanbShadow.CANME.bit.ME6 = 1;
                      ECanbRegs.CANME.all = ECanbShadow.CANME.all;
                      // Write to DLC field in Master Control reg
                      ECanbMboxes.MBOX6.MSGCTRL.bit.DLC = 8;
                      //**********************************************

                      /* Mbox7
                        Transmit Mbox
                        MsgID:0x1806e5f4  Extended 29 Bit
                        sending command for internal  charger
                      */
                      // Write to the MSGID field
                      ECanbMboxes.MBOX7.MSGID.bit.STDMSGID=0x307;
                      ECanbMboxes.MBOX7.MSGID.bit.IDE=0;
                      ECanbMboxes.MBOX7.MSGID.bit.AAM=0;
                      ECanbMboxes.MBOX7.MSGID.bit.AME=0;
                      // Configure Mailbox 1 as a Transmit mailbox
                       ECanbShadow.CANMD.all = ECanbRegs.CANMD.all;
                       ECanbShadow.CANMD.bit.MD7 = 0;
                       ECanbRegs.CANMD.all = ECanbShadow.CANMD.all;
                       // Enable Mailbox1
                       ECanbShadow.CANME.all = ECanbRegs.CANME.all;
                       ECanbShadow.CANME.bit.ME7 = 1;
                       ECanbRegs.CANME.all = ECanbShadow.CANME.all;
                       // Write to DLC field in Master Control reg
                       ECanbMboxes.MBOX7.MSGCTRL.bit.DLC = 8;


ECanbMboxes.MBOX9.MSGID.bit.STDMSGID=0x501;
ECanbMboxes.MBOX9.MSGID.bit.IDE=0;
ECanbMboxes.MBOX9.MSGID.bit.AAM=0;
ECanbMboxes.MBOX9.MSGID.bit.AME=0;
// Configure Mailbox 1 as a Transmit mailbox
ECanbShadow.CANMD.all = ECanbRegs.CANMD.all;
ECanbShadow.CANMD.bit.MD9 = 0;
ECanbRegs.CANMD.all = ECanbShadow.CANMD.all;
// Enable Mailbox1
ECanbShadow.CANME.all = ECanbRegs.CANME.all;
ECanbShadow.CANME.bit.ME9 = 1;
ECanbRegs.CANME.all = ECanbShadow.CANME.all;
// Write to DLC field in Master Control reg
ECanbMboxes.MBOX9.MSGCTRL.bit.DLC = 8;

ECanbMboxes.MBOX10.MSGID.bit.STDMSGID=0x502;
ECanbMboxes.MBOX10.MSGID.bit.IDE=0;
ECanbMboxes.MBOX10.MSGID.bit.AAM=0;
ECanbMboxes.MBOX10.MSGID.bit.AME=0;
// Configure Mailbox 1 as a Transmit mailbox
ECanbShadow.CANMD.all = ECanbRegs.CANMD.all;
ECanbShadow.CANMD.bit.MD10 = 0;
ECanbRegs.CANMD.all = ECanbShadow.CANMD.all;
// Enable Mailbox1
ECanbShadow.CANME.all = ECanbRegs.CANME.all;
ECanbShadow.CANME.bit.ME10 = 1;
ECanbRegs.CANME.all = ECanbShadow.CANME.all;
// Write to DLC field in Master Control reg
ECanbMboxes.MBOX10.MSGCTRL.bit.DLC = 8;

ECanbMboxes.MBOX11.MSGID.bit.STDMSGID=0x503;
ECanbMboxes.MBOX11.MSGID.bit.IDE=0;
ECanbMboxes.MBOX11.MSGID.bit.AAM=0;
ECanbMboxes.MBOX11.MSGID.bit.AME=0;
// Configure Mailbox 1 as a Transmit mailbox
ECanbShadow.CANMD.all = ECanbRegs.CANMD.all;
ECanbShadow.CANMD.bit.MD11 = 0;
ECanbRegs.CANMD.all = ECanbShadow.CANMD.all;
// Enable Mailbox1
ECanbShadow.CANME.all = ECanbRegs.CANME.all;
ECanbShadow.CANME.bit.ME11 = 1;
ECanbRegs.CANME.all = ECanbShadow.CANME.all;
// Write to DLC field in Master Control reg
ECanbMboxes.MBOX11.MSGCTRL.bit.DLC = 8;


                    //**********************************************
     /* Mbox2
       receive Mbox
       MsgID:0x18FF50E5  Extended 29 Bit
       receiving Data from internal charger
     */
     // Write to the MSGID field
     ECanbMboxes.MBOX8.MSGID.bit.STDMSGID=0x101;
     ECanbMboxes.MBOX8.MSGID.bit.IDE=0;
     ECanbMboxes.MBOX8.MSGID.bit.AAM=0;
     ECanbMboxes.MBOX8.MSGID.bit.AME=0;
     // Configure Mailbox 2 as a receive mailbox
      ECanbShadow.CANMD.all = ECanbRegs.CANMD.all;
      ECanbShadow.CANMD.bit.MD8 = 1;
      ECanbRegs.CANMD.all = ECanbShadow.CANMD.all;
      // Enable Mailbox2
      ECanbShadow.CANME.all = ECanbRegs.CANME.all;
      ECanbShadow.CANME.bit.ME8 = 1;
      ECanbRegs.CANME.all = ECanbShadow.CANME.all;
      // Write to DLC field in Master Control reg
      ECanbMboxes.MBOX8.MSGCTRL.bit.DLC = 8;
      //**********************************************

   ////////////////////////////////////////////////////////////////////
   ////////////////////////////////////////////////////////////////////
   ////////////////////////////////////////////////////////////////////

      // Rec-SIF
          ECanbMboxes.MBOX12.MSGID.all = 0x1C3FF456;
          ECanbMboxes.MBOX12.MSGID.bit.IDE = 1;
          ECanbMboxes.MBOX12.MSGID.bit.AAM = 0;
          ECanbMboxes.MBOX12.MSGID.bit.AME = 0;
          // Configure Mailbox 1 as a Transmit mailbox
          ECanbShadow.CANMD.all = ECanbRegs.CANMD.all;
          ECanbShadow.CANMD.bit.MD12 = 1;
          ECanbRegs.CANMD.all = ECanbShadow.CANMD.all;
          // Enable Mailbox1
          ECanbShadow.CANME.all = ECanbRegs.CANME.all;
          ECanbShadow.CANME.bit.ME12 = 1;
          ECanbRegs.CANME.all = ECanbShadow.CANME.all;
          // Write to DLC field in Master Control reg
          ECanbMboxes.MBOX12.MSGCTRL.bit.DLC = 8;
          //**********************************************

          // Rec-CHM
          ECanbMboxes.MBOX13.MSGID.all=0x1826F456;
          ECanbMboxes.MBOX13.MSGID.bit.IDE=1;
          ECanbMboxes.MBOX13.MSGID.bit.AAM=0;
          ECanbMboxes.MBOX13.MSGID.bit.AME=0;
          // Configure Mailbox 1 as a Transmit mailbox
          ECanbShadow.CANMD.all = ECanbRegs.CANMD.all;
          ECanbShadow.CANMD.bit.MD13 = 1;
          ECanbRegs.CANMD.all = ECanbShadow.CANMD.all;
          // Enable Mailbox1
          ECanbShadow.CANME.all = ECanbRegs.CANME.all;
          ECanbShadow.CANME.bit.ME13 = 1;
          ECanbRegs.CANME.all = ECanbShadow.CANME.all;
          // Write to DLC field in Master Control reg
          ECanbMboxes.MBOX13.MSGCTRL.bit.DLC = 8;
          //**********************************************

          // Rec-CRM
          ECanbMboxes.MBOX14.MSGID.all=0x1801F456;
          ECanbMboxes.MBOX14.MSGID.bit.IDE=1;
          ECanbMboxes.MBOX14.MSGID.bit.AAM=0;
          ECanbMboxes.MBOX14.MSGID.bit.AME=0;
          // Configure Mailbox 1 as a Transmit mailbox
          ECanbShadow.CANMD.all = ECanbRegs.CANMD.all;
          ECanbShadow.CANMD.bit.MD14 = 1;
          ECanbRegs.CANMD.all = ECanbShadow.CANMD.all;
          // Enable Mailbox1
          ECanbShadow.CANME.all = ECanbRegs.CANME.all;
          ECanbShadow.CANME.bit.ME14 = 1;
          ECanbRegs.CANME.all = ECanbShadow.CANME.all;
          // Write to DLC field in Master Control reg
          ECanbMboxes.MBOX14.MSGCTRL.bit.DLC = 8;
          //**********************************************

          // Rec-CML
          ECanbMboxes.MBOX15.MSGID.all=0x1808F456;
          ECanbMboxes.MBOX15.MSGID.bit.IDE=1;
          ECanbMboxes.MBOX15.MSGID.bit.AAM=0;
          ECanbMboxes.MBOX15.MSGID.bit.AME=0;
          // Configure Mailbox 1 as a Transmit mailbox
          ECanbShadow.CANMD.all = ECanbRegs.CANMD.all;
          ECanbShadow.CANMD.bit.MD15 = 1;
          ECanbRegs.CANMD.all = ECanbShadow.CANMD.all;
          // Enable Mailbox1
          ECanbShadow.CANME.all = ECanbRegs.CANME.all;
          ECanbShadow.CANME.bit.ME15 = 1;
          ECanbRegs.CANME.all = ECanbShadow.CANME.all;
          // Write to DLC field in Master Control reg
          ECanbMboxes.MBOX15.MSGCTRL.bit.DLC = 8;
          //**********************************************

          // Rec-CTS
          ECanbMboxes.MBOX16.MSGID.all=0x1807F456;
          ECanbMboxes.MBOX16.MSGID.bit.IDE=1;
          ECanbMboxes.MBOX16.MSGID.bit.AAM=0;
          ECanbMboxes.MBOX16.MSGID.bit.AME=0;
          // Configure Mailbox 1 as a Transmit mailbox
          ECanbShadow.CANMD.all = ECanbRegs.CANMD.all;
          ECanbShadow.CANMD.bit.MD16 = 1;
          ECanbRegs.CANMD.all = ECanbShadow.CANMD.all;
          // Enable Mailbox1
          ECanbShadow.CANME.all = ECanbRegs.CANME.all;
          ECanbShadow.CANME.bit.ME16 = 1;
          ECanbRegs.CANME.all = ECanbShadow.CANME.all;
          // Write to DLC field in Master Control reg
          ECanbMboxes.MBOX16.MSGCTRL.bit.DLC = 8;
          //**********************************************

          // Rec-CR0
          ECanbMboxes.MBOX17.MSGID.all=0x100AF456;
          ECanbMboxes.MBOX17.MSGID.bit.IDE=1;
          ECanbMboxes.MBOX17.MSGID.bit.AAM=0;
          ECanbMboxes.MBOX17.MSGID.bit.AME=0;
          // Configure Mailbox 1 as a Transmit mailbox
          ECanbShadow.CANMD.all = ECanbRegs.CANMD.all;
          ECanbShadow.CANMD.bit.MD17 = 1;
          ECanbRegs.CANMD.all = ECanbShadow.CANMD.all;
          // Enable Mailbox1
          ECanbShadow.CANME.all = ECanbRegs.CANME.all;
          ECanbShadow.CANME.bit.ME17 = 1;
          ECanbRegs.CANME.all = ECanbShadow.CANME.all;
          // Write to DLC field in Master Control reg
          ECanbMboxes.MBOX17.MSGCTRL.bit.DLC = 8;
          //**********************************************

          // Rec-CCS
          ECanbMboxes.MBOX18.MSGID.all=0x1812F456;
          ECanbMboxes.MBOX18.MSGID.bit.IDE=1;
          ECanbMboxes.MBOX18.MSGID.bit.AAM=0;
          ECanbMboxes.MBOX18.MSGID.bit.AME=0;
          // Configure Mailbox 1 as a Transmit mailbox
          ECanbShadow.CANMD.all = ECanbRegs.CANMD.all;
          ECanbShadow.CANMD.bit.MD18 = 1;
          ECanbRegs.CANMD.all = ECanbShadow.CANMD.all;
          // Enable Mailbox1
          ECanbShadow.CANME.all = ECanbRegs.CANME.all;
          ECanbShadow.CANME.bit.ME18 = 1;
          ECanbRegs.CANME.all = ECanbShadow.CANME.all;
          // Write to DLC field in Master Control reg
          ECanbMboxes.MBOX18.MSGCTRL.bit.DLC = 8;


          //Tra-BHM
              ECanbMboxes.MBOX19.MSGID.all=0x182756F4;
              ECanbMboxes.MBOX19.MSGID.bit.IDE=1;
              ECanbMboxes.MBOX19.MSGID.bit.AAM=0;
              ECanbMboxes.MBOX19.MSGID.bit.AME=0;
              // Configure Mailbox 2 as a receive mailbox
              ECanbShadow.CANMD.all = ECanbRegs.CANMD.all;
              ECanbShadow.CANMD.bit.MD19 = 0;
              ECanbRegs.CANMD.all = ECanbShadow.CANMD.all;
              // Enable Mailbox2
              ECanbShadow.CANME.all = ECanbRegs.CANME.all;
              ECanbShadow.CANME.bit.ME19 = 1;
              ECanbRegs.CANME.all = ECanbShadow.CANME.all;
              // Write to DLC field in Master Control reg
              ECanbMboxes.MBOX19.MSGCTRL.bit.DLC = 8;
              //**********************************************

              //Tra-BRM
              ECanbMboxes.MBOX20.MSGID.all=0x1CEB56f4;
              ECanbMboxes.MBOX20.MSGID.bit.IDE=1;
              ECanbMboxes.MBOX20.MSGID.bit.AAM=0;
              ECanbMboxes.MBOX20.MSGID.bit.AME=0;
              // Configure Mailbox 1 as a Transmit mailbox
              ECanbShadow.CANMD.all = ECanbRegs.CANMD.all;
              ECanbShadow.CANMD.bit.MD20 = 0;
              ECanbRegs.CANMD.all = ECanbShadow.CANMD.all;
              // Enable Mailbox1
              ECanbShadow.CANME.all = ECanbRegs.CANME.all;
              ECanbShadow.CANME.bit.ME20 = 1;
              ECanbRegs.CANME.all = ECanbShadow.CANME.all;
              // Write to DLC field in Master Control reg
              ECanbMboxes.MBOX20.MSGCTRL.bit.DLC = 8;

              //Tra-BCS
              ECanbMboxes.MBOX21.MSGID.all=0x181156F4;
              ECanbMboxes.MBOX21.MSGID.bit.IDE=1;
              ECanbMboxes.MBOX21.MSGID.bit.AAM=0;
              ECanbMboxes.MBOX21.MSGID.bit.AME=0;
              // Configure Mailbox 1 as a Transmit mailbox
              ECanbShadow.CANMD.all = ECanbRegs.CANMD.all;
              ECanbShadow.CANMD.bit.MD21 = 0;
              ECanbRegs.CANMD.all = ECanbShadow.CANMD.all;
              // Enable Mailbox1
              ECanbShadow.CANME.all = ECanbRegs.CANME.all;
              ECanbShadow.CANME.bit.ME21 = 1;
              ECanbRegs.CANME.all = ECanbShadow.CANME.all;
              // Write to DLC field in Master Control reg
              ECanbMboxes.MBOX21.MSGCTRL.bit.DLC = 8;

              //Tra-BSM
              ECanbMboxes.MBOX22.MSGID.all=0x181356F4;
              ECanbMboxes.MBOX22.MSGID.bit.IDE=1;
              ECanbMboxes.MBOX22.MSGID.bit.AAM=0;
              ECanbMboxes.MBOX22.MSGID.bit.AME=0;
              // Configure Mailbox 1 as a Transmit mailbox
              ECanbShadow.CANMD.all = ECanbRegs.CANMD.all;
              ECanbShadow.CANMD.bit.MD22 = 0;
              ECanbRegs.CANMD.all = ECanbShadow.CANMD.all;
              // Enable Mailbox1
              ECanbShadow.CANME.all = ECanbRegs.CANME.all;
              ECanbShadow.CANME.bit.ME22 = 1;
              ECanbRegs.CANME.all = ECanbShadow.CANME.all;
              // Write to DLC field in Master Control reg
              ECanbMboxes.MBOX22.MSGCTRL.bit.DLC = 8;

              //Tra-BSD
              ECanbMboxes.MBOX23.MSGID.all=0x181C56F4;
              ECanbMboxes.MBOX23.MSGID.bit.IDE=1;
              ECanbMboxes.MBOX23.MSGID.bit.AAM=0;
              ECanbMboxes.MBOX23.MSGID.bit.AME=0;
              // Configure Mailbox 1 as a Transmit mailbox
              ECanbShadow.CANMD.all = ECanbRegs.CANMD.all;
              ECanbShadow.CANMD.bit.MD23 = 0;
              ECanbRegs.CANMD.all = ECanbShadow.CANMD.all;
              // Enable Mailbox1
              ECanbShadow.CANME.all = ECanbRegs.CANME.all;
              ECanbShadow.CANME.bit.ME23 = 1;
              ECanbRegs.CANME.all = ECanbShadow.CANME.all;
              // Write to DLC field in Master Control reg
              ECanbMboxes.MBOX23.MSGCTRL.bit.DLC = 8;

              //Tra-BCP
              ECanbMboxes.MBOX24.MSGID.all=0x1C0656F4;
              ECanbMboxes.MBOX24.MSGID.bit.IDE=1;
              ECanbMboxes.MBOX24.MSGID.bit.AAM=0;
              ECanbMboxes.MBOX24.MSGID.bit.AME=0;
              // Configure Mailbox 1 as a Transmit mailbox
              ECanbShadow.CANMD.all = ECanbRegs.CANMD.all;
              ECanbShadow.CANMD.bit.MD24 = 0;
              ECanbRegs.CANMD.all = ECanbShadow.CANMD.all;
              // Enable Mailbox1
              ECanbShadow.CANME.all = ECanbRegs.CANME.all;
              ECanbShadow.CANME.bit.ME24 = 1;
              ECanbRegs.CANME.all = ECanbShadow.CANME.all;
              // Write to DLC field in Master Control reg
              ECanbMboxes.MBOX24.MSGCTRL.bit.DLC = 8;

              //Tra-BRO
              ECanbMboxes.MBOX25.MSGID.all=0x100956F4;
              ECanbMboxes.MBOX25.MSGID.bit.IDE=1;
              ECanbMboxes.MBOX25.MSGID.bit.AAM=0;
              ECanbMboxes.MBOX25.MSGID.bit.AME=0;
              // Configure Mailbox 1 as a Transmit mailbox
              ECanbShadow.CANMD.all = ECanbRegs.CANMD.all;
              ECanbShadow.CANMD.bit.MD25 = 0;
              ECanbRegs.CANMD.all = ECanbShadow.CANMD.all;
              // Enable Mailbox1
              ECanbShadow.CANME.all = ECanbRegs.CANME.all;
              ECanbShadow.CANME.bit.ME25 = 1;
              ECanbRegs.CANME.all = ECanbShadow.CANME.all;
              // Write to DLC field in Master Control reg
              ECanbMboxes.MBOX25.MSGCTRL.bit.DLC = 8;

              //Tra-BCL
              ECanbMboxes.MBOX26.MSGID.all=0x181056F4;
              ECanbMboxes.MBOX26.MSGID.bit.IDE=1;
              ECanbMboxes.MBOX26.MSGID.bit.AAM=0;
              ECanbMboxes.MBOX26.MSGID.bit.AME=0;
              // Configure Mailbox 1 as a Transmit mailbox
              ECanbShadow.CANMD.all = ECanbRegs.CANMD.all;
              ECanbShadow.CANMD.bit.MD26 = 0;
              ECanbRegs.CANMD.all = ECanbShadow.CANMD.all;
              // Enable Mailbox1
              ECanbShadow.CANME.all = ECanbRegs.CANME.all;
              ECanbShadow.CANME.bit.ME26 = 1;
              ECanbRegs.CANME.all = ECanbShadow.CANME.all;
              // Write to DLC field in Master Control reg
              ECanbMboxes.MBOX26.MSGCTRL.bit.DLC = 8;

              //Tra-BST
              ECanbMboxes.MBOX27.MSGID.all=0x101956F4;
              ECanbMboxes.MBOX27.MSGID.bit.IDE=1;
              ECanbMboxes.MBOX27.MSGID.bit.AAM=0;
              ECanbMboxes.MBOX27.MSGID.bit.AME=0;
              // Configure Mailbox 1 as a Transmit mailbox
              ECanbShadow.CANMD.all = ECanbRegs.CANMD.all;
              ECanbShadow.CANMD.bit.MD27 = 0;
              ECanbRegs.CANMD.all = ECanbShadow.CANMD.all;
              // Enable Mailbox1
              ECanbShadow.CANME.all = ECanbRegs.CANME.all;
              ECanbShadow.CANME.bit.ME27 = 1;
              ECanbRegs.CANME.all = ECanbShadow.CANME.all;
              // Write to DLC field in Master Control reg
              ECanbMboxes.MBOX27.MSGCTRL.bit.DLC = 8;


              //Tra- BMS multi-packet transmission request
              ECanbMboxes.MBOX28.MSGID.all=0x1CEC56f4;
              ECanbMboxes.MBOX28.MSGID.bit.IDE=1;
              ECanbMboxes.MBOX28.MSGID.bit.AAM=0;
              ECanbMboxes.MBOX28.MSGID.bit.AME=0;
              // Configure Mailbox 1 as a Transmit mailbox
              ECanbShadow.CANMD.all = ECanbRegs.CANMD.all;
              ECanbShadow.CANMD.bit.MD28 = 0;
              ECanbRegs.CANMD.all = ECanbShadow.CANMD.all;
              // Enable Mailbox1
              ECanbShadow.CANME.all = ECanbRegs.CANME.all;
              ECanbShadow.CANME.bit.ME28 = 1;
              ECanbRegs.CANME.all = ECanbShadow.CANME.all;
              // Write to DLC field in Master Control reg
              ECanbMboxes.MBOX28.MSGCTRL.bit.DLC = 8;

              // Rec- EVCC multi-packet transmission response
              ECanbMboxes.MBOX29.MSGID.all=0x1CECF456;
              ECanbMboxes.MBOX29.MSGID.bit.IDE=1;
              ECanbMboxes.MBOX29.MSGID.bit.AAM=0;
              ECanbMboxes.MBOX29.MSGID.bit.AME=0;
              // Configure Mailbox 1 as a Transmit mailbox
              ECanbShadow.CANMD.all = ECanbRegs.CANMD.all;
              ECanbShadow.CANMD.bit.MD29 = 1;
              ECanbRegs.CANMD.all = ECanbShadow.CANMD.all;
              // Enable Mailbox1
              ECanbShadow.CANME.all = ECanbRegs.CANME.all;
              ECanbShadow.CANME.bit.ME29 = 1;
              ECanbRegs.CANME.all = ECanbShadow.CANME.all;
              // Write to DLC field in Master Control reg
              ECanbMboxes.MBOX29.MSGCTRL.bit.DLC = 8;




}
void a_Mailbox_configuration_Settings(void){


    // mbox0-transmit-bms2bmb-id1
    ECanaMboxes.MBOX0.MSGID.bit.STDMSGID=0x1;
    ECanaMboxes.MBOX0.MSGID.bit.IDE=0;
    ECanaMboxes.MBOX0.MSGID.bit.AAM=0;
    ECanaMboxes.MBOX0.MSGID.bit.AME=0;
    ECanaShadow.CANMD.all = ECanbRegs.CANMD.all;
    ECanaShadow.CANMD.bit.MD0 = 0;
    ECanaRegs.CANMD.all = ECanaShadow.CANMD.all;
    ECanaShadow.CANME.all = ECanaRegs.CANME.all;
    ECanaShadow.CANME.bit.ME0 = 1;
    ECanaRegs.CANME.all = ECanaShadow.CANME.all;
    ECanaMboxes.MBOX0.MSGCTRL.bit.DLC = 8;
    //**********************************************
    // mbox1-transmit-bms2bmb-id2
    ECanaMboxes.MBOX1.MSGID.bit.STDMSGID=0x2;
    ECanaMboxes.MBOX1.MSGID.bit.IDE=0;
    ECanaMboxes.MBOX1.MSGID.bit.AAM=0;
    ECanaMboxes.MBOX1.MSGID.bit.AME=0;
    ECanaShadow.CANMD.all = ECanaRegs.CANMD.all;
    ECanaShadow.CANMD.bit.MD1 = 0;
    ECanaRegs.CANMD.all = ECanaShadow.CANMD.all;
    ECanaShadow.CANME.all = ECanaRegs.CANME.all;
    ECanaShadow.CANME.bit.ME1 = 1;
    ECanaRegs.CANME.all = ECanaShadow.CANME.all;
    ECanaMboxes.MBOX1.MSGCTRL.bit.DLC = 8;
    //**********************************************
    // mbox2-receive-bmb2bms-id3
    ECanaMboxes.MBOX2.MSGID.bit.STDMSGID=0x3;
    ECanaMboxes.MBOX2.MSGID.bit.IDE=0;
    ECanaMboxes.MBOX2.MSGID.bit.AAM=0;
    ECanaMboxes.MBOX2.MSGID.bit.AME=0;
    ECanaShadow.CANMD.all = ECanaRegs.CANMD.all;
    ECanaShadow.CANMD.bit.MD2 = 1;
    ECanaRegs.CANMD.all = ECanaShadow.CANMD.all;
    ECanaShadow.CANME.all = ECanaRegs.CANME.all;
    ECanaShadow.CANME.bit.ME2 = 1;
    ECanaRegs.CANME.all = ECanaShadow.CANME.all;
    ECanaMboxes.MBOX2.MSGCTRL.bit.DLC = 8;
    //**********************************************
    // mbox3-receive-bmb2bms-id4
    ECanaMboxes.MBOX3.MSGID.bit.STDMSGID=0x4;
    ECanaMboxes.MBOX3.MSGID.bit.IDE=0;
    ECanaMboxes.MBOX3.MSGID.bit.AAM=0;
    ECanaMboxes.MBOX3.MSGID.bit.AME=0;
    ECanaShadow.CANMD.all = ECanaRegs.CANMD.all;
    ECanaShadow.CANMD.bit.MD3 = 1;
    ECanaRegs.CANMD.all = ECanaShadow.CANMD.all;
    ECanaShadow.CANME.all = ECanaRegs.CANME.all;
    ECanaShadow.CANME.bit.ME3 = 1;
    ECanaRegs.CANME.all = ECanaShadow.CANME.all;
    ECanaMboxes.MBOX3.MSGCTRL.bit.DLC = 8;
    //**********************************************
    // mbox4-receive-bmb2bms-id5
    ECanaMboxes.MBOX4.MSGID.bit.STDMSGID=0x5;
    ECanaMboxes.MBOX4.MSGID.bit.IDE=0;
    ECanaMboxes.MBOX4.MSGID.bit.AAM=0;
    ECanaMboxes.MBOX4.MSGID.bit.AME=0;
    ECanaShadow.CANMD.all = ECanaRegs.CANMD.all;
    ECanaShadow.CANMD.bit.MD4 = 1;
    ECanaRegs.CANMD.all = ECanaShadow.CANMD.all;
    ECanaShadow.CANME.all = ECanaRegs.CANME.all;
    ECanaShadow.CANME.bit.ME4 = 1;
    ECanaRegs.CANME.all = ECanaShadow.CANME.all;
    ECanaMboxes.MBOX4.MSGCTRL.bit.DLC = 8;
    //**********************************************
    // mbox5-receive-bmb2bms-id6
    ECanaMboxes.MBOX5.MSGID.bit.STDMSGID=0x6;
    ECanaMboxes.MBOX5.MSGID.bit.IDE=0;
    ECanaMboxes.MBOX5.MSGID.bit.AAM=0;
    ECanaMboxes.MBOX5.MSGID.bit.AME=0;
    ECanaShadow.CANMD.all = ECanaRegs.CANMD.all;
    ECanaShadow.CANMD.bit.MD5 = 1;
    ECanaRegs.CANMD.all = ECanaShadow.CANMD.all;
    ECanaShadow.CANME.all = ECanaRegs.CANME.all;
    ECanaShadow.CANME.bit.ME5 = 1;
    ECanaRegs.CANME.all = ECanaShadow.CANME.all;
    ECanaMboxes.MBOX5.MSGCTRL.bit.DLC = 8;
    //**********************************************
    // mbox6-receive-bmb2bms-id7
    ECanaMboxes.MBOX6.MSGID.bit.STDMSGID=0x7;
    ECanaMboxes.MBOX6.MSGID.bit.IDE=0;
    ECanaMboxes.MBOX6.MSGID.bit.AAM=0;
    ECanaMboxes.MBOX6.MSGID.bit.AME=0;
    ECanaShadow.CANMD.all = ECanaRegs.CANMD.all;
    ECanaShadow.CANMD.bit.MD6 = 1;
    ECanaRegs.CANMD.all = ECanaShadow.CANMD.all;
    ECanaShadow.CANME.all = ECanaRegs.CANME.all;
    ECanaShadow.CANME.bit.ME6 = 1;
    ECanaRegs.CANME.all = ECanaShadow.CANME.all;
    ECanaMboxes.MBOX6.MSGCTRL.bit.DLC = 8;
    //**********************************************
    // mbox7-receive-bmb2bms-id8
    ECanaMboxes.MBOX7.MSGID.bit.STDMSGID=0x8;
    ECanaMboxes.MBOX7.MSGID.bit.IDE=0;
    ECanaMboxes.MBOX7.MSGID.bit.AAM=0;
    ECanaMboxes.MBOX7.MSGID.bit.AME=0;
    ECanaShadow.CANMD.all = ECanaRegs.CANMD.all;
    ECanaShadow.CANMD.bit.MD7 = 1;
    ECanaRegs.CANMD.all = ECanaShadow.CANMD.all;
    ECanaShadow.CANME.all = ECanaRegs.CANME.all;
    ECanaShadow.CANME.bit.ME7 = 1;
    ECanaRegs.CANME.all = ECanaShadow.CANME.all;
    ECanaMboxes.MBOX7.MSGCTRL.bit.DLC = 8;
    //**********************************************
    // mbox8-receive-bmb2bms-id9
    ECanaMboxes.MBOX8.MSGID.bit.STDMSGID=0x9;
    ECanaMboxes.MBOX8.MSGID.bit.IDE=0;
    ECanaMboxes.MBOX8.MSGID.bit.AAM=0;
    ECanaMboxes.MBOX8.MSGID.bit.AME=0;
    ECanaShadow.CANMD.all = ECanaRegs.CANMD.all;
    ECanaShadow.CANMD.bit.MD8 = 1;
    ECanaRegs.CANMD.all = ECanaShadow.CANMD.all;
    ECanaShadow.CANME.all = ECanaRegs.CANME.all;
    ECanaShadow.CANME.bit.ME8 = 1;
    ECanaRegs.CANME.all = ECanaShadow.CANME.all;
    ECanaMboxes.MBOX8.MSGCTRL.bit.DLC = 8;
    //**********************************************
    // mbox9-receive-bmb2bms-id10
    ECanaMboxes.MBOX9.MSGID.bit.STDMSGID=10;
    ECanaMboxes.MBOX9.MSGID.bit.IDE=0;
    ECanaMboxes.MBOX9.MSGID.bit.AAM=0;
    ECanaMboxes.MBOX9.MSGID.bit.AME=0;
    ECanaShadow.CANMD.all = ECanaRegs.CANMD.all;
    ECanaShadow.CANMD.bit.MD9 = 1;
    ECanaRegs.CANMD.all = ECanaShadow.CANMD.all;
    ECanaShadow.CANME.all = ECanaRegs.CANME.all;
    ECanaShadow.CANME.bit.ME9 = 1;
    ECanaRegs.CANME.all = ECanaShadow.CANME.all;
    ECanaMboxes.MBOX9.MSGCTRL.bit.DLC = 8;
    //**********************************************
    // mbox10-receive-bmb2bms-id11
    ECanaMboxes.MBOX10.MSGID.bit.STDMSGID=11;
    ECanaMboxes.MBOX10.MSGID.bit.IDE=0;
    ECanaMboxes.MBOX10.MSGID.bit.AAM=0;
    ECanaMboxes.MBOX10.MSGID.bit.AME=0;
    ECanaShadow.CANMD.all = ECanaRegs.CANMD.all;
    ECanaShadow.CANMD.bit.MD10 = 1;
    ECanaRegs.CANMD.all = ECanaShadow.CANMD.all;
    ECanaShadow.CANME.all = ECanaRegs.CANME.all;
    ECanaShadow.CANME.bit.ME10 = 1;
    ECanaRegs.CANME.all = ECanaShadow.CANME.all;
    ECanaMboxes.MBOX10.MSGCTRL.bit.DLC = 8;
    //**********************************************
    // mbox11-receive-bmb2bms-id12
    ECanaMboxes.MBOX11.MSGID.bit.STDMSGID=12;
    ECanaMboxes.MBOX11.MSGID.bit.IDE=0;
    ECanaMboxes.MBOX11.MSGID.bit.AAM=0;
    ECanaMboxes.MBOX11.MSGID.bit.AME=0;
    ECanaShadow.CANMD.all = ECanaRegs.CANMD.all;
    ECanaShadow.CANMD.bit.MD11 = 1;
    ECanaRegs.CANMD.all = ECanaShadow.CANMD.all;
    ECanaShadow.CANME.all = ECanaRegs.CANME.all;
    ECanaShadow.CANME.bit.ME11 = 1;
    ECanaRegs.CANME.all = ECanaShadow.CANME.all;
    ECanaMboxes.MBOX11.MSGCTRL.bit.DLC = 8;
    //**********************************************
    // mbox12-receive-bmb2bms-id13
    ECanaMboxes.MBOX12.MSGID.bit.STDMSGID=13;
    ECanaMboxes.MBOX12.MSGID.bit.IDE=0;
    ECanaMboxes.MBOX12.MSGID.bit.AAM=0;
    ECanaMboxes.MBOX12.MSGID.bit.AME=0;
    ECanaShadow.CANMD.all = ECanaRegs.CANMD.all;
    ECanaShadow.CANMD.bit.MD12 = 1;
    ECanaRegs.CANMD.all = ECanaShadow.CANMD.all;
    ECanaShadow.CANME.all = ECanaRegs.CANME.all;
    ECanaShadow.CANME.bit.ME12 = 1;
    ECanaRegs.CANME.all = ECanaShadow.CANME.all;
    ECanaMboxes.MBOX12.MSGCTRL.bit.DLC = 8;
    //**********************************************
    // mbox13-receive-bmb2bms-id14
    ECanaMboxes.MBOX13.MSGID.bit.STDMSGID=14;
    ECanaMboxes.MBOX13.MSGID.bit.IDE=0;
    ECanaMboxes.MBOX13.MSGID.bit.AAM=0;
    ECanaMboxes.MBOX13.MSGID.bit.AME=0;
    ECanaShadow.CANMD.all = ECanaRegs.CANMD.all;
    ECanaShadow.CANMD.bit.MD13 = 1;
    ECanaRegs.CANMD.all = ECanaShadow.CANMD.all;
    ECanaShadow.CANME.all = ECanaRegs.CANME.all;
    ECanaShadow.CANME.bit.ME13 = 1;
    ECanaRegs.CANME.all = ECanaShadow.CANME.all;
    ECanaMboxes.MBOX13.MSGCTRL.bit.DLC = 8;
    //**********************************************
    // mbox14-receive-bmb2bms-id15
    ECanaMboxes.MBOX14.MSGID.bit.STDMSGID=15;
    ECanaMboxes.MBOX14.MSGID.bit.IDE=0;
    ECanaMboxes.MBOX14.MSGID.bit.AAM=0;
    ECanaMboxes.MBOX14.MSGID.bit.AME=0;
    ECanaShadow.CANMD.all = ECanaRegs.CANMD.all;
    ECanaShadow.CANMD.bit.MD14 = 1;
    ECanaRegs.CANMD.all = ECanaShadow.CANMD.all;
    ECanaShadow.CANME.all = ECanaRegs.CANME.all;
    ECanaShadow.CANME.bit.ME14 = 1;
    ECanaRegs.CANME.all = ECanaShadow.CANME.all;
    ECanaMboxes.MBOX14.MSGCTRL.bit.DLC = 8;
    //**********************************************
    // mbox15-receive-bmb2bms-id16
    ECanaMboxes.MBOX15.MSGID.bit.STDMSGID=16;
    ECanaMboxes.MBOX15.MSGID.bit.IDE=0;
    ECanaMboxes.MBOX15.MSGID.bit.AAM=0;
    ECanaMboxes.MBOX15.MSGID.bit.AME=0;
    ECanaShadow.CANMD.all = ECanaRegs.CANMD.all;
    ECanaShadow.CANMD.bit.MD15 = 1;
    ECanaRegs.CANMD.all = ECanaShadow.CANMD.all;
    ECanaShadow.CANME.all = ECanaRegs.CANME.all;
    ECanaShadow.CANME.bit.ME15 = 1;
    ECanaRegs.CANME.all = ECanaShadow.CANME.all;
    ECanaMboxes.MBOX15.MSGCTRL.bit.DLC = 8;
    //**********************************************
    // mbox16-receive-bmb2bms-id17
    ECanaMboxes.MBOX16.MSGID.bit.STDMSGID=17;
    ECanaMboxes.MBOX16.MSGID.bit.IDE=0;
    ECanaMboxes.MBOX16.MSGID.bit.AAM=0;
    ECanaMboxes.MBOX16.MSGID.bit.AME=0;
    ECanaShadow.CANMD.all = ECanaRegs.CANMD.all;
    ECanaShadow.CANMD.bit.MD16 = 1;
    ECanaRegs.CANMD.all = ECanaShadow.CANMD.all;
    ECanaShadow.CANME.all = ECanaRegs.CANME.all;
    ECanaShadow.CANME.bit.ME16 = 1;
    ECanaRegs.CANME.all = ECanaShadow.CANME.all;
    ECanaMboxes.MBOX16.MSGCTRL.bit.DLC = 8;
    //**********************************************
    // mbox17-receive-bmb2bms-id18
    ECanaMboxes.MBOX17.MSGID.bit.STDMSGID=18;
    ECanaMboxes.MBOX17.MSGID.bit.IDE=0;
    ECanaMboxes.MBOX17.MSGID.bit.AAM=0;
    ECanaMboxes.MBOX17.MSGID.bit.AME=0;
    ECanaShadow.CANMD.all = ECanaRegs.CANMD.all;
    ECanaShadow.CANMD.bit.MD17 = 1;
    ECanaRegs.CANMD.all = ECanaShadow.CANMD.all;
    ECanaShadow.CANME.all = ECanaRegs.CANME.all;
    ECanaShadow.CANME.bit.ME17 = 1;
    ECanaRegs.CANME.all = ECanaShadow.CANME.all;
    ECanaMboxes.MBOX17.MSGCTRL.bit.DLC = 8;
    //**********************************************
    // mbox18-receive-bmb2bms-id19
    ECanaMboxes.MBOX18.MSGID.bit.STDMSGID=19;
    ECanaMboxes.MBOX18.MSGID.bit.IDE=0;
    ECanaMboxes.MBOX18.MSGID.bit.AAM=0;
    ECanaMboxes.MBOX18.MSGID.bit.AME=0;
    ECanaShadow.CANMD.all = ECanaRegs.CANMD.all;
    ECanaShadow.CANMD.bit.MD18 = 1;
    ECanaRegs.CANMD.all = ECanaShadow.CANMD.all;
    ECanaShadow.CANME.all = ECanaRegs.CANME.all;
    ECanaShadow.CANME.bit.ME18 = 1;
    ECanaRegs.CANME.all = ECanaShadow.CANME.all;
    ECanaMboxes.MBOX18.MSGCTRL.bit.DLC = 8;
    //**********************************************
    // mbox19-receive-bmb2bms-id20
    ECanaMboxes.MBOX19.MSGID.bit.STDMSGID=20;
    ECanaMboxes.MBOX19.MSGID.bit.IDE=0;
    ECanaMboxes.MBOX19.MSGID.bit.AAM=0;
    ECanaMboxes.MBOX19.MSGID.bit.AME=0;
    ECanaShadow.CANMD.all = ECanaRegs.CANMD.all;
    ECanaShadow.CANMD.bit.MD19 = 1;
    ECanaRegs.CANMD.all = ECanaShadow.CANMD.all;
    ECanaShadow.CANME.all = ECanaRegs.CANME.all;
    ECanaShadow.CANME.bit.ME19 = 1;
    ECanaRegs.CANME.all = ECanaShadow.CANME.all;
    ECanaMboxes.MBOX19.MSGCTRL.bit.DLC = 8;
    //**********************************************
    // mbox20-receive-bmb2bms-id21
    ECanaMboxes.MBOX20.MSGID.bit.STDMSGID=21;
    ECanaMboxes.MBOX20.MSGID.bit.IDE=0;
    ECanaMboxes.MBOX20.MSGID.bit.AAM=0;
    ECanaMboxes.MBOX20.MSGID.bit.AME=0;
    ECanaShadow.CANMD.all = ECanaRegs.CANMD.all;
    ECanaShadow.CANMD.bit.MD20 = 1;
    ECanaRegs.CANMD.all = ECanaShadow.CANMD.all;
    ECanaShadow.CANME.all = ECanaRegs.CANME.all;
    ECanaShadow.CANME.bit.ME20 = 1;
    ECanaRegs.CANME.all = ECanaShadow.CANME.all;
    ECanaMboxes.MBOX20.MSGCTRL.bit.DLC = 8;
    //**********************************************
    // mbox21-receive-bmb2bms-id22
    ECanaMboxes.MBOX21.MSGID.bit.STDMSGID=22;
    ECanaMboxes.MBOX21.MSGID.bit.IDE=0;
    ECanaMboxes.MBOX21.MSGID.bit.AAM=0;
    ECanaMboxes.MBOX21.MSGID.bit.AME=0;
    ECanaShadow.CANMD.all = ECanaRegs.CANMD.all;
    ECanaShadow.CANMD.bit.MD21 = 1;
    ECanaRegs.CANMD.all = ECanaShadow.CANMD.all;
    ECanaShadow.CANME.all = ECanaRegs.CANME.all;
    ECanaShadow.CANME.bit.ME21 = 1;
    ECanaRegs.CANME.all = ECanaShadow.CANME.all;
    ECanaMboxes.MBOX21.MSGCTRL.bit.DLC = 8;
    //**********************************************
    // mbox22-receive-bmb2bms-id23
    ECanaMboxes.MBOX22.MSGID.bit.STDMSGID=23;
    ECanaMboxes.MBOX22.MSGID.bit.IDE=0;
    ECanaMboxes.MBOX22.MSGID.bit.AAM=0;
    ECanaMboxes.MBOX22.MSGID.bit.AME=0;
    ECanaShadow.CANMD.all = ECanaRegs.CANMD.all;
    ECanaShadow.CANMD.bit.MD22 = 1;
    ECanaRegs.CANMD.all = ECanaShadow.CANMD.all;
    ECanaShadow.CANME.all = ECanaRegs.CANME.all;
    ECanaShadow.CANME.bit.ME22 = 1;
    ECanaRegs.CANME.all = ECanaShadow.CANME.all;
    ECanaMboxes.MBOX22.MSGCTRL.bit.DLC = 8;
    //**********************************************
    // mbox23-receive-bmb2bms-id24
    ECanaMboxes.MBOX23.MSGID.bit.STDMSGID=24;
    ECanaMboxes.MBOX23.MSGID.bit.IDE=0;
    ECanaMboxes.MBOX23.MSGID.bit.AAM=0;
    ECanaMboxes.MBOX23.MSGID.bit.AME=0;
    ECanaShadow.CANMD.all = ECanaRegs.CANMD.all;
    ECanaShadow.CANMD.bit.MD23 = 1;
    ECanaRegs.CANMD.all = ECanaShadow.CANMD.all;
    ECanaShadow.CANME.all = ECanaRegs.CANME.all;
    ECanaShadow.CANME.bit.ME23 = 1;
    ECanaRegs.CANME.all = ECanaShadow.CANME.all;
    ECanaMboxes.MBOX23.MSGCTRL.bit.DLC = 8;
    //**********************************************
    // mbox24-receive-bmb2bms-id25
    ECanaMboxes.MBOX24.MSGID.bit.STDMSGID=25;
    ECanaMboxes.MBOX24.MSGID.bit.IDE=0;
    ECanaMboxes.MBOX24.MSGID.bit.AAM=0;
    ECanaMboxes.MBOX24.MSGID.bit.AME=0;
    ECanaShadow.CANMD.all = ECanaRegs.CANMD.all;
    ECanaShadow.CANMD.bit.MD24 = 1;
    ECanaRegs.CANMD.all = ECanaShadow.CANMD.all;
    ECanaShadow.CANME.all = ECanaRegs.CANME.all;
    ECanaShadow.CANME.bit.ME24 = 1;
    ECanaRegs.CANME.all = ECanaShadow.CANME.all;
    ECanaMboxes.MBOX24.MSGCTRL.bit.DLC = 8;
    //**********************************************
    // mbox25-receive-bmb2bms-id26
    ECanaMboxes.MBOX25.MSGID.bit.STDMSGID=26;
    ECanaMboxes.MBOX25.MSGID.bit.IDE=0;
    ECanaMboxes.MBOX25.MSGID.bit.AAM=0;
    ECanaMboxes.MBOX25.MSGID.bit.AME=0;
    ECanaShadow.CANMD.all = ECanaRegs.CANMD.all;
    ECanaShadow.CANMD.bit.MD25 = 1;
    ECanaRegs.CANMD.all = ECanaShadow.CANMD.all;
    ECanaShadow.CANME.all = ECanaRegs.CANME.all;
    ECanaShadow.CANME.bit.ME25 = 1;
    ECanaRegs.CANME.all = ECanaShadow.CANME.all;
    ECanaMboxes.MBOX25.MSGCTRL.bit.DLC = 8;
    //**********************************************
    // mbox26-receive-bmb2bms-id26
    ECanaMboxes.MBOX26.MSGID.bit.STDMSGID=27;
    ECanaMboxes.MBOX26.MSGID.bit.IDE=0;
    ECanaMboxes.MBOX26.MSGID.bit.AAM=0;
    ECanaMboxes.MBOX26.MSGID.bit.AME=0;
    ECanaShadow.CANMD.all = ECanaRegs.CANMD.all;
    ECanaShadow.CANMD.bit.MD26 = 1;
    ECanaRegs.CANMD.all = ECanaShadow.CANMD.all;
    ECanaShadow.CANME.all = ECanaRegs.CANME.all;
    ECanaShadow.CANME.bit.ME26 = 1;
    ECanaRegs.CANME.all = ECanaShadow.CANME.all;
    ECanaMboxes.MBOX26.MSGCTRL.bit.DLC = 8;
    //**********************************************
    // mbox27-receive-bmb2bms-id26
    ECanaMboxes.MBOX27.MSGID.bit.STDMSGID=28;
    ECanaMboxes.MBOX27.MSGID.bit.IDE=0;
    ECanaMboxes.MBOX27.MSGID.bit.AAM=0;
    ECanaMboxes.MBOX27.MSGID.bit.AME=0;
    ECanaShadow.CANMD.all = ECanaRegs.CANMD.all;
    ECanaShadow.CANMD.bit.MD27 = 1;
    ECanaRegs.CANMD.all = ECanaShadow.CANMD.all;
    ECanaShadow.CANME.all = ECanaRegs.CANME.all;
    ECanaShadow.CANME.bit.ME27 = 1;
    ECanaRegs.CANME.all = ECanaShadow.CANME.all;
    ECanaMboxes.MBOX27.MSGCTRL.bit.DLC = 8;

    //**********************************************
    // mbox28-receive-bmb2bms-id26
    ECanaMboxes.MBOX28.MSGID.bit.STDMSGID=29;
    ECanaMboxes.MBOX28.MSGID.bit.IDE=0;
    ECanaMboxes.MBOX28.MSGID.bit.AAM=0;
    ECanaMboxes.MBOX28.MSGID.bit.AME=0;
    ECanaShadow.CANMD.all = ECanaRegs.CANMD.all;
    ECanaShadow.CANMD.bit.MD28 = 1;
    ECanaRegs.CANMD.all = ECanaShadow.CANMD.all;
    ECanaShadow.CANME.all = ECanaRegs.CANME.all;
    ECanaShadow.CANME.bit.ME28 = 1;
    ECanaRegs.CANME.all = ECanaShadow.CANME.all;
    ECanaMboxes.MBOX28.MSGCTRL.bit.DLC = 8;
    //**********************************************
    // mbox29-receive-bmb2bms-id26
    ECanaMboxes.MBOX29.MSGID.bit.STDMSGID=30;
    ECanaMboxes.MBOX29.MSGID.bit.IDE=0;
    ECanaMboxes.MBOX29.MSGID.bit.AAM=0;
    ECanaMboxes.MBOX29.MSGID.bit.AME=0;
    ECanaShadow.CANMD.all = ECanaRegs.CANMD.all;
    ECanaShadow.CANMD.bit.MD29 = 1;
    ECanaRegs.CANMD.all = ECanaShadow.CANMD.all;
    ECanaShadow.CANME.all = ECanaRegs.CANME.all;
    ECanaShadow.CANME.bit.ME29 = 1;
    ECanaRegs.CANME.all = ECanaShadow.CANME.all;
    ECanaMboxes.MBOX29.MSGCTRL.bit.DLC = 8;
    //**********************************************
    // mbox30-receive-bmb2bms-id26
    ECanaMboxes.MBOX30.MSGID.bit.STDMSGID=31;
    ECanaMboxes.MBOX30.MSGID.bit.IDE=0;
    ECanaMboxes.MBOX30.MSGID.bit.AAM=0;
    ECanaMboxes.MBOX30.MSGID.bit.AME=0;
    ECanaShadow.CANMD.all = ECanaRegs.CANMD.all;
    ECanaShadow.CANMD.bit.MD30 = 1;
    ECanaRegs.CANMD.all = ECanaShadow.CANMD.all;
    ECanaShadow.CANME.all = ECanaRegs.CANME.all;
    ECanaShadow.CANME.bit.ME30 = 1;
    ECanaRegs.CANME.all = ECanaShadow.CANME.all;
    ECanaMboxes.MBOX30.MSGCTRL.bit.DLC = 8;

}
void b_CAN_sending_transmit_mailbox(void){


    LED4_TOGGLE;

    ECanbMboxes.MBOX1.MDL.byte.BYTE0 = CAN_Y.Measurement1.Data[0];
    ECanbMboxes.MBOX1.MDL.byte.BYTE1 = CAN_Y.Measurement1.Data[1];
    ECanbMboxes.MBOX1.MDL.byte.BYTE2 = CAN_Y.Measurement1.Data[2];
    ECanbMboxes.MBOX1.MDL.byte.BYTE3 = CAN_Y.Measurement1.Data[3];
    ECanbMboxes.MBOX1.MDH.byte.BYTE4 = CAN_Y.Measurement1.Data[4];
    ECanbMboxes.MBOX1.MDH.byte.BYTE5 = CAN_Y.Measurement1.Data[5];
    ECanbMboxes.MBOX1.MDH.byte.BYTE6 = CAN_Y.Measurement1.Data[6];
    ECanbMboxes.MBOX1.MDH.byte.BYTE7 = CAN_Y.Measurement1.Data[7];

    ECanbMboxes.MBOX2.MDL.byte.BYTE0= CAN_Y.Measurement2.Data[0];
    ECanbMboxes.MBOX2.MDL.byte.BYTE1= CAN_Y.Measurement2.Data[1];
    ECanbMboxes.MBOX2.MDL.byte.BYTE2= CAN_Y.Measurement2.Data[2];
    ECanbMboxes.MBOX2.MDL.byte.BYTE3= CAN_Y.Measurement2.Data[3];
    ECanbMboxes.MBOX2.MDH.byte.BYTE4= CAN_Y.Measurement2.Data[4];
    ECanbMboxes.MBOX2.MDH.byte.BYTE5= CAN_Y.Measurement2.Data[5];
    ECanbMboxes.MBOX2.MDH.byte.BYTE6= CAN_Y.Measurement2.Data[6];
    ECanbMboxes.MBOX2.MDH.byte.BYTE7= CAN_Y.Measurement2.Data[7];

    ECanbMboxes.MBOX3.MDL.byte.BYTE0= CAN_Y.Estimation1.Data[0];
    ECanbMboxes.MBOX3.MDL.byte.BYTE1= CAN_Y.Estimation1.Data[1];
    ECanbMboxes.MBOX3.MDL.byte.BYTE2= CAN_Y.Estimation1.Data[2];
    ECanbMboxes.MBOX3.MDL.byte.BYTE3= CAN_Y.Estimation1.Data[3];
    ECanbMboxes.MBOX3.MDH.byte.BYTE4= CAN_Y.Estimation1.Data[4];
    ECanbMboxes.MBOX3.MDH.byte.BYTE5= CAN_Y.Estimation1.Data[5];
    ECanbMboxes.MBOX3.MDH.byte.BYTE6= CAN_Y.Estimation1.Data[6];
    ECanbMboxes.MBOX3.MDH.byte.BYTE7= CAN_Y.Estimation1.Data[7];

    ECanbMboxes.MBOX4.MDL.byte.BYTE0= CAN_Y.Estimation2.Data[0];
    ECanbMboxes.MBOX4.MDL.byte.BYTE1= CAN_Y.Estimation2.Data[1];
    ECanbMboxes.MBOX4.MDL.byte.BYTE2= CAN_Y.Estimation2.Data[2];
    ECanbMboxes.MBOX4.MDL.byte.BYTE3= CAN_Y.Estimation2.Data[3];
    ECanbMboxes.MBOX4.MDH.byte.BYTE4= CAN_Y.Estimation2.Data[4];
    ECanbMboxes.MBOX4.MDH.byte.BYTE5= CAN_Y.Estimation2.Data[5];
    ECanbMboxes.MBOX4.MDH.byte.BYTE6= CAN_Y.Estimation2.Data[6];
    ECanbMboxes.MBOX4.MDH.byte.BYTE7= CAN_Y.Estimation2.Data[7];


    ECanbMboxes.MBOX5.MDL.byte.BYTE0= CAN_Y.Fault.Data[0];
    ECanbMboxes.MBOX5.MDL.byte.BYTE1= CAN_Y.Fault.Data[1];
    ECanbMboxes.MBOX5.MDL.byte.BYTE2= CAN_Y.Fault.Data[2];
    ECanbMboxes.MBOX5.MDL.byte.BYTE3= CAN_Y.Fault.Data[3];
    ECanbMboxes.MBOX5.MDH.byte.BYTE4= CAN_Y.Fault.Data[4];
    ECanbMboxes.MBOX5.MDH.byte.BYTE5= CAN_Y.Fault.Data[5];
    ECanbMboxes.MBOX5.MDH.byte.BYTE6= CAN_Y.Fault.Data[6];
    ECanbMboxes.MBOX5.MDH.byte.BYTE7= CAN_Y.Fault.Data[7];


//status
    ECanbMboxes.MBOX6.MDL.byte.BYTE0= CAN_Y.Status.Data[0];
    ECanbMboxes.MBOX6.MDL.byte.BYTE1= CAN_Y.Status.Data[1];
    ECanbMboxes.MBOX6.MDL.byte.BYTE2= CAN_Y.Status.Data[2];
    ECanbMboxes.MBOX6.MDL.byte.BYTE3= CAN_Y.Status.Data[3];
    ECanbMboxes.MBOX6.MDH.byte.BYTE4= CAN_Y.Status.Data[4];
    ECanbMboxes.MBOX6.MDH.byte.BYTE5= CAN_Y.Status.Data[5];
    ECanbMboxes.MBOX6.MDH.byte.BYTE6= CAN_Y.Status.Data[6];
    ECanbMboxes.MBOX6.MDH.byte.BYTE7= CAN_Y.Status.Data[7];

//diagnosis
    ECanbMboxes.MBOX7.MDL.byte.BYTE0= CAN_Y.Diagnosis.Data[0];
    ECanbMboxes.MBOX7.MDL.byte.BYTE1= CAN_Y.Diagnosis.Data[1];
    ECanbMboxes.MBOX7.MDL.byte.BYTE2= CAN_Y.Diagnosis.Data[2];
    ECanbMboxes.MBOX7.MDL.byte.BYTE3= CAN_Y.Diagnosis.Data[3];
    ECanbMboxes.MBOX7.MDH.byte.BYTE4= CAN_Y.Diagnosis.Data[4];
    ECanbMboxes.MBOX7.MDH.byte.BYTE5= CAN_Y.Diagnosis.Data[5];
    ECanbMboxes.MBOX7.MDH.byte.BYTE6= CAN_Y.Diagnosis.Data[6];
    ECanbMboxes.MBOX7.MDH.byte.BYTE7= CAN_Y.Diagnosis.Data[7];


    ECanbMboxes.MBOX9.MDL.byte.BYTE0= CAN_Y.THC1.Data[0];
    ECanbMboxes.MBOX9.MDL.byte.BYTE1= CAN_Y.THC1.Data[1];
    ECanbMboxes.MBOX9.MDL.byte.BYTE2= CAN_Y.THC1.Data[2];
    ECanbMboxes.MBOX9.MDL.byte.BYTE3= CAN_Y.THC1.Data[3];
    ECanbMboxes.MBOX9.MDH.byte.BYTE4= CAN_Y.THC1.Data[4];
    ECanbMboxes.MBOX9.MDH.byte.BYTE5= CAN_Y.THC1.Data[5];
    ECanbMboxes.MBOX9.MDH.byte.BYTE6= CAN_Y.THC1.Data[6];
    ECanbMboxes.MBOX9.MDH.byte.BYTE7= CAN_Y.THC1.Data[7];

    ECanbMboxes.MBOX10.MDL.byte.BYTE0= CAN_Y.THC2.Data[0];
    ECanbMboxes.MBOX10.MDL.byte.BYTE1= CAN_Y.THC2.Data[1];
    ECanbMboxes.MBOX10.MDL.byte.BYTE2= CAN_Y.THC2.Data[2];
    ECanbMboxes.MBOX10.MDL.byte.BYTE3= CAN_Y.THC2.Data[3];
    ECanbMboxes.MBOX10.MDH.byte.BYTE4= CAN_Y.THC2.Data[4];
    ECanbMboxes.MBOX10.MDH.byte.BYTE5= CAN_Y.THC2.Data[5];
    ECanbMboxes.MBOX10.MDH.byte.BYTE6= CAN_Y.THC2.Data[6];
    ECanbMboxes.MBOX10.MDH.byte.BYTE7= CAN_Y.THC2.Data[7];


    ECanbMboxes.MBOX11.MDL.byte.BYTE0= CAN_Y.THC3.Data[0];
    ECanbMboxes.MBOX11.MDL.byte.BYTE1= CAN_Y.THC3.Data[1];
    ECanbMboxes.MBOX11.MDL.byte.BYTE2= CAN_Y.THC3.Data[2];
    ECanbMboxes.MBOX11.MDL.byte.BYTE3= CAN_Y.THC3.Data[3];
    ECanbMboxes.MBOX11.MDH.byte.BYTE4= CAN_Y.THC3.Data[4];
    ECanbMboxes.MBOX11.MDH.byte.BYTE5= CAN_Y.THC3.Data[5];
    ECanbMboxes.MBOX11.MDH.byte.BYTE6= CAN_Y.THC3.Data[6];
    ECanbMboxes.MBOX11.MDH.byte.BYTE7= CAN_Y.THC3.Data[7];


//// Mbox 1 sending DATA
ECanbShadow.CANTRS.all=ECanbRegs.CANTRS.all;
ECanbShadow.CANTRS.bit.TRS1=1;
ECanbRegs.CANTRS.all=ECanbShadow.CANTRS.all;

//// Mbox 2 sending DATA
ECanbShadow.CANTRS.all=ECanbRegs.CANTRS.all;
ECanbShadow.CANTRS.bit.TRS2=1;
ECanbRegs.CANTRS.all=ECanbShadow.CANTRS.all;
//// Mbox 1 sending DATA

ECanbShadow.CANTRS.all=ECanbRegs.CANTRS.all;
ECanbShadow.CANTRS.bit.TRS3=1;
ECanbRegs.CANTRS.all=ECanbShadow.CANTRS.all;

//// Mbox 1 sending DATA
ECanbShadow.CANTRS.all=ECanbRegs.CANTRS.all;
ECanbShadow.CANTRS.bit.TRS5=1;
ECanbRegs.CANTRS.all=ECanbShadow.CANTRS.all;

ECanbShadow.CANTRS.all=ECanbRegs.CANTRS.all;
ECanbShadow.CANTRS.bit.TRS7=1;
ECanbRegs.CANTRS.all=ECanbShadow.CANTRS.all;


//thc


if(t1sFlag == 1){
    t1sFlag = 0;



    ECanbShadow.CANTRS.all=ECanbRegs.CANTRS.all;
    ECanbShadow.CANTRS.bit.TRS9=1;
    ECanbRegs.CANTRS.all=ECanbShadow.CANTRS.all;

    ECanbShadow.CANTRS.all=ECanbRegs.CANTRS.all;
    ECanbShadow.CANTRS.bit.TRS10=1;
    ECanbRegs.CANTRS.all=ECanbShadow.CANTRS.all;

    ECanbShadow.CANTRS.all=ECanbRegs.CANTRS.all;
    ECanbShadow.CANTRS.bit.TRS11=1;
    ECanbRegs.CANTRS.all=ECanbShadow.CANTRS.all;

ECanbShadow.CANTRS.all=ECanbRegs.CANTRS.all;
ECanbShadow.CANTRS.bit.TRS6=1;
ECanbRegs.CANTRS.all=ECanbShadow.CANTRS.all;

//// Mbox 1 sending DATA
ECanbShadow.CANTRS.all=ECanbRegs.CANTRS.all;
ECanbShadow.CANTRS.bit.TRS4=1;
ECanbRegs.CANTRS.all=ECanbShadow.CANTRS.all;

}







}

void a_CAN_sending_transmit_mailbox(void){

    ECanaMboxes.MBOX0.MDL.byte.BYTE0 = CANBMB_Y.balaner1.Data[0];
    ECanaMboxes.MBOX0.MDL.byte.BYTE1 = CANBMB_Y.balaner1.Data[1];
    ECanaMboxes.MBOX0.MDL.byte.BYTE2 = CANBMB_Y.balaner1.Data[2];
    ECanaMboxes.MBOX0.MDL.byte.BYTE3 = CANBMB_Y.balaner1.Data[3];
    ECanaMboxes.MBOX0.MDH.byte.BYTE4 = CANBMB_Y.balaner1.Data[4];
    ECanaMboxes.MBOX0.MDH.byte.BYTE5 = CANBMB_Y.balaner1.Data[5];
    ECanaMboxes.MBOX0.MDH.byte.BYTE6 = CANBMB_Y.balaner1.Data[6];
    ECanaMboxes.MBOX0.MDH.byte.BYTE7 = CANBMB_Y.balaner1.Data[7];

    ECanaMboxes.MBOX1.MDL.byte.BYTE0 = CANBMB_Y.balaner2.Data[0];
    ECanaMboxes.MBOX1.MDL.byte.BYTE1 = CANBMB_Y.balaner2.Data[1];
    ECanaMboxes.MBOX1.MDL.byte.BYTE2 = CANBMB_Y.balaner2.Data[2];
    ECanaMboxes.MBOX1.MDL.byte.BYTE3 = CANBMB_Y.balaner2.Data[3];
    ECanaMboxes.MBOX1.MDH.byte.BYTE4 = CANBMB_Y.balaner2.Data[4];
    ECanaMboxes.MBOX1.MDH.byte.BYTE5 = CANBMB_Y.balaner2.Data[5];
    ECanaMboxes.MBOX1.MDH.byte.BYTE6 = CANBMB_Y.balaner2.Data[6];
    ECanaMboxes.MBOX1.MDH.byte.BYTE7 = CANBMB_Y.balaner2.Data[7];

    //// Mbox 0 sending DATA
    ECanaShadow.CANTRS.all=ECanaRegs.CANTRS.all;
    ECanaShadow.CANTRS.bit.TRS0=1;
    ECanaRegs.CANTRS.all=ECanaShadow.CANTRS.all;

    //// Mbox 1 sending DATA
    ECanaShadow.CANTRS.all=ECanaRegs.CANTRS.all;
    ECanaShadow.CANTRS.bit.TRS1=1;
    ECanaRegs.CANTRS.all=ECanaShadow.CANTRS.all;
}



void VCU_CAN_init(void){
      /////CAN  Configuratin

    InitECanbGpio();
    InitECanaGpio();
    InitECanb();
    InitECana();
    b_Mailbox_configuration_Settings();
    a_Mailbox_configuration_Settings();
    }

void VCU_CAN_TaskManager(Uint32 PC){
        if(PC%10==0){
            if(ECanbRegs.CANRMP.all !=0){
                b_Flag.bit.processing_received_mailbox=1;
            }
            if(ECanaRegs.CANRMP.all !=0){
                a_Flag.bit.processing_received_mailbox=1;
            }

            if(PC%200==0){

                b_Flag.bit.sending_transmit_mailbox=1;
             }
            if(PC%10000==10){
                 t1sFlag=1;
             }
            if(PC%2500==0){
                a_Flag.bit.sending_transmit_mailbox=1;
            }
        }
}


void Fast_charge_CAN_Function(void){

    //SIF received from EVCC
    if(ECanbRegs.CANRMP.bit.RMP12){
        ECanbRegs.CANRMP.bit.RMP12 = 1;
/*
        ChargeAl_U.CAN_Input_i.SIF.Flag = 1;

        ChargeAl_U.CAN_Input_i.SIF.Data[0] = ECanbMboxes.MBOX12.MDL.byte.BYTE0;
        ChargeAl_U.CAN_Input_i.SIF.Data[1] = ECanbMboxes.MBOX12.MDL.byte.BYTE1;
        ChargeAl_U.CAN_Input_i.SIF.Data[2] = ECanbMboxes.MBOX12.MDL.byte.BYTE2;
        ChargeAl_U.CAN_Input_i.SIF.Data[3] = ECanbMboxes.MBOX12.MDL.byte.BYTE3;
        ChargeAl_U.CAN_Input_i.SIF.Data[4] = ECanbMboxes.MBOX12.MDH.byte.BYTE4;
        ChargeAl_U.CAN_Input_i.SIF.Data[5] = ECanbMboxes.MBOX12.MDH.byte.BYTE5;
        ChargeAl_U.CAN_Input_i.SIF.Data[6] = ECanbMboxes.MBOX12.MDH.byte.BYTE6;
        ChargeAl_U.CAN_Input_i.SIF.Data[7] = ECanbMboxes.MBOX12.MDH.byte.BYTE7;

        */
    }

    //CHM received from EVCC
    if(ECanbRegs.CANRMP.bit.RMP13){
        ECanbRegs.CANRMP.bit.RMP13 = 1;

        ChargeAl_U.CAN_Input_d.CHM.Flag = 1;



        ECanbMboxes.MBOX19.MDL.byte.BYTE0 = ChargeAl_Y.BHM_l.Data[0];
                ECanbMboxes.MBOX19.MDL.byte.BYTE1 = ChargeAl_Y.BHM_l.Data[1];
                ECanbMboxes.MBOX19.MDL.byte.BYTE2 = ChargeAl_Y.BHM_l.Data[2];
                ECanbMboxes.MBOX19.MDL.byte.BYTE3 = ChargeAl_Y.BHM_l.Data[3];
                ECanbMboxes.MBOX19.MDH.byte.BYTE4 = ChargeAl_Y.BHM_l.Data[4];
                ECanbMboxes.MBOX19.MDH.byte.BYTE5 = ChargeAl_Y.BHM_l.Data[5];
                ECanbMboxes.MBOX19.MDH.byte.BYTE6 = ChargeAl_Y.BHM_l.Data[6];
                ECanbMboxes.MBOX19.MDH.byte.BYTE7 = ChargeAl_Y.BHM_l.Data[7];
                ChargeAl_Y.CAN_Output_p.BHM.Flag = 0;

                ECanbShadow.CANTRS.all=ECanbRegs.CANTRS.all;
                ECanbShadow.CANTRS.bit.TRS19=1;
                ECanbRegs.CANTRS.all=ECanbShadow.CANTRS.all;
        /*
        ChargeAl_U.CAN_Input_i.CHM.Data[0] = ECanbMboxes.MBOX13.MDL.byte.BYTE0;
        ChargeAl_U.CAN_Input_i.CHM.Data[1] = ECanbMboxes.MBOX13.MDL.byte.BYTE1;
        ChargeAl_U.CAN_Input_i.CHM.Data[2] = ECanbMboxes.MBOX13.MDL.byte.BYTE2;
        ChargeAl_U.CAN_Input_i.CHM.Data[3] = ECanbMboxes.MBOX13.MDL.byte.BYTE3;
        ChargeAl_U.CAN_Input_i.CHM.Data[4] = ECanbMboxes.MBOX13.MDH.byte.BYTE4;
        ChargeAl_U.CAN_Input_i.CHM.Data[5] = ECanbMboxes.MBOX13.MDH.byte.BYTE5;
        ChargeAl_U.CAN_Input_i.CHM.Data[6] = ECanbMboxes.MBOX13.MDH.byte.BYTE6;
        ChargeAl_U.CAN_Input_i.CHM.Data[7] = ECanbMboxes.MBOX13.MDH.byte.BYTE7;
        */

    }

    //CRM received from EVCC
    if(ECanbRegs.CANRMP.bit.RMP14){
        ECanbRegs.CANRMP.bit.RMP14 = 1;

        ChargeAl_U.CAN_Input_d.CHM.Flag = 1;


        /*
        ChargeAl_U.CAN_Input_i.CRM.Data[0] = ECanbMboxes.MBOX14.MDL.byte.BYTE0;
        ChargeAl_U.CAN_Input_i.CRM.Data[1] = ECanbMboxes.MBOX14.MDL.byte.BYTE1;
        ChargeAl_U.CAN_Input_i.CRM.Data[2] = ECanbMboxes.MBOX14.MDL.byte.BYTE2;
        ChargeAl_U.CAN_Input_i.CRM.Data[3] = ECanbMboxes.MBOX14.MDL.byte.BYTE3;
        ChargeAl_U.CAN_Input_i.CRM.Data[4] = ECanbMboxes.MBOX14.MDH.byte.BYTE4;
        ChargeAl_U.CAN_Input_i.CRM.Data[5] = ECanbMboxes.MBOX14.MDH.byte.BYTE5;
        ChargeAl_U.CAN_Input_i.CRM.Data[6] = ECanbMboxes.MBOX14.MDH.byte.BYTE6;
        ChargeAl_U.CAN_Input_i.CRM.Data[7] = ECanbMboxes.MBOX14.MDH.byte.BYTE7;
*/
    }

    //CML received from EVCC
    if(ECanbRegs.CANRMP.bit.RMP15){
        ECanbRegs.CANRMP.bit.RMP15 = 1;
/*
        ChargeAl_U.CAN_Input_i.CML.Flag = 1;
        ChargeAl_U.CAN_Input_i.CML.Data[0] = ECanbMboxes.MBOX15.MDL.byte.BYTE0;
        ChargeAl_U.CAN_Input_i.CML.Data[1] = ECanbMboxes.MBOX15.MDL.byte.BYTE1;
        ChargeAl_U.CAN_Input_i.CML.Data[2] = ECanbMboxes.MBOX15.MDL.byte.BYTE2;
        ChargeAl_U.CAN_Input_i.CML.Data[3] = ECanbMboxes.MBOX15.MDL.byte.BYTE3;
        ChargeAl_U.CAN_Input_i.CML.Data[4] = ECanbMboxes.MBOX15.MDH.byte.BYTE4;
        ChargeAl_U.CAN_Input_i.CML.Data[5] = ECanbMboxes.MBOX15.MDH.byte.BYTE5;
        ChargeAl_U.CAN_Input_i.CML.Data[6] = ECanbMboxes.MBOX15.MDH.byte.BYTE6;
        ChargeAl_U.CAN_Input_i.CML.Data[7] = ECanbMboxes.MBOX15.MDH.byte.BYTE7;
*/
    }
    //CTS received from EVCC
    if(ECanbRegs.CANRMP.bit.RMP16){
        ECanbRegs.CANRMP.bit.RMP16 = 1;

/*
        ChargeAl_U.CAN_Input_i.CTS.Flag = 1;
        ChargeAl_U.CAN_Input_i.CTS.Data[0] = ECanbMboxes.MBOX16.MDL.byte.BYTE0;
        ChargeAl_U.CAN_Input_i.CTS.Data[1] = ECanbMboxes.MBOX16.MDL.byte.BYTE1;
        ChargeAl_U.CAN_Input_i.CTS.Data[2] = ECanbMboxes.MBOX16.MDL.byte.BYTE2;
        ChargeAl_U.CAN_Input_i.CTS.Data[3] = ECanbMboxes.MBOX16.MDL.byte.BYTE3;
        ChargeAl_U.CAN_Input_i.CTS.Data[4] = ECanbMboxes.MBOX16.MDH.byte.BYTE4;
        ChargeAl_U.CAN_Input_i.CTS.Data[5] = ECanbMboxes.MBOX16.MDH.byte.BYTE5;
        ChargeAl_U.CAN_Input_i.CTS.Data[6] = ECanbMboxes.MBOX16.MDH.byte.BYTE6;
        ChargeAl_U.CAN_Input_i.CTS.Data[7] = ECanbMboxes.MBOX16.MDH.byte.BYTE7;

*/
    }
    //CR0 received from EVCC
    if(ECanbRegs.CANRMP.bit.RMP17){
        ECanbRegs.CANRMP.bit.RMP17 = 1;

/*
        ChargeAl_U.CAN_Input_i.CR0.Flag = 1;
        ChargeAl_U.CAN_Input_i.CR0.Data[0] = ECanbMboxes.MBOX17.MDL.byte.BYTE0;
        ChargeAl_U.CAN_Input_i.CR0.Data[1] = ECanbMboxes.MBOX17.MDL.byte.BYTE1;
        ChargeAl_U.CAN_Input_i.CR0.Data[2] = ECanbMboxes.MBOX17.MDL.byte.BYTE2;
        ChargeAl_U.CAN_Input_i.CR0.Data[3] = ECanbMboxes.MBOX17.MDL.byte.BYTE3;
        ChargeAl_U.CAN_Input_i.CR0.Data[4] = ECanbMboxes.MBOX17.MDH.byte.BYTE4;
        ChargeAl_U.CAN_Input_i.CR0.Data[5] = ECanbMboxes.MBOX17.MDH.byte.BYTE5;
        ChargeAl_U.CAN_Input_i.CR0.Data[6] = ECanbMboxes.MBOX17.MDH.byte.BYTE6;
        ChargeAl_U.CAN_Input_i.CR0.Data[7] = ECanbMboxes.MBOX17.MDH.byte.BYTE7;
*/

    }
    //CCS received from EVCC
    if(ECanbRegs.CANRMP.bit.RMP18){
        ECanbRegs.CANRMP.bit.RMP18 = 1;

        /*
        ChargeAl_U.CAN_Input_i.CCS.Flag = 1;
        ChargeAl_U.CAN_Input_i.CCS.Data[0] = ECanbMboxes.MBOX18.MDL.byte.BYTE0;
        ChargeAl_U.CAN_Input_i.CCS.Data[1] = ECanbMboxes.MBOX18.MDL.byte.BYTE1;
        ChargeAl_U.CAN_Input_i.CCS.Data[2] = ECanbMboxes.MBOX18.MDL.byte.BYTE2;
        ChargeAl_U.CAN_Input_i.CCS.Data[3] = ECanbMboxes.MBOX18.MDL.byte.BYTE3;
        ChargeAl_U.CAN_Input_i.CCS.Data[4] = ECanbMboxes.MBOX18.MDH.byte.BYTE4;
        ChargeAl_U.CAN_Input_i.CCS.Data[5] = ECanbMboxes.MBOX18.MDH.byte.BYTE5;
        ChargeAl_U.CAN_Input_i.CCS.Data[6] = ECanbMboxes.MBOX18.MDH.byte.BYTE6;
        ChargeAl_U.CAN_Input_i.CCS.Data[7] = ECanbMboxes.MBOX18.MDH.byte.BYTE7;
*/
    }








}

void Fast_Charge_CAN_Output(void){

    //BHM
    if (ChargeAl_Y.CAN_Output_p.BHM.Flag){

        ECanbMboxes.MBOX19.MDL.byte.BYTE0 = ChargeAl_Y.BHM_l.Data[0];
        ECanbMboxes.MBOX19.MDL.byte.BYTE1 = ChargeAl_Y.BHM_l.Data[1];
        ECanbMboxes.MBOX19.MDL.byte.BYTE2 = ChargeAl_Y.BHM_l.Data[2];
        ECanbMboxes.MBOX19.MDL.byte.BYTE3 = ChargeAl_Y.BHM_l.Data[3];
        ECanbMboxes.MBOX19.MDH.byte.BYTE4 = ChargeAl_Y.BHM_l.Data[4];
        ECanbMboxes.MBOX19.MDH.byte.BYTE5 = ChargeAl_Y.BHM_l.Data[5];
        ECanbMboxes.MBOX19.MDH.byte.BYTE6 = ChargeAl_Y.BHM_l.Data[6];
        ECanbMboxes.MBOX19.MDH.byte.BYTE7 = ChargeAl_Y.BHM_l.Data[7];
        counterCHM++;
        ChargeAl_Y.CAN_Output_p.BHM.Flag = 0;

        ECanbShadow.CANTRS.all=ECanbRegs.CANTRS.all;
        ECanbShadow.CANTRS.bit.TRS19=1;
        ECanbRegs.CANTRS.all=ECanbShadow.CANTRS.all;

    }
/*
    //BRM
    if (ChargeAl_Y.CAN_Output_l.BRM.Flag){

        ECanbMboxes.MBOX20.MDL.byte.BYTE0 = ChargeAl_Y.BRM_m.Data[0];
        ECanbMboxes.MBOX20.MDL.byte.BYTE1 = ChargeAl_Y.BRM_m.Data[1];
        ECanbMboxes.MBOX20.MDL.byte.BYTE2 = ChargeAl_Y.BRM_m.Data[2];
        ECanbMboxes.MBOX20.MDL.byte.BYTE3 = ChargeAl_Y.BRM_m.Data[3];
        ECanbMboxes.MBOX20.MDH.byte.BYTE4 = ChargeAl_Y.BRM_m.Data[4];
        ECanbMboxes.MBOX20.MDH.byte.BYTE5 = ChargeAl_Y.BRM_m.Data[5];
        ECanbMboxes.MBOX20.MDH.byte.BYTE6 = ChargeAl_Y.BRM_m.Data[6];
        ECanbMboxes.MBOX20.MDH.byte.BYTE7 = ChargeAl_Y.BRM_m.Data[7];
        ChargeAl_Y.CAN_Output_l.BRM.Flag = 0;

        ECanbShadow.CANTRS.all=ECanbRegs.CANTRS.all;
        ECanbShadow.CANTRS.bit.TRS20=1;
        ECanbRegs.CANTRS.all=ECanbShadow.CANTRS.all;
    }



    //BCS
    if (ChargeAl_Y.CAN_Output_l.BCS.Flag){

        ECanbMboxes.MBOX21.MDL.byte.BYTE0 = ChargeAl_Y.BCS_c.Data[0];
        ECanbMboxes.MBOX21.MDL.byte.BYTE1 = ChargeAl_Y.BCS_c.Data[1];
        ECanbMboxes.MBOX21.MDL.byte.BYTE2 = ChargeAl_Y.BCS_c.Data[2];
        ECanbMboxes.MBOX21.MDL.byte.BYTE3 = ChargeAl_Y.BCS_c.Data[3];
        ECanbMboxes.MBOX21.MDH.byte.BYTE4 = ChargeAl_Y.BCS_c.Data[4];
        ECanbMboxes.MBOX21.MDH.byte.BYTE5 = ChargeAl_Y.BCS_c.Data[5];
        ECanbMboxes.MBOX21.MDH.byte.BYTE6 = ChargeAl_Y.BCS_c.Data[6];
        ECanbMboxes.MBOX21.MDH.byte.BYTE7 = ChargeAl_Y.BCS_c.Data[7];
        ChargeAl_Y.CAN_Output_l.BCS.Flag = 0;

        ECanbShadow.CANTRS.all=ECanbRegs.CANTRS.all;
        ECanbShadow.CANTRS.bit.TRS21=1;
        ECanbRegs.CANTRS.all=ECanbShadow.CANTRS.all;
    }

    //BSM
    if (ChargeAl_Y.CAN_Output_l.BSM.Flag){

        ECanbMboxes.MBOX22.MDL.byte.BYTE0 = ChargeAl_Y.BSM_b.Data[0];
        ECanbMboxes.MBOX22.MDL.byte.BYTE1 = ChargeAl_Y.BSM_b.Data[1];
        ECanbMboxes.MBOX22.MDL.byte.BYTE2 = ChargeAl_Y.BSM_b.Data[2];
        ECanbMboxes.MBOX22.MDL.byte.BYTE3 = ChargeAl_Y.BSM_b.Data[3];
        ECanbMboxes.MBOX22.MDH.byte.BYTE4 = ChargeAl_Y.BSM_b.Data[4];
        ECanbMboxes.MBOX22.MDH.byte.BYTE5 = ChargeAl_Y.BSM_b.Data[5];
        ECanbMboxes.MBOX22.MDH.byte.BYTE6 = ChargeAl_Y.BSM_b.Data[6];
        ECanbMboxes.MBOX22.MDH.byte.BYTE7 = ChargeAl_Y.BSM_b.Data[7];
        ChargeAl_Y.CAN_Output_l.BSM.Flag = 0;

        ECanbShadow.CANTRS.all=ECanbRegs.CANTRS.all;
        ECanbShadow.CANTRS.bit.TRS22=1;
        ECanbRegs.CANTRS.all=ECanbShadow.CANTRS.all;
    }

    //BSD
    if (ChargeAl_Y.CAN_Output_l.BSD.Flag){

        ECanbMboxes.MBOX23.MDL.byte.BYTE0 = ChargeAl_Y.BSD_a.Data[0];
        ECanbMboxes.MBOX23.MDL.byte.BYTE1 = ChargeAl_Y.BSD_a.Data[1];
        ECanbMboxes.MBOX23.MDL.byte.BYTE2 = ChargeAl_Y.BSD_a.Data[2];
        ECanbMboxes.MBOX23.MDL.byte.BYTE3 = ChargeAl_Y.BSD_a.Data[3];
        ECanbMboxes.MBOX23.MDH.byte.BYTE4 = ChargeAl_Y.BSD_a.Data[4];
        ECanbMboxes.MBOX23.MDH.byte.BYTE5 = ChargeAl_Y.BSD_a.Data[5];
        ECanbMboxes.MBOX23.MDH.byte.BYTE6 = ChargeAl_Y.BSD_a.Data[6];
        ECanbMboxes.MBOX23.MDH.byte.BYTE7 = ChargeAl_Y.BSD_a.Data[7];
        ChargeAl_Y.CAN_Output_l.BSD.Flag = 0;

        ECanbShadow.CANTRS.all=ECanbRegs.CANTRS.all;
        ECanbShadow.CANTRS.bit.TRS23=1;
        ECanbRegs.CANTRS.all=ECanbShadow.CANTRS.all;
    }
    //BCP
    if (ChargeAl_Y.CAN_Output_l.BCP.Flag){

        ECanbMboxes.MBOX24.MDL.byte.BYTE0 = ChargeAl_Y.BCP_d.Data[0];
        ECanbMboxes.MBOX24.MDL.byte.BYTE1 = ChargeAl_Y.BCP_d.Data[1];
        ECanbMboxes.MBOX24.MDL.byte.BYTE2 = ChargeAl_Y.BCP_d.Data[2];
        ECanbMboxes.MBOX24.MDL.byte.BYTE3 = ChargeAl_Y.BCP_d.Data[3];
        ECanbMboxes.MBOX24.MDH.byte.BYTE4 = ChargeAl_Y.BCP_d.Data[4];
        ECanbMboxes.MBOX24.MDH.byte.BYTE5 = ChargeAl_Y.BCP_d.Data[5];
        ECanbMboxes.MBOX24.MDH.byte.BYTE6 = ChargeAl_Y.BCP_d.Data[6];
        ECanbMboxes.MBOX24.MDH.byte.BYTE7 = ChargeAl_Y.BCP_d.Data[7];
        ChargeAl_Y.CAN_Output_l.BCP.Flag = 0;

        ECanbShadow.CANTRS.all=ECanbRegs.CANTRS.all;
        ECanbShadow.CANTRS.bit.TRS24=1;
        ECanbRegs.CANTRS.all=ECanbShadow.CANTRS.all;
    }
    //BRO
    if (ChargeAl_Y.CAN_Output_l.BRO.Flag){

        ECanbMboxes.MBOX25.MDL.byte.BYTE0 = ChargeAl_Y.BRO_c.Data[0];
        ECanbMboxes.MBOX25.MDL.byte.BYTE1 = ChargeAl_Y.BRO_c.Data[1];
        ECanbMboxes.MBOX25.MDL.byte.BYTE2 = ChargeAl_Y.BRO_c.Data[2];
        ECanbMboxes.MBOX25.MDL.byte.BYTE3 = ChargeAl_Y.BRO_c.Data[3];
        ECanbMboxes.MBOX25.MDH.byte.BYTE4 = ChargeAl_Y.BRO_c.Data[4];
        ECanbMboxes.MBOX25.MDH.byte.BYTE5 = ChargeAl_Y.BRO_c.Data[5];
        ECanbMboxes.MBOX25.MDH.byte.BYTE6 = ChargeAl_Y.BRO_c.Data[6];
        ECanbMboxes.MBOX25.MDH.byte.BYTE7 = ChargeAl_Y.BRO_c.Data[7];
        ChargeAl_Y.CAN_Output_l.BRO.Flag = 0;

        ECanbShadow.CANTRS.all=ECanbRegs.CANTRS.all;
        ECanbShadow.CANTRS.bit.TRS25=1;
        ECanbRegs.CANTRS.all=ECanbShadow.CANTRS.all;
    }

    //BCL
    if (ChargeAl_Y.CAN_Output_l.BCL.Flag){

        ECanbMboxes.MBOX26.MDL.byte.BYTE0 = ChargeAl_Y.BCL_b.Data[0];
        ECanbMboxes.MBOX26.MDL.byte.BYTE1 = ChargeAl_Y.BCL_b.Data[1];
        ECanbMboxes.MBOX26.MDL.byte.BYTE2 = ChargeAl_Y.BCL_b.Data[2];
        ECanbMboxes.MBOX26.MDL.byte.BYTE3 = ChargeAl_Y.BCL_b.Data[3];
        ECanbMboxes.MBOX26.MDH.byte.BYTE4 = ChargeAl_Y.BCL_b.Data[4];
        ECanbMboxes.MBOX26.MDH.byte.BYTE5 = ChargeAl_Y.BCL_b.Data[5];
        ECanbMboxes.MBOX26.MDH.byte.BYTE6 = ChargeAl_Y.BCL_b.Data[6];
        ECanbMboxes.MBOX26.MDH.byte.BYTE7 = ChargeAl_Y.BCL_b.Data[7];
        ChargeAl_Y.CAN_Output_l.BCL.Flag = 0;

        ECanbShadow.CANTRS.all=ECanbRegs.CANTRS.all;
        ECanbShadow.CANTRS.bit.TRS26=1;
        ECanbRegs.CANTRS.all=ECanbShadow.CANTRS.all;
    }


    //BST
    if (ChargeAl_Y.CAN_Output_l.BST.Flag){

        ECanbMboxes.MBOX27.MDL.byte.BYTE0 = ChargeAl_Y.BST_n.Data[0];
        ECanbMboxes.MBOX27.MDL.byte.BYTE1 = ChargeAl_Y.BST_n.Data[1];
        ECanbMboxes.MBOX27.MDL.byte.BYTE2 = ChargeAl_Y.BST_n.Data[2];
        ECanbMboxes.MBOX27.MDL.byte.BYTE3 = ChargeAl_Y.BST_n.Data[3];
        ECanbMboxes.MBOX27.MDH.byte.BYTE4 = ChargeAl_Y.BST_n.Data[4];
        ECanbMboxes.MBOX27.MDH.byte.BYTE5 = ChargeAl_Y.BST_n.Data[5];
        ECanbMboxes.MBOX27.MDH.byte.BYTE6 = ChargeAl_Y.BST_n.Data[6];
        ECanbMboxes.MBOX27.MDH.byte.BYTE7 = ChargeAl_Y.BST_n.Data[7];
        ChargeAl_Y.CAN_Output_l.BST.Flag = 0;

        ECanbShadow.CANTRS.all=ECanbRegs.CANTRS.all;
        ECanbShadow.CANTRS.bit.TRS27=1;
        ECanbRegs.CANTRS.all=ECanbShadow.CANTRS.all;
    }
*/


}



void VCU_b_CAN_Function(void){

    if(b_Flag.bit.processing_received_mailbox==1){
        CAN_U.In1.Data[0] = ECanbMboxes.MBOX8.MDL.byte.BYTE0;
        CAN_U.In1.Data[1] = ECanbMboxes.MBOX8.MDL.byte.BYTE1;
        CAN_U.In1.Data[2] = ECanbMboxes.MBOX8.MDL.byte.BYTE2;
        CAN_U.In1.Data[3] = ECanbMboxes.MBOX8.MDL.byte.BYTE3;
        CAN_U.In1.Data[4] = ECanbMboxes.MBOX8.MDH.byte.BYTE4;
        CAN_U.In1.Data[5] = ECanbMboxes.MBOX8.MDH.byte.BYTE5;
        CAN_U.In1.Data[6] = ECanbMboxes.MBOX8.MDH.byte.BYTE6;
        CAN_U.In1.Data[7] = ECanbMboxes.MBOX8.MDH.byte.BYTE7;
        CAN_U.In1.ID = 0x101;
        CAN_U.In1.Length = 8;
        CAN_U.In1.Extended = 0;

        test3_U.CAN_VCU_Flag=1;

        ECanbRegs.CANRMP.all=0xFFFFFFFF;

        b_Flag.bit.processing_received_mailbox=0;
    }


    if(b_Flag.bit.sending_transmit_mailbox==1){
        b_CAN_sending_transmit_mailbox();
        b_Flag.bit.sending_transmit_mailbox=0;
    }
}
void VCU_a_CAN_Function(void){

    if(a_Flag.bit.processing_received_mailbox==1){


        //check for which bmb data
        if(ECanaRegs.CANRMP.bit.RMP2 && ECanaRegs.CANRMP.bit.RMP3 && ECanaRegs.CANRMP.bit.RMP4){
            ECanaRegs.CANRMP.bit.RMP2 = 1;ECanaRegs.CANRMP.bit.RMP3 = 1;ECanaRegs.CANRMP.bit.RMP4 = 1;
            bmbReadyCounter[0]++;
                        bmbReadyFlag[0] = 1;

            CANBMB_U.m1_1.Data[0] = ECanaMboxes.MBOX2.MDL.byte.BYTE0;
            CANBMB_U.m1_1.Data[1] = ECanaMboxes.MBOX2.MDL.byte.BYTE1;
            CANBMB_U.m1_1.Data[2] = ECanaMboxes.MBOX2.MDL.byte.BYTE2;
            CANBMB_U.m1_1.Data[3] = ECanaMboxes.MBOX2.MDL.byte.BYTE3;
            CANBMB_U.m1_1.Data[4] = ECanaMboxes.MBOX2.MDH.byte.BYTE4;
            CANBMB_U.m1_1.Data[5] = ECanaMboxes.MBOX2.MDH.byte.BYTE5;
            CANBMB_U.m1_1.Data[6] = ECanaMboxes.MBOX2.MDH.byte.BYTE6;
            CANBMB_U.m1_1.Data[7] = ECanaMboxes.MBOX2.MDH.byte.BYTE7;
            CANBMB_U.m1_1.ID = 3;
            CANBMB_U.m1_1.Length = 8;
            CANBMB_U.m1_1.Extended = 0;

            CANBMB_U.m1_2.Data[0] = ECanaMboxes.MBOX3.MDL.byte.BYTE0;
            CANBMB_U.m1_2.Data[1] = ECanaMboxes.MBOX3.MDL.byte.BYTE1;
            CANBMB_U.m1_2.Data[2] = ECanaMboxes.MBOX3.MDL.byte.BYTE2;
            CANBMB_U.m1_2.Data[3] = ECanaMboxes.MBOX3.MDL.byte.BYTE3;
            CANBMB_U.m1_2.Data[4] = ECanaMboxes.MBOX3.MDH.byte.BYTE4;
            CANBMB_U.m1_2.Data[5] = ECanaMboxes.MBOX3.MDH.byte.BYTE5;
            CANBMB_U.m1_2.Data[6] = ECanaMboxes.MBOX3.MDH.byte.BYTE6;
            CANBMB_U.m1_2.Data[7] = ECanaMboxes.MBOX3.MDH.byte.BYTE7;
            CANBMB_U.m1_2.ID = 4;
            CANBMB_U.m1_2.Length = 8;
            CANBMB_U.m1_2.Extended = 0;

            CANBMB_U.m1_3.Data[0] = ECanaMboxes.MBOX4.MDL.byte.BYTE0;
            CANBMB_U.m1_3.Data[1] = ECanaMboxes.MBOX4.MDL.byte.BYTE1;
            CANBMB_U.m1_3.Data[2] = ECanaMboxes.MBOX4.MDL.byte.BYTE2;
            CANBMB_U.m1_3.Data[3] = ECanaMboxes.MBOX4.MDL.byte.BYTE3;
            CANBMB_U.m1_3.Data[4] = ECanaMboxes.MBOX4.MDH.byte.BYTE4;
            CANBMB_U.m1_3.Data[5] = ECanaMboxes.MBOX4.MDH.byte.BYTE5;
            CANBMB_U.m1_3.Data[6] = ECanaMboxes.MBOX4.MDH.byte.BYTE6;
            CANBMB_U.m1_3.Data[7] = ECanaMboxes.MBOX4.MDH.byte.BYTE7;
            CANBMB_U.m1_3.ID = 5;
            CANBMB_U.m1_3.Length = 8;
            CANBMB_U.m1_3.Extended = 0;

        }
        if(ECanaRegs.CANRMP.bit.RMP5 && ECanaRegs.CANRMP.bit.RMP6 && ECanaRegs.CANRMP.bit.RMP7){
            ECanaRegs.CANRMP.bit.RMP5 = 1;ECanaRegs.CANRMP.bit.RMP6 = 1;ECanaRegs.CANRMP.bit.RMP7 = 1;
            bmbReadyFlag[1] = 1;
            bmbReadyCounter[1]++;

            CANBMB_U.m2_1.Data[0] = ECanaMboxes.MBOX5.MDL.byte.BYTE0;
            CANBMB_U.m2_1.Data[1] = ECanaMboxes.MBOX5.MDL.byte.BYTE1;
            CANBMB_U.m2_1.Data[2] = ECanaMboxes.MBOX5.MDL.byte.BYTE2;
            CANBMB_U.m2_1.Data[3] = ECanaMboxes.MBOX5.MDL.byte.BYTE3;
            CANBMB_U.m2_1.Data[4] = ECanaMboxes.MBOX5.MDH.byte.BYTE4;
            CANBMB_U.m2_1.Data[5] = ECanaMboxes.MBOX5.MDH.byte.BYTE5;
            CANBMB_U.m2_1.Data[6] = ECanaMboxes.MBOX5.MDH.byte.BYTE6;
            CANBMB_U.m2_1.Data[7] = ECanaMboxes.MBOX5.MDH.byte.BYTE7;
            CANBMB_U.m2_1.ID = 6;
            CANBMB_U.m2_1.Length = 8;
            CANBMB_U.m2_1.Extended = 0;

            CANBMB_U.m2_2.Data[0] = ECanaMboxes.MBOX6.MDL.byte.BYTE0;
            CANBMB_U.m2_2.Data[1] = ECanaMboxes.MBOX6.MDL.byte.BYTE1;
            CANBMB_U.m2_2.Data[2] = ECanaMboxes.MBOX6.MDL.byte.BYTE2;
            CANBMB_U.m2_2.Data[3] = ECanaMboxes.MBOX6.MDL.byte.BYTE3;
            CANBMB_U.m2_2.Data[4] = ECanaMboxes.MBOX6.MDH.byte.BYTE4;
            CANBMB_U.m2_2.Data[5] = ECanaMboxes.MBOX6.MDH.byte.BYTE5;
            CANBMB_U.m2_2.Data[6] = ECanaMboxes.MBOX6.MDH.byte.BYTE6;
            CANBMB_U.m2_2.Data[7] = ECanaMboxes.MBOX6.MDH.byte.BYTE7;
            CANBMB_U.m2_2.ID = 7;
            CANBMB_U.m2_2.Length = 8;
            CANBMB_U.m2_2.Extended = 0;

            CANBMB_U.m2_3.Data[0] = ECanaMboxes.MBOX7.MDL.byte.BYTE0;
            CANBMB_U.m2_3.Data[1] = ECanaMboxes.MBOX7.MDL.byte.BYTE1;
            CANBMB_U.m2_3.Data[2] = ECanaMboxes.MBOX7.MDL.byte.BYTE2;
            CANBMB_U.m2_3.Data[3] = ECanaMboxes.MBOX7.MDL.byte.BYTE3;
            CANBMB_U.m2_3.Data[4] = ECanaMboxes.MBOX7.MDH.byte.BYTE4;
            CANBMB_U.m2_3.Data[5] = ECanaMboxes.MBOX7.MDH.byte.BYTE5;
            CANBMB_U.m2_3.Data[6] = ECanaMboxes.MBOX7.MDH.byte.BYTE6;
            CANBMB_U.m2_3.Data[7] = ECanaMboxes.MBOX7.MDH.byte.BYTE7;
            CANBMB_U.m2_3.ID = 8;
            CANBMB_U.m2_3.Length = 8;
            CANBMB_U.m2_3.Extended = 0;
        }
        if(ECanaRegs.CANRMP.bit.RMP8 && ECanaRegs.CANRMP.bit.RMP9 && ECanaRegs.CANRMP.bit.RMP10){
            ECanaRegs.CANRMP.bit.RMP8 = 1;ECanaRegs.CANRMP.bit.RMP9 = 1;ECanaRegs.CANRMP.bit.RMP10 = 1;
            bmbReadyFlag[2] = 1;
            bmbReadyCounter[2]++;

            CANBMB_U.m3_1.Data[0] = ECanaMboxes.MBOX8.MDL.byte.BYTE0;
            CANBMB_U.m3_1.Data[1] = ECanaMboxes.MBOX8.MDL.byte.BYTE1;
            CANBMB_U.m3_1.Data[2] = ECanaMboxes.MBOX8.MDL.byte.BYTE2;
            CANBMB_U.m3_1.Data[3] = ECanaMboxes.MBOX8.MDL.byte.BYTE3;
            CANBMB_U.m3_1.Data[4] = ECanaMboxes.MBOX8.MDH.byte.BYTE4;
            CANBMB_U.m3_1.Data[5] = ECanaMboxes.MBOX8.MDH.byte.BYTE5;
            CANBMB_U.m3_1.Data[6] = ECanaMboxes.MBOX8.MDH.byte.BYTE6;
            CANBMB_U.m3_1.Data[7] = ECanaMboxes.MBOX8.MDH.byte.BYTE7;
            CANBMB_U.m3_1.ID = 9;
            CANBMB_U.m3_1.Length = 8;
            CANBMB_U.m3_1.Extended = 0;

            CANBMB_U.m3_2.Data[0] = ECanaMboxes.MBOX9.MDL.byte.BYTE0;
            CANBMB_U.m3_2.Data[1] = ECanaMboxes.MBOX9.MDL.byte.BYTE1;
            CANBMB_U.m3_2.Data[2] = ECanaMboxes.MBOX9.MDL.byte.BYTE2;
            CANBMB_U.m3_2.Data[3] = ECanaMboxes.MBOX9.MDL.byte.BYTE3;
            CANBMB_U.m3_2.Data[4] = ECanaMboxes.MBOX9.MDH.byte.BYTE4;
            CANBMB_U.m3_2.Data[5] = ECanaMboxes.MBOX9.MDH.byte.BYTE5;
            CANBMB_U.m3_2.Data[6] = ECanaMboxes.MBOX9.MDH.byte.BYTE6;
            CANBMB_U.m3_2.Data[7] = ECanaMboxes.MBOX9.MDH.byte.BYTE7;
            CANBMB_U.m3_2.ID = 10;
            CANBMB_U.m3_2.Length = 8;
            CANBMB_U.m3_2.Extended = 0;

            CANBMB_U.m3_3.Data[0] = ECanaMboxes.MBOX10.MDL.byte.BYTE0;
            CANBMB_U.m3_3.Data[1] = ECanaMboxes.MBOX10.MDL.byte.BYTE1;
            CANBMB_U.m3_3.Data[2] = ECanaMboxes.MBOX10.MDL.byte.BYTE2;
            CANBMB_U.m3_3.Data[3] = ECanaMboxes.MBOX10.MDL.byte.BYTE3;
            CANBMB_U.m3_3.Data[4] = ECanaMboxes.MBOX10.MDH.byte.BYTE4;
            CANBMB_U.m3_3.Data[5] = ECanaMboxes.MBOX10.MDH.byte.BYTE5;
            CANBMB_U.m3_3.Data[6] = ECanaMboxes.MBOX10.MDH.byte.BYTE6;
            CANBMB_U.m3_3.Data[7] = ECanaMboxes.MBOX10.MDH.byte.BYTE7;
            CANBMB_U.m3_3.ID = 11;
            CANBMB_U.m3_3.Length = 8;
            CANBMB_U.m3_3.Extended = 0;
        }
        if(ECanaRegs.CANRMP.bit.RMP11 && ECanaRegs.CANRMP.bit.RMP12 && ECanaRegs.CANRMP.bit.RMP13){
            ECanaRegs.CANRMP.bit.RMP11 = 1;ECanaRegs.CANRMP.bit.RMP12 = 1;ECanaRegs.CANRMP.bit.RMP13 = 1;
            bmbReadyFlag[3] = 1;
            bmbReadyCounter[3]++;

            CANBMB_U.m4_1.Data[0] = ECanaMboxes.MBOX11.MDL.byte.BYTE0;
            CANBMB_U.m4_1.Data[1] = ECanaMboxes.MBOX11.MDL.byte.BYTE1;
            CANBMB_U.m4_1.Data[2] = ECanaMboxes.MBOX11.MDL.byte.BYTE2;
            CANBMB_U.m4_1.Data[3] = ECanaMboxes.MBOX11.MDL.byte.BYTE3;
            CANBMB_U.m4_1.Data[4] = ECanaMboxes.MBOX11.MDH.byte.BYTE4;
            CANBMB_U.m4_1.Data[5] = ECanaMboxes.MBOX11.MDH.byte.BYTE5;
            CANBMB_U.m4_1.Data[6] = ECanaMboxes.MBOX11.MDH.byte.BYTE6;
            CANBMB_U.m4_1.Data[7] = ECanaMboxes.MBOX11.MDH.byte.BYTE7;
            CANBMB_U.m4_1.ID = 12;
            CANBMB_U.m4_1.Length = 8;
            CANBMB_U.m4_1.Extended = 0;

            CANBMB_U.m4_2.Data[0] = ECanaMboxes.MBOX12.MDL.byte.BYTE0;
            CANBMB_U.m4_2.Data[1] = ECanaMboxes.MBOX12.MDL.byte.BYTE1;
            CANBMB_U.m4_2.Data[2] = ECanaMboxes.MBOX12.MDL.byte.BYTE2;
            CANBMB_U.m4_2.Data[3] = ECanaMboxes.MBOX12.MDL.byte.BYTE3;
            CANBMB_U.m4_2.Data[4] = ECanaMboxes.MBOX12.MDH.byte.BYTE4;
            CANBMB_U.m4_2.Data[5] = ECanaMboxes.MBOX12.MDH.byte.BYTE5;
            CANBMB_U.m4_2.Data[6] = ECanaMboxes.MBOX12.MDH.byte.BYTE6;
            CANBMB_U.m4_2.Data[7] = ECanaMboxes.MBOX12.MDH.byte.BYTE7;
            CANBMB_U.m4_2.ID = 13;
            CANBMB_U.m4_2.Length = 8;
            CANBMB_U.m4_2.Extended = 0;

            CANBMB_U.m4_3.Data[0] = ECanaMboxes.MBOX13.MDL.byte.BYTE0;
            CANBMB_U.m4_3.Data[1] = ECanaMboxes.MBOX13.MDL.byte.BYTE1;
            CANBMB_U.m4_3.Data[2] = ECanaMboxes.MBOX13.MDL.byte.BYTE2;
            CANBMB_U.m4_3.Data[3] = ECanaMboxes.MBOX13.MDL.byte.BYTE3;
            CANBMB_U.m4_3.Data[4] = ECanaMboxes.MBOX13.MDH.byte.BYTE4;
            CANBMB_U.m4_3.Data[5] = ECanaMboxes.MBOX13.MDH.byte.BYTE5;
            CANBMB_U.m4_3.Data[6] = ECanaMboxes.MBOX13.MDH.byte.BYTE6;
            CANBMB_U.m4_3.Data[7] = ECanaMboxes.MBOX13.MDH.byte.BYTE7;
            CANBMB_U.m4_3.ID = 14;
            CANBMB_U.m4_3.Length = 8;
            CANBMB_U.m4_3.Extended = 0;
        }
        if(ECanaRegs.CANRMP.bit.RMP14 && ECanaRegs.CANRMP.bit.RMP15 && ECanaRegs.CANRMP.bit.RMP16){
            ECanaRegs.CANRMP.bit.RMP14 = 1;ECanaRegs.CANRMP.bit.RMP15 = 1;ECanaRegs.CANRMP.bit.RMP16 = 1;
            bmbReadyFlag[4] = 1;
            bmbReadyCounter[4]++;
            CANBMB_U.m5_1.Data[0] = ECanaMboxes.MBOX14.MDL.byte.BYTE0;
            CANBMB_U.m5_1.Data[1] = ECanaMboxes.MBOX14.MDL.byte.BYTE1;
            CANBMB_U.m5_1.Data[2] = ECanaMboxes.MBOX14.MDL.byte.BYTE2;
            CANBMB_U.m5_1.Data[3] = ECanaMboxes.MBOX14.MDL.byte.BYTE3;
            CANBMB_U.m5_1.Data[4] = ECanaMboxes.MBOX14.MDH.byte.BYTE4;
            CANBMB_U.m5_1.Data[5] = ECanaMboxes.MBOX14.MDH.byte.BYTE5;
            CANBMB_U.m5_1.Data[6] = ECanaMboxes.MBOX14.MDH.byte.BYTE6;
            CANBMB_U.m5_1.Data[7] = ECanaMboxes.MBOX14.MDH.byte.BYTE7;
            CANBMB_U.m5_1.ID = 15;
            CANBMB_U.m5_1.Length = 8;
            CANBMB_U.m5_1.Extended = 0;

            CANBMB_U.m5_2.Data[0] = ECanaMboxes.MBOX15.MDL.byte.BYTE0;
            CANBMB_U.m5_2.Data[1] = ECanaMboxes.MBOX15.MDL.byte.BYTE1;
            CANBMB_U.m5_2.Data[2] = ECanaMboxes.MBOX15.MDL.byte.BYTE2;
            CANBMB_U.m5_2.Data[3] = ECanaMboxes.MBOX15.MDL.byte.BYTE3;
            CANBMB_U.m5_2.Data[4] = ECanaMboxes.MBOX15.MDH.byte.BYTE4;
            CANBMB_U.m5_2.Data[5] = ECanaMboxes.MBOX15.MDH.byte.BYTE5;
            CANBMB_U.m5_2.Data[6] = ECanaMboxes.MBOX15.MDH.byte.BYTE6;
            CANBMB_U.m5_2.Data[7] = ECanaMboxes.MBOX15.MDH.byte.BYTE7;
            CANBMB_U.m5_2.ID = 16;
            CANBMB_U.m5_2.Length = 8;
            CANBMB_U.m5_2.Extended = 0;

            CANBMB_U.m5_3.Data[0] = ECanaMboxes.MBOX16.MDL.byte.BYTE0;
            CANBMB_U.m5_3.Data[1] = ECanaMboxes.MBOX16.MDL.byte.BYTE1;
            CANBMB_U.m5_3.Data[2] = ECanaMboxes.MBOX16.MDL.byte.BYTE2;
            CANBMB_U.m5_3.Data[3] = ECanaMboxes.MBOX16.MDL.byte.BYTE3;
            CANBMB_U.m5_3.Data[4] = ECanaMboxes.MBOX16.MDH.byte.BYTE4;
            CANBMB_U.m5_3.Data[5] = ECanaMboxes.MBOX16.MDH.byte.BYTE5;
            CANBMB_U.m5_3.Data[6] = ECanaMboxes.MBOX16.MDH.byte.BYTE6;
            CANBMB_U.m5_3.Data[7] = ECanaMboxes.MBOX16.MDH.byte.BYTE7;
            CANBMB_U.m5_3.ID = 17;
            CANBMB_U.m5_3.Length = 8;
            CANBMB_U.m5_3.Extended = 0;
        }
        if(ECanaRegs.CANRMP.bit.RMP17 && ECanaRegs.CANRMP.bit.RMP18 && ECanaRegs.CANRMP.bit.RMP19){
            ECanaRegs.CANRMP.bit.RMP17 = 1;ECanaRegs.CANRMP.bit.RMP18 = 1;ECanaRegs.CANRMP.bit.RMP19 = 1;
            bmbReadyFlag[5] = 1;
            bmbReadyCounter[5]++;

            CANBMB_U.m6_1.Data[0] = ECanaMboxes.MBOX17.MDL.byte.BYTE0;
            CANBMB_U.m6_1.Data[1] = ECanaMboxes.MBOX17.MDL.byte.BYTE1;
            CANBMB_U.m6_1.Data[2] = ECanaMboxes.MBOX17.MDL.byte.BYTE2;
            CANBMB_U.m6_1.Data[3] = ECanaMboxes.MBOX17.MDL.byte.BYTE3;
            CANBMB_U.m6_1.Data[4] = ECanaMboxes.MBOX17.MDH.byte.BYTE4;
            CANBMB_U.m6_1.Data[5] = ECanaMboxes.MBOX17.MDH.byte.BYTE5;
            CANBMB_U.m6_1.Data[6] = ECanaMboxes.MBOX17.MDH.byte.BYTE6;
            CANBMB_U.m6_1.Data[7] = ECanaMboxes.MBOX17.MDH.byte.BYTE7;
            CANBMB_U.m6_1.ID = 18;
            CANBMB_U.m6_1.Length = 8;
            CANBMB_U.m6_1.Extended = 0;

            CANBMB_U.m6_2.Data[0] = ECanaMboxes.MBOX18.MDL.byte.BYTE0;
            CANBMB_U.m6_2.Data[1] = ECanaMboxes.MBOX18.MDL.byte.BYTE1;
            CANBMB_U.m6_2.Data[2] = ECanaMboxes.MBOX18.MDL.byte.BYTE2;
            CANBMB_U.m6_2.Data[3] = ECanaMboxes.MBOX18.MDL.byte.BYTE3;
            CANBMB_U.m6_2.Data[4] = ECanaMboxes.MBOX18.MDH.byte.BYTE4;
            CANBMB_U.m6_2.Data[5] = ECanaMboxes.MBOX18.MDH.byte.BYTE5;
            CANBMB_U.m6_2.Data[6] = ECanaMboxes.MBOX18.MDH.byte.BYTE6;
            CANBMB_U.m6_2.Data[7] = ECanaMboxes.MBOX18.MDH.byte.BYTE7;
            CANBMB_U.m6_2.ID = 19;
            CANBMB_U.m6_2.Length = 8;
            CANBMB_U.m6_2.Extended = 0;

            CANBMB_U.m6_3.Data[0] = ECanaMboxes.MBOX19.MDL.byte.BYTE0;
            CANBMB_U.m6_3.Data[1] = ECanaMboxes.MBOX19.MDL.byte.BYTE1;
            CANBMB_U.m6_3.Data[2] = ECanaMboxes.MBOX19.MDL.byte.BYTE2;
            CANBMB_U.m6_3.Data[3] = ECanaMboxes.MBOX19.MDL.byte.BYTE3;
            CANBMB_U.m6_3.Data[4] = ECanaMboxes.MBOX19.MDH.byte.BYTE4;
            CANBMB_U.m6_3.Data[5] = ECanaMboxes.MBOX19.MDH.byte.BYTE5;
            CANBMB_U.m6_3.Data[6] = ECanaMboxes.MBOX19.MDH.byte.BYTE6;
            CANBMB_U.m6_3.Data[7] = ECanaMboxes.MBOX19.MDH.byte.BYTE7;
            CANBMB_U.m6_3.ID = 20;
            CANBMB_U.m6_3.Length = 8;
            CANBMB_U.m6_3.Extended = 0;
        }
        if(ECanaRegs.CANRMP.bit.RMP20 && ECanaRegs.CANRMP.bit.RMP21 && ECanaRegs.CANRMP.bit.RMP22){
            ECanaRegs.CANRMP.bit.RMP20 = 1;ECanaRegs.CANRMP.bit.RMP21 = 1;ECanaRegs.CANRMP.bit.RMP22 = 1;
            bmbReadyFlag[6] = 1;
            bmbReadyCounter[6]++;

            CANBMB_U.m7_1.Data[0] = ECanaMboxes.MBOX20.MDL.byte.BYTE0;
            CANBMB_U.m7_1.Data[1] = ECanaMboxes.MBOX20.MDL.byte.BYTE1;
            CANBMB_U.m7_1.Data[2] = ECanaMboxes.MBOX20.MDL.byte.BYTE2;
            CANBMB_U.m7_1.Data[3] = ECanaMboxes.MBOX20.MDL.byte.BYTE3;
            CANBMB_U.m7_1.Data[4] = ECanaMboxes.MBOX20.MDH.byte.BYTE4;
            CANBMB_U.m7_1.Data[5] = ECanaMboxes.MBOX20.MDH.byte.BYTE5;
            CANBMB_U.m7_1.Data[6] = ECanaMboxes.MBOX20.MDH.byte.BYTE6;
            CANBMB_U.m7_1.Data[7] = ECanaMboxes.MBOX20.MDH.byte.BYTE7;
            CANBMB_U.m7_1.ID = 21;
            CANBMB_U.m7_1.Length = 8;
            CANBMB_U.m7_1.Extended = 0;

            CANBMB_U.m7_2.Data[0] = ECanaMboxes.MBOX21.MDL.byte.BYTE0;
            CANBMB_U.m7_2.Data[1] = ECanaMboxes.MBOX21.MDL.byte.BYTE1;
            CANBMB_U.m7_2.Data[2] = ECanaMboxes.MBOX21.MDL.byte.BYTE2;
            CANBMB_U.m7_2.Data[3] = ECanaMboxes.MBOX21.MDL.byte.BYTE3;
            CANBMB_U.m7_2.Data[4] = ECanaMboxes.MBOX21.MDH.byte.BYTE4;
            CANBMB_U.m7_2.Data[5] = ECanaMboxes.MBOX21.MDH.byte.BYTE5;
            CANBMB_U.m7_2.Data[6] = ECanaMboxes.MBOX21.MDH.byte.BYTE6;
            CANBMB_U.m7_2.Data[7] = ECanaMboxes.MBOX21.MDH.byte.BYTE7;
            CANBMB_U.m7_2.ID = 22;
            CANBMB_U.m7_2.Length = 8;
            CANBMB_U.m7_2.Extended = 0;

            CANBMB_U.m7_3.Data[0] = ECanaMboxes.MBOX22.MDL.byte.BYTE0;
            CANBMB_U.m7_3.Data[1] = ECanaMboxes.MBOX22.MDL.byte.BYTE1;
            CANBMB_U.m7_3.Data[2] = ECanaMboxes.MBOX22.MDL.byte.BYTE2;
            CANBMB_U.m7_3.Data[3] = ECanaMboxes.MBOX22.MDL.byte.BYTE3;
            CANBMB_U.m7_3.Data[4] = ECanaMboxes.MBOX22.MDH.byte.BYTE4;
            CANBMB_U.m7_3.Data[5] = ECanaMboxes.MBOX22.MDH.byte.BYTE5;
            CANBMB_U.m7_3.Data[6] = ECanaMboxes.MBOX22.MDH.byte.BYTE6;
            CANBMB_U.m7_3.Data[7] = ECanaMboxes.MBOX22.MDH.byte.BYTE7;
            CANBMB_U.m7_3.ID = 23;
            CANBMB_U.m7_3.Length = 8;
            CANBMB_U.m7_3.Extended = 0;
        }
        if(ECanaRegs.CANRMP.bit.RMP23 && ECanaRegs.CANRMP.bit.RMP24 && ECanaRegs.CANRMP.bit.RMP25){
            ECanaRegs.CANRMP.bit.RMP23 = 1;ECanaRegs.CANRMP.bit.RMP24 = 1;ECanaRegs.CANRMP.bit.RMP25 = 1;
            bmbReadyFlag[7] = 1;
            bmbReadyCounter[7]++;

            CANBMB_U.m8_1.Data[0] = ECanaMboxes.MBOX23.MDL.byte.BYTE0;
            CANBMB_U.m8_1.Data[1] = ECanaMboxes.MBOX23.MDL.byte.BYTE1;
            CANBMB_U.m8_1.Data[2] = ECanaMboxes.MBOX23.MDL.byte.BYTE2;
            CANBMB_U.m8_1.Data[3] = ECanaMboxes.MBOX23.MDL.byte.BYTE3;
            CANBMB_U.m8_1.Data[4] = ECanaMboxes.MBOX23.MDH.byte.BYTE4;
            CANBMB_U.m8_1.Data[5] = ECanaMboxes.MBOX23.MDH.byte.BYTE5;
            CANBMB_U.m8_1.Data[6] = ECanaMboxes.MBOX23.MDH.byte.BYTE6;
            CANBMB_U.m8_1.Data[7] = ECanaMboxes.MBOX23.MDH.byte.BYTE7;
            CANBMB_U.m8_1.ID = 24;
            CANBMB_U.m8_1.Length = 8;
            CANBMB_U.m8_1.Extended = 0;

            CANBMB_U.m8_2.Data[0] = ECanaMboxes.MBOX24.MDL.byte.BYTE0;
            CANBMB_U.m8_2.Data[1] = ECanaMboxes.MBOX24.MDL.byte.BYTE1;
            CANBMB_U.m8_2.Data[2] = ECanaMboxes.MBOX24.MDL.byte.BYTE2;
            CANBMB_U.m8_2.Data[3] = ECanaMboxes.MBOX24.MDL.byte.BYTE3;
            CANBMB_U.m8_2.Data[4] = ECanaMboxes.MBOX24.MDH.byte.BYTE4;
            CANBMB_U.m8_2.Data[5] = ECanaMboxes.MBOX24.MDH.byte.BYTE5;
            CANBMB_U.m8_2.Data[6] = ECanaMboxes.MBOX24.MDH.byte.BYTE6;
            CANBMB_U.m8_2.Data[7] = ECanaMboxes.MBOX24.MDH.byte.BYTE7;
            CANBMB_U.m8_2.ID = 25;
            CANBMB_U.m8_2.Length = 8;
            CANBMB_U.m8_2.Extended = 0;

            CANBMB_U.m8_3.Data[0] = ECanaMboxes.MBOX25.MDL.byte.BYTE0;
            CANBMB_U.m8_3.Data[1] = ECanaMboxes.MBOX25.MDL.byte.BYTE1;
            CANBMB_U.m8_3.Data[2] = ECanaMboxes.MBOX25.MDL.byte.BYTE2;
            CANBMB_U.m8_3.Data[3] = ECanaMboxes.MBOX25.MDL.byte.BYTE3;
            CANBMB_U.m8_3.Data[4] = ECanaMboxes.MBOX25.MDH.byte.BYTE4;
            CANBMB_U.m8_3.Data[5] = ECanaMboxes.MBOX25.MDH.byte.BYTE5;
            CANBMB_U.m8_3.Data[6] = ECanaMboxes.MBOX25.MDH.byte.BYTE6;
            CANBMB_U.m8_3.Data[7] = ECanaMboxes.MBOX25.MDH.byte.BYTE7;
            CANBMB_U.m8_3.ID = 26;
            CANBMB_U.m8_3.Length = 8;
            CANBMB_U.m8_3.Extended = 0;
        }





        //ECanaRegs.CANRMP.all = 0xFFFFFFFF;
        a_Flag.bit.processing_received_mailbox=0;
    }


    if(a_Flag.bit.sending_transmit_mailbox==1){

        a_CAN_sending_transmit_mailbox();
        a_Flag.bit.sending_transmit_mailbox=0;
    }
}
