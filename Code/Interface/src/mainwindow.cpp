#include "inc/mainwindow.h"
#include "ui_mainwindow.h"
#include "inc/field.h"
#include<QDebug>
#include <QLineEdit>
#include <QSignalMapper>
#include "inc/experiment.h"
#include <QSqlTableModel>
#include <QTextEdit>

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
    this->tables = new Table(this->info_variables,ui->densification_tableWidget, ui->shear_tableWidget);


    InitialConfiguration_OutsideExperimentHeaderButtons();
    InitialConfiguration_InsideExperimentHeaderButtons();
    InitialConfiguration_PhasesButtons();
    InitialConfiguration_PhasesFields();
    InitialConfiguration_Tables();


    connect(ui->sampleDescription_lineEdit, SIGNAL(editingFinished()),this->setupFields, SLOT(setVariables()));
    send_data = new sendCommands();
    receive_data = new ThreadController(NULL,this->tables);

    for(int i=0;i<20;i++){
        if(!send_data->connectToMachine()){
            QThread::msleep(500);
        } else{
          break;
        }
    }

    if(send_data->errorOccurred || this->receive_data->receiveDataThread->errorOccurred){
        qDebug() << "Não foi possível se conectar à máquina.";
        delete send_data;
        delete receive_data;
        delete ui;
        exit(-1);
    }

    this->CreateDataseTables();


    this->timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(changeInitialPositionValue()));



    fillTextEditForTests();

}


/**
 * @brief Destrói a janela principal.
 * 
 * Destrói a instância ui;
 * 
 */
MainWindow::~MainWindow()
{
    delete send_data;
    delete receive_data;
    delete ui;
}

void MainWindow::CreateDataseTables(){
    const QString path ="./database.db";
    qDebug() << "Antes de criar a tabela";
    my_db = new DBManager (path, this->info_variables);
    if(my_db->isOpen())
    {
        if(!my_db->tableExists(experiment_table)){my_db->createTable(experiment_table);}
        
        if(!my_db->tableExists(densification_table)){my_db->createTable(densification_table);}
        if(!my_db->tableExists(shear_table)){my_db->createTable(shear_table);}
        //if(!my_db.tableExists(shear_table)){my_db.createTable(shear_table);}

         // insere dados do experimento no banco de dados
        // faz um select com os dados para verificar se estão corretos

    }
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




    connectButtonToSlots_WithArguments(ui->inside_experiment_header_layout,ui->insideExperiment_stack,0);

    connectButtonToSlots_WithArguments(ui->densificationHeader_layout,ui->densification_stack,1);

    connectButtonToSlots_WithArguments(ui->shearHeader_layout,ui->shear_stack,2);
//    connect(ui->densificationGraphs_toolButton, &QToolButton::clicked,  this->setupButtons, [this]{
//        this->setupButtons->changePage_InsideExperiment(ui->densification_stack,true); });

//    connect(ui->densificationTable_toolButton, &QToolButton::clicked,  this->setupButtons, [this]{
//        this->setupButtons->changePage_InsideExperiment(ui->densification_stack,true); });

//    connect(ui->densificationResult_toolButton, &QToolButton::clicked,  this->setupButtons, [this]{
//        this->setupButtons->changePage_InsideExperiment(ui->densification_stack,true); });

}

