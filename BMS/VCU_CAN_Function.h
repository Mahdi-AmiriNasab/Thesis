/*
 * VCU_CAN_Function.h
 *
 *  Created on: Apr 20, 2022
 *      Author: 10661011
 */

#ifndef VCU_CAN_FUNCTION_H_
#define VCU_CAN_FUNCTION_H_
#include "DSP28x_Project.h"

extern void VCU_CAN_init(void);
extern void VCU_CAN_TaskManager(Uint32 PC);

typedef struct VCU_CAN_Flag_bit{
    Uint16 processing_received_mailbox:1;
    Uint16 sending_transmit_mailbox:1;

} VCU_CAN_Flag_bit;
typedef union {
    Uint16 all;
    VCU_CAN_Flag_bit bit;
}VCU_CAN_Flag;
#endif /* VCU_CAN_FUNCTION_H_ */
