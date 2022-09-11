#include "inc/table.h"
#include <QHeaderView>
Table::Table(Experiment *parent)
{
    table_variables = parent;
}

void Table::customizeTable(QTableWidget *table_widget)
{

    table_widget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    table_widget->setStyleSheet("QTableWidget{"
                                "background-color: white;"
                                "alternate-background-color: #77A0AC;"
                                "selection-background-color: #0D495C;"
                                "font:  20pt 'Ubuntu'; border:0px; }"
                                "QHeaderView { font: bold 30pt 'Ubuntu'; }"
                                );

    table_widget->setAlternatingRowColors(true);

    // cell item properties
    table_widget->setSelectionMode(QAbstractItemView::SingleSelection);
    table_widget->setSelectionBehavior(QAbstractItemView::SelectRows);
    table_widget->setTextElideMode(Qt::ElideRight);

    table_widget->setShowGrid(true);
    table_widget->setGridStyle(Qt::DotLine);

    table_widget->horizontalHeader()->setVisible(true);
    table_widget->verticalHeader()->setVisible(false);
    //table_widget->horizontalHeader()->setDefaultSectionSize(150);
    //table_widget->horizontalHeader()->setStretchLastSection(true);


    //table_widget->horizontalHeader()->setFont(QFont ( "Ubuntu", 50, QFont::Normal));
    table_widget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch) ;
    table_widget->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);






}

void Table::updateData_TablePhases(QTableWidget *table_widget)
{

    float calculations[] = {
        table_variables->getArea(),table_variables->getinitial_volume(),
        table_variables->getinitial_wet_density(),table_variables->getinitial_dry_density(),
        table_variables->getinitial_void_ratio(),table_variables->getwater_specific_weight(),
        table_variables->getinitial_saturation()};

    for(int i=0;i<7;i++){
        QTableWidgetItem *item = new QTableWidgetItem;
        QString variable = QString::number(calculations[i]);
        item->setText(variable);
        item->setTextAlignment(Qt::AlignCenter);
        table_widget->setItem(i,1,item);
    }
}

void Table::initialConfig_TableInfo(QTableWidget *table_widget)
{
    QString lineNames []= {
        "Nome do experimento", "Nome do operador", "Tipo de teste", "Tipo de espécime",
        "Classe USCS", "Classe ASHTO", "Preparações da amostra", "Id da amostra",
        "Número do furo", "Localização da amostra", "Descrição da amostra",
        "Altura inicial (cm)", "Peso úmido inicial (g)", "Umidade inicial (%)",
        "Peso específico dos sólidos (g/cm³)", "Limite de plasticidade (%)",
        "Limite de liquidez (%)", "Posição inicial (cm)", "Diamêtro (cm)",
        "Tempo de início do experimento (s)",  "Tempo atual (s)",
        "Pressão", "Área (cm²)", "Volume inicial (cm³)","Massa específica úmida inicial da amostra de solo (g/cm³)",
        "Massa específica seca inicial da amostra de solo (g/cm³)","Índice de vazios","Peso Específico da água",
        "Saturação inicial da amostra de solo (%)"
    };

    int row_count = sizeof(lineNames)/sizeof(QString);

    table_widget->setRowCount(row_count);
    table_widget->setColumnCount(2);
    QStringList headerLabels;
    headerLabels << "Variável" << "Valor";
    table_widget->setHorizontalHeaderLabels(headerLabels);


    for(int i=0;i<row_count;i++){
        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(lineNames[i]);
        //item->setTextAlignment(Qt::AlignHCenter);
        item->setTextAlignment(Qt::AlignCenter);
        table_widget->setItem(i,0,item);

    }
}

void Table::initialConfig_TablePhases(QTableWidget *table_widget)
{
    table_widget->setRowCount(7);
    table_widget->setColumnCount(2);
    QStringList headerLabels;
    headerLabels << "Variável" << "Valor";
    table_widget->setHorizontalHeaderLabels(headerLabels);
    QString lineNames []= {
        "Área (cm²)", "Volume inicial (cm³)","Massa específica úmida inicial da amostra de solo (g/cm³)",
        "Massa específica seca inicial da amostra de solo (g/cm³)","Índice de vazios","Peso Específico da água",
        "Saturação inicial da amostra de solo (%)"
    };

    for(int i=0;i<7;i++){
        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(lineNames[i]);
        //item->setTextAlignment(Qt::AlignHCenter);
        item->setTextAlignment(Qt::AlignCenter);
        table_widget->setItem(i,0,item);

    }
}
