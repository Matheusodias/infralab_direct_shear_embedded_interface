#ifndef TABLE_H
#define TABLE_H

#include <QObject>
#include <QTableWidget>
#include "experiment.h"



class Table : public QObject
{
    Q_OBJECT
public:
    explicit Table(Experiment *parent = nullptr);
    void customizeTable(QTableWidget * table_widget);
    void initialConfig_TablePhases(QTableWidget * table_widget);
    void updateData_TablePhases(QTableWidget * table_widget);

    void initialConfig_TableInfo(QTableWidget * table_widget);

private:
    Experiment * table_variables;
signals:

};

#endif // TABLE_H
