/*
 * CAN_Driver.c
 *
 *  Created on: May 13, 2023
 *      Author: EV-Workshop2-NB
 */

#include "DSP28x_Project.h"

 struct ECAN_REGS ECanaShadow;
 struct ECAN_REGS ECanbShadow_CANB;






void INIT_CANB_MAILBOX(void){

            //**********************************************
            /* Mbox1
            Transmit Mbox
            MsgID:0x101  Standard 11 Bit
            MSG Name:  BMS_Command
            sending command for BMS
            */
            // Write to the MSGID field
            ECanbMboxes.MBOX1.MSGID.bit.STDMSGID=0x7E2;
            ECanbMboxes.MBOX1.MSGID.bit.IDE=0;
            ECanbMboxes.MBOX1.MSGID.bit.AAM=0;
            ECanbMboxes.MBOX1.MSGID.bit.AME=0;
            // Configure Mailbox 1 as a Transmit mailbox
            ECanbShadow_CANB.CANMD.all = ECanbRegs.CANMD.all;
            ECanbShadow_CANB.CANMD.bit.MD1 = 0;
            ECanbRegs.CANMD.all = ECanbShadow_CANB.CANMD.all;
            // Enable Mailbox1
            ECanbShadow_CANB.CANME.all = ECanbRegs.CANME.all;
            ECanbShadow_CANB.CANME.bit.ME1 = 1;
            ECanbRegs.CANME.all = ECanbShadow_CANB.CANME.all;
            // Write to DLC field in Master Control reg
            ECanbMboxes.MBOX1.MSGCTRL.bit.DLC = 8;
            //**********************************************

            //**********************************************
            /* Mbox2
            receive Mbox
            MsgID:0x301  Standard 11 Bit
            receiving Data from internal charger
            */
            // Write to the MSGID field
            ECanbMboxes.MBOX2.MSGID.bit.STDMSGID=0x7E1;
            ECanbMboxes.MBOX2.MSGID.bit.IDE=0;
            ECanbMboxes.MBOX2.MSGID.bit.AAM=0;
            ECanbMboxes.MBOX2.MSGID.bit.AME=0;
            // Configure Mailbox 2 as a receive mailbox
            ECanbShadow_CANB.CANMD.all = ECanbRegs.CANMD.all;
            ECanbShadow_CANB.CANMD.bit.MD2 = 1;
            ECanbRegs.CANMD.all = ECanbShadow_CANB.CANMD.all;
            // Enable Mailbox2
            ECanbShadow_CANB.CANME.all = ECanbRegs.CANME.all;
            ECanbShadow_CANB.CANME.bit.ME2 = 1;
            ECanbRegs.CANME.all = ECanbShadow_CANB.CANME.all;
            // Write to DLC field in Master Control reg
            ECanbMboxes.MBOX2.MSGCTRL.bit.DLC = 8;
            //**********************************************
}



void INIT_CAN_B_Config(void){

        /////CAN  Configuratin

      InitECanbGpio();
      InitECanb();
      INIT_CANB_MAILBOX();

}


void INIT_CANA_MAILBOX(void){

            //**********************************************
            /* Mbox1
            Transmit Mbox
            MsgID:0x101  Standard 11 Bit
            MSG Name:  BMS_Command
            sending command for BMS
            */
            // Write to the MSGID field
            ECanaMboxes.MBOX1.MSGID.bit.STDMSGID=0x7E2;
            ECanaMboxes.MBOX1.MSGID.bit.IDE=0;
            ECanaMboxes.MBOX1.MSGID.bit.AAM=0;
            ECanaMboxes.MBOX1.MSGID.bit.AME=0;
            // Configure Mailbox 1 as a Transmit mailbox
            ECanaShadow.CANMD.all = ECanaRegs.CANMD.all;
            ECanaShadow.CANMD.bit.MD1 = 0;
            ECanaRegs.CANMD.all = ECanaShadow.CANMD.all;
            // Enable Mailbox1
            ECanaShadow.CANME.all = ECanaRegs.CANME.all;
            ECanaShadow.CANME.bit.ME1 = 1;
            ECanaRegs.CANME.all = ECanaShadow.CANME.all;
            // Write to DLC field in Master Control reg
            ECanaMboxes.MBOX1.MSGCTRL.bit.DLC = 8;
            //**********************************************

            //**********************************************
            /* Mbox2
            receive Mbox
            MsgID:0x301  Standard 11 Bit
            receiving Data from internal charger
            */
            // Write to the MSGID field
            ECanaMboxes.MBOX2.MSGID.bit.STDMSGID=0x7E1;
            ECanaMboxes.MBOX2.MSGID.bit.IDE=0;
            ECanaMboxes.MBOX2.MSGID.bit.AAM=0;
            ECanaMboxes.MBOX2.MSGID.bit.AME=0;
            // Configure Mailbox 2 as a receive mailbox
            ECanaShadow.CANMD.all = ECanaRegs.CANMD.all;
            ECanaShadow.CANMD.bit.MD2 = 1;
            ECanaRegs.CANMD.all = ECanaShadow.CANMD.all;
            // Enable Mailbox2
            ECanaShadow.CANME.all = ECanaRegs.CANME.all;
            ECanaShadow.CANME.bit.ME2 = 1;
            ECanaRegs.CANME.all = ECanaShadow.CANME.all;
            // Write to DLC field in Master Control reg
            ECanaMboxes.MBOX2.MSGCTRL.bit.DLC = 8;
            //**********************************************
}

void INIT_CAN_A_Config(void){
      /////CAN  Configuratin

    InitECanaGpio();
    InitECana();
    INIT_CANA_MAILBOX();
    }

void Init_CAN_Driver_config(void){
    INIT_CAN_A_Config();
    INIT_CAN_B_Config();
}
