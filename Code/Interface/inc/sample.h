#ifndef SAMPLE_H
#define SAMPLE_H

#include <QString>

class Sample
{
public:
    Sample();
    void set_sample_preparations(QString preparation);
    void set_sample_id(int id);
    void set_sample_location(QString location);
    void set_sample_description(QString description);
private:
    QString	sample_preparations	;
    int	sample_id;
    QString	sample_location;
    QString	sample_description;
};

#endif // SAMPLE_H
