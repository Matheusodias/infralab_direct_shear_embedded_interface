#include <QDebug>
#include <stdint.h>

#include "threadcontroller.h"
#include "receivedata.h"

ThreadController::ThreadController(QObject *parent)
    : QObject{parent}
{

    this->receiveDataThread = new receiveData;
    this->isThreadDestroyed = false;
    
    connect(this->receiveDataThread, &receiveData::finished,this, &ThreadController::receiveThreadFinishedSlot);
    
    this->receiveDataThread->init();
}

ThreadController::~ThreadController() {
    qDebug("Terminei a controller");
    if(this->receiveDataThread->isRunning()){
        qDebug("Controller terminou antes");
        this->receiveDataThread->quit();
        this->receiveDataThread->wait(1);
        // a thread não consegue sair no quit com o accept, mas no read sim.
        // Caso demore mais de 1 segundo para sair, pode dar terminate na thread.
        if(this->receiveDataThread->isRunning())
        {
            this->receiveDataThread->terminate();
            this->receiveDataThread->wait();
        }
        delete this->receiveDataThread;
    }
}


void ThreadController::receiveThreadFinishedSlot()
{
    qDebug("Thread terminou antes");
    delete this->receiveDataThread;
}
