TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    MinuteClass.cpp \
    HourClass.cpp \
    ApplicationWindown.cpp \
    HandleTime.cpp \
    Second.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    MinuteClass.h \
    HourClass.h \
    ApplicationWindown.h \
    HandleTime.h \
    Second.h
