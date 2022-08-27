#include "inc/button.h"
#include <QGraphicsDropShadowEffect>
#include <QDebug>
#include <QToolButton>
/**
 * @brief Constrói um novo objeto da classe Button.
 * 
 * Esta classe tem como objetivo criar as variáveis de estilo, imagem, ícones e outras
 * configurações iniciais dos botões;
 * 
 */
Button::Button()
{

    // Add styleSheets
    this->styleSheetConfiguration();

    // Add images
    this->imageConfiguration();

    // Add pixmaps
    this->iconsConfiguration();

    this->clickedButton[0] = nullptr;
    this->clickedButton[1] = nullptr;


}

void Button::styleSheetConfiguration()
{
    QString headerButton_lightStyleSheet; /*!< Estilo do botão do header com cores claras. */
    QString headerButton_darkStyleSheet; /*!< Estilo do botão do header com cores escuras. */
    QString phasesButton_lightStyleSheet; /*!< Estilo do botão das etapas com cores escuras. */
    QString phasesButton_darkStyleSheet; /*!< Estilo do botão das etapas com cores escuras. */
    QString continueButton_StyleSheet; /*!< Estilo do botão de continuar da criação do experimento */
    QString headerButton_lightStyleSheet2;
    QString headerButton_darkStyleSheet2;

    //qproperty-iconSize: 24px;
    // Add stylesheet
    headerButton_lightStyleSheet = "QPushButton{ background-color:white; border-bottom:5px solid rgb(227, 227, 227);"
                                          "border-right:5px solid rgb(227, 227, 227); border-top:1px solid rgb(227, 227, 227);"
                                          "border-left:1px solid rgb(227, 227, 227); border-radius:25px;}"
                                          "QPushButton:pressed {background-color:rgb(229, 229, 229);}";

    headerButton_darkStyleSheet = "QPushButton{ background-color:#0D495C; border-bottom:5px solid rgb(39, 64, 71);"
                                         "border-right:5px solid rgb(39, 64, 71); border-top:1px solid rgb(39, 64, 71);"
                                         "border-left:1px solid rgb(39, 64, 71); border-radius:25px;}"
                                         "QPushButton:pressed {background-color:#072a36;}";

    phasesButton_lightStyleSheet = "QPushButton{ background-color:white; border-bottom:3px solid #0D495C;"
                                         "border-right:3px solid #0D495C;border-top:2px solid #0D495C;"
                                         "border-left:2px solid #0D495C;border-radius:15px; color:#10576D;font: 700 13pt 'Ubuntu';}"
                                         "QPushButton:pressed {background-color:rgb(229, 229, 229);}";

    phasesButton_darkStyleSheet = "QPushButton{ background-color:#77A0AC; border-bottom:3px solid #0D495C;"
                                         "border-right:3px solid #0D495C;border-top:2px solid #0D495C;"
                                         "border-left:2px solid #0D495C;border-radius:15px; color:white;font: 700 13pt 'Ubuntu';}"
                                         "QPushButton:pressed {background-color:#0D495C;}";


    continueButton_StyleSheet = "QToolButton{ background-color:#0E3A47; border-bottom:2px solid rgb(7, 36, 44);"
                                         "border-right:1px solid rgb(7, 36, 44);border-top:1px solid rgb(7, 36, 44);"
                                         "border-left:1px solid rgb(7, 36, 44);border-radius:10px;font: 700 13pt 'Ubuntu';"
                                           "color: white; padding:3;}"
                                          "QToolButton:pressed {background-color:black;}";



    headerButton_lightStyleSheet2 = "QToolButton{ background-color:white; border-bottom:5px solid rgb(227, 227, 227);"
                                          "border-right:5px solid rgb(227, 227, 227); border-top:1px solid rgb(227, 227, 227);"
                                          "border-left:1px solid rgb(227, 227, 227); border-radius:25px;}"
                                          "QToolButton:pressed {background-color:rgb(229, 229, 229);}";

    headerButton_darkStyleSheet2 = "QToolButton{ background-color:#0D495C; border-bottom:5px solid rgb(39, 64, 71);"
                                         "border-right:5px solid rgb(39, 64, 71); border-top:1px solid rgb(39, 64, 71);"
                                         "border-left:1px solid rgb(39, 64, 71); border-radius:25px;}"
                                         "QToolButton:pressed {background-color:#072a36;}";




    this->button_styleSheets[headerButton_lightBackgroundColor] = headerButton_lightStyleSheet;
    this->button_styleSheets[headerButton_darkBackgroundColor]  = headerButton_darkStyleSheet;
    this->button_styleSheets[phasesButton_lightBackgroundColor] = phasesButton_lightStyleSheet;
    this->button_styleSheets[phasesButton_darkBackgroundColor]  = phasesButton_darkStyleSheet;
    this->button_styleSheets[continueButton_BackgroundColor] = continueButton_StyleSheet;
    this->button_styleSheets[5] = headerButton_lightStyleSheet2;
    this->button_styleSheets[6]  = headerButton_darkStyleSheet2;

}

void Button::imageConfiguration()
{
    this->button_images[historyButton_lightIcon] = ":lightHistory.png";
    this->button_images[historyButton_darkIcon] = ":darkHistory.png";
    this->button_images[experimentButton_lightIcon] = ":lightExperiment.png";
    this->button_images[experimentButton_darkIcon] = ":darkExperiment.png";
    this->button_images[configurationButton_lightIcon] = ":lightConfiguration.png";
    this->button_images[configurationButton_darkIcon] = ":darkConfiguration.png";
    this->button_images[continueButton_Icon] = ":Arrow.png";
    this->button_images[7] = ":light_history.png";
}

