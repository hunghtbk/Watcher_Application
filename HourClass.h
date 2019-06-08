#ifndef HOURCLASS_H
#define HOURCLASS_H
#include <QQuickPaintedItem>
#include <QPainter>
#include <QDebug>
#include <QPen>
class HourClass: public QQuickPaintedItem
{
public:
    HourClass(QQuickItem *parent = 0);
    void paint(QPainter *painter);
};

#endif // HOURCLASS_H
