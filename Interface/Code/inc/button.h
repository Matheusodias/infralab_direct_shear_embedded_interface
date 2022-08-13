#ifndef BUTTON_H
#define BUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>

#define button_lightBackgroundColor 0
#define button_darkBackgroundColor 1
#define historyButton_LightIcon 0
#define historyButton_DarkIcon 1
#define experimentButton_LightIcon 2
#define experimentButton_DarkIcon 3
#define configurationButton_LightIcon 4
#define configurationButton_DarkIcon 5

class Button : public QWidget
{
    Q_OBJECT
public:
    Button(QWidget *parent = nullptr);
    void setButtonShadow(QPushButton * button);
    void setButtonStyleSheet(QPushButton * button,uint8_t color, uint8_t icon);
    void initialConfiguration_OutsideExperimentHeaderButtons(QHBoxLayout * layout);
    void changeButtonStyle(QPushButton *button, uint8_t icon);



private:
    QPushButton * clickedButton;
    uint8_t clickedButtonIcon;

    QString button_LightStyleSheet;
    QString button_DarkStyleSheet;
    QString button_styleSheets[2];
    QString button_Images[6];
    QIcon button_Icons[6];

signals:

};

#endif // BUTTON_H
