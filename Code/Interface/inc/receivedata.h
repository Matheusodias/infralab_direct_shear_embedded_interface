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
        uint32_t previous_sample_number;
        Table *interface_tables;

    public:
        char server_socket_name[100];
        int  server_socket_id;
        int  client_socket_id;
        uint8_t errorOccurred;;
        receiveData(QObject * parent = nullptr,Table *interface_tables = nullptr);
        ~receiveData();
        uint8_t initSocketServer();
        void init();
        machine_to_interface_message machine_message;

    public slots:

    signals:
        

};

#endif // RECEIVEDATA_H
