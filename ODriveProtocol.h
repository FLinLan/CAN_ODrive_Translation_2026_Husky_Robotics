#include <stdint.h>

// defining all the macros for Host -> ODrive for now
#define Estop 0x02u
#define RxSdo 0x04u
#define TxSdo 0x05u
#define Address 0x06u
#define Set_Axis_State 0x07u
#define Set_Controller_Mode 0x00b
#define Set_Input_Pos 0x00cu
#define Set_Input_Vel 0x00du
#define Set_Input_Torque 0x00eu
#define Set_Vel_Gains 0x1bu
#define Reboot 0x16u


typedef struct {
    uint16_t node_id         : 5;  // 5 bits
    uint16_t command_id      : 6;  // 6 bits
} ODriveArbitrationField;