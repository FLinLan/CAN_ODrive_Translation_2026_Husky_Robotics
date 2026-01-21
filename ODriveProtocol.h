#pragma once

// defining all the macros for Host -> ODrive for now
#define Estop 0x02U
#define RxSdo 0x04U
#define TxSdo 0x05U
#define ODrive_Cmd_Address 0x06U
#define Set_Axis_State 0x07U
#define Set_Controller_Mode 0x00BU
#define Set_Input_Pos 0x00CU
#define Set_Input_Vel 0x00DU
#define Set_Input_Torque 0x00EU
#define Set_Vel_Gains 0x1BU
#define Reboot 0x16U
#define Clear_Errors 0x18U
#define Set_Absolute_Pos 0x19U
#define Set_Pos_Gain 0x1AU
#define Set_Vel_Gains 0x1BU
#define Enter_DFU_Mode 0x1FU

typedef struct {
    uint16_t node_id         : 6;  // 6 bits
    uint16_t command_id      : 5;  // 5 bits
} ODriveArbitrationField;

// ODrive CANSimple ID layout:
// bits [10:5] = node_id (6 bits)
// bits [4:0]  = cmd_id  (5 bits)
// macro function for getting CAN and NODE IDs
#define ODRIVE_SET_CAN_ID(node_id, cmd_id) \
    ( (uint16_t)((((uint16_t)((node_id) & 0x3FU)) << 5) | ((uint16_t)((cmd_id) & 0x1FU))) )

#define ODRIVE_GET_NODE_ID(can_id) \
    ( (uint8_t)(((can_id) >> 5) & 0x3FU) )

#define ODRIVE_GET_CMD_ID(can_id) \
    ( (uint8_t)((can_id) & 0x1FU) )