void Button::iconsConfiguration()
{
    this->button_icons[historyButton_lightIcon].addPixmap(QPixmap(this->button_images[historyButton_lightIcon]),QIcon::Normal,QIcon::On);
    this->button_icons[historyButton_darkIcon].addPixmap(QPixmap(this->button_images[historyButton_darkIcon]),QIcon::Normal,QIcon::On);
    this->button_icons[experimentButton_lightIcon].addPixmap(QPixmap(this->button_images[experimentButton_lightIcon]),QIcon::Normal,QIcon::On);
    this->button_icons[experimentButton_darkIcon].addPixmap(QPixmap(this->button_images[experimentButton_darkIcon]),QIcon::Normal,QIcon::On);
    this->button_icons[configurationButton_lightIcon].addPixmap(QPixmap(this->button_images[configurationButton_lightIcon]),QIcon::Normal,QIcon::On);
    this->button_icons[configurationButton_darkIcon].addPixmap(QPixmap(this->button_images[configurationButton_darkIcon]),QIcon::Normal,QIcon::On);
    this->button_icons[continueButton_Icon].addPixmap(QPixmap(this->button_images[continueButton_Icon]),QIcon::Normal,QIcon::On);
    this->button_icons[7].addPixmap(QPixmap(this->button_images[7]),QIcon::Normal,QIcon::On);

}

/**
 * @brief Estiliza um QPushButton ou QToolButton para ter sombra.
 * 
 * @param button O botão que será estilizado.
 */
void Button::setButtonShadow(void * button, uint8_t type_of_button)
{

    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
    effect->setBlurRadius(5); //Adjust accordingly
    effect->setOffset(5,5); //Adjust accordingly
    if(type_of_button == push_button){
         QPushButton * pushButton = (QPushButton *)button;
         pushButton->setGraphicsEffect(effect);
    } else if(type_of_button == tool_button){
        QToolButton * toolButton = (QToolButton *)button;
        toolButton->setGraphicsEffect(effect);
    }


    return;
}

/**
 * @brief Altera o ícone e estilo do botão.
 * 
 * @param button Botão que será alterado.
 * @param style Estilo do botão, podendo ser claro ou escuro. 
 * @param icon  Ícone do botão.
 */
void Button::setButton_style_icon(void *button, uint8_t style, uint8_t icon, uint8_t type_of_button)
{

    if(type_of_button == push_button){
         QPushButton * pushButton = (QPushButton *)button;
         pushButton->setIcon(button_icons[icon]);
         pushButton->setStyleSheet(this->button_styleSheets[style]);
    } else if(type_of_button == tool_button){
        QToolButton * toolButton = (QToolButton *)button;
        toolButton->setIcon(button_icons[icon]);
        toolButton->setStyleSheet(this->button_styleSheets[style]);
    }


    return;
}

/**
 * @brief Realiza a estilização dos botões encontrados no cabeçalho das páginas fora do experimento.
 * 
 * Essa estilização é realizada iterando sobre os elementos do layout do cabeçalho.
 * 
 * @param boxlayout Layout do cabeçalho das páginas fora do experimento.
 */
void Button::initialButtonStyling(QHBoxLayout * boxlayout, uint8_t style_option)
{
    QLayout *layout = boxlayout->layout();
    if (layout) {
        for (int i = 0; i < layout->count(); ++i){
            QPushButton * button = qobject_cast<QPushButton*>(layout->itemAt(i)->widget());
            if(button){
                this->setButtonShadow((void *)button,0);
                button->setStyleSheet(this->button_styleSheets[style_option]);
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
void Button::changeButton_style(QPushButton *current_button, uint8_t icon, uint8_t style)
{
    // Always sending the lightBackgroundColor of a button
    // It will always be a multiple of 2 or 0, so to differentiate multiple buttons we get the position as follows:
    // pos = 0/2 = 0, pos = 2/2=1, pos = 4/2 = 2.
    uint8_t pos = style/2;
    if(this->clickedButton[pos]==current_button){
        return;
    }
    else if(this->clickedButton[pos]!=nullptr && this->clickedButton[pos]!=current_button){
        if(icon==no_icon) {
            this->clickedButton[pos]->setStyleSheet(this->button_styleSheets[style]);
        } else {
            this->setButton_style_icon(this->clickedButton[pos], style, this->clickedButtonIcon[pos],0);
        }

    }
    this->clickedButton[pos] = current_button;
    this->clickedButtonIcon[pos] = icon ;

    // Always sending the lightIcon, so to change to the darkIcon
    // you just need to add 1.
    // Same principle for background color, add 1 to button_lightBackgroundColor
    // to turn it dark.
    if(icon==no_icon){
        current_button->setStyleSheet(this->button_styleSheets[++style]);
    } else {
        this->setButton_style_icon(current_button, ++style, ++icon,0);
    }
    return;
}

void Button::initialButtonStyling2(QHBoxLayout *boxlayout, uint8_t style_option)
{
    QLayout *layout = boxlayout->layout();
    if (layout) {
        for (int i = 0; i < layout->count(); ++i){
            QToolButton * button = qobject_cast<QToolButton*>(layout->itemAt(i)->widget());
            if(button){
                this->setButtonShadow((void *)button,0);
                button->setStyleSheet(this->button_styleSheets[style_option]);
                button->setMaximumSize(QSize(300, 80));
                button->setMinimumSize(QSize(110, 70));
                button->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
            }
       }
    }

    return;
}





