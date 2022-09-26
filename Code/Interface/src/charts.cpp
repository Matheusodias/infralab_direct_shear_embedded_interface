#include "inc/charts.h"

Charts::Charts(QObject *parent)
    : QObject{parent}
{
    chart_title[0] = "Tempo por deslocamento vertical";
    chart_title[1] = "Deslocamento horizontal versus deslocamento vertical";
    x_axis_title[0] = "Tempo (s)";
    y_axis_title[0] =  "Desloc. vertical (cm)";
    
    x_axis_title[1] = "Desloc. horizontal (cm)";
    y_axis_title[1] = "Desloc. vertical (cm)";
}

void Charts::initialConfiguration(QVBoxLayout * layout, int option)
{
    this->series[option] = new QSplineSeries(this);
    m_axisX[option] = new QValueAxis();
    m_axisY[option] = new QValueAxis();

    series[option]->append(0, 0);
/* series[option]->append(2, 4);
    series[option]->append(3, 8);
    series[option]->append(7, 4);
    series[option]->append(10, 5);
    *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);
*/
    chart[option] = new QChart();
    chart[option]->legend()->hide();
    chart[option]->addSeries(series[option]);
    chart[option]->addAxis(m_axisX[option],Qt::AlignBottom);
    chart[option]->addAxis(m_axisY[option],Qt::AlignLeft);
    series[option]->attachAxis(m_axisX[option]);
    series[option]->attachAxis(m_axisY[option]);
    //chart->createDefaultAxes();
    chart[option]->setTitle(chart_title[option]);

    m_axisX[option]->setTitleText(x_axis_title[option]);
    m_axisY[option]->setTitleText(y_axis_title[option]);
    
//    chart->axes(Qt::Vertical).at(0)->setTitleText("Deslocamento vertical (cm)");
//    chart->axes(Qt::Horizontal).at(0)->setTitleText("Tempo");

    chartView[option] = new QChartView(chart[option]);
    chartView[option]->setRenderHint(QPainter::Antialiasing);
    layout->addWidget(chartView[option]);
}

void Charts:: updateDensificationCharts(int time, float vertical_displacement)
{
    qDebug() << "Estou aqui" <<time  << " " << vertical_displacement;
    series[densification_chart]->append(time, vertical_displacement);
    chart[densification_chart]->removeSeries(series[densification_chart]);
    chart[densification_chart]->addSeries(series[densification_chart]);
    if(time > m_axisX[densification_chart]->max()){
       // qDebug() << "entrei aqui";
        m_axisX[densification_chart]->setMax(time);
        //chart->axes(Qt::Horizontal).at(0)->setMax(20+current_value);
    }
    if(vertical_displacement > m_axisY[densification_chart]->max()){
        m_axisY[densification_chart]->setMax(vertical_displacement);
    }
    //chartView->update();
}


void Charts:: updateShearCharts(float horizontal_displacement, float vertical_displacement)
{
    qDebug() << "Estou aqui" <<horizontal_displacement  << " " << vertical_displacement;
    series[shear_chart]->append(horizontal_displacement, vertical_displacement);
    chart[shear_chart]->removeSeries(series[shear_chart]);
    chart[shear_chart]->addSeries(series[shear_chart]);
    if(horizontal_displacement > m_axisX[shear_chart]->max()){
       // qDebug() << "entrei aqui";
        m_axisX[shear_chart]->setMax(horizontal_displacement);
        //chart->axes(Qt::Horizontal).at(0)->setMax(20+current_value);
    }
    if(vertical_displacement > m_axisY[shear_chart]->max()){
        m_axisY[shear_chart]->setMax(vertical_displacement);
    }
    //chartView->update();
}

void Charts:: reset_Chart()
{
   for(int i=0;i<2;i++){
        series[i]->deleteLater();
        chart[i]->deleteLater();
        m_axisX[i]->deleteLater();
        m_axisY[i]->deleteLater();
        chartView[i]->deleteLater();
   }

    
}