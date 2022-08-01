#ifndef THREADCONTROLLER_H
#define THREADCONTROLLER_H

#include <QObject>
#include <QThread>

#include "receivedata.h"

class ThreadController : public QObject
{
    Q_OBJECT
    
    
    private:
        
        bool isThreadDestroyed;

    public:
        receiveData *receiveDataThread;
        ThreadController(QObject *parent = nullptr);
        ~ThreadController();


    public slots:
        void receiveThreadFinishedSlot();
        

    signals:
    
    
    

};

#endif // THREADCONTROLLER_H
