#ifndef MinuteClass_H
#define MinuteClass_H
#include <QQuickPaintedItem>

class MinuteClass: public QQuickPaintedItem
{
public:
    MinuteClass(QQuickItem *parent = 0);
    void paint(QPainter *painter);
};

#endif // MinuteClass_H
