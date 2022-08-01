#ifndef RECEIVEDATA_H
#define RECEIVEDATA_H

#include <QThread>

#include "socket_local.h"

class receiveData : public QThread
{
    private:
        
        
        
        void readClientMessage();
        void run() override;

    public:
        char server_socket_name[100];
        int  server_socket_id;
        int  client_socket_id;
        receiveData(QObject * parent = nullptr);
        ~receiveData();
        void init();
        machine_to_interface_message machine_message;

    public slots:

    signals:
        

};

#endif // RECEIVEDATA_H
