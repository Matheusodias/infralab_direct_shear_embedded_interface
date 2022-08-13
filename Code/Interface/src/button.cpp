#include "inc/button.h"
#include <QGraphicsDropShadowEffect>
#include <QDebug>

/**
 * @brief Constrói um novo objeto da classe Button.
 * 
 * Esta classe tem como objetivo criar as variáveis de estilo, imagem, ícones e outras
 * configurações iniciais dos botões;
 * 
 * @param parent 
 */
Button::Button()
{

    // Add stylesheet
    this->button_LightStyleSheet = "QPushButton{ background-color:white; border-bottom:5px solid rgb(227, 227, 227);"
                                          "border-right:5px solid rgb(227, 227, 227); border-top:1px solid rgb(227, 227, 227);"
                                          "border-left:1px solid rgb(227, 227, 227); border-radius:40px;}"
                                          "QPushButton:pressed {background-color:rgb(229, 229, 229);}";

    this->button_DarkStyleSheet = "QPushButton{ background-color:#0D495C; border-bottom:5px solid rgb(39, 64, 71);"
                                         "border-right:5px solid rgb(39, 64, 71); border-top:1px solid rgb(39, 64, 71);"
                                         "border-left:1px solid rgb(39, 64, 71); border-radius:40px;}"
                                         "QPushButton:pressed {background-color:#072a36;}";

    this->button_styleSheets[button_lightBackgroundColor] = this->button_LightStyleSheet;
    this->button_styleSheets[button_darkBackgroundColor] = this->button_DarkStyleSheet;

    // Add images

    this->button_Images[historyButton_LightIcon] = ":lightHistory.png";
    this->button_Images[historyButton_DarkIcon] = ":darkHistory.png";
    this->button_Images[experimentButton_LightIcon] = ":lightExperiment.png";
    this->button_Images[experimentButton_DarkIcon] = ":darkExperiment.png";
    this->button_Images[configurationButton_LightIcon] = ":lightConfiguration.png";
    this->button_Images[configurationButton_DarkIcon] = ":darkConfiguration.png";


    // Add pixmaps

    this->button_Icons[historyButton_LightIcon].addPixmap(QPixmap(this->button_Images[historyButton_LightIcon]),QIcon::Normal,QIcon::On);
    this->button_Icons[historyButton_DarkIcon].addPixmap(QPixmap(this->button_Images[historyButton_DarkIcon]),QIcon::Normal,QIcon::On);
    this->button_Icons[experimentButton_LightIcon].addPixmap(QPixmap(this->button_Images[experimentButton_LightIcon]),QIcon::Normal,QIcon::On);
    this->button_Icons[experimentButton_DarkIcon].addPixmap(QPixmap(this->button_Images[experimentButton_DarkIcon]),QIcon::Normal,QIcon::On);
    this->button_Icons[configurationButton_LightIcon].addPixmap(QPixmap(this->button_Images[configurationButton_LightIcon]),QIcon::Normal,QIcon::On);
    this->button_Icons[configurationButton_DarkIcon].addPixmap(QPixmap(this->button_Images[configurationButton_DarkIcon]),QIcon::Normal,QIcon::On);


    this->clickedButton = nullptr;


}

/**
 * @brief Estiliza um QPushButton para ter sombra.
 * 
 * @param button O botão que será estilizado.
 */
void Button::setButtonShadow(QPushButton *button)
{
    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
    effect->setBlurRadius(5); //Adjust accordingly
    effect->setOffset(5,5); //Adjust accordingly
    button->setGraphicsEffect(effect);

    return;
}

/**
 * @brief Altera o ícone e estilo do botão.
 * 
 * @param button Botão que será alterado.
 * @param style Estilo do botão, podendo ser claro ou escuro. 
 * @param icon  Ícone do botão.
 */
void Button::setButtonStyleSheet(QPushButton *button, uint8_t style, uint8_t icon)
{
    button->setIcon(button_Icons[icon]);
    button->setStyleSheet(this->button_styleSheets[style]);
    return;
}

/**
 * @brief Realiza a estilização dos botões encontrados no cabeçalho das páginas fora do experimento.
 * 
 * Essa estilização é realizada iterando sobre os elementos do layout do cabeçalho.
 * 
 * @param boxlayout Layout do cabeçalho das páginas fora do experimento.
 */
void Button::initialConfiguration_OutsideExperimentHeaderButtons(QHBoxLayout * boxlayout)
{
    QLayout *layout = boxlayout->layout();
    if (layout) {
        for (int i = 0; i < layout->count(); ++i){
            QPushButton * button = qobject_cast<QPushButton*>(layout->itemAt(i)->widget());
            if(button){
                this->setButtonShadow(button);
                button->setStyleSheet(this->button_styleSheets[button_lightBackgroundColor]);
            }
       }
    }

    return;
}

/**
 * @brief Altera a estilização do botão ao ser clicado.
 * 
 * Os botões do cabeçalho, das páginas fora do experimento, são alterados para
 * uma cor mais escura ao serem clicados e apenas um botão pode estar selecionado por vez.
 * 
 * 
 * @param current_button Botão que foi clicado
 * @param icon Ícone do botão clicado
 */
void Button::changeButtonStyle(QPushButton *current_button, uint8_t icon)
{

    if(this->clickedButton==current_button){
        return;
    }
    else if(this->clickedButton!=nullptr && this->clickedButton!=current_button){
        this->setButtonStyleSheet(this->clickedButton, button_lightBackgroundColor, this->clickedButtonIcon);
    }

    this->clickedButton = current_button;
    this->clickedButtonIcon = icon ;
    // Always sending the lightIcon, so to change to the darkIcon
    // you just need to add 1.
    // Same principle for background color, add 1 to button_lightBackgroundColor
    // to turn it dark.
    this->setButtonStyleSheet(current_button, button_darkBackgroundColor, ++icon);

    return;
}

/*
 *
 * #historyButton{
    background-color:white;
    border-bottom:5px solid rgb(227, 227, 227);
    border-right:5px solid rgb(227, 227, 227);
    border-top:5px solid rgb(227, 227, 227);
    border-left:5px solid rgb(227, 227, 227);
    border-radius:40px;
}

#historyButton:pressed {
    background-color:rgb(229, 229, 229);
    border-bottom:5px solid rgb(227, 227, 227);
    border-right:5px solid rgb(227, 227, 227);
    border-top:1px solid rgb(227, 227, 227);
    border-left:1px solid rgb(227, 227, 227);
    border-radius:40px;
}

#experimentButton{
    background-color:white;
    border-bottom:5px solid rgb(227, 227, 227);
    border-right:5px solid rgb(227, 227, 227);
    border-top:5px solid rgb(227, 227, 227);
    border-left:5px solid rgb(227, 227, 227);
    border-radius:40px;
}

#experimentButton:pressed {
    background-color:rgb(229, 229, 229);
    border-bottom:5px solid rgb(227, 227, 227);
    border-right:5px solid rgb(227, 227, 227);
    border-top:1px solid rgb(227, 227, 227);
    border-left:1px solid rgb(227, 227, 227);
    border-radius:40px;
}

*/


