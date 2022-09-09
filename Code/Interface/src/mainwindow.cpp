#include "inc/mainwindow.h"
#include "ui_mainwindow.h"
#include "inc/field.h"
#include<QDebug>
#include <QLineEdit>
#include <QSignalMapper>
#include "inc/experiment.h"

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
    ui->mainStack->setCurrentIndex(1);
    //ui->lineEdit->setInputMethodHints(inputMethodHints() | Qt::InputMethodHint::ImhDigitsOnly);
    this->setupButtons = new Button();

    this->info_variables = new Experiment();
    this->setupFields = new Field(this->info_variables);
    this->phasesTable = new Table(this->info_variables);


    InitialConfiguration_OutsideExperimentHeaderButtons();
    InitialConfiguration_InsideExperimentHeaderButtons();
    InitialConfiguration_PhasesButtons();
    InitialConfiguration_PhasesFields();
    InitialConfiguration_Tables();


    connect(ui->sampleDescription_lineEdit, SIGNAL(editingFinished()),this->setupFields, SLOT(setVariables()));

    this->timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT( changeInitialPositionValue()) );





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
    this->setupButtons->changeButton_style(ui->experimentButton,experimentButton_lightIcon,headerButton_lightBackgroundColor,0);
    ui->outside_experiment_stack->setCurrentIndex(2);
    connectButtonsToSlots_Layout(ui->outside_experiment_header_layout, SIGNAL(clicked()), SLOT(changeOutsideExperimentPage()));
}

void MainWindow::InitialConfiguration_InsideExperimentHeaderButtons()
{
    this->setupButtons->initialButtonStyling_Layout(ui->inside_experiment_header_layout, headerButton_lightBackgroundColor, outsideExperiment_buttonSize);
    this->setupButtons->initialButtonStyling_Layout(ui->densificationHeader_layout, phasesButton_lightBackgroundColor,phases_buttonSize);
    this->setupButtons->initialButtonStyling_Layout(ui->shearHeader_layout, phasesButton_lightBackgroundColor,phases_buttonSize);



    connectButtonToSlots_WithArguments(ui->densification_button,ui->insideExperiment_stack);
    connectButtonToSlots_WithArguments(ui->shear_button,ui->insideExperiment_stack);
    connectButtonToSlots_WithArguments(ui->info_button,ui->insideExperiment_stack);




//    connect(ui->densification_button, &QToolButton::clicked,  this->setupButtons, [this]{
//        this->setupButtons->changeHeaderPage_InsideExperiment(ui->insideExperiment_stack); });
//    connect(ui->shear_button, &QToolButton::clicked,  this->setupButtons, [this]{
//        this->setupButtons->changeHeaderPage_InsideExperiment(ui->insideExperiment_stack); });
//    connect(ui->info_button, &QToolButton::clicked,  this->setupButtons, [this]{
//        this->setupButtons->changeHeaderPage_InsideExperiment(ui->insideExperiment_stack); });



    connect(ui->densificationGraphs_toolButton, &QToolButton::clicked,  this->setupButtons, [this]{
        this->setupButtons->changePage_InsideExperiment(ui->densification_stack,true); });

    connect(ui->densificationTable_toolButton, &QToolButton::clicked,  this->setupButtons, [this]{
        this->setupButtons->changePage_InsideExperiment(ui->densification_stack,true); });

    connect(ui->densificationResult_toolButton, &QToolButton::clicked,  this->setupButtons, [this]{
        this->setupButtons->changePage_InsideExperiment(ui->densification_stack,true); });





}

void MainWindow::InitialConfiguration_PhasesButtons()
{
    // Insert style of phases buttons
    this->setupButtons->initialButtonStyling_Layout(ui->phases_layout, phasesButton_lightBackgroundColor,phases_buttonSize);
    this->setupButtons->changeButton_style(ui->phase1_button,no_icon,phasesButton_lightBackgroundColor,1);
    ui->phases_stack->setCurrentIndex(0);
    connectButtonsToSlots_Layout(ui->phases_layout, SIGNAL(clicked()), SLOT(changePhase()));

    this->setupButtons->initialButtonStyling_Widget(ui->phases_stack, continueButton_BackgroundColor, phases_continueButtonSize);

    this->setupButtons->initExperiment_ButtonStyle(ui->initExperiment_toolButton);


    //this->setupButtons->setButton_style_icon(ui->continuePhase1_button, continueButton_BackgroundColor, continueButton_Icon);
    //this->setupButtons->setButtonShadow(ui->continuePhase1_button);
    connectButtonsToSlots_Widget(ui->phase1_page, SIGNAL(clicked()),SLOT(nextPhase()));
    connectButtonsToSlots_Widget(ui->phase2_page, SIGNAL(clicked()),SLOT(nextPhase()));
    connectButtonsToSlots_Widget(ui->phase3_page, SIGNAL(clicked()),SLOT(nextPhase()));
    connectButtonsToSlots_Widget(ui->calculations_page, SIGNAL(clicked()),SLOT(nextPhase()));

    connectButtonsToSlots_Layout(ui->positionLayout, SIGNAL(clicked()), SLOT(changeInitialPositionValue()));
    connectButtonsToSlots_Layout(ui->positionLayout, SIGNAL(pressed()), SLOT(onPositionButton_pressed()));
    connectButtonsToSlots_Layout(ui->positionLayout, SIGNAL(released()), SLOT(onPositionButton_released()));

}

