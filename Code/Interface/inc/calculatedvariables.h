#ifndef CALCULATEDVARIABLES_H
#define CALCULATEDVARIABLES_H

#include "experiment.h"
class CalculatedVariables
{
private:
    float area;
    float initial_volume;
    float initial_wet_density;
    float initial_dry_density;
    float initial_void_ratio;
    float water_specific_weight;
    float initial_saturation;

    Experiment * variables;

public:
    CalculatedVariables();
    void calculateValues();
};

#endif // CALCULATEDVARIABLES_H
