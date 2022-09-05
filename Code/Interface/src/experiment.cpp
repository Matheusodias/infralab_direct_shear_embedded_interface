#include "inc/experiment.h"
#include "inc/sample.h"
#include "inc/experiment_mutable_variables.h"

Experiment::Experiment()
{
    this->experiment_sample = new Sample();
    this->mutable_variables = new Experiment_mutable_variables();
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

