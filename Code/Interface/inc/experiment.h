#ifndef EXPERIMENT_H
#define EXPERIMENT_H

#include <QString>
#include <QStringList>
#define pi_value 3.1415f

class Experiment
{
public:


    Experiment();

    QStringList getAllData();


    void setAllVariables_onExperimetCreation();
    const QString &getName() const;
    void setName(const QString &newName);

    const QString &getOperator_name() const;
    void setOperator_name(const QString &newOperator_name);

    const QString &getTest_type() const;
    void setTest_type(const QString &newTest_type);

    const QString &getSpecimen_type() const;
    void setSpecimen_type(const QString &newSpecimen_type);

    const QString &getUscs_class() const;
    void setUscs_class(const QString &newUscs_class);

    const QString &getAshto_class() const;
    void setAshto_class(const QString &newAshto_class);

    const QString &getSample_preparations() const;
    void setSample_preparations(const QString &newSample_preparations);

    int getSample_id() const;
    void setSample_id(int newSample_id);

    int getBoring_number() const;
    void setBoring_number(int newBoring_number);

    const QString &getSample_location() const;
    void setSample_location(const QString &newSample_location);

    const QString &getSample_description() const;
    void setSample_description(const QString &newSample_description);

    float getInitial_height() const;
    void setInitial_height(float newInitial_height);

    float getInitial_wet_weight() const;
    void setInitial_wet_weight(float newInitial_wet_weight);

    float getInitial_moisture() const;
    void setInitial_moisture(float newInitial_moisture);

    float getSpgr_solids() const;
    void setSpgr_solids(float newSpgr_solids);

    float getPlastic_limit() const;
    void setPlastic_limit(float newPlastic_limit);

    float getLiquid_limit() const;
    void setLiquid_limit(float newLiquid_limit);

    float getInitial_position() const;
    void setInitial_position(float newInitial_position);

    float getDiameter() const;
    void setDiameter(float newDiameter);

    float getArea();
    float getinitial_volume();
    float getinitial_wet_density();
    float getinitial_dry_density();
    float getinitial_void_ratio();
    float getwater_specific_weight();
    float getinitial_saturation();


    float getPressure() const;
    void setPressure(float newPressure);

private:
    QString	name;
    QString	operator_name;
    QString	test_type;
    QString	specimen_type;
    QString	uscs_class;
    QString	ashto_class;
    QString	sample_preparations;
    int	sample_id;
    int	boring_number;
    QString	sample_location;
    QString	sample_description;
    float initial_height;
    float initial_wet_weight;
    float initial_moisture;
    float spgr_solids;
    float plastic_limit;
    float liquid_limit;
    float initial_position;
    float diameter;
    float pressure;
    int initial_time;
    int present_time;



};

#endif // EXPERIMENT_H
