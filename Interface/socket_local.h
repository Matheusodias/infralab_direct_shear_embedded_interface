#ifndef SOCKET_LOCAL_H
#define SOCKET_LOCAL_H

#include<stdint.h>
#include <QMetaType>


#define interface_payload_size 3 * sizeof(uint16_t)
#define machine_payload_size 8 * sizeof(uint32_t)

typedef union interface_to_machine_message{
    unsigned char payload[interface_payload_size];
    struct {
        uint8_t command;
        union {
            uint16_t pressure;
            struct {
                uint16_t distance;
                uint16_t velocity;
            };
            struct {
                uint8_t enabled;
                uint16_t sample_period;
            };
        };
    };
} interface_to_machine_message;


typedef union  machine_to_interface_message{
    unsigned char payload[machine_payload_size];
    struct {
        uint32_t sample_number[2];
        uint32_t date_time[2];
        float displacement[2];
        float load[2];
    };
} machine_to_interface_message;

Q_DECLARE_METATYPE(interface_to_machine_message);
Q_DECLARE_METATYPE(machine_to_interface_message);






#endif // SOCKET_LOCAL_H
