#ifndef BUTTON_H
#define BUTTON_H

#include <QWidget>
#include <QPushButton>

#define historyButton_lightOption 0
#define historyButton_darkOption 1

class Button : public QWidget
{
    Q_OBJECT
public:
    Button(QWidget *parent = nullptr);
    void setButtonShadow(QPushButton * button);
    void setButtonStyleSheet(QPushButton * button,int option);

private:
    QString historyButton_LightStyleSheet;
    QString historyButton_DarkStyleSheet;
    QString experimentButton_LightStyleSheet;
    QString experimentButton_DarkStyleSheet;
    QString button_styleSheets[4];

    QString historyButton_LightImage;
    QString historyButton_DarkImage;
    QString experimentButton_LightImage;
    QString experimentButton_DarkImage;
    QString button_Images[4];

signals:

};

#endif // BUTTON_H
