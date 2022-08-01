#include <QtTest>
#include <QCoreApplication>

// add necessary includes here
#include <QDebug>
#include "machineclient.h"
#include "../Interface/threadcontroller.h"
#include "../Interface/socket_local.h"
#include <unistd.h>

/**
 * @brief Classe de testes para o socket.
 * 
 * Esta classe testa se o envio e recebimento das mensagens através 
 * do socket local funciona.
 * 
 * 
*/
class SocketTests : public QObject
{
    Q_OBJECT

public:
    
    SocketTests();
    ~SocketTests();
private:
    /**
     * @brief A classe ThreadController cria o socket servidor que irá aguardar a conexão do cliente.
     * 
     * A classe ThreadController cria um objeto da classe receiveData que é uma Thread. Fazendo com que a
     * interface e o serviço dos sockets rode em paralelo.
     */
    ThreadController *test_receiveData; /*!< */
    void compareStructIntElements(int result, int expected);
    void compareStructFloatElements(float result, float expected);

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_receiveDataFromMachine();
    void test_receiveDataFromMachine_data();


};
/**
 * @brief Contrutor da classe de testes do socket.
 * Pode ser utilizado para instanciar classes, diferentes da atual, ou para configurações iniciais.
*/
SocketTests::SocketTests()
{
    this->test_receiveData = new ThreadController();
    qDebug() << "Cria instância do socket test";
}

/**
 * @brief Destrutor da classe de testes do socket.
 * 
 * No destrutor é eliminada a instância test_receiveData da ThreadController.
*/

SocketTests::~SocketTests()
{
    qDebug() << "Destrói instância do socket test";
    delete this->test_receiveData;
}

/**
* \brief Primeiro teste.
* 
* Teste que roda antes de todos os outros testes. Pode ser utilizado para alguma configuração inicial.
*/
void SocketTests::initTestCase()
{
    qDebug() << "Teste antes dos socket test";
}

/**
 * @brief Último teste.
 * 
 * Teste que roda ao final de todos os outros testes. Pode ser utilizado para alguma configuração final dos dados.
 * Como liberação de memória ou algum outro pós-processamento.
 */
void SocketTests::cleanupTestCase()
{
    qDebug() << "Teste depois dos socket test";
}

/**
 * @brief Teste que verifica se a interface está recebendo corretamente os dados da máquina.
 * 
 * Este teste é uma simulação, não é utilizada a máquina real para este teste.
 */
void SocketTests::test_receiveDataFromMachine()
{
    machineClient test_sendData;

    QFETCH(int, number);
    QFETCH(machine_to_interface_message, message);

    test_sendData.sendMessages(number);
    //Tempo mínimo de intervalo entre um envio e outro
    QThread::usleep(100);

    compareStructIntElements(test_receiveData->receiveDataThread->machine_message.sample_number[0],message.sample_number[0]);
    compareStructIntElements(test_receiveData->receiveDataThread->machine_message.sample_number[1],message.sample_number[1]);
    compareStructIntElements(test_receiveData->receiveDataThread->machine_message.date_time[0],message.date_time[0]);
    compareStructIntElements(test_receiveData->receiveDataThread->machine_message.date_time[1],message.date_time[1]);
    compareStructFloatElements(test_receiveData->receiveDataThread->machine_message.displacement[0],message.displacement[0]);
    compareStructFloatElements(test_receiveData->receiveDataThread->machine_message.displacement[1],message.displacement[1]);
    compareStructFloatElements(test_receiveData->receiveDataThread->machine_message.load[0],message.load[0]);
    compareStructFloatElements(test_receiveData->receiveDataThread->machine_message.load[1],message.load[1]);
}

/**
 * @brief Função que possui os dados necessários para realizar o teste test_receiveDataFromMachine.
 * 
 * Funções que terminam com _data nos testes, tem a função de fornecerem os dados para o teste ser executado.
 * Exemplo: test_receiveDataFromMachine e   test_receiveDataFromMachine_data.
 */
void SocketTests::test_receiveDataFromMachine_data()
{
    QTest::addColumn<int>("number");
    QTest::addColumn<machine_to_interface_message>("message");
    
    machine_to_interface_message test_message[100];
    for(int i=0,j=0;i<100;i+=4,j++){
        test_message[j].sample_number[0] = 10 + i;
        test_message[j].sample_number[1] = 20 + i;
        test_message[j].date_time[0] = 30 + i;
        test_message[j].date_time[1] = 40 + i;
        test_message[j].displacement[0] = 50.2 + i;
        test_message[j].displacement[1] = 60.2 + i;;
        test_message[j].load[0] = 70.2 + i;
        test_message[j].load[1] = 80.2 + i;

        QString test_name_temp = QString("Send %1").arg(j);
        std::string str = test_name_temp.toStdString();
        const char* test_name = str.c_str();
        QTest::newRow(test_name) << i << test_message[j];
    }


}

void SocketTests::compareStructIntElements(int result, int expected)
{   
    QCOMPARE(result,expected);
}

void SocketTests::compareStructFloatElements(float result, float expected)
{
    QCOMPARE(result,expected);
}

QTEST_MAIN(SocketTests)

#include "tst_sockettests.moc"
