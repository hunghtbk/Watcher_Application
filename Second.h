#ifndef SECOND_H
#define SECOND_H
#include <QQuickPaintedItem>

class Second: public QQuickPaintedItem
{
public:
    Second(QQuickItem *parent = 0);
    void paint(QPainter *painter);
};

#endif // SECOND_H
