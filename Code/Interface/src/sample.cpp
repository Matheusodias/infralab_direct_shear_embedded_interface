#include "inc/sample.h"

Sample::Sample()
{

}


void Sample::set_sample_preparations(QString preparation){
    this->sample_preparations = preparation;
}
void Sample::set_sample_id(int id){
    this->sample_id = id;
}
void Sample::set_sample_location(QString location){
    this->sample_location = location;
}
void Sample::set_sample_description(QString description){
    this->sample_description = description;
}
