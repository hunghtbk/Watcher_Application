#include "MinuteClass.h"
#include <QPainter>
#include <QDebug>
#include <QPen>
MinuteClass::MinuteClass(QQuickItem *parent)
{

}

void MinuteClass::paint(QPainter *painter)
{
    qDebug() << "Start Paint";
    QColor red_color("#FF0000");
    QPen pen(red_color);
    pen.setWidth(5);
    painter->setPen(pen);
    QPointF f1(240,160), f2(240,240);
    painter->drawLine(f1, f2);
}