void MainWindow::InitialConfiguration_PhasesFields()
{
    this->setupFields->customizeField(ui->phase1_gridLayout);
    this->setupFields->customizeField(ui->phase2_gridLayout);
    this->setupFields->customizeField(ui->phase3_gridLayout);

    this->setupFields->customizeOneField(ui->initialPosition_label, ui->initialPosition_lineEdit);
    ui->initialPosition_lineEdit->setAlignment(Qt::AlignCenter);
    ui->initialPosition_lineEdit->setFont(QFont ( "Ubuntu", 30, QFont::Normal));
}

void MainWindow::InitialConfiguration_Tables()
{
    this->phasesTable->customizeTable(ui->phases_tableWidget);
    this->phasesTable->initialConfig_TablePhases(ui->phases_tableWidget);
}

void MainWindow::connectButtonToSlots_WithArguments(QToolButton *senderButton, QStackedWidget * stack_widget)
{

//    QLayout *layout = boxlayout->layout();
//    if (layout) {
//        for (int i = 0; i < layout->count(); ++i){
//           QToolButton * button = qobject_cast<QToolButton*>(layout->itemAt(i)->widget());

//           if(button){
//                connect(button, signal,this,slot);
//           }
//       }
//    }



    connect(senderButton, &QToolButton::clicked,  this->setupButtons, [this, stack_widget]{
        this->setupButtons->changeHeaderPage_InsideExperiment(stack_widget); });
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
    uint8_t pos = icon? 0:1;
    page_stack->setCurrentIndex(next_page);
    this->setupButtons->changeButton_style(buttonSender, choosen_icon, style, pos);

    if(next_page == 3){
        this->phasesTable->updateData_TablePhases(ui->phases_tableWidget);
    }
}

void MainWindow::nextPhase()
{
    int current_page = ui->phases_stack->currentIndex();
    int next_page = current_page + 1;

    QToolButton * button = qobject_cast<QToolButton*>(ui->phases_layout->itemAt(next_page)->widget());
    ui->phases_stack->setCurrentIndex(next_page);
    this->setupButtons->changeButton_style(button,no_icon,phasesButton_lightBackgroundColor, 1);

    if(next_page == 3){
        this->phasesTable->updateData_TablePhases(ui->phases_tableWidget);
    }
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

void MainWindow::changeInitialPositionValue()
{

    QToolButton* buttonSender = qobject_cast<QToolButton*>(sender());
    if(!buttonSender){
        buttonSender = currentPressedButton;
    }
    QString button_names[] = {
         "minus100_toolButton",
         "minus10_toolButton",
         "minus1_toolButton",
         "plus1_toolButton",
         "plus10_toolButton",
         "plus100_toolButton"
    };
    float move[] = {-0.1,-0.01,-0.001, 0.001, 0.01, 0.1};
    float add = 0.0;
    for(int i = 0;i < sizeof(button_names)/sizeof(QString);i++)
    {
        if(button_names[i]== buttonSender->objectName()){
            add = move[i];
        }
    }

    QString current_text = ui->initialPosition_lineEdit->text();
    float new_position = current_text.toFloat() + add;
    ui->initialPosition_lineEdit->setText(QString::number(new_position));

}

void MainWindow::onPositionButton_pressed()
{
    timer->start(100);
    QToolButton* buttonSender = qobject_cast<QToolButton*>(sender());
    currentPressedButton = buttonSender;
}

void MainWindow::onPositionButton_released()
{
    timer->stop();
    currentPressedButton = nullptr;
}



void MainWindow::on_initExperiment_toolButton_clicked()
{
    this->info_variables->setPressure(ui->initialPosition_lineEdit->text().toFloat());
    receive_data = new ThreadController();

    for(int i=0;i<3;i++){
        send_data = new sendCommands();
        if(send_data->errorOccurred){
            delete send_data;
            QThread::msleep(200);
        } else{
            break;
        }
    }
    ui->mainStack->setCurrentIndex(0);

}

