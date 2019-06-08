#ifndef APPLICATIONWINDOWN_H
#define APPLICATIONWINDOWN_H

#include <QObject>
#include <QQmlApplicationEngine>
#include "MinuteClass.h"
#include "HourClass.h"
#include "HandleTime.h"
#include <QThread>
class ApplicationWindown : public QObject
{
    Q_OBJECT
public:
    static ApplicationWindown* getInstance();
    void initApplication();
signals:

public slots:
    void setTimeInUI(int hour, int minute, int second);
private:
    ApplicationWindown();
    static ApplicationWindown * m_instance;
    QQmlApplicationEngine engine;
    HandleTime *m_handleTime;
    QThread* m_thread;
    QObject *rootObject;
    QObject *qmlObject;
};

#endif // APPLICATIONWINDOWN_H
