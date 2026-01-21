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

typedef struct {
    uint16_t priority        : 1;  // 1 bit
    uint16_t uuid            : 7;  // 7 bits
    uint16_t power_domain    : 1;  // 1 bit
    uint16_t motor_domain    : 1;  // 1 bit
    uint16_t peripheral_domain : 1; // 1 bit
} ArbitrationField;


typedef struct {
    uint8_t comm_and_ID;  
    uint8_t sender_UUID;  
    uint8_t data0;  
    uint8_t data1; 
    uint8_t data2; 
    uint8_t data3; 
    uint8_t data4; 
    uint8_t data5;  
} DataField;

#define SET_ARBITRATION_ID(priority, uuid, power_domain, motor_domain, peripheral_domain) \
    ( (uint16_t)( \
        (((uint16_t)((priority) & 0x1u))           << 10)  | \
        (((uint16_t)((uuid) & 0x7Fu))               << 3)  | \
        (((uint16_t)((power_domain) & 0x1u))        << 2)  | \
        (((uint16_t)((motor_domain) & 0x1u))        << 1)  | \
        (((uint16_t)((peripheral_domain) & 0x1u))   << 0) ) )

#define GET_PRIORITY(can_id) \
    ( (uint8_t)(((can_id) >> 10)& 0x1u) )

#define GET_UUID(can_id) \
    ( (uint8_t)(((can_id) >> 3) & 0x7Fu) )

#define GET_POWER_DOMAIN(can_id) \
    ( (uint8_t)(((can_id) >> 2) & 0x1u) )

#define GET_MOTOR_DOMAIN(can_id) \
    ( (uint8_t)(((can_id) >> 1) & 0x1u) )

#define GET_PERIPHERAL_DOMAIN(can_id) \
    ( (uint8_t)(((can_id) >> 0) & 0x1u) )