void MainWindow::InitialConfiguration_PhasesButtons()
{
    // Insert style of phases buttons
    this->setupButtons->initialButtonStyling_Layout(ui->phases_layout, phasesButton_lightBackgroundColor,phases_buttonSize);
    this->setupButtons->changeButton_style(ui->phase1_button,no_icon,phasesButton_lightBackgroundColor,1);
    ui->phases_stack->setCurrentIndex(0);
    connectButtonsToSlots_Layout(ui->phases_layout, SIGNAL(clicked()), SLOT(changePhase()));

    this->setupButtons->initialButtonStyling_Widget(ui->phases_stack, continueButton_BackgroundColor, phases_continueButtonSize);

    this->setupButtons->initExperiment_ButtonStyle(ui->initExperiment_toolButton,false);
    ui->initExperiment_toolButton->setDisabled(true);
    this->setupButtons->pressureButton_style(ui->releasePressure_toolButton);

    //this->setupButtons->setButton_style_icon(ui->continuePhase1_button, continueButton_BackgroundColor, continueButton_Icon);
    //this->setupButtons->setButtonShadow(ui->continuePhase1_button);
    connectButtonsToSlots_Widget(ui->phase1_page, SIGNAL(clicked()),SLOT(nextPhase()));
    connectButtonsToSlots_Widget(ui->phase2_page, SIGNAL(clicked()),SLOT(nextPhase()));
    connectButtonsToSlots_Widget(ui->phase3_page, SIGNAL(clicked()),SLOT(nextPhase()));
    connectButtonsToSlots_Widget(ui->calculations_page, SIGNAL(clicked()),SLOT(nextPhase()));
    connect(ui->continuePosition_Button, SIGNAL(clicked()),this, SLOT(nextPhase()));


    //connectButtonsToSlots_Layout(ui->positionLayout, SIGNAL(clicked()), SLOT(changeInitialPositionValue()));
    connectButtonsToSlots_Layout(ui->positionLayout, SIGNAL(pressed()), SLOT(onPositionButton_pressed()));
    connectButtonsToSlots_Layout(ui->positionLayout, SIGNAL(released()), SLOT(onPositionButton_released()));

}

void MainWindow::InitialConfiguration_PhasesFields()
{
    this->setupFields->customizeField(ui->phase1_gridLayout);
    this->setupFields->customizeField(ui->phase2_gridLayout);
    this->setupFields->customizeField(ui->phase3_gridLayout);

    //this->setupFields->customizeOneField(ui->initialPosition_label, ui->initialPosition_lineEdit);
    //ui->initialPosition_lineEdit->setAlignment(Qt::AlignCenter);
    //ui->initialPosition_lineEdit->setFont(QFont ( "Ubuntu", 30, QFont::Normal));
}

void MainWindow::InitialConfiguration_Tables()
{
    this->tables->customizeTable(ui->phases_tableWidget);
    //this->tables->initialConfig_TablePhases(ui->phases_tableWidget);
    this->tables->initialConfig_StaticTable(ui->phases_tableWidget,phases_table);
    this->tables->customizeTable(ui->info_tableWidget);
    this->tables->initialConfig_StaticTable(ui->info_tableWidget,info_table);

    this->tables->customizeTable(ui->shear_tableWidget);
    this->tables->customizeTable(ui->densification_tableWidget);
    this->tables->initialConfig_DynamicTable(ui->densification_tableWidget,design_densification_table);
    this->tables->initialConfig_DynamicTable(ui->shear_tableWidget,design_shear_table);


    this->tables->customizeTable(ui->densificationResult_tableWidget);
    this->tables->initialConfig_StaticTable(ui->densificationResult_tableWidget,densification_result_table);
    // this->tables->initialConfig_ShearTable(ui->shear_tableWidget);

    //this->tables->exportCSV();


}

void MainWindow::connectButtonToSlots_WithArguments(QHBoxLayout * boxlayout, QStackedWidget * stack_widget, int option)
{

    QLayout *layout = boxlayout->layout();
    if (layout) {
        for (int i = 0; i < layout->count(); ++i){
           QToolButton * button = qobject_cast<QToolButton*>(layout->itemAt(i)->widget());
           if(button){
               connect(button, &QToolButton::clicked,  this->setupButtons, [this, stack_widget, option]{
                   if(option==0){
                       this->setupButtons->changeHeaderPage_InsideExperiment(stack_widget);
                   } else{
                       this->setupButtons->changePage_InsideExperiment(stack_widget, option==1);
                   }
                   });
           }
       }
    }





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

void MainWindow::changePage(QToolButton *buttonSender, QString buttons_name[6], uint8_t array_size, QStackedWidget * page_stack, uint8_t icon[], uint8_t style)
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
        //this->tables->updateData_TablePhases(ui->phases_tableWidget);
        this->tables->updateData_StaticTable(ui->phases_tableWidget,phases_table);
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
        //this->tables->updateData_TablePhases(ui->phases_tableWidget);
        this->tables->updateData_StaticTable(ui->phases_tableWidget,phases_table);
    }
}

