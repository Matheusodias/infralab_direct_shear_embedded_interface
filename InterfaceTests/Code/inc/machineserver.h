#ifndef MACHINESERVER_H
#define MACHINESERVER_H

#include <QThread>
#include "../Interface/Code/inc/socket_local.h"

class machineServer : public QThread
{
    Q_OBJECT
    public:
        machineServer(QObject * parent = nullptr);
        ~machineServer();
        void init();
        char server_socket_name[100];
        int  server_socket_id;
        int  client_socket_id;
        interface_to_machine_message interface_message;
        uint8_t errorOccurred;

    private:
        void run() override;
        void accept_clients();
        void read_interface_message();

};

#endif // MACHINESERVER_H
