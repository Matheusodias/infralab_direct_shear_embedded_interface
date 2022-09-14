#include "inc/experiment.h"

#include <cmath>
#include <QDebug>
Experiment::Experiment()
{
    
}

QStringList Experiment::getAllData_forInfoTable()
{
    QStringList temporary_list;
    temporary_list.push_back(this->getName());
    temporary_list.push_back(this->getOperator_name());
    temporary_list.push_back("vazio");
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

    for(int i=0;i<sizeof(calculations)/sizeof(float);i++){
        temporary_list.push_back(QString::number(calculations[i]));    
    }

    return temporary_list;
}

void Experiment::setAllVariables_onExperimetCreation()
{
    // Iterar sobre as labels e setar as variaveis

//    this->name = ;
//    this->operator_name =;
//    this->test_type =;
//    this->specimen_type =;
//    this->uscs_class =;
//    this->ashto_class =;
//    this->boring_number =;
//    this->diameter =;
//    this->spgr_solids =;
//    this->plastic_limit =;
//    this->liquid_limit =;

//    experiment_sample->set_sample_preparations();
//    experiment_sample->set_sample_id();
//    experiment_sample->set_sample_location();
//    experiment_sample->set_sample_description();


//    this->mutable_variables->set_height();
//    this->mutable_variables->set_weight();
//    this->mutable_variables->set_moisture();
//    this->mutable_variables->set_position();
//    this->mutable_variables->set_time();

    // save in database
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
    qDebug() << "passei no pressure" << newPressure;
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



