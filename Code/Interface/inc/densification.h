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

private:
    uint32_t sample_number;
    float vertical_displacement;
    float vertical_load;


};

#endif // DENSIFICATION_H
