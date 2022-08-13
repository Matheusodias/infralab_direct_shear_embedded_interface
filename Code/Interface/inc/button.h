#ifndef BUTTON_H
#define BUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>


#define button_lightBackgroundColor 0 /*!< Número identificador do estilo do botão com cores claras. */
#define button_darkBackgroundColor 1 /*!< Número identificador do estilo do botão com cores escuras. */
#define historyButton_LightIcon 0 /*!< Número identificador do ícone do botão histórico para ser utilizado com o background claro.*/
#define historyButton_DarkIcon 1 /*!< Número identificador do ícone do botão histórico para ser utilizado com o background escuro.*/
#define experimentButton_LightIcon 2 /*!< Número identificador do ícone do botão experimento para ser utilizado com o background claro.*/
#define experimentButton_DarkIcon 3 /*!< Número identificador do ícone do botão experimento para ser utilizado com o background escuro.*/
#define configurationButton_LightIcon 4 /*!< Número identificador do ícone do botão configurações para ser utilizado com o background claro.*/
#define configurationButton_DarkIcon 5 /*!< Número identificador do ícone do botão configurações para ser utilizado com o background escuro.*/



/**
 * @brief Classe dos botões.
 * 
 * Esta classe é responsável por cuidar do comportamento e estilização dos botões.
 */
class Button
{
public:
    Button();
    void setButtonShadow(QPushButton * button);
    void setButtonStyleSheet(QPushButton * button,uint8_t style, uint8_t icon);
    void initialConfiguration_OutsideExperimentHeaderButtons(QHBoxLayout * layout);
    void changeButtonStyle(QPushButton *button, uint8_t icon);



private:
    QPushButton * clickedButton; /*!< Botão do cabeçalho, fora do experimento, que foi clicado. */
    uint8_t clickedButtonIcon; /*!< Ícone do botão clickedButton. */

    QString button_LightStyleSheet; /*!< Estilo do botão com cores claras. */
    QString button_DarkStyleSheet; /*!< Estilo do botão com cores escuras. */
    QString button_styleSheets[2]; /*!< Array com os estilos claro e escudo.*/
    QString button_Images[6]; /*!< Array com as imagens dos botões. */
    QIcon button_Icons[6]; /*!< Array com os ícones dos botões. */

signals:

};

#endif // BUTTON_H
