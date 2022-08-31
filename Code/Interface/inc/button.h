#ifndef BUTTON_H
#define BUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QToolButton>


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
#define outsideExperiment_buttonSize 0
#define phases_buttonSize 1
#define phases_continueButtonSize 2

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
    void setButtonShadow(QToolButton * button);
    void setButton_style_icon(QToolButton * button, uint8_t style, uint8_t icon);
    void initialButtonStyling_Layout(QHBoxLayout * boxlayout, uint8_t style_option, uint8_t size);
    void changeButton_style(QToolButton *current_button, uint8_t icon, uint8_t style);
    void initialButtonStyling_Widget(QObject * selectedWidget, uint8_t style_option, uint8_t size);



private:
    QToolButton * clickedButton[2]; /*!< Botão do cabeçalho ou/e das etapas, que foi clicado. */
    uint8_t clickedButtonIcon[2]; /*!< Ícone do botão do cabeçalho ou/e das etapas que foi clicado. */

    QString button_styleSheets[10]; /*!< Array com os estilos claro e escudo.*/
    QString button_images[10]; /*!< Array com as imagens dos botões. */
    QIcon button_icons[10]; /*!< Array com os ícones dos botões. */


    QSize buttonMaximumSize[10];
    QSize buttonMinimumSize[10];


    void styleSheetConfiguration();
    void imageConfiguration();
    void iconsConfiguration();
    void buttonSizeConfiguration();

signals:

};

#endif // BUTTON_H
