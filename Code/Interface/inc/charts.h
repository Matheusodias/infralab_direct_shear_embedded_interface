#ifndef CHARTS_H
#define CHARTS_H

#include <QObject>
#include <QtCharts>
#include <QVBoxLayout>

#define densification_chart 0
#define shear_chart 1

class Charts : public QObject
{
    Q_OBJECT
public:
    explicit Charts(QObject *parent = nullptr);
    void initialConfiguration(QVBoxLayout * layout,int option);
    void reset_Chart();
private:
    QSplineSeries *series[2];
    QChart *chart[2];
    QValueAxis *m_axisX[2];
    QValueAxis *m_axisY[2];
    QString chart_title[2];
    QString x_axis_title[2];
    QString y_axis_title[2];
    QChartView *chartView[2];
signals:

public slots:
    void updateDensificationCharts(int time, float vertical_displacement);
    void updateShearCharts(float horizontal_displacement, float vertical_displacement);

};

#endif // CHARTS_H
