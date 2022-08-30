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
    this->setupButtons->initialButtonStyling_Layout(ui->outside_experiment_header_layout, headerButton_lightBackgroundColor, outsideExperiment_buttonSize);
    // Mark experiment button as first page
    this->setupButtons->changeButton_style(ui->experimentButton,experimentButton_lightIcon,headerButton_lightBackgroundColor);
    ui->outside_experiment_stack->setCurrentIndex(2);
    connectButtonsToSlots_Layout(ui->outside_experiment_header_layout, SIGNAL(clicked()), SLOT(changeOutsideExperimentPage()));
}

void MainWindow::InitialConfiguration_PhasesButtons()
{
    // Insert style of phases buttons
    this->setupButtons->initialButtonStyling_Layout(ui->phases_layout, phasesButton_lightBackgroundColor,phases_buttonSize);
    this->setupButtons->changeButton_style(ui->phase1_button,no_icon,phasesButton_lightBackgroundColor);
    ui->phases_stack->setCurrentIndex(0);
    connectButtonsToSlots_Layout(ui->phases_layout, SIGNAL(clicked()), SLOT(changePhase()));

    this->setupButtons->initialButtonStyling_Widget(ui->phases_stack, continueButton_BackgroundColor, phases_buttonSize);

    //this->setupButtons->setButton_style_icon(ui->continuePhase1_button, continueButton_BackgroundColor, continueButton_Icon);
    //this->setupButtons->setButtonShadow(ui->continuePhase1_button);
    connectButtonsToSlots_Widget(ui->phases_stack, SIGNAL(clicked()),SLOT(nextPhase()));

}

void MainWindow::connectButtonsToSlots_Layout(QHBoxLayout *boxlayout, const char *signal, const char *slot)
{
    QLayout *layout = boxlayout->layout();
    if (layout) {
        for (int i = 0; i < layout->count(); ++i){
           QToolButton * button = qobject_cast<QToolButton*>(layout->itemAt(i)->widget());
           if(button){
                connect(button, signal,this,slot);
           }
       }
    }
}

void MainWindow::connectButtonsToSlots_Widget(QObject *selectedWidget, const char *signal, const char *slot)
{
   QList<QToolButton*> selectedButtons = selectedWidget->findChildren<QToolButton*>();
   for(QList<QToolButton *>::iterator buttons = selectedButtons.begin();buttons != selectedButtons.end(); buttons++){
       connect(*buttons, signal,this,slot);
   }
   return;
}

void MainWindow::changePage(QToolButton *buttonSender, QString buttons_name[5], uint8_t array_size, QStackedWidget * page_stack, uint8_t icon[], uint8_t style)
{
    QString object_name = buttonSender->objectName();
    int next_page = 0;
    for(int i=0;i<array_size;i++){
        if(object_name == buttons_name[i]){
            next_page = i;
        }
    }
    uint8_t choosen_icon = icon?icon[next_page]:no_icon;
    page_stack->setCurrentIndex(next_page);
    this->setupButtons->changeButton_style(buttonSender, choosen_icon, style);
}

void MainWindow::nextPhase()
{
    int current_page = ui->phases_stack->currentIndex();
    int next_page = current_page + 1;

    QToolButton * button = qobject_cast<QToolButton*>(ui->phases_layout->itemAt(next_page)->widget());
    ui->phases_stack->setCurrentIndex(next_page);
    this->setupButtons->changeButton_style(button,no_icon,phasesButton_lightBackgroundColor);
}

void MainWindow::changePhase()
{
    QToolButton* buttonSender = qobject_cast<QToolButton*>(sender()); // retrieve the button you have clicked
    QString buttons_name[5] = {"phase1_button","phase2_button","phase3_button","calculations_button","position_button"};
    uint8_t array_size = sizeof(buttons_name)/sizeof(buttons_name[0]);
    changePage(buttonSender, buttons_name, array_size, ui->phases_stack, NULL, phasesButton_lightBackgroundColor);
}

void MainWindow::changeOutsideExperimentPage()
{
    QToolButton* buttonSender = qobject_cast<QToolButton*>(sender()); // retrieve the button you have clicked
    QString buttons_name[] = {"historyButton","configurationButton","experimentButton"};
    uint8_t icon[3] = {historyButton_lightIcon,configurationButton_lightIcon,experimentButton_lightIcon};
    uint8_t array_size = sizeof(buttons_name)/sizeof(buttons_name[0]);
    changePage(buttonSender, buttons_name, array_size, ui->outside_experiment_stack, icon,headerButton_lightBackgroundColor);
}


