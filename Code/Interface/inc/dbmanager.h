#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>
#include "experiment.h"

#define experiment_table 0
#define densification_table 1
#define shear_table 2

class DBManager
{
public:
    DBManager(const QString & path, Experiment * temp_experiment_data);
    ~DBManager();
    bool isOpen() const;
    bool createTable(uint8_t option);
    bool tableExists(uint8_t option);
    bool insertIntoTable(uint8_t option);
   
   


private:
    QSqlDatabase prova_conceito_database;
    QString table_name[3] = {"EXPERIMENT_TABLE","DENSIFICATION_TABLE","SHEAR_TABLE"};
    Experiment * experiment_data;
    void insertValuesIntoBind(QSqlQuery *query);
    QString create_table[3];
    QString insert_into_table[3];



};
#endif // DBMANAGER_H
