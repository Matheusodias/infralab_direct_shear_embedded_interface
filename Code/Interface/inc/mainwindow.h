#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolButton>
#include <QStackedWidget>
#include <QTimer>
#include "button.h"
#include "field.h"
#include "table.h"
#include "threadcontroller.h"
#include "sendcommands.h"
#include "dbmanager.h"
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
    Experiment * info_variables;
    DBManager * my_db;

private slots:

    void nextPhase();

    void changePhase();

    void changeOutsideExperimentPage();

    void changeInitialPositionValue();

    void onPositionButton_pressed();

    void onPositionButton_released();




    void on_initExperiment_toolButton_clicked();

    void on_releasePressure_toolButton_clicked();

private:
    Ui::MainWindow *ui; /*!< Instância da classe e serve para operar seus elementos, como botões.*/
    Button *setupButtons; /*!< Instância da classe Button para a estilização dos botões.*/
    Field *setupFields;
    Table *tables;
    ThreadController *receive_data;
    sendCommands *send_data;
    QTimer * timer;

    void fillTextEditForTests();
    void InitialConfiguration_OutsideExperimentHeaderButtons();
    void InitialConfiguration_InsideExperimentHeaderButtons();
    void InitialConfiguration_PhasesButtons();
    void InitialConfiguration_PhasesFields();
    void InitialConfiguration_Tables();
    void CreateDataseTables();

    void connectButtonToSlots_WithArguments(QHBoxLayout * boxlayout, QStackedWidget * stack_widget, int option);
    void connectButtonsToSlots_Layout(QHBoxLayout * list, const char *signal, const char *slot);
    void connectButtonsToSlots_Widget(QObject * list, const char *signal, const char *slot);
    void changePage(QToolButton* buttonSender,QString buttons_name[6], uint8_t array_size, QStackedWidget * page_stack,uint8_t icon[3],uint8_t style);

};
#endif // MAINWINDOW_H
