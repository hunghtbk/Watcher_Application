#include "ApplicationWindown.h"
#include <QDebug>
#include <MinuteClass.h>
#include <HourClass.h>
#include <Second.h>
#include <qqml.h>
#include <QDateTime>

ApplicationWindown* ApplicationWindown::m_instance = nullptr;
ApplicationWindown::ApplicationWindown()
{
    qDebug() << "Start Application";
}

ApplicationWindown *ApplicationWindown::getInstance()
{
    if (m_instance == nullptr) {
        m_instance = new ApplicationWindown();
    }
    return m_instance;
}

void ApplicationWindown::initApplication()
{
    (void)qmlRegisterType<MinuteClass>("Time", 1, 0, "Minute");
    (void)qmlRegisterType<HourClass>("Time", 1, 0, "Hour");
    (void)qmlRegisterType<Second>("Time", 1, 0, "Second");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    m_thread = new QThread();
    m_handleTime = new HandleTime();
    m_handleTime->moveToThread(m_thread);

    connect(m_thread, SIGNAL (started()), m_handleTime, SLOT (process()));
    connect(m_handleTime, SIGNAL (finished(int, int, int)), this, SLOT (setTimeInUI(int, int, int)));
    m_thread->start();
}

void ApplicationWindown::setTimeInUI(int hour, int minute, int second)
{
    rootObject = engine.rootObjects().first();
    qmlObject = rootObject->findChild<QObject*>("second");
    if (qmlObject) {
        int currentRotation = qmlObject->property("rotation").toInt();
        int changeRotate = (second - currentRotation/6) * 6;
        qmlObject->setProperty("secondrotate", changeRotate);
        qmlObject->setProperty("secondValue", second);
    } else {
        qDebug() << "Not Found!";
    }

    qmlObject = rootObject->findChild<QObject*>("minute");
    if (qmlObject) {
        int currentRotation = qmlObject->property("rotation").toInt();
        int changeRotate = (minute - currentRotation/6) * 6;
        qmlObject->setProperty("minuterotate", changeRotate);
        qmlObject->setProperty("minuteValue", minute);
    } else {
        qDebug() << "Not Found!";
    }

    qmlObject = rootObject->findChild<QObject*>("hour");
    if (qmlObject) {
        int currentRotation = qmlObject->property("rotation").toInt();
        int changeRotate;
        if (hour > 12) {
            hour = hour - 12;
        }
        changeRotate = (hour - currentRotation/30) * 30;
        qmlObject->setProperty("hourrotate", changeRotate);
        qmlObject->setProperty("hourValue", hour);
    } else {
        qDebug() << "Not Found!";
    }

    qDebug() << hour << "-" << minute << "-" << second;
}

