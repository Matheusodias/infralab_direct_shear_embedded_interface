#include "inc/mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

/**
 * @brief Constrói uma nova janela principal.
 * 
 * É o construtor da janela principal da interface.
 * 
 * @param parent 
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setInputMethodHints(inputMethodHints() | Qt::InputMethodHint::ImhDigitsOnly);
    this->setupButtons = new Button();

    InitialConfiguration_OutsideExperimentHeaderButtons();
    InitialConfiguration_PhasesButtons();
}


/**
 * @brief Destrói a janela principal.
 * 
 * Destrói a instância ui;
 * 
 */
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitialConfiguration_OutsideExperimentHeaderButtons()
{
    // Insert buttons styles on header outside experiment
    this->setupButtons->initialButtonStyling(ui->outside_experiment_header_layout, headerButton_lightBackgroundColor);
    this->setupButtons->initialButtonStyling2(ui->outside_experiment_header_layout, 5);
    // Mark experiment button as first page
    this->setupButtons->changeButton_style(ui->experimentButton,experimentButton_lightIcon,headerButton_lightBackgroundColor);
    ui->outside_experiment_stack->setCurrentIndex(2);
    qDebug() << "Antes";
    connectButtonsToSlots_Layout(ui->outside_experiment_header_layout, SIGNAL(clicked()), SLOT(changeOutsideExperimentPage()), tool_button);
    qDebug() << "Depois";
}

void MainWindow::InitialConfiguration_PhasesButtons()
{
    // Insert style of phases buttons
    this->setupButtons->initialButtonStyling(ui->phases_layout, phasesButton_lightBackgroundColor);
    this->setupButtons->changeButton_style(ui->phase1_button,no_icon,phasesButton_lightBackgroundColor);
    ui->phases_stack->setCurrentIndex(0);

    connectButtonsToSlots_Layout(ui->phases_layout, SIGNAL(clicked()), SLOT(changePhase()), push_button);



    this->setupButtons->setButton_style_icon(ui->continuePhase1_button, continueButton_BackgroundColor, continueButton_Icon, 1);
    this->setupButtons->setButtonShadow((void *)ui->continuePhase1_button,1);
    connectButtonsToSlots_Widget(ui->phases_stack, SIGNAL(clicked()),SLOT(nextPhase()),tool_button);

}


/**
 * @brief Função ativada ao clicar no botão do histórico.
 * 
 * Altera a página atual e a estilização do botão selecionado.
 */
void MainWindow::on_historyButton_clicked()
{
    ui->outside_experiment_stack->setCurrentIndex(0);

    this->setupButtons->changeButton_style(ui->historyButton,historyButton_lightIcon, headerButton_lightBackgroundColor);
}

/**
 * @brief Função ativada ao clicar no botão do experimento.
 * 
 * Altera a página atual e a estilização do botão selecionado.
 */
void MainWindow::on_experimentButton_clicked()
{
    ui->outside_experiment_stack->setCurrentIndex(2);
    this->setupButtons->changeButton_style(ui->experimentButton,experimentButton_lightIcon, headerButton_lightBackgroundColor);
}

/**
 * @brief Função ativada ao clicar no botão das configurações.
 * 
 * Altera a página atual e a estilização do botão selecionado.
 */
void MainWindow::on_configurationButton_clicked()
{
    ui->outside_experiment_stack->setCurrentIndex(1);
    this->setupButtons->changeButton_style(ui->configurationButton,configurationButton_lightIcon, headerButton_lightBackgroundColor);
}

void MainWindow::connectButtonsToSlots_Layout(QHBoxLayout *boxlayout, const char *signal, const char *slot, uint8_t isToolButton)
{
    QLayout *layout = boxlayout->layout();
    if (layout) {
        for (int i = 0; i < layout->count(); ++i){
            if(isToolButton){
               QToolButton * button = qobject_cast<QToolButton*>(layout->itemAt(i)->widget());
               if(button){
                    connect(button, signal,this,slot);
               }

            } else {
                QPushButton * button = qobject_cast<QPushButton*>(layout->itemAt(i)->widget());
                if(button){
                     connect(button, signal,this,slot);
                }
            }
       }
    }
}

void MainWindow::connectButtonsToSlots_Widget(QObject *selectedWidget, const char *signal, const char *slot, uint8_t isToolButton)
{
   if(isToolButton){
       QList<QToolButton*> selectedButtons =
                   selectedWidget->findChildren<QToolButton*>();
       for(QList<QToolButton *>::iterator buttons = selectedButtons.begin();buttons != selectedButtons.end(); buttons++){
           connect(*buttons, signal,this,slot);
       }
   } else{
       QList<QPushButton*> selectedButtons =
                   selectedWidget->findChildren<QPushButton*>();
       for(QList<QPushButton *>::iterator buttons = selectedButtons.begin();buttons != selectedButtons.end(); buttons++){
           connect(*buttons, signal,this,slot);
       }
   }
   return;

}

void MainWindow::nextPhase()
{
    int current_page = ui->phases_stack->currentIndex();
    int next_page = current_page + 1;

    QPushButton * button = qobject_cast<QPushButton*>(ui->phases_layout->itemAt(next_page)->widget());
    ui->phases_stack->setCurrentIndex(next_page);
    this->setupButtons->changeButton_style(button,no_icon,phasesButton_lightBackgroundColor);
}

void MainWindow::changePhase()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    int next_page = 0;
    QString object_name = buttonSender->objectName();
    if( object_name == "phase2_button"){
        next_page = 1;
    } else if(object_name == "phase3_button"){
        next_page = 2;
    } else if(object_name == "calculations_button"){
        next_page = 3;
    } else if(object_name == "position_button"){
        next_page = 4;
    }
    ui->phases_stack->setCurrentIndex(next_page);
    this->setupButtons->changeButton_style(buttonSender,no_icon,phasesButton_lightBackgroundColor);
}

void MainWindow::changeOutsideExperimentPage()
{
    QToolButton* buttonSender = qobject_cast<QToolButton*>(sender()); // retrieve the button you have clicked
    int next_page = 0;
    QString object_name = buttonSender->objectName();
    QString buttons_name[] = {"toolButton","toolButton_2","toolButton_3"};/*{"historyButton","configurationButton","experimentButton"};*/
    for(int i=0;i<3;i++){
        if(object_name == buttons_name[i]){
            next_page = i;
        }
    }
     ui->outside_experiment_stack->setCurrentIndex(next_page);
    //this->setupButtons->changeButton_style(buttonSender,no_icon,phasesButton_lightBackgroundColor);
}

