#ifndef CHARTS_H
#define CHARTS_H

#include <QObject>
#include <QtCharts>
#include <QVBoxLayout>

#define densification_chart 0
#define shear_chart 1
/**
 * @brief Classe responsável pelos gráficos.
 * 
 * Esta classe é responsável por criar, estilizar e atualizar os gráficos.
 * 
 */
class Charts : public QObject
{
    Q_OBJECT
public:
    explicit Charts(QObject *parent = nullptr);
    void initialConfiguration(QVBoxLayout * layout,int option);
    void reset_Chart();
private:
    QSplineSeries *series[2];/*!<Cada elemento no array guarda os dados de algum gráfico.*/
    QChart *chart[2];/*!<Gráfico que recebe as séries e os eixos*/
    QValueAxis *m_axisX[2]; /*!<Array com os eixos X.*/
    QValueAxis *m_axisY[2];/*!<Array com os eixos Y.*/
    QString chart_title[2];/*!<Array com os títulos dos gráficos.*/
    QString x_axis_title[2];/*!<Array com os títulos dos eixos x.*/
    QString y_axis_title[2];/*!<Array com os títulos dos eixos y.*/
    QChartView *chartView[2];/*!<Utilizado para inserir o gráfico em um layout.*/
signals:

public slots:
    void updateDensificationCharts(int time, float vertical_displacement);
    void updateShearCharts(float horizontal_displacement, float vertical_displacement);

};

#endif // CHARTS_H