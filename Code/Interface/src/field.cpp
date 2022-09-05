#include "inc/field.h"
#include <QLineEdit>
#include <QLabel>
#include <QDebug>
Field::Field(QObject *parent)
    : QObject{parent}
{

    this->FieldMinimumSize[0] = QSize(100, 15);
    this->FieldMaximumSize[0] = QSize(1000, 100);


}

void Field::customizeField(QLayout *gridLayout)
{
    QLayout *layout = gridLayout->layout();
    if (layout) {
        for (int i = 0; i < layout->count(); ++i){
            QLayout * fieldLayout = layout->itemAt(i)->layout();

            QLineEdit * lineEdit = qobject_cast<QLineEdit*>(fieldLayout->itemAt(1)->widget());
            QLabel * label = qobject_cast<QLabel*>(fieldLayout->itemAt(0)->widget());

            if(lineEdit && label){
                //qDebug() << lineEdit->objectName();

                //lineEdit->setMaximumSize(this->lineEditMaximumSize[size]);
                lineEdit->setAlignment(Qt::AlignTop);
                lineEdit->setMinimumSize(this->FieldMinimumSize[0]);
                lineEdit->setMaximumSize(this->FieldMaximumSize[0]);
                lineEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
                lineEdit->setFont(QFont ( "Ubuntu", 13, QFont::Normal));

                QFont font( "Ubuntu", 15, QFont::Bold);
                label->setFont(font);
                label->setStyleSheet("color: #10576D;");
                label->setAlignment(Qt::AlignBottom);
            }


       }
    }

}
