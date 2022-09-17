#ifndef FIELD_H
#define FIELD_H

#include <QObject>
#include <QGridLayout>
#include "experiment.h"
#include <QLabel>
#include <QLineEdit>
class Field : public QObject
{
    Q_OBJECT
public:
    Field(Experiment *parent = nullptr);
    void customizeField(QLayout * gridLayout);
    void customizeOneField(QLabel *label, QLineEdit *lineEdit);
    void clearFields(QLayout * gridLayout);
    Experiment * info_variables;

private:
    QSize FieldMaximumSize[10];
    QSize FieldMinimumSize[10];

signals:

public slots:
    void setVariables();


};

#endif // FIELD_H
