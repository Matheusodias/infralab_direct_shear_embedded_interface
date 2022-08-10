#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setupButtons =new Button();
    setupButtons->setButtonShadow(ui->historyButton);
    setupButtons->setButtonShadow(ui->experimentButton);
    setupButtons->setButtonShadow(ui->pushButton);




}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_historyButton_clicked()
{
    bool state = ui->historyButton->isChecked();
    if(state){
        setupButtons->setButtonStyleSheet(ui->historyButton, historyButton_darkOption);
    } else {
        setupButtons->setButtonStyleSheet(ui->historyButton, historyButton_lightOption);
    }

}

