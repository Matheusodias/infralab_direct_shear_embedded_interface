#include "sendcommands.h"

#include <errno.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>

#include <QDebug>

sendCommands::sendCommands()
{
    char temp_socket_name[] = "./machine";
    strncpy(this->socket_name,temp_socket_name,strlen(temp_socket_name)+1);
    //qDebug() << "Nome do socket = " << this->socket_name << strlen(this->socket_name);
    this->socket_id = socket(PF_LOCAL, SOCK_STREAM,0);

    struct sockaddr send_command;
    strncpy(send_command.sa_data,this->socket_name,strlen(this->socket_name)+1);
    send_command.sa_family = AF_LOCAL;

    //qDebug() << "Nome do socket = " << send_command.sa_data << strlen(send_command.sa_data);
    int socket_size = strlen(send_command.sa_data) + sizeof(send_command.sa_family);
    if(connect(this->socket_id, &send_command, socket_size)!=0){
        close(this->socket_id);
        this->errorOccurred=1;
        qDebug () << "Error connecting client: " << strerror(errno);
    }
    this->errorOccurred=0;
}

sendCommands::~sendCommands()
{
    close(this->socket_id);
    qDebug() << "Close";
}

int16_t sendCommands::sendMessage()
{
    if(this->errorOccurred){
        qDebug() << "Ocorreu um erro anteriormente ao tentar se conectar ao servidor da Máquina."; 
        qDebug() << "Por favor tente novamente se conectar ao servidor e depois tente mandar mensagens";
        return -1;
    }

    int16_t status = write(socket_id, this->interface_message.payload, interface_payload_size);
    return status;
}

void sendCommands::setCommand(uint8_t command)
{

    this->interface_message.command = command;

    // switch (command)
    // {
    //     case 1:
    //         setPressure(150);
    //     break;
    //     case 2:
    //         setVelocity(50);
    //         setDistance(20);
    //     break;    
    //     case 3:
    //         setEnabled(1);
    //         setSamplingPeriod(10);
    //     default:
    //         qDebug() << "Invalid Command";
    //     break;
    // }

}

void sendCommands::setPressure(uint8_t pressure)
{
    this->interface_message.pressure = pressure;
    //qDebug() << "Pressure = " << this->interface_message.pressure;
}

void sendCommands::setVelocity(uint8_t velocity)
{
    this->interface_message.velocity = velocity;
    //qDebug() << "Velocity = " << this->interface_message.velocity;
}

void sendCommands::setDistance(int8_t distance)
{
    this->interface_message.distance = distance;
    //qDebug() << "Distance = " << this->interface_message.distance;
}

void sendCommands::setEnabled(uint8_t enabled)
{
    this->interface_message.enabled = enabled;
    //qDebug() << "Distance = " << this->interface_message.enabled;
}

void sendCommands::setSamplingPeriod(uint16_t sample_period)
{
    this->interface_message.sample_period = sample_period;
    //qDebug() << "Distance = " << this->interface_message.sample_period;
}


uint16_t sendCommands::getPressure()
{
    return this->interface_message.pressure;
}

uint16_t sendCommands::getVelocity()
{
    return this->interface_message.velocity;
}

int16_t sendCommands::getDistance()
{
    return this->interface_message.distance;
}

uint8_t sendCommands::getEnabled()
{
    return this->interface_message.enabled;
}

uint16_t sendCommands::getSamplingPeriod()
{
    return this->interface_message.enabled;
}
