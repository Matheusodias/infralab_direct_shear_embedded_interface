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
#define extra_variables_table 3

class DBManager : public QObject
{
    Q_OBJECT
public:
    DBManager(const QString & path, Experiment * temp_experiment_data);
    ~DBManager();
    bool isOpen() const;
    bool createTable(uint8_t option);
    bool tableExists(uint8_t option);
    bool insertIntoTable(uint8_t option);
   
    Experiment * experiment_data;


private:
    uint32_t experiment_id;

    QSqlDatabase prova_conceito_database;
    QString table_name[4] = {"EXPERIMENT_TABLE","DENSIFICATION_TABLE","SHEAR_TABLE","EXTRA_VARIABLES_TABLE"};
    
    void insertValuesIntoBind_Experiment(QSqlQuery *query);
    void insertValuesIntoBind_Densification(QSqlQuery *query);
    void insertValuesIntoBind_Shear(QSqlQuery *query);
    void insertValuesIntoBind_ExtraVariables(QSqlQuery *query);
    QString create_table[4];
    QString insert_into_table[4];

    bool selectExperimentId();


public slots:
    void update_database_table();

};
#endif // DBMANAGER_H
