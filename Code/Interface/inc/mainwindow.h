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

    void nextPhase();

    void changePhase();

    void changeOutsideExperimentPage();

private:
    Ui::MainWindow *ui; /*!< Instância da classe e serve para operar seus elementos, como botões.*/
    Button *setupButtons; /*!< Instância da classe Button para a estilização dos botões.*/

    void InitialConfiguration_OutsideExperimentHeaderButtons();
    void InitialConfiguration_PhasesButtons();

    void connectButtonsToSlots_Layout(QHBoxLayout * list, const char *signal, const char *slot);

    void connectButtonsToSlots_Widget(QObject * list, const char *signal, const char *slot);
    void changePage(QToolButton* buttonSender,QString buttons_name[5], uint8_t array_size, QStackedWidget * page_stack,uint8_t icon[3],uint8_t style);

};
#endif // MAINWINDOW_H
