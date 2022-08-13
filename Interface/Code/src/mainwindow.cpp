#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setupButtons =new Button();



    setupButtons->initialConfiguration_OutsideExperimentHeaderButtons(ui->outside_experiment_header_layout);

    ui->outside_experiment_stack->setCurrentIndex(2);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_historyButton_clicked()
{
    ui->outside_experiment_stack->setCurrentIndex(0);

    this->setupButtons->changeButtonStyle(ui->historyButton,historyButton_LightIcon);
}


void MainWindow::on_experimentButton_clicked()
{
    ui->outside_experiment_stack->setCurrentIndex(2);
    this->setupButtons->changeButtonStyle(ui->experimentButton,experimentButton_LightIcon);
}


void MainWindow::on_configurationButton_clicked()
{
    ui->outside_experiment_stack->setCurrentIndex(1);
    this->setupButtons->changeButtonStyle(ui->configurationButton,configurationButton_LightIcon);
}

