#include "HourClass.h"

HourClass::HourClass(QQuickItem *parent)
{

}

void HourClass::paint(QPainter *painter)
{
    qDebug() << "Start Paint";
    QColor red_color("Green");
    QPen pen(red_color);
    pen.setWidth(5);
    painter->setPen(pen);
    QPointF f1(240,190), f2(240,240);
    painter->drawLine(f1, f2);
}
