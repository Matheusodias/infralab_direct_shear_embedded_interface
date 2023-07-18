#include "inc/mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QThread>
//#include <QDesktopWidget>
//#include <QWidget>


int main(int argc, char *argv[])
{
    //qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowFlags(Qt::FramelessWindowHint);

    w.showMaximized();
    QMessageBox::warning(nullptr, "Aviso", "Ligue os sensores de deslocamento!");
    //w.show();

    //Novo
    //w.setGeometry(QApplication::desktop()->screenGeometry()); // define a geometria da janela para ocupar toda a tela
    //w.showFullScreen(); // exibe a janela em modo de tela cheia
    
    

    return a.exec();
    
    
    


}
