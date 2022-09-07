#include "inc/table.h"

Table::Table(QObject *parent)
    : QObject{parent}
{

}

void Table::customizeTable(QTableWidget *table_widget)
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
        table_widget->setItem(i,0,item);

        int a = 2;
        int b =4;
        QTableWidgetItem *item2 = new QTableWidgetItem;
        item2->setText(QString::number(a*b));
        table_widget->setItem(i,1,item2);

    }
}
