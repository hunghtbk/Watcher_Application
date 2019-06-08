#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <ApplicationWindown.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    ApplicationWindown::getInstance()->initApplication();

    return app.exec();
}