void MainWindow::changePhase()
{
    QToolButton* buttonSender = qobject_cast<QToolButton*>(sender()); // retrieve the button you have clicked
    QString buttons_name[6] = {"phase1_button","phase2_button","phase3_button","calculations_button","position_button","pressure_button"};
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
    qDebug() << "Estou no displacement";
    ui->initialPositionValue_label->setText(QString::number(receive_data->receiveDataThread->machine_message.displacement[1]));
    qDebug() << receive_data->receiveDataThread->machine_message.displacement[1];
}

void MainWindow::onPositionButton_pressed()
{
    int sampling_period = 100;
    timer->start(sampling_period);
    QToolButton* buttonSender = qobject_cast<QToolButton*>(sender());


    float velocity = 10.0;
    if(buttonSender->objectName() == "moveLeft_toolButton"){
        velocity *= -1;
    }
    send_data->setCommand(0);
    send_data->setEnabled(1);
    send_data->setSamplingPeriod(sampling_period);
    send_data->sendMessage();

    send_data->setCommand(1);
    send_data->setVelocity(velocity);
    send_data->sendMessage();


}

void MainWindow::onPositionButton_released()
{

    send_data->setCommand(1);
    send_data->setVelocity(0);
    send_data->sendMessage();

    send_data->setCommand(0);
    send_data->setEnabled(0);
    send_data->setSamplingPeriod(0);
    send_data->sendMessage();


    timer->stop();
}



void MainWindow::on_initExperiment_toolButton_clicked()
{
    this->info_variables->setInitial_time(true);
    this->info_variables->setExperimentStarted(true);
    this->info_variables->setInitial_position(ui->initialPositionValue_label->text().toFloat());
    
    send_data->setCommand(3);
    send_data->setPressure(this->info_variables->getPressure());
    send_data->sendMessage();

    send_data->setCommand(0);
    send_data->setEnabled(1);
    send_data->setSamplingPeriod(1000);
    send_data->sendMessage();
    
    ui->mainStack->setCurrentIndex(0);
    ui->insideExperiment_stack->setCurrentIndex(0);
    ui->densification_stack->setCurrentIndex(0);
    this->setupButtons->changeButton_style(ui->densification_button, densificationButton_lightIcon, headerButton_lightBackgroundColor,0);
    this->setupButtons->changeButton_style(ui->densificationGraphs_toolButton, no_icon, phasesButton_lightBackgroundColor,1);
    //this->tables->updateData_TableInfo(ui->info_tableWidget);
    this->tables->updateData_StaticTable(ui->info_tableWidget,info_table);
    if(my_db->isOpen()){
        my_db->insertIntoTable(experiment_table);
    }

    
  

}


void MainWindow::on_releasePressure_toolButton_clicked()
{


        QToolButton * sender_button = qobject_cast<QToolButton *>(sender());

        bool isPositionButtonsEnable = !(sender_button->isChecked());
        int style = 0;
        if(isPositionButtonsEnable){
            style = pressureButton_GreenBackgroundColor;
            sender_button->setText("Liberar a baixa pressão");
        } else {
            style = pressureButton_RedBackgroundColor;
            sender_button->setText("Parar a baixa pressão");
        }

        this->send_data->setCommand(2);
        this->send_data->sendMessage();


        this->setupButtons->initExperiment_ButtonStyle(ui->initExperiment_toolButton,!isPositionButtonsEnable);
        ui->initExperiment_toolButton->setDisabled(isPositionButtonsEnable);

        this->setupButtons->setButton_style_icon(sender_button, style , no_icon );


        QLayout *layout = ui->positionLayout->layout();
        if (layout) {
            for (int i = 0; i < layout->count(); ++i){
               QToolButton * button = qobject_cast<QToolButton*>(layout->itemAt(i)->widget());

               if(button){
                    button->setEnabled(isPositionButtonsEnable);
                    int move_button_style =  isPositionButtonsEnable? continueButton_BackgroundColor:moveButton_DisabledBackgroundColor;
                    this->setupButtons->setButton_style_icon(button, move_button_style, no_icon);
               }
           }
        }

}

