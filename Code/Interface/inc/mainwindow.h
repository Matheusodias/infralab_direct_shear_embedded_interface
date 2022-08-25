#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "button.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
/**
 * @brief Classe que instância a janela principal da interface.
 * 
 * É a janela prinicipal da aplicação.
 * 
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_historyButton_clicked();

    void on_experimentButton_clicked();

    void on_configurationButton_clicked();

    void on_phase1_button_clicked();

    void on_phase2_button_clicked();

    void on_phase3_button_clicked();

    void on_calculations_button_clicked();

    void on_position_button_clicked();

    void nextPhase();

    void changePhase();

private:
    Ui::MainWindow *ui; /*!< Instância da classe e serve para operar seus elementos, como botões.*/
    Button *setupButtons; /*!< Instância da classe Button para a estilização dos botões.*/

    void changePhasePage(uint8_t phase, QPushButton * button);


};
#endif // MAINWINDOW_H
