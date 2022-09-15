#include "../../Interface/inc/receivedata.h"
#include<QDebug>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

receiveData::receiveData(QObject * parent,Table * shear_densification_variables): QThread(parent)
{
    this->shear_densification_variables = shear_densification_variables;
    

}

receiveData::~receiveData()
{
    qDebug() << "Fechei o servidor";
    unlink(this->server_socket_name);
    close(this->server_socket_id);
    close(this->client_socket_id);
}

uint8_t receiveData::initSocketServer()
{
    this->errorOccurred=0;
    struct sockaddr receive_data;
    this->server_socket_id = socket(PF_LOCAL, SOCK_STREAM, 0);
    char path[] = "./interface";
    strncpy(this->server_socket_name,path,strlen(path)+1);

    receive_data.sa_family = AF_LOCAL;
    strncpy(receive_data.sa_data, this->server_socket_name,strlen(this->server_socket_name)+1);

    uint8_t socket_size = strlen(receive_data.sa_data) + sizeof(receive_data.sa_family);

    if(bind(this->server_socket_id, &receive_data, socket_size)!=0)
    {
        qDebug () << "Error no bind do server socket id: " << strerror(errno);
        this->errorOccurred=1;
        return 0;
    }

    //qDebug() << "Nome do socket = " << receive_data.sa_data;
    if(listen(this->server_socket_id,2)!=0)
    {
        qDebug () << "Error in server listen: " << strerror(errno);
        this->errorOccurred=1;
        return 0;
    }

    return 1;
}

void receiveData::init()
{
    // qualquer operação antes do start pode ser posta aqui
    this->start();
    if(this->isRunning())
    {
        qDebug("thread iniciando ..");
    }
}

void receiveData::run()
{
    while(1){
        if(this->errorOccurred){
            qDebug() << "Um erro anterior impediu que o socket servidor fosse iniciado. Por favor tente ligar o servidor novamente";
            break;
        }
        struct sockaddr clienteAddr;
        socklen_t clienteLength = sizeof(( struct sockaddr *) & clienteAddr);
        qDebug() << "Antes do accept interface";
        this->client_socket_id = accept(this->server_socket_id, &clienteAddr, &clienteLength);
        if(this->client_socket_id<0)
        {
            qDebug () << "Error no accept do servidor: " << strerror(errno);
            break;
        }
        qDebug() << "Depois do accept interface";
        readClientMessage();
    }
    qDebug() << "Terminou a run";

}


void receiveData::readClientMessage()
{
    while(1){
        int value = read(this->client_socket_id,&this->machine_message.payload,machine_payload_size);
        if(value<=0){
            //qDebug() << this->machine_message.sample_number == this->previous_sample_number;
            break;
        };
        qDebug() << "SampleNumber" << this->machine_message.sample_number;
        //qDebug() << "DateTime" << this->machine_message.date_time;
        qDebug() << "Displacement[0]" << this->machine_message.displacement[0];
        qDebug() << "Displacement[1]" << this->machine_message.displacement[1];
        qDebug() << "Load[0]" << this->machine_message.load[0];
        qDebug() << "Load[1]" << this->machine_message.load[1];
        qDebug() << "State" << this->machine_message.state << Qt::endl;

        if(this->shear_densification_variables->table_variables->getExperimentStarted()==true){
            this->shear_densification_variables->table_variables->densification_variables.setDensificationVariables
            (this->machine_message.sample_number, this->machine_message.displacement[0], this->machine_message.load[0]);
            QStringList data = this->shear_densification_variables->table_variables->updateDensificationTable();
            this->shear_densification_variables->updateData_DynamicTable(data, densification_phase);
            this->shear_densification_variables->updateData_DynamicTable(data, shear_phase);
            
        }

        
        
        // = updateDensificationTable();

        // update densification table
        // update shear table

    }
}
