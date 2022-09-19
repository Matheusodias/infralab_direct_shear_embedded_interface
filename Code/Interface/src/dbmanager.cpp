#include "inc/dbmanager.h"

DBManager::DBManager(const QString & path,Experiment * temp_experiment_data)
{
    this->experiment_data = temp_experiment_data;

    this->prova_conceito_database = QSqlDatabase::addDatabase("QSQLITE");
    this->prova_conceito_database.setDatabaseName(path);

    if(this->prova_conceito_database.open())
    {
        qDebug() << "Banco de dados: " << path << " criado.";
    } else{
        qDebug() << "Erro ao criar o banco. " << this->prova_conceito_database.lastError();
    }

    
    this->create_table[experiment_table] =  QString(
    "CREATE TABLE %1 "
    "(experiment_id INTEGER NOT NULL, "
    "name TEXT NOT NULL,"
    "operator_name TEXT	NOT NULL,"
    "initial_time INTEGER NOT NULL, "
    "test_type TEXT	NOT NULL,"
    "specimen_type TEXT	NOT NULL,"
    "uscs_class TEXT NOT NULL,"
    "ashto_class TEXT NOT NULL,"
    "sample_preparations TEXT NOT NULL,"
    "sample_id INTEGER NOT NULL,"
    "boring_number INTEGER NOT NULL,"
    "sample_location TEXT NOT NULL,"
    "sample_description TEXT NOT NULL,"
    "initial_height REAL NOT NULL, "
    "initial_wet_weight REAL NOT NULL,"
    "initial_moisture REAL NOT NULL,"
    "spgr_solids REAL NOT NULL,"
    "plastic_limit REAL NOT NULL,"
    "liquid_limit REAL NOT NULL,"
    "initial_position REAL NOT NULL,"
    "diameter REAL NOT NULL,"
    "pressure REAL NOT NULL,"

    "PRIMARY KEY(experiment_id));"

    ).arg(this->table_name[experiment_table]);


    this->insert_into_table[experiment_table] = 
    QString(
        "INSERT INTO %1 ("
        "name, operator_name, initial_time, test_type,"
        "specimen_type, uscs_class, ashto_class,"
        "sample_preparations, sample_id, boring_number,"
        "sample_location , sample_description, initial_height,"
        "initial_wet_weight, initial_moisture, spgr_solids,"
        "plastic_limit, liquid_limit, initial_position,"
        "diameter, pressure)"
        "Values (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)"
    ).arg(this->table_name[experiment_table]);

    this->create_table[densification_table] =  QString(
    "CREATE TABLE %1 "
    "(densification_id INTEGER NOT NULL,"
    "experiment_id INTEGER NOT NULL,"
    "sample_number INTEGER NOT NULL,"
    "vertical_displacement REAL NOT NULL, "
    "vertical_load REAL NOT NULL,"
    "PRIMARY KEY(densification_id),"
    "FOREIGN KEY(experiment_id) REFERENCES EXPERIMENT_TABLE(experiment_id));"
    ).arg(this->table_name[densification_table]);

    this->insert_into_table[densification_table] = 
    QString(
        "INSERT INTO %1 ("
        "experiment_id ,"
        "sample_number,"
        "vertical_displacement,"
        "vertical_load)"
        "Values (?,?,?,?)"
    ).arg(this->table_name[densification_table]);



    this->create_table[shear_table] =  QString(
    "CREATE TABLE %1 "
    "(shear_id  INTEGER NOT NULL,"
    "experiment_id INTEGER  NOT NULL,"
    "horizontal_displacement REAL NOT NULL,"
    "horizontal_load REAL NOT NULL,"
    "PRIMARY KEY(shear_id),"
    "FOREIGN KEY(experiment_id) REFERENCES EXPERIMENT_TABLE(experiment_id));"
    ).arg(this->table_name[shear_table]);

    this->insert_into_table[shear_table] =
    QString(
        "INSERT INTO %1 ("
        "experiment_id,"
        "horizontal_displacement,"
        "horizontal_load)"
        "Values (?,?,?)"
    ).arg(this->table_name[shear_table]);

    this->create_table[extra_variables_table] =
    QString(
        "CREATE TABLE %1 ("
        "extra_variables_id INTEGER NOT NULL,"
        "experiment_id INTEGER  NOT NULL,"
        "sample_period INTEGER NOT NULL,"
        "sample_number_diff INTEGER NOT NULL,"
        "distance REAL NOT NULL,"
        "velocity REAL NOT NULL,"
        "duration INTEGER NOT NULL,"
        "PRIMARY KEY(extra_variables_id),"
        "FOREIGN KEY(experiment_id) REFERENCES EXPERIMENT_TABLE(experiment_id));"
    ).arg(this->table_name[extra_variables_table]);

    this->insert_into_table[extra_variables_table] =
    QString(
        "INSERT INTO %1 ("
        "experiment_id,"
        "sample_period,"
        "sample_number_diff,"
        "distance,"
        "velocity,"
        "duration)"
        "Values (?,?,?,?,?,?)"
    ).arg(this->table_name[extra_variables_table]);

/*
    1 cisalhamento e de adensamento
    
    experiment_id INTEGER PRIMARY KEY NOT NULL 4
    sample_number INTEGER NOT NULL 4
    horizontal_displacement REAL NOT NULL 8 
    vertical_displacement REAL NOT NULL 8
    horizontal_load REAL NOT NULL 8
    vertical_load REAL NOT NULL 8
    fase INTEGER NOT NULL 1(apenas uma flag)
   

    4+4+8+8+8+8+4 = 8+16+16+1 = 24+17 = 41B

    41 * (12H = 12*60*60s = 43200s) = 1771200B
    

    1771200 - (1209600+  518400.0) = 43200B ou 42.1875MB a mais se utilizar 1 classe em vez de 2


    Vanta


*/

/*
*   densification_id  INTEGER PRIMARY KEY NOT NULL 4
*   experiment_id INTEGER FOREIGN KEY NOT NULL 4
*   sample_number INTEGER NOT NULL 4
*   vertical_displacement REAL NOT NULL 8 
*   vertical_load REAL NOT NULL 8
*   28 TOTAL 


    28 * (12H = 12*60*60s = 43200s) = 1209600B
*/
 

/* 
*   shear_id INTEGER PRIMARY KEY NOT NULL 4
*   experiment_id INTEGER FOREIGN KEY NOT NULL 4
*   horizontal_displacement REAL NOT NULL 8
*   horizontal_load REAL NOT NULL 8
*   
*   24 TOTAL

24 * 43200/2 (supondo que o cisalhamento comece na metade do tempo) = 518400B;

Para recuperar o sample number da SHEAR_TABLE.

sample_number_shear atual = sample_number_densification - this->sample_number_diff
Então para mostrar o número de amostra do cisalhamento,
basta primeiro realizar o select na tabela de adensamento e realizar a conta acima

Assim, não precisa salvar esse dado na tabela de cisalhamento





*/




}

