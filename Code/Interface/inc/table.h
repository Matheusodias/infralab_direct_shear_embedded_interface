#ifndef TABLE_H
#define TABLE_H

#include <QObject>
#include <QTableWidget>
#include "experiment.h"


#define phases_table 0
#define info_table 1
#define design_densification_table 0
#define design_shear_table 1

class Table : public QObject
{
    Q_OBJECT
public:
    explicit Table(Experiment *parent = nullptr, QTableWidget *densification  = nullptr
    , QTableWidget *shear  = nullptr);
    void customizeTable(QTableWidget * table_widget);

    void initialConfig_ShearTable(QTableWidget * table_widget);
    void updateData_ShearTable(QTableWidget * table_widget);

    void initialConfig_StaticTable(QTableWidget *table_widget, uint8_t option);
    void updateData_StaticTable(QTableWidget *table_widget, uint8_t option);

    void updateData_DynamicTable();
    void initialConfig_DynamicTable(QTableWidget *table_widget,uint8_t option);

    void exportCSV();

private:
    Experiment * table_variables;
    QStringList lineNames[2];
    QStringList columnValues[2];

    QStringList headerNames[2];
    QStringList machineTablevalues[2];

    QTableWidget *densificationTable;
    QTableWidget *shearTable;

signals:

};

#endif // TABLE_H
