#ifndef HANDLETIME_H
#define HANDLETIME_H

#include <QObject>
#include <QDebug>
class HandleTime : public QObject
{
    Q_OBJECT
public:
    HandleTime();
    ~HandleTime();

signals:
    void finished(int, int, int);
    void error(QString err);
public slots:
    void process();
    void updateTime();
};

#endif // HANDLETIME_H
