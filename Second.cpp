#include "Second.h"
#include <QPainter>
#include <QDebug>
#include <QPen>
Second::Second(QQuickItem *parent)
{

}

void Second::paint(QPainter *painter)
{
    qDebug() << "Start Paint";
    QColor red_color("black");
    QPen pen(red_color);
    pen.setWidth(5);
    painter->setPen(pen);
    QPointF f1(240,100), f2(240,240);
    painter->drawLine(f1, f2);
}
