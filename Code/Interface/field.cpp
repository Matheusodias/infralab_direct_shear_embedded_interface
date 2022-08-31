#include "field.h"
#include <QLineEdit>
Field::Field(QObject *parent)
    : QObject{parent}
{

    this->FieldMinimumSize[0] = QSize(100, 15);


}

void Field::customizeField(QGridLayout *gridLayout)
{
    QLayout *layout = gridLayout->layout();
    if (layout) {
        for (int i = 0; i < layout->count(); ++i){
            QLineEdit * lineEdit = qobject_cast<QLineEdit*>(layout->itemAt(i)->widget());

            if(lineEdit){


                //lineEdit->setMaximumSize(this->lineEditMaximumSize[size]);
                lineEdit->setAlignment(Qt::AlignTop);
                lineEdit->setMinimumSize(this->FieldMinimumSize[0]);
                lineEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            }
       }
    }

}
