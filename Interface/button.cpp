#include "button.h"
#include <QGraphicsDropShadowEffect>

Button::Button(QWidget *parent)
    : QWidget{parent}
{

    this->historyButton_LightStyleSheet = "#historyButton{ background-color:white; border-bottom:5px solid rgb(227, 227, 227);"
                                          "border-right:5px solid rgb(227, 227, 227); border-top:1px solid rgb(227, 227, 227);"
                                          "border-left:1px solid rgb(227, 227, 227); border-radius:40px;}"
                                          "#historyButton:pressed {background-color:rgb(229, 229, 229);}";

    this->historyButton_DarkStyleSheet = "#historyButton{ background-color:#0D495C; border-bottom:5px solid rgb(39, 64, 71);"
                                         "border-right:5px solid rgb(39, 64, 71); border-top:1px solid rgb(39, 64, 71);"
                                         "border-left:1px solid rgb(39, 64, 71); border-radius:40px;}"
                                         "#historyButton:pressed {background-color:#072a36;}";

    this->button_styleSheets[historyButton_lightOption] = this->historyButton_LightStyleSheet;
    this->button_styleSheets[historyButton_darkOption] = this->historyButton_DarkStyleSheet;

    this->historyButton_LightImage = ":lightHistory_withoutBackground.png";
    this->historyButton_DarkImage = ":darkHistory_withoutBackground.png";

    this->button_Images[historyButton_lightOption] = this->historyButton_LightImage;
    this->button_Images[historyButton_darkOption] = this->historyButton_DarkImage;





}

void Button::setButtonShadow(QPushButton *button)
{
    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
    effect->setBlurRadius(5); //Adjust accordingly
    effect->setOffset(5,5); //Adjust accordingly
    button->setGraphicsEffect(effect);
}

void Button::setButtonStyleSheet(QPushButton *button, int option)
{
    QIcon ico;
    ico.addPixmap(QPixmap(this->button_Images[option]),QIcon::Normal,QIcon::On);
    button->setStyleSheet(this->button_styleSheets[option]);
    button->setIcon(ico);
}

