#include "inc/shear.h"

Shear::Shear(QObject *parent)
    : QObject{parent}
{
    this->setVelocity(0);
    this->setDistance(0);
}

int16_t Shear::getVelocity() const
{
    return velocity;
}

void Shear::setVelocity(int16_t newVelocity)
{
    velocity = newVelocity;
}

int16_t Shear::getDistance() const
{
    return distance;
}

void Shear::setDistance(int16_t newDistance)
{
    distance = newDistance;
}
