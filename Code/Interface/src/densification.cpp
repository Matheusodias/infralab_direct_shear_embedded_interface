#include "inc/densification.h"
#include <QString>

Densification::Densification()
{

}

void Densification::setDensificationVariables(uint32_t sample_number, float vertical_displacement, float vertical_load)
{
    this->sample_number = sample_number;
    this->vertical_displacement = vertical_displacement;
    this->vertical_load = vertical_load;
}

QStringList Densification::getDensificationVariables()
{
    QStringList temporary_list;
    temporary_list.push_back(QString::number(this->sample_number));
    temporary_list.push_back("dia");
    temporary_list.push_back("hora/min/seg");
    temporary_list.push_back(QString::number(this->sample_number));

    temporary_list.push_back(QString::number(this->vertical_displacement));
    temporary_list.push_back(QString::number(this->vertical_load));

    return temporary_list;

}

uint32_t Densification::getSample_number() const
{
    return sample_number;
}
