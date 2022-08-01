#ifndef SENDCOMMANDS_H
#define SENDCOMMANDS_H

#include<stdint.h>
#include "socket_local.h"

class sendCommands
{
    private:
        int socket_id;
        char socket_name[100];
        interface_to_machine_message interface_message;

        bool enabled;
        int16_t sampling_period;

        void setVelocity(uint8_t velocity);
        void setDistance(int8_t distance);
        void setPressure(uint8_t pressure);

        void setEnabled(bool enabled);
        void setSamplingPeriod(int16_t sampling_period);


    public:
        sendCommands();
        ~sendCommands();
        void setCommand(uint8_t command);
        int16_t sendMessage();
        

        int8_t getVelocity();
        int8_t getDistance();
        int8_t getPressure();
        bool getEnabled();
        int16_t getSamplingPeriod();

};

#endif // SENDCOMMANDS_H
