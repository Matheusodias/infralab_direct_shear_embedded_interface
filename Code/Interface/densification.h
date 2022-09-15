#ifndef DENSIFICATION_H
#define DENSIFICATION_H

#include <stdint.h>

class Densification
{
public:
    Densification();
    void setDensificationVariables(uint32_t sample_number, float vertical_displacement,
                                   float vertical_load);
private:
    uint32_t sample_number;
    float vertical_displacement;
    float vertical_load;
};

#endif // DENSIFICATION_H
