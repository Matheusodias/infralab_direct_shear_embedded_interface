#ifndef FIELD_H
#define FIELD_H

#include <QObject>
#include <QGridLayout>
class Field : public QObject
{
    Q_OBJECT
public:
    explicit Field(QObject *parent = nullptr);
    void customizeField(QLayout * gridLayout);

private:
    QSize FieldMaximumSize[10];
    QSize FieldMinimumSize[10];
signals:

};

#endif // FIELD_H
