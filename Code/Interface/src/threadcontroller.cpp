#include <QDebug>
#include <stdint.h>

#include "inc/threadcontroller.h"
#include "inc/receivedata.h"

/**
 * @brief Construtor da classe Thread Controller.
 * 
 * Responsável por instância e iniciar a thread da classe receiveData.
 * 
 * @param parent 
 */
ThreadController::ThreadController(QObject *parent)
    : QObject{parent}
{

    this->receiveDataThread = new receiveData;
    this->isThreadDestroyed = false;
    
    connect(this->receiveDataThread, &receiveData::finished,this, &ThreadController::receiveThreadFinishedSlot);
    
    this->receiveDataThread->init();
}

/**
 * @brief Destrutor da classe ThreadController.
 * 
 * Responsável por encerrar corretamente a thread da classe receiveData.
 */
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

/**
 * @brief Esse slot é disparado quando a thread da classe receiveData termina antes da classe ThreadController. 
 * 
 * Quando isso ocorre, é deletado a instância da classe receiveData.
 * 
 */
void ThreadController::receiveThreadFinishedSlot()
{
    qDebug("Thread terminou antes");
    delete this->receiveDataThread;
}
