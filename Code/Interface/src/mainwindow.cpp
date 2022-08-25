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
    this->setupButtons =new Button();
    // Insert buttons styles on header outside experiment
    this->setupButtons->initialButtonStyling(ui->outside_experiment_header_layout, headerButton_lightBackgroundColor);
    // Mark experiment button as first page
    this->setupButtons->changeButton_style(ui->experimentButton,experimentButton_lightIcon,headerButton_lightBackgroundColor);
    ui->outside_experiment_stack->setCurrentIndex(2);

    // Insert style of phases buttons
    this->setupButtons->initialButtonStyling(ui->phases_layout, phasesButton_lightBackgroundColor);

    this->setupButtons->setButton_style_icon(ui->continuePhase1_button, continueButton_BackgroundColor, continueButton_Icon, 1);
    this->setupButtons->setButtonShadow((void *)ui->continuePhase1_button,1);

    connect(ui->continuePhase1_button,SIGNAL(clicked()),this,SLOT(nextPhase()));
    connect(ui->phase3_button,SIGNAL(clicked()),this,SLOT(changePhase()));
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


void MainWindow::on_phase1_button_clicked()
{
    changePhasePage(0,ui->phase1_button);
}


void MainWindow::on_phase2_button_clicked()
{
    changePhasePage(1,ui->phase2_button);
}


void MainWindow::on_phase3_button_clicked()
{
    changePhasePage(2,ui->phase3_button);
}


void MainWindow::on_calculations_button_clicked()
{
    changePhasePage(3,ui->calculations_button);
}


void MainWindow::on_position_button_clicked()
{
    changePhasePage(4,ui->position_button);
}

void MainWindow::changePhasePage(uint8_t phase, QPushButton * button)
{
   ui->phases_stack->setCurrentIndex(phase);
   this->setupButtons->changeButton_style(button,no_icon,phasesButton_lightBackgroundColor);
}

void MainWindow::nextPhase()
{
    int current_page = ui->phases_stack->currentIndex();
    int next_page = current_page + 1;
    QPushButton * button = qobject_cast<QPushButton*>(ui->phases_layout->itemAt(next_page)->widget());
    changePhasePage(next_page, button);
}

void MainWindow::changePhase()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    int next_page = 0;
    if(buttonSender->objectName() == "phase2_button"){
        next_page = 1;
    } else if(buttonSender->objectName() == "phase3_button"){
        next_page = 2;
    } else if(buttonSender->objectName() == "calculations_button"){
        next_page = 3;
    } else if(buttonSender->objectName() == "calculations_button"){
        next_page = 4;
    }

//    for (int i = 0; i < layout->count(); ++i){
//        QPushButton * button = qobject_cast<QPushButton*>(layout->itemAt(i)->widget());
//        if(button){
//            this->setButtonShadow((void *)button,0);
//            button->setStyleSheet(this->button_styleSheets[style_option]);
//        }
//   }

    changePhasePage(next_page,buttonSender);
//
}

