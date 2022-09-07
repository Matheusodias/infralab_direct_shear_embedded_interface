#ifndef TABLE_H
#define TABLE_H

#include <QObject>
#include <QTableWidget>
class Table : public QObject
{
    Q_OBJECT
public:
    explicit Table(QObject *parent = nullptr);
    void customizeTable(QTableWidget * table_widget);
signals:

};

#endif // TABLE_H
