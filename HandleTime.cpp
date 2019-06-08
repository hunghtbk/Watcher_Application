#include "HandleTime.h"
#include <QTimer>
#include <QDateTime>

HandleTime::HandleTime()
{

}

HandleTime::~HandleTime()
{

}

void HandleTime::process()
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    timer->start(1000);

}

void HandleTime::updateTime()
{
    QDateTime dateTime;
    QTime time = dateTime.currentDateTime().time();
    int hour, minute, second;
    hour = time.hour();
    minute = time.minute();
    second = time.second();
    emit finished(hour, minute, second);
}
