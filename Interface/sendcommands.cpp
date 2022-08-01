#include "sendcommands.h"

#include <errno.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>

#include <QDebug>

sendCommands::sendCommands()
{
    char temp_socket_name[] = "../infralab_direct_shear_embedded/ClienteServidor/machine";
    strncpy(this->socket_name,temp_socket_name,strlen(temp_socket_name)+1);
    //qDebug() << "Nome do socket = " << this->socket_name << strlen(this->socket_name);
    this->socket_id = socket(PF_LOCAL, SOCK_STREAM,0);

    struct sockaddr send_command;
    strncpy(send_command.sa_data,this->socket_name,strlen(this->socket_name)+1);
    send_command.sa_family = AF_LOCAL;

    qDebug() << "Nome do socket = " << send_command.sa_data << strlen(send_command.sa_data);
    uint8_t socket_size = strlen(send_command.sa_data) + sizeof(send_command.sa_family);
    if(connect(this->socket_id, &send_command, socket_size)!=0){
        close(this->socket_id);
        qDebug () << "Error connecting client: " << strerror(errno);
    }
}

sendCommands::~sendCommands()
{
    close(this->socket_id);
    qDebug() << "Close";
}

int16_t sendCommands::sendMessage()
{
    qDebug("send message");
    int16_t status = write(socket_id, this->interface_message.payload, interface_payload_size);
    return status;
}

void sendCommands::setCommand(uint8_t command)
{

    this->interface_message.command = command;

    switch (command)
    {
        case 1:
            setPressure(150);
        break;
        case 2:
            setVelocity(50);
            setDistance(20);
        break;    

        default:
            qDebug() << "Invalid Command";
        break;
    }

}

void sendCommands::setPressure(uint8_t pressure)
{
    this->interface_message.pressure = pressure;
    qDebug() << "Pressure = " << this->interface_message.pressure;
}

void sendCommands::setVelocity(uint8_t velocity)
{
    this->interface_message.velocity = velocity;
    qDebug() << "Velocity = " << this->interface_message.velocity;
}

void sendCommands::setDistance(int8_t distance)
{
    this->interface_message.distance = distance;
    qDebug() << "Distance = " << this->interface_message.distance;
}