DBManager::~DBManager()
{
    if(this->prova_conceito_database.isOpen())
    {
        this->prova_conceito_database.close();
    }
}

bool DBManager::isOpen() const
{
    return this->prova_conceito_database.isOpen();
}

bool DBManager::createTable(uint8_t option)
{
    bool success = false;
    QSqlQuery query;
    query.prepare(this->create_table[option]);
    //qDebug() << this->create_table[option];
    if(query.exec())
    {
        qDebug() << "Tabela "<< this->table_name[option] << "criada.";
        success = true;
    } else{
        qDebug() << "Erro ao criar a tabela: " << this->table_name[option] << "\n" << query.lastError();
    }
    return success;
}

bool DBManager::tableExists(uint8_t option)
{
    bool success = false;
    QSqlQuery query;
    QString command = QString("SELECT EXISTS ( SELECT name FROM sqlite_schema WHERE type='table' AND name='%1')").arg(this->table_name[option]);
    query.prepare(command);

    if(query.exec()){
        while(query.next()){
            if(query.value(0) == 1)
            {
                qDebug() << "A tabela "<< this->table_name[option] << " existe.";
                success = true;
            } else{
                qDebug() << "A tabela "<< this->table_name[option] << " não existe.";
                success = false;
            }

        }
    } else{
        qDebug() << "Erro na seleção da tabela " << this->table_name[option] << ": " << query.lastError();
    }
    return success;
}

