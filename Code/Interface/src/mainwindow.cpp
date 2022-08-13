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

    setupButtons =new Button();
    setupButtons->initialConfiguration_OutsideExperimentHeaderButtons(ui->outside_experiment_header_layout);
    ui->outside_experiment_stack->setCurrentIndex(2);
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

    this->setupButtons->changeButtonStyle(ui->historyButton,historyButton_LightIcon);
}

/**
 * @brief Função ativada ao clicar no botão do experimento.
 * 
 * Altera a página atual e a estilização do botão selecionado.
 */
void MainWindow::on_experimentButton_clicked()
{
    ui->outside_experiment_stack->setCurrentIndex(2);
    this->setupButtons->changeButtonStyle(ui->experimentButton,experimentButton_LightIcon);
}

/**
 * @brief Função ativada ao clicar no botão das configurações.
 * 
 * Altera a página atual e a estilização do botão selecionado.
 */
void MainWindow::on_configurationButton_clicked()
{
    ui->outside_experiment_stack->setCurrentIndex(1);
    this->setupButtons->changeButtonStyle(ui->configurationButton,configurationButton_LightIcon);
}

