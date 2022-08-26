#ifndef BUTTON_H
#define BUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>


#define headerButton_lightBackgroundColor 0 /*!< Número identificador do estilo do botão header com cores claras. */
#define headerButton_darkBackgroundColor 1 /*!< Número identificador do estilo do botão header com cores escuras. */
#define phasesButton_lightBackgroundColor 2 /*!< Número identificador do estilo do botão etapas com cores claras. */
#define phasesButton_darkBackgroundColor 3 /*!< Número identificador do estilo do botão etapas com cores escuras. */
#define continueButton_BackgroundColor 4 /*!< Número identificador do estilo do botão de continuar nas etapas. */
#define historyButton_lightIcon 0 /*!< Número identificador do ícone do botão histórico para ser utilizado com o background claro.*/
#define historyButton_darkIcon 1 /*!< Número identificador do ícone do botão histórico para ser utilizado com o background escuro.*/
#define experimentButton_lightIcon 2 /*!< Número identificador do ícone do botão experimento para ser utilizado com o background claro.*/
#define experimentButton_darkIcon 3 /*!< Número identificador do ícone do botão experimento para ser utilizado com o background escuro.*/
#define configurationButton_lightIcon 4 /*!< Número identificador do ícone do botão configurações para ser utilizado com o background claro.*/
#define configurationButton_darkIcon 5 /*!< Número identificador do ícone do botão configurações para ser utilizado com o background escuro.*/
#define continueButton_Icon 6  /*!< Número identificador do ícone do botão continuar*/
#define no_icon 255 /*!< Número que informa que o botão não possui ícone. */
#define push_button 0
#define tool_button 1
#define is_layout 1

/**
 * @brief Classe dos botões.
 * 
 * Esta classe é responsável por cuidar do comportamento e estilização dos botões.
 */
class Button: public QObject
{
    Q_OBJECT
public:
    Button();
    void setButtonShadow(void * button, uint8_t type_of_button);
    void setButton_style_icon(void *button, uint8_t style, uint8_t icon,uint8_t type_of_button);
    void initialButtonStyling(QHBoxLayout * boxlayout, uint8_t style_option);
    void changeButton_style(QPushButton *current_button, uint8_t icon, uint8_t style);



private:
    QPushButton * clickedButton[2]; /*!< Botão do cabeçalho ou/e das etapas, que foi clicado. */
    uint8_t clickedButtonIcon[2]; /*!< Ícone do botão do cabeçalho ou/e das etapas que foi clicado. */



    QString button_styleSheets[5]; /*!< Array com os estilos claro e escudo.*/
    QString button_images[7]; /*!< Array com as imagens dos botões. */
    QIcon button_icons[7]; /*!< Array com os ícones dos botões. */


    void styleSheetConfiguration();
    void imageConfiguration();
    void iconsConfiguration();

signals:

};

#endif // BUTTON_H
