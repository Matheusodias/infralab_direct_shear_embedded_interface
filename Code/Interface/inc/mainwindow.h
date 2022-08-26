#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolButton>
#include <QStackedWidget>
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

    void nextPhase();

    void changePhase();

private:
    Ui::MainWindow *ui; /*!< Instância da classe e serve para operar seus elementos, como botões.*/
    Button *setupButtons; /*!< Instância da classe Button para a estilização dos botões.*/

    void InitialConfiguration_OutsideExperimentHeaderButtons();
    void InitialConfiguration_PhasesButtons();

    void connectButtonsToSlots(void * list, const char *signal, const char *slot, uint8_t isLayout, uint8_t isToolButton);

    void connectButtonsToSlots_Layout(QHBoxLayout * list, const char *signal, const char *slot, uint8_t isToolButton);

    void connectButtonsToSlots_Widget(QObject * list, const char *signal, const char *slot, uint8_t isToolButton);


};
#endif // MAINWINDOW_H
