#include "inc/densification.h"
#include <QString>
#include <QDebug>

Densification::Densification()
{
    this->setDiff_sampleNumber_initExperiment(0);
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
    temporary_list.push_back(QString::number(this->vertical_displacement));
    temporary_list.push_back(QString::number(this->vertical_load));

    return temporary_list;

}

uint32_t Densification::getSample_number() const
{
    return sample_number - diff_sampleNumber_initExperiment;
}
void Densification::setDiff_sampleNumber_initExperiment(uint32_t diff)
{
    this->diff_sampleNumber_initExperiment = diff;
}
float Densification::getVertical_displacement() const
{
    return vertical_displacement;
}

float Densification::getVertical_load() const
{
    return vertical_load;
}

QStringList Densification::getDensificationResults()
{
    QStringList temporary_list;
    temporary_list.push_back("duration");
    temporary_list.push_back(QString::number(this->vertical_load));
    temporary_list.push_back("final_height");
    temporary_list.push_back(QString::number(this->vertical_displacement));
    temporary_list.push_back("final_volume");


    return temporary_list;
}


//Nome da variável	Nome na tabela	Observação
//duration_densification	Tempo Total Adensamento	present_time - initial time ao iniciar a fase de cisalhamento
//recommended_shear_ratio	Razão de cisalhamento recomendada
//final_read	Leitura da carga final	Última leitura da carga antes de iniciar a fase de cisalhamento.
//final_heigth	Altura final	initial_height - height_change
//heigth_change	Mudança de altura
//final_volume	Volume Final da fase de adensamento(cm³)	area * final_height