bool DBManager::selectExperimentId()
{
    bool success = false;
    QSqlQuery query;
    QString command = QString("SELECT MAX(experiment_id) FROM  %1;").arg(this->table_name[experiment_table]);
    query.prepare(command);

    if(query.exec()){
        while(query.next()){
               qDebug() << "ExperimentId " << query.value(0).toString();
               this->experiment_id = query.value(0).toInt();

        }

        success = true;
    } else{
        qDebug() << "Erro na seleção da tabela " << this->table_name << ": " << query.lastError();
    }
    return success;
}

bool DBManager::insertIntoTable(uint8_t option)
{
    bool success = false;
    QSqlQuery query;
    query.prepare(this->insert_into_table[option]);


    if(option == experiment_table){
        this->insertValuesIntoBind_Experiment(&query);
    } else if(option == densification_table) {
        this->insertValuesIntoBind_Densification(&query);
    } else if(option == shear_table) {
        this->insertValuesIntoBind_Shear(&query);
    } else if(option == extra_variables_table){
        this->insertValuesIntoBind_ExtraVariables(&query);
    }
    

    if(query.exec()){
        qDebug() << "Inserção concluída com sucesso.";
        success = true;
        if(option == experiment_table){
            while(!this->selectExperimentId());
        }
    } else{
        qDebug() << "Erro na inserção da tabela " << this->table_name[option] << ": " << query.lastError();
    }
    return success;

}



void DBManager::insertValuesIntoBind_Densification(QSqlQuery *query)
{
    query->addBindValue(this->experiment_id);
    query->addBindValue(this->experiment_data->densification_variables.getSample_number());
    query->addBindValue(this->experiment_data->densification_variables.getVertical_displacement());
    query->addBindValue(this->experiment_data->densification_variables.getVertical_load());
    

}

void DBManager::insertValuesIntoBind_Shear(QSqlQuery *query)
{
    query->addBindValue(this->experiment_id);
    query->addBindValue(this->experiment_data->shear_variables.getHorizontal_displacement());
    query->addBindValue(this->experiment_data->shear_variables.getHorizontal_load());
}

void DBManager::insertValuesIntoBind_ExtraVariables(QSqlQuery *query)
{
    query->addBindValue(this->experiment_id);
    query->addBindValue(this->experiment_data->getSample_period());
    query->addBindValue(this->experiment_data->shear_variables.getSample_number_diff());
    query->addBindValue(this->experiment_data->shear_variables.getDistance());
    query->addBindValue(this->experiment_data->shear_variables.getVelocity());
    uint64_t duration = this->experiment_data->getDuration(true);
    query->addBindValue(QVariant::fromValue(duration));
}


void DBManager::insertValuesIntoBind_Experiment(QSqlQuery *query)
{
    
    query->addBindValue(this->experiment_data->getName());
    query->addBindValue(this->experiment_data->getOperator_name());
    uint64_t miliseconds = this->experiment_data->getInitial_time_seconds()*1000 + this->experiment_data->getInitial_time_miliseconds();
    query->addBindValue(QVariant::fromValue(miliseconds));
    query->addBindValue(this->experiment_data->getTest_type());
    query->addBindValue(this->experiment_data->getSpecimen_type());
    query->addBindValue(this->experiment_data->getUscs_class());
    query->addBindValue(this->experiment_data->getAshto_class());
    query->addBindValue(this->experiment_data->getSample_preparations());
    query->addBindValue(this->experiment_data->getSample_id());
    query->addBindValue(this->experiment_data->getBoring_number());
    query->addBindValue(this->experiment_data->getSample_location());
    query->addBindValue(this->experiment_data->getSample_description());
    query->addBindValue(this->experiment_data->getInitial_height());
    query->addBindValue(this->experiment_data->getInitial_wet_weight());
    query->addBindValue(this->experiment_data->getInitial_moisture());
    query->addBindValue(this->experiment_data->getSpgr_solids());
    query->addBindValue(this->experiment_data->getPlastic_limit());
    query->addBindValue(this->experiment_data->getLiquid_limit());
    query->addBindValue(this->experiment_data->getInitial_position());
    query->addBindValue(this->experiment_data->getDiameter());
    query->addBindValue(this->experiment_data->getPressure());
}

void DBManager::update_database_table()
{   
    
    this->insertIntoTable(densification_table);

    if(this->experiment_data->getPhase()==shear_phase){
        this->insertIntoTable(shear_table);
    }
}
