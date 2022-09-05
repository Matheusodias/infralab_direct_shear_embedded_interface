#ifndef EXPERIMENT_H
#define EXPERIMENT_H

#include <sample.h>
#include <experiment_mutable_variables.h>
#include <QString>
class Experiment
{
public:
    Experiment();
    void setAllVariables_onExperimetCreation();
private:
    QString	name;
    QString	operator_name;
    QString	test_type;
    QString	specimen_type;
    QString	uscs_class;
    QString	ashto_class;
    int	boring_number;
    float diameter;
    float spgr_solids;
    float plastic_limit;
    float liquid_limit;

    Sample * experiment_sample;
    Experiment_mutable_variables * mutable_variables;

};

#endif // EXPERIMENT_H