void MainWindow::fillTextEditForTests()
{
    QString array_data[30] = {
        "Experimento 2",
        "Ivan D",
        "Teste do tipo 2",
        "Espécime do tipo 2",
        "Classe uscs 35",
        "Classe ashto 3",
        "Nenhuma preparação",
        "1234", "12",
        "Localização da amostra",
        "Descrição da amostra",
        "500","2","3","4","5",
        "6", "7", "8",
    };

    int i=0;
    ui->experimentName_lineEdit->setText(array_data[i++]);
    ui->operator_lineEdit->setText(array_data[i++]);
    ui->testType_lineEdit->setText(array_data[i++]);
    ui->specimenType_lineEdit->setText(array_data[i++]);
    ui->uscs_lineEdit->setText(array_data[i++]);
    ui->ashto_lineEdit->setText(array_data[i++]);
    ui->samplePreparation_lineEdit->setText(array_data[i++]);
    ui->sampleId_lineEdit->setText(array_data[i++]);
    ui->boringNumber_lineEdit->setText(array_data[i++]);
    ui->sampleLocation_lineEdit->setText(array_data[i++]);
    ui->sampleDescription_lineEdit->setText(array_data[i++]);
    ui->height_lineEdit->setText(array_data[i++]);
    ui->wetWeight_lineEdit->setText(array_data[i++]);
    ui->humidity_lineEdit->setText(array_data[i++]);
    ui->spgr_lineEdit->setText(array_data[i++]);
    ui->plastic_lineEdit->setText(array_data[i++]);
    ui->liquid_lineEdit->setText(array_data[i++]);
    ui->diameter_lineEdit->setText(array_data[i++]);
    qDebug() << "Valor da pressure" << array_data[i];
    ui->pressure_lineEdit->setText(array_data[i++]);
    i=0;

    info_variables->setName(array_data[i++]);
    info_variables->setOperator_name(array_data[i++]);
    info_variables->setTest_type(array_data[i++]);
    info_variables->setSpecimen_type(array_data[i++]);
    info_variables->setUscs_class(array_data[i++]);
    info_variables->setAshto_class(array_data[i++]);
    info_variables->setSample_preparations(array_data[i++]);
    info_variables->setSample_id(array_data[i++].toInt());
    info_variables->setBoring_number(array_data[i++].toInt());
    info_variables->setSample_location(array_data[i++]);
    info_variables->setSample_description(array_data[i++]);
    info_variables->setInitial_height(array_data[i++].toFloat());
    info_variables->setInitial_wet_weight(array_data[i++].toFloat());
    info_variables->setInitial_moisture(array_data[i++].toFloat());
    info_variables->setSpgr_solids(array_data[i++].toFloat());
    info_variables->setPlastic_limit(array_data[i++].toFloat());
    info_variables->setLiquid_limit(array_data[i++].toFloat());
    info_variables->setDiameter(array_data[i++].toFloat());
    info_variables->setPressure(array_data[i++].toFloat());



    //phase1_gridLayout
    // phase2_gridLayout
    // layout_SampleDescription
    // phase3_gridLayout
    return;
}


void MainWindow::on_configurationButton_3_clicked()
{
    this->tables->updateData_StaticTable(ui->densificationResult_tableWidget,densification_result_table);
}

