#include "inc/experiment.h"

#include <cmath>
#include <QDebug>
#include <time.h>
#include <sys/time.h>
Experiment::Experiment()
{

}

QStringList Experiment::getAllData_forInfoTable()
{
    
    QStringList temporary_list;
    temporary_list.push_back(this->getName());
    temporary_list.push_back(this->getOperator_name());
    temporary_list.push_back(this->getInitial_timeString());
    temporary_list.push_back("vazio2");
    temporary_list.push_back(this->getTest_type());
    temporary_list.push_back(this->getSpecimen_type());
    temporary_list.push_back(this->getUscs_class());
    temporary_list.push_back(this->getAshto_class());
    temporary_list.push_back(this->getSample_preparations());
    temporary_list.push_back(QString::number(getSample_id()));
    temporary_list.push_back(QString::number(getBoring_number()));
    temporary_list.push_back(this->getSample_location());
    temporary_list.push_back(this->getSample_description());
    temporary_list.push_back(QString::number(getInitial_height()));;
    temporary_list.push_back(QString::number(getInitial_wet_weight()));
    temporary_list.push_back(QString::number(getInitial_moisture()));
    temporary_list.push_back(QString::number(getSpgr_solids()));
    temporary_list.push_back(QString::number(getPlastic_limit()));
    temporary_list.push_back(QString::number(getLiquid_limit()));
    temporary_list.push_back(QString::number(getInitial_position()));
    temporary_list.push_back(QString::number(getDiameter()));


    temporary_list.push_back(QString::number(getArea()));
    temporary_list.push_back(QString::number(getinitial_volume()));
    temporary_list.push_back(QString::number(getinitial_wet_density()));
    temporary_list.push_back(QString::number(getinitial_dry_density()));
    temporary_list.push_back(QString::number(getinitial_void_ratio()));
    temporary_list.push_back(QString::number(getwater_specific_weight()));
    temporary_list.push_back(QString::number(getinitial_saturation()));
    temporary_list.push_back(QString::number(getPressure()));


    return temporary_list;

}

QStringList Experiment::getAllData_forPhasesTable(){
    float calculations[] = {
        getArea(),getinitial_volume(),
        getinitial_wet_density(),getinitial_dry_density(),
        getinitial_void_ratio(),getwater_specific_weight(),
        getinitial_saturation()
    };

    QStringList temporary_list;

    for(unsigned long int i=0;i<sizeof(calculations)/sizeof(float);i++){
        temporary_list.push_back(QString::number(calculations[i]));    
    }

    return temporary_list;
}

QStringList Experiment:: updateDensificationTable()
{
    QStringList temporary_list =  densification_variables.getDensificationVariables();
   
    temporary_list[1] = this->day_month_year();
    temporary_list[2] =this->hour_min_sec();

    

   
    

    return temporary_list;
}

QString Experiment::hour_min_sec()
{
    time_t seconds = (time_t)(this->getInitial_time()/1000 + densification_variables.getSample_number());
    struct tm * time_seconds = localtime(&seconds);
    QString time_string = QString("%1:%2:%3").arg(time_seconds->tm_hour).arg(time_seconds->tm_min).arg(time_seconds->tm_sec);
    return time_string;
}

QString Experiment::day_month_year()
{
    time_t seconds = (time_t)(this->getInitial_time()/1000 + densification_variables.getSample_number());
    struct tm * time_seconds = localtime(&seconds);
    QString time_string = QString("%1/%2/%3").arg(time_seconds->tm_mday).arg(time_seconds->tm_mon).
    arg(time_seconds->tm_year + 1900);

    return time_string;
}

bool Experiment::getExperimentStarted() const
{
    return experimentStarted;
}

void Experiment::setExperimentStarted(bool newExperimentStarted)
{
    experimentStarted = newExperimentStarted;
}

const QString &Experiment::getName() const
{
    return name;
}

void Experiment::setName(const QString &newName)
{
    name = newName;
}

const QString &Experiment::getOperator_name() const
{
    return operator_name;
}

void Experiment::setOperator_name(const QString &newOperator_name)
{
    operator_name = newOperator_name;
}

const QString &Experiment::getTest_type() const
{
    return test_type;
}

void Experiment::setTest_type(const QString &newTest_type)
{
    test_type = newTest_type;
}

const QString &Experiment::getSpecimen_type() const
{
    return specimen_type;
}

void Experiment::setSpecimen_type(const QString &newSpecimen_type)
{
    specimen_type = newSpecimen_type;
}

const QString &Experiment::getUscs_class() const
{
    return uscs_class;
}

void Experiment::setUscs_class(const QString &newUscs_class)
{
    uscs_class = newUscs_class;
}

const QString &Experiment::getAshto_class() const
{
    return ashto_class;
}

void Experiment::setAshto_class(const QString &newAshto_class)
{
    ashto_class = newAshto_class;
}

const QString &Experiment::getSample_preparations() const
{
    return sample_preparations;
}

