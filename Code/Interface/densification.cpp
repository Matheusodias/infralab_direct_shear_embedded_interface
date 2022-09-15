#include "densification.h"

Densification::Densification()
{

}

void Densification::setDensificationVariables(uint32_t sample_number, float vertical_displacement, float vertical_load)
{
    this->sample_number = sample_number;
    this->vertical_displacement = vertical_displacement;
    this->vertical_load = vertical_load;
}
