#ifndef RECEIVEDATA_H
#define RECEIVEDATA_H

#include <QThread>

#include "socket_local.h"
#include "table.h"

class receiveData : public QThread
{
    Q_OBJECT
    private:
        void readClientMessage();
        void run() override;
        Table * shear_densification_variables;


    public:
        char server_socket_name[100];
        int  server_socket_id;
        int  client_socket_id;
        uint8_t errorOccurred;;
        receiveData(QObject * parent = nullptr,Table * shear_densification_variables = nullptr);
        ~receiveData();
        uint8_t initSocketServer();
        void init();
        machine_to_interface_message machine_message;

    public slots:

    signals:
        void data_arrived();       

};

#endif // RECEIVEDATA_H