void Experiment::setSample_preparations(const QString &newSample_preparations)
{
    sample_preparations = newSample_preparations;
}

int Experiment::getSample_id() const
{
    return sample_id;
}

void Experiment::setSample_id(int newSample_id)
{
    sample_id = newSample_id;
}

int Experiment::getBoring_number() const
{
    return boring_number;
}

void Experiment::setBoring_number(int newBoring_number)
{
    boring_number = newBoring_number;
}

const QString &Experiment::getSample_location() const
{
    return sample_location;
}

void Experiment::setSample_location(const QString &newSample_location)
{
    sample_location = newSample_location;
}

const QString &Experiment::getSample_description() const
{
    return sample_description;
}

void Experiment::setSample_description(const QString &newSample_description)
{
    sample_description = newSample_description;
}

float Experiment::getInitial_height() const
{
    return initial_height;
}

void Experiment::setInitial_height(float newInitial_height)
{
    initial_height = newInitial_height;
}

float Experiment::getInitial_wet_weight() const
{
    return initial_wet_weight;
}

void Experiment::setInitial_wet_weight(float newInitial_wet_weight)
{
    initial_wet_weight = newInitial_wet_weight;
}

float Experiment::getInitial_moisture() const
{
    return initial_moisture;
}

void Experiment::setInitial_moisture(float newInitial_moisture)
{
    initial_moisture = newInitial_moisture;
}

float Experiment::getSpgr_solids() const
{
    return spgr_solids;
}

void Experiment::setSpgr_solids(float newSpgr_solids)
{
    spgr_solids = newSpgr_solids;
}

float Experiment::getPlastic_limit() const
{
    return plastic_limit;
}

void Experiment::setPlastic_limit(float newPlastic_limit)
{
    plastic_limit = newPlastic_limit;
}

float Experiment::getLiquid_limit() const
{
    return liquid_limit;
}

void Experiment::setLiquid_limit(float newLiquid_limit)
{
    liquid_limit = newLiquid_limit;
}

float Experiment::getInitial_position() const
{
    return initial_position;
}

void Experiment::setInitial_position(float newInitial_position)
{
    initial_position = newInitial_position;
}

float Experiment::getDiameter() const
{
    return diameter;
}

void Experiment::setDiameter(float newDiameter)
{
    diameter = newDiameter;
}

float Experiment::getArea()
{
    float value = (pi_value*(diameter*diameter))/4.0;
    return value;
}

float Experiment::getinitial_volume()
{
    float value =  getArea() * initial_height;

    return (std::isfinite(value))? value : 0;
}

float Experiment::getinitial_wet_density()
{
    float value =  initial_wet_weight * getinitial_volume();
    return (std::isfinite(value))? value : 0;
}

float Experiment::getinitial_dry_density()
{
    float value =  ((getinitial_wet_density() * 100) / (100 + initial_moisture));
    return (std::isfinite(value))? value : 0;
}

float Experiment::getinitial_void_ratio()
{
    float value =  ((spgr_solids/getinitial_dry_density()) - 1);
    return (std::isfinite(value))? value : 0;
}

float Experiment::getwater_specific_weight()
{
    return 1.09;
}

float Experiment::getinitial_saturation()
{
    float value =  (spgr_solids *  initial_moisture) / (getinitial_void_ratio() * getwater_specific_weight());
    return (std::isfinite(value))? value : 0;
}

float Experiment::getPressure() const
{
    return pressure;
}

void Experiment::setPressure(float newPressure)
{
    pressure = newPressure;
}

int Experiment::getPhase() const
{
    return this->phase;
}

void Experiment::changePhase()
{
    this->phase = shear_phase;
}

uint64_t Experiment::getInitial_time() const
{
    return initial_time;
}

void Experiment::setInitial_time()
{
    struct timeval tv;

    gettimeofday(&tv, NULL);

    unsigned long long millisecondsSinceEpoch =
    (unsigned long long)(tv.tv_sec) * 1000 +
    (unsigned long long)(tv.tv_usec) / 1000;
    this->initial_time = millisecondsSinceEpoch;
}

QString Experiment::getInitial_timeString()
{
    time_t seconds = (time_t)(this->getInitial_time()/1000);
    struct tm * time_seconds = localtime(&seconds);
    QString time_string = QString("%1/%2/%3 %4H:%5min:%6seg").arg(time_seconds->tm_mday).arg(time_seconds->tm_mon).
    arg(time_seconds->tm_year + 1900).arg(time_seconds->tm_hour).arg(time_seconds->tm_min).arg(time_seconds->tm_sec);

    return time_string;
}

/*
 * tabela info precisa do time completo dia hora min seg ...
 * tabela adensamento e cisalhamento precisa do dia/mes/ano e hora/min/seg separados
 * o calculo do tempo é feito pegando o tempo inicial e somando o número de amostra
 *
 * *
 *
 * /
 *
 */





