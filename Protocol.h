// extract information from the struct consisted of 
// 0 | 0000000 | 0 | 0 | 0 |

#include <stdint.h>

typedef struct {
    uint16_t priority        : 1;  // 1 bit
    uint16_t uuid            : 7;  // 7 bits
    uint16_t power_domain    : 1;  // 1 bit
    uint16_t motor_domain    : 1;  // 1 bit
    uint16_t peripheral_domain : 1; // 1 bit
} ArbitrationField;

typedef struct {
    uint16_t ACK_request : 1;  // 1 bit
    uint16_t Packet_ID    : 7;  // 7 bits
} CommandID;

/*
Bit assignments:
    Comm_and_ID : 0
    Sender_UUID : 1
    Data[0]: 2
    Data[1]: 3    
    Data[2]: 4
    Data[3]: 5
    Data[4]: 6
    Data[5]: 7
*/
uint8_t PacketData[8] = {0}; 
