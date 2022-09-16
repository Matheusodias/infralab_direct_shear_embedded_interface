#ifndef DENSIFICATION_H
#define DENSIFICATION_H

#include <stdint.h>
#include <QStringList>
class Densification
{
public:
    Densification();
    void setDensificationVariables(uint32_t sample_number, float vertical_displacement,
                                   float vertical_load);
    
    QStringList getDensificationVariables();
    QStringList getDensificationResults();

    uint32_t getSample_number() const;

    float getVertical_displacement() const;
    float getVertical_load() const;

    void setDiff_sampleNumber_initExperiment(uint32_t diff);

private:
    uint32_t sample_number;
    float vertical_displacement;
    float vertical_load;
    uint32_t diff_sampleNumber_initExperiment;


};

#endif // DENSIFICATION_H
