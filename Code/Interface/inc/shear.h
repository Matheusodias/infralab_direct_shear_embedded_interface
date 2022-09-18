#ifndef SHEAR_H
#define SHEAR_H

#include <QObject>

class Shear : public QObject
{
    Q_OBJECT
public:
    explicit Shear(QObject *parent = nullptr);

    int16_t getVelocity() const;
    void setVelocity(int16_t newVelocity);

    int16_t getDistance() const;
    void setDistance(int16_t newDistance);

private:

    int16_t velocity;
    int16_t distance;

//    vertical_displacement // recebido
//    horizontal_displacement // recebido
//    shear_load // recebido
//    normal_tension // normal_load/area
//    shear_tension // shear_load/area

signals:

};

#endif // SHEAR_H
